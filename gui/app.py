import os
import sys
import subprocess
import re
from PyQt5.QtWidgets import (
    QApplication, QMainWindow, QTabWidget, QWidget, QLabel, QFileDialog,
    QVBoxLayout, QHBoxLayout, QTableWidget, QTableWidgetItem,
    QTextEdit, QPushButton, QFileDialog, QMessageBox, QPlainTextEdit, QTextEdit
)
from PyQt5.QtGui import QTextCursor, QColor, QPainter, QTextFormat
from PyQt5.QtCore import Qt, QRect, QSize, QTimer, QPropertyAnimation, QEasingCurve
from PyQt5.QtWidgets import QHeaderView, QAbstractItemView, QToolTip, QGraphicsOpacityEffect
from PyQt5.QtGui import QKeySequence, QSyntaxHighlighter, QTextCharFormat, QFont
from PyQt5.QtWidgets import QShortcut

class SyntaxHighlighter(QSyntaxHighlighter):
    def __init__(self, document):
        super().__init__(document)

        # --- Define text formats
        self.comment_format = QTextCharFormat()
        self.comment_format.setForeground(QColor("green"))
        self.comment_format.setFontItalic(True)

        self.keyword_format = QTextCharFormat()
        self.keyword_format.setForeground(QColor(85, 0, 255))  # Purple/Blue color
        self.keyword_format.setFontWeight(QFont.Bold)

        self.symbols_format = QTextCharFormat()
        self.symbols_format.setForeground(QColor("Gray")) 
        self.symbols_format.setFontWeight(QFont.Bold)

        # --- Extract keywords from your lexer
        self.keywords = [
            "if", "else", "for", "while", "do", "int", "float", "bool", "string", "char",
            "return", "switch", "case", "default", "continue", "break", "const", "true", "false",
            "pow", "sqrt", "print", "void"
        ]

        self.symbols = [
            "<", ">", "+", "-", "*", "/", "mod", "~", "!", "=", "(", ")", "{", "}", "&", "|", "^", ";"
        ]

        # Build regex for keywords
        self.keyword_pattern = r'\b(' + '|'.join(re.escape(kw) for kw in self.keywords) + r')\b'
        self.symbols_pattern = '(' + '|'.join(re.escape(sym) for sym in self.symbols) + ')'

    def highlightBlock(self, text):
        # --- Highlight keywords
        for match in re.finditer(self.keyword_pattern, text):
            start, end = match.span()
            self.setFormat(start, end - start, self.keyword_format)

        # --- Highlight Symbols
        for match in re.finditer(self.symbols_pattern, text):
            start, end = match.span()
            self.setFormat(start, end - start, self.symbols_format)

        # --- Highlight comments
        comment_index = text.find("//")
        if comment_index >= 0:
            self.setFormat(comment_index, len(text) - comment_index, self.comment_format)

# === Custom Editor with Line Numbers ===
class LineNumberArea(QWidget):
    def __init__(self, editor):
        super().__init__(editor)
        self.code_editor = editor

    def sizeHint(self):
        return QSize(self.code_editor.line_number_area_width(), 0)

    def paintEvent(self, event):
        self.code_editor.line_number_area_paint_event(event)

class CodeEditor(QPlainTextEdit):
    def __init__(self):
        super().__init__()
        self.error_messages = {}
        self.setMouseTracking(True)
        QToolTip.setFont(self.font())

        self.line_number_area = LineNumberArea(self)
        self.extra_selections = []
        self.highlighter = SyntaxHighlighter(self.document())

        self.blockCountChanged.connect(self.update_line_number_area_width)
        self.updateRequest.connect(self.update_line_number_area)
        self.cursorPositionChanged.connect(self.highlight_current_line)#
        
        self.comment_shortcut = QShortcut(QKeySequence("Ctrl+/"), self)
        self.comment_shortcut.activated.connect(self.toggle_comment)

        self.update_line_number_area_width(0)

    def line_number_area_width(self):
        digits = len(str(max(1, self.blockCount())))
        space = 14 + self.fontMetrics().width('9') * digits
        return space

    def resizeEvent(self, event):
        super().resizeEvent(event)
        cr = self.contentsRect()
        rect = QRect(cr.left(), cr.top(), self.line_number_area_width(), cr.height())
        self.line_number_area.setGeometry(rect)

    def update_line_number_area_width(self, _):
        self.setViewportMargins(self.line_number_area_width(), 0, 0, 0)

    def update_line_number_area(self, rect, dy):
        if dy:
            self.line_number_area.scroll(0, dy)
        else:
            self.line_number_area.update(0, rect.y(), self.line_number_area.width(), rect.height())

        if rect.contains(self.viewport().rect()):
            self.update_line_number_area_width(0)

    def line_number_area_paint_event(self, event):
        painter = QPainter(self.line_number_area)
        painter.fillRect(event.rect(), Qt.lightGray)

        block = self.firstVisibleBlock()
        block_number = block.blockNumber()
        top = int(self.blockBoundingGeometry(block).translated(self.contentOffset()).top())
        bottom = top + int(self.blockBoundingRect(block).height())

        while block.isValid() and top <= event.rect().bottom():
            if block.isVisible() and bottom >= event.rect().top():
                number = str(block_number + 1)
                painter.setPen(Qt.black)
                painter.drawText(0, top, self.line_number_area.width(), self.fontMetrics().height(),
                                 Qt.AlignHCenter | Qt.AlignVCenter, number)
            block = block.next()
            top = bottom
            bottom = top + int(self.blockBoundingRect(block).height())
            block_number += 1

    def mouseMoveEvent(self, event):
        cursor = self.cursorForPosition(event.pos())
        block = cursor.block()
        line_number = block.blockNumber() + 1

        if line_number in self.error_messages:
            message = self.error_messages[line_number]
            QToolTip.showText(event.globalPos(), message, self)
        else:
            QToolTip.hideText()

        super().mouseMoveEvent(event)

    
    def toggle_comment(self):
        cursor = self.textCursor()
        start = cursor.selectionStart()
        end = cursor.selectionEnd()

        cursor.setPosition(start)
        start_block = cursor.block()

        cursor.setPosition(end)
        if cursor.atBlockStart() and end != start:
            end_block = cursor.block().previous()
        else:
            end_block = cursor.block()

        block = start_block
        self.textCursor().beginEditBlock()
        while True:
            text = block.text()
            if text.strip().startswith("//"):
                # Uncomment
                index = text.index("//")
                cursor = QTextCursor(block)
                cursor.movePosition(QTextCursor.Right, QTextCursor.MoveAnchor, index)
                cursor.movePosition(QTextCursor.Right, QTextCursor.KeepAnchor, 2)
                cursor.removeSelectedText()
            else:
                # Comment
                cursor = QTextCursor(block)
                cursor.movePosition(QTextCursor.StartOfBlock)
                cursor.insertText("//")

            if block == end_block:
                break
            block = block.next()

        self.textCursor().endEditBlock()

    def highlight_line(self, line_number, color, message=None):
        block = self.document().findBlockByNumber(line_number - 1)
        if block.isValid():
            selection = QTextEdit.ExtraSelection()
            selection.format.setBackground(color) 
            selection.format.setProperty(QTextFormat.FullWidthSelection, True)
            selection.cursor = QTextCursor(block)
            self.extra_selections.append(selection)

            if message:
                self.error_messages[line_number] = message

        self.setExtraSelections(self.extra_selections)

    def keyPressEvent(self, event):
        if event.key() == Qt.Key_Tab:
            cursor = self.textCursor()
            cursor.insertText(" " * 4)  # Insert 4 spaces
        else:
            super().keyPressEvent(event)

    def goto_line(self, line_number):
        """Scroll to the given line number and center it in the view"""
        if line_number < 1:
            line_number = 1
        
        # Find the block corresponding to the line number
        block = self.document().findBlockByLineNumber(line_number - 1)
        if block.isValid():
            # Create a cursor at the start of that block
            cursor = QTextCursor(block)
            # Set the cursor
            self.setTextCursor(cursor)
            # Center the cursor/view
            self.centerCursor()
            # Highlight the line temporarily
            self.highlight_line(line_number, QColor(255, 255, 0, 100))  # Light yellow highlight
            
            # Remove the highlight after a short delay
            QTimer.singleShot(2000, lambda: self.remove_highlight(line_number))

    def highlight_current_line(self):
        """Optional: Highlight the current line (gray background)"""
        extra_selections = self.extra_selections.copy()

        if not self.isReadOnly():
            selection = QTextEdit.ExtraSelection()
            line_color = QColor(Qt.darkGray).lighter(160)
            selection.format.setBackground(line_color)
            selection.format.setProperty(QTextFormat.FullWidthSelection, True)
            selection.cursor = self.textCursor()
            extra_selections.append(selection)

        self.setExtraSelections(extra_selections)

    def remove_highlight(self, line_number):
        """Remove the temporary highlight"""
        # Remove the specific highlight
        self.extra_selections = [sel for sel in self.extra_selections 
                                if not (isinstance(sel.cursor.block().blockNumber(), int) and 
                                    sel.cursor.block().blockNumber() == line_number - 1 and 
                                    sel.format.background().color() == QColor(255, 255, 0, 100))]
        self.setExtraSelections(self.extra_selections)

# === Main Window ===
class LanguageGUI(QMainWindow):
    def __init__(self):
        super().__init__()
        self.activeFileName = None
        self.unused_variables = []

        self.setWindowTitle("YAPL Compiler")
        self.setGeometry(100, 100, 1200, 800)

        central_widget = QWidget()
        self.setCentralWidget(central_widget)
        main_layout = QVBoxLayout(central_widget)

        # Top: Editor + Buttons
        editor_layout = QVBoxLayout()
        button_layout = QHBoxLayout()

        self.editor = CodeEditor()
        self.editor.setPlaceholderText("Write your code here...")
        editor_layout.addWidget(self.editor)

        self.run_button = QPushButton("Run")
        self.run_button.setStyleSheet("QPushButton { padding-top: 10px; padding-bottom: 10px; }")
        
        self.upload_button = QPushButton("Upload File")
        self.upload_button.setStyleSheet("QPushButton { padding-top: 10px; padding-bottom: 10px; }")

        self.save_button = QPushButton("Save File")
        self.save_button.setStyleSheet("QPushButton { padding-top: 10px; padding-bottom: 10px; }")

        button_layout.addWidget(self.run_button)
        button_layout.addWidget(self.upload_button)
        button_layout.addWidget(self.save_button)

        editor_layout.addLayout(button_layout)
        main_layout.addLayout(editor_layout)

        # Bottom: Tabs
        self.tabs = QTabWidget()
        main_layout.addWidget(self.tabs)

        # Create tabs
        self.symbol_table_tab = self.create_table_tab(
            ["Name", "Node Type", "Data Type", "Line Number", "Scope Depth", "Is Const", "Is Initialized", "Is Used"]
        )
        self.symbol_table_tab.table.setEditTriggers(QAbstractItemView.NoEditTriggers)

        self.quadruples_tab = self.create_table_tab(
            ["Operation", "Operand 1", "Operand 2", "Result"]
        )
        self.symbol_table_tab.table.setEditTriggers(QAbstractItemView.NoEditTriggers)

        self.optimized_quadruples_tab = self.create_table_tab(
            ["Operation", "Operand 1", "Operand 2", "Result"]
        )
        self.symbol_table_tab.table.setEditTriggers(QAbstractItemView.NoEditTriggers)

        self.symbol_table_tab.table.cellDoubleClicked.connect(self.on_symbol_table_double_click)

        self.output_tab = self.create_output_tab()
        self.errors_tab = self.create_output_tab()

        self.tabs.addTab(self.symbol_table_tab, "Symbol Table")
        self.tabs.addTab(self.quadruples_tab, "Quadruples")
        self.tabs.addTab(self.optimized_quadruples_tab, "Optimized Quadruples")
        self.tabs.addTab(self.output_tab, "Output")
        self.tabs.addTab(self.errors_tab, "Errors")

        # Connect Buttons
        self.run_button.clicked.connect(self.run_code)
        self.upload_button.clicked.connect(self.upload_file)
        self.save_button.clicked.connect(self.save_file)

    def create_table_tab(self, headers):
        tab = QWidget()
        layout = QVBoxLayout(tab)

        table = QTableWidget()
        table.setColumnCount(len(headers))
        table.setHorizontalHeaderLabels(headers)
        table.horizontalHeader().setSectionResizeMode(QHeaderView.Stretch)
        table.horizontalHeader().setStretchLastSection(True)
        layout.addWidget(table)

        tab.table = table
        return tab
    
    def on_symbol_table_double_click(self, row, column):
        # Get the line number from the table (4th column is the line number)
        line_number_str = self.symbol_table_tab.table.item(row, 3).text()
        try:
            line_number = int(line_number_str)
            self.editor.goto_line(line_number)
            self.show_toast(f"Jumped to line {line_number}")
        except (ValueError, TypeError):
            self.show_toast("Invalid line number")

    def create_output_tab(self):
        tab = QWidget()
        layout = QVBoxLayout(tab)

        text_edit = QTextEdit()
        text_edit.setReadOnly(True)
        layout.addWidget(text_edit)

        tab.text_edit = text_edit
        return tab

    def add_row(self, table, row_data):
        row_pos = table.rowCount()
        table.insertRow(row_pos)
        for col, data in enumerate(row_data):
            table.setItem(row_pos, col, QTableWidgetItem(str(data)))

    def show_output_with_errors(self, lines, error_lines):
        text_edit = self.output_tab.text_edit
        text_edit.clear()

        for idx, line in enumerate(lines, start=1):
            if idx in error_lines:
                text_edit.setTextColor(QColor("red"))
            else:
                text_edit.setTextColor(QColor("black"))
            text_edit.append(line)

        text_edit.setTextColor(QColor("black"))
        text_edit.moveCursor(QTextCursor.Start)

    def run_code(self):
        self.editor.error_messages = {}
        self.editor.extra_selections = []
        self.unused_variables = []
        self.editor.setExtraSelections([])
        self.save_button.click()

        # Clear all tables
        self.symbol_table_tab.table.setRowCount(0)
        self.quadruples_tab.table.setRowCount(0)
        self.optimized_quadruples_tab.table.setRowCount(0)

        # Define the log folder path
        log_folder_path = 'log'

        # Iterate over each file in the log folder and empty its contents
        for file_name in os.listdir(log_folder_path):
            file_path = os.path.join(log_folder_path, file_name)
            if os.path.isfile(file_path):
                with open(file_path, 'w') as file:
                    file.truncate(0)


        process = subprocess.Popen(['./yapl.exe', self.activeFileName], stdout=subprocess.PIPE)
        stdout, _ = process.communicate()

        if "error" not in stdout.decode().lower():
            with open('log/symbol_table.txt', 'r') as f:
                lines = f.readlines()[1:]
                self.symbol_table_tab.table.setRowCount(0)
                for line in lines:
                    line = line.strip()
                    record = line.split(",")
                    for part in record: part.strip()
                    self.add_row(self.symbol_table_tab.table, record)
                    if record[7].lower() == "no":
                        self.unused_variables.append((
                            int(record[3]), 
                            QColor("orange"), 
                            f"variable {record[0]} is not used"))
                    

            with open('log/quadruples.txt', 'r') as f:
                lines = f.readlines()
                self.quadruples_tab.table.setRowCount(0)
                for line in lines:
                    line = line.strip()
                    record = line.split(",")
                    for part in record: part.strip()
                    self.add_row(self.quadruples_tab.table, record)

            with open('log/optimized_quadruples.txt', 'r') as f:
                optimized_lines = f.readlines()
                self.optimized_quadruples_tab.table.setRowCount(0)
                for line in optimized_lines:
                    line = line.strip()
                    record = line.split(",")
                    for part in record: part.strip()
                    self.add_row(self.optimized_quadruples_tab.table, record)
                    
        self.show_output_with_errors(stdout.decode().splitlines(), [])
        self.show_errors_tab()

    def upload_file(self):
        file_name, _ = QFileDialog.getOpenFileName(self, "Open File", "", "All Files (*)")
        if file_name:
            with open(file_name, 'r') as f:
                content = f.read()
                self.activeFileName = file_name
                self.editor.setPlainText(content)

    def save_file(self):
        (file_name, __), _ = QFileDialog.getSaveFileName(self, "Save File", "", "All Files (*)") if self.activeFileName is None else (self.activeFileName, ""), ""
        if file_name:
            with open(file_name, 'w') as f:
                f.write(self.editor.toPlainText())
            self.activeFileName = file_name
            self.show_toast("File saved successfully.")

    def show_errors_tab(self):
        text_edit = self.errors_tab.text_edit
        text_edit.clear()

        lines = []
        error_line_numbers = self.unused_variables.copy()

        for lineNum, color, message in error_line_numbers:
            text_edit.append( f"{lineNum}: WARNING - {message}" )

        try:
            with open('log/errors.txt', 'r') as f:
                lines = f.readlines()

            for line in lines:
                parts = line.split(',')
                text_edit.append(f"{parts[0]}: {parts[1]} - {parts[2]}")
                lineNumber = parts[0]
                error_message = parts[2]
                error_line_numbers.append(
                    (
                        int(lineNumber), 
                        QColor("red") if  parts[1].lower() == "error" else QColor("orange"),
                        error_message
                    )
                ),
                        

        except FileNotFoundError:
            text_edit.append("No errors detected or 'output' file not found.")

        text_edit.moveCursor(QTextCursor.Start)

        # Highlight first error line if exists
        for lineNum, color, message in error_line_numbers:
            self.editor.highlight_line(lineNum, color, message)

    def show_toast(self, message):
        # Create toast widget
        toast = QLabel(message, self)
        toast.setStyleSheet("""
            background-color: #333333;
            color: white;
            border-radius: 10px;
            padding: 10px 20px;
        """)
        toast.setAlignment(Qt.AlignCenter)
        
        # Position toast at the bottom center
        toast_width = 250
        toast_height = 50
        toast.resize(toast_width, toast_height)
        
        # Position at the bottom center of the window
        x = (self.width() - toast_width) // 2
        y = self.height() - toast_height - 40  # 40px from bottom
        toast.move(x, y)
        
        # Show the toast
        toast.show()
        
        # Create fade effect
        self.fade_effect = QGraphicsOpacityEffect()
        toast.setGraphicsEffect(self.fade_effect)
        
        # Create animation to automatically hide the toast after delay
        self.fade_anim = QPropertyAnimation(self.fade_effect, b"opacity")
        self.fade_anim.setDuration(1000) 
        self.fade_anim.setStartValue(0.0)
        self.fade_anim.setEndValue(1.0)
        self.fade_anim.setEasingCurve(QEasingCurve.InOutQuad)
        
        # When animation finishes, delete the toast
        # self.fade_anim.finished.connect(toast.deleteLater)
        
        # Start with quick fade in, then delay, then fade out
        self.fade_anim.start()
        
        # Second animation for fade out
        QTimer.singleShot(2000, lambda: self.start_fade_out(toast))

    def start_fade_out(self, toast):
        # Create fade out animation
        self.fade_out = QPropertyAnimation(self.fade_effect, b"opacity")
        self.fade_out.setDuration(1000)  # 1 second fade out
        self.fade_out.setStartValue(1.0)
        self.fade_out.setEndValue(0.0)
        self.fade_out.setEasingCurve(QEasingCurve.InOutQuad)
        self.fade_out.start()

if __name__ == "__main__":
    app = QApplication(sys.argv)
    app.setStyleSheet("""
        QToolTip {
            background-color: #f0f0f0;
            color: #333333;
            border: 1px solid #cccccc;
            border-radius: 8px;
            padding: 8px;
            font-size: 12pt;
        }
    """)

    app.setStyleSheet("""
        QPlainTextEdit {
            padding-left: 8px;
            padding-top: 8px;
            padding-bottom: 8px;
            font-size: 14px;
        }
    """)

    window = LanguageGUI()
    window.show()
    sys.exit(app.exec_())

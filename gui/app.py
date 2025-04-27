import os
import sys
import subprocess
from PyQt5.QtWidgets import (
    QApplication, QMainWindow, QTabWidget, QWidget,
    QVBoxLayout, QHBoxLayout, QTableWidget, QTableWidgetItem,
    QTextEdit, QPushButton, QFileDialog, QMessageBox, QPlainTextEdit, QTextEdit
)
from PyQt5.QtGui import QTextCursor, QColor, QPainter, QTextFormat
from PyQt5.QtCore import Qt, QRect, QSize
from PyQt5.QtWidgets import QHeaderView, QAbstractItemView
from PyQt5.QtGui import QKeySequence
from PyQt5.QtWidgets import QShortcut

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
        self.line_number_area = LineNumberArea(self)
        self.extra_selections = []

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

    def highlight_line(self, line_number, color):
        """Highlight a specific line number with red background"""

        block = self.document().findBlockByNumber(line_number - 1)
        if block.isValid():
            selection = QTextEdit.ExtraSelection()
            selection.format.setBackground(color) 
            selection.format.setProperty(QTextFormat.FullWidthSelection, True)
            selection.cursor = QTextCursor(block)
            self.extra_selections.append(selection)

        self.setExtraSelections(self.extra_selections)

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

# === Main Window ===
class LanguageGUI(QMainWindow):
    def __init__(self):
        super().__init__()
        self.activeFileName = None

        self.setWindowTitle("Language GUI")
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
            ["Name", "Node Type", "Data Type", "Scope Depth", "Is Const", "Is Initialized", "Is Used"]
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

        # Highlight error lines in code editor
        if error_lines:
            self.editor.highlight_line(error_lines[0])  # Just highlighting first error line for now

    def run_code(self):
        self.save_button.click()
        self.extra_selections = []

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


        process = subprocess.Popen(['./yapl', self.activeFileName], stdout=subprocess.PIPE)
        stdout, _ = process.communicate()

        if "error" not in stdout.decode().lower():
            with open('log/symbol_table.txt', 'r') as f:
                lines = f.readlines()[2:]
                self.symbol_table_tab.table.setRowCount(0)
                for line in lines:
                    self.add_row(self.symbol_table_tab.table, line.split())

            with open('log/quadruples.txt', 'r') as f:
                lines = f.readlines()
                self.quadruples_tab.table.setRowCount(0)
                for line in lines:
                    self.add_row(self.quadruples_tab.table, line.split())

            with open('log/optimized_quadruples.txt', 'r') as f:
                optimized_lines = f.readlines()
                self.optimized_quadruples_tab.table.setRowCount(0)
                for line in optimized_lines:
                    self.add_row(self.optimized_quadruples_tab.table, line.split())
                    
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
        print(file_name)
        if file_name:
            with open(file_name, 'w') as f:
                f.write(self.editor.toPlainText())
            self.activeFileName = file_name
            QMessageBox.information(self, "Saved", "File saved successfully.")

    def show_errors_tab(self):
        text_edit = self.errors_tab.text_edit
        text_edit.clear()

        lines = []
        error_line_numbers = []

        try:
            with open('log/errors.txt', 'r') as f:
                lines = f.readlines()

            for line in lines:
                text_edit.append(line)
                lineNumber = line.split(':', 1)[0]
                error_line_numbers.append((int(lineNumber), QColor("red") if "Error" in line else QColor("orange")))

        except FileNotFoundError:
            text_edit.append("No errors detected or 'output' file not found.")

        text_edit.moveCursor(QTextCursor.Start)

        # Highlight first error line if exists
        for lineNum, color in error_line_numbers:
            self.editor.highlight_line(lineNum, color)

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = LanguageGUI()
    window.show()
    sys.exit(app.exec_())

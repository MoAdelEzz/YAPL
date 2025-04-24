import os
import subprocess
import tkinter as tk
import re
from tkinter import ttk, filedialog, messagebox
from tkinter.scrolledtext import ScrolledText


class CodeEditorGUI:
    def __init__(self, root):
        self.root = root
        self.root.title("YAPL Compiler")
        self.root.geometry("1200x700")

        self.bg_color = "#1e1e1e"
        self.text_color = "#d4d4d4"
        self.accent_color = "#569cd6"

        self.root.configure(bg=self.bg_color)
        self.create_menu()

        self.top_bar = ttk.Frame(self.root, style="Top.TFrame")
        self.top_bar.pack(fill=tk.X)

        self.run_button = ttk.Button(self.top_bar, text="▶ Run", command=self.run_code, style="Run.TButton")
        self.run_button.pack(side=tk.RIGHT, padx=10, pady=5)

        self.notebook = ttk.Notebook(self.root, style="TNotebook")
        self.notebook.pack(fill=tk.BOTH, expand=True)

        self.create_tabs()
        self.configure_styles()

        self.current_file = None
        self.compiler_path = tk.StringVar(value="./yapl")

    def configure_styles(self):
        style = ttk.Style()
        style.theme_use("default")

        style.configure("Top.TFrame", background=self.bg_color)
        style.configure("Run.TButton", background=self.accent_color, foreground="white", font=("Segoe UI", 10, "bold"))
        style.map("Run.TButton", background=[("active", "#4fa3d1")])

        style.configure("TNotebook", background=self.bg_color, borderwidth=0)
        style.configure("TNotebook.Tab", background="#2d2d2d", foreground="white", padding=[10, 4], font=("Segoe UI", 10))
        style.map("TNotebook.Tab",
                   background=[("selected", self.accent_color)],
                   foreground=[("selected", "white")])
        style.configure("TFrame", background=self.bg_color)

    def create_menu(self):
        menu_bar = tk.Menu(self.root, bg="#2d2d2d", fg="white", activebackground="#3c3f41", activeforeground="white")

        file_menu = tk.Menu(menu_bar, tearoff=0, bg="#2d2d2d", fg="white", activebackground="#3c3f41")
        file_menu.add_command(label="New", command=self.new_file, accelerator="Ctrl+N")
        file_menu.add_command(label="Open", command=self.open_file, accelerator="Ctrl+O")
        file_menu.add_command(label="Save", command=self.save_file, accelerator="Ctrl+S")
        file_menu.add_command(label="Save As", command=self.save_as_file, accelerator="Ctrl+Shift+S")
        file_menu.add_separator()
        file_menu.add_command(label="Exit", command=self.root.quit)
        menu_bar.add_cascade(label="File", menu=file_menu)

        run_menu = tk.Menu(menu_bar, tearoff=0, bg="#2d2d2d", fg="white", activebackground="#3c3f41")
        run_menu.add_command(label="Run", command=self.run_code, accelerator="F5")
        menu_bar.add_cascade(label="Run", menu=run_menu)

        self.root.config(menu=menu_bar)

        self.root.bind("<Control-n>", lambda _: self.new_file())
        self.root.bind("<Control-o>", lambda _: self.open_file())
        self.root.bind("<Control-s>", lambda _: self.save_file())
        self.root.bind("<Control-a>", lambda _: self.editor.focus_set() or self.editor.tag_add("sel", "1.0", tk.END))
        self.root.bind("<Control-Shift-S>", lambda _: self.save_as_file())
        self.root.bind("<F5>", lambda _: self.run_code())

    def create_tabs(self):
        self.editor_frame = ttk.Frame(self.notebook)
        self.notebook.add(self.editor_frame, text="Code")
        self.editor = self.create_text_editor(self.editor_frame)

        self.output_frame = ttk.Frame(self.notebook)
        self.notebook.add(self.output_frame, text="Output")
        self.output_text = self.create_text_area(self.output_frame)

        self.assembly_frame = ttk.Frame(self.notebook)
        self.notebook.add(self.assembly_frame, text="Assembly")
        self.assembly_text = self.create_text_area(self.assembly_frame)
        self.symbols_frame = ttk.Frame(self.notebook)
        self.notebook.add(self.symbols_frame, text="Symbol Table")

        self.symbols_table = ttk.Treeview(
            self.symbols_frame, 
            columns=("Name", "Kind", "Data Type", "Scope", "Is Constant", "Is Initialized", "Is Used"),
            show="headings", 
            height=10,
        )
        self.symbols_table.pack(fill=tk.BOTH, expand=True, padx=5, pady=5)

        for col in self.symbols_table["columns"]:
            self.symbols_table.heading(col, text=col, anchor=tk.CENTER)
            self.symbols_table.column(col, anchor=tk.CENTER, minwidth=150)

        self.errors_frame = ttk.Frame(self.notebook)
        self.notebook.add(self.errors_frame, text="Errors")
        self.errors_text = self.create_text_area(self.errors_frame)

    def create_text_editor(self, parent):
        frame = ttk.Frame(parent)
        frame.pack(fill=tk.BOTH, expand=True)

        line_numbers = tk.Text(frame, width=5, padx=5, takefocus=0, border=0,
                               bg="#1e1e1e", fg="#6a9955", state=tk.DISABLED,
                               font=("Consolas", 10))
        line_numbers.pack(side=tk.LEFT, fill=tk.Y)

        text_editor = ScrolledText(frame, wrap=tk.NONE, undo=True,
                                   bg="#1e1e1e", fg=self.text_color, insertbackground="white",
                                   font=("Consolas", 10), padx=10, pady=10)
        text_editor.pack(fill=tk.BOTH, expand=True)

        def update_line_numbers(event=None):
            line_count = int(text_editor.index('end-1c').split('.')[0])
            line_numbers.config(state=tk.NORMAL)
            line_numbers.delete('1.0', tk.END)
            for i in range(1, line_count + 1):
                line_numbers.insert(tk.END, f"{i}\n")
            line_numbers.config(state=tk.DISABLED)

        text_editor.bind('<KeyRelease>', update_line_numbers)
        update_line_numbers()

        return text_editor

    def create_text_area(self, parent):
        text_area = ScrolledText(parent, wrap=tk.WORD, bg="#1e1e1e", fg=self.text_color,
                                 font=("Consolas", 10), padx=10, pady=10)
        text_area.pack(fill=tk.BOTH, expand=True)
        return text_area

    def new_file(self):
        self.editor.delete('1.0', tk.END)
        self.current_file = None
        self.root.title("Code Editor - New File")

    def open_file(self):
        file_path = filedialog.askopenfilename(filetypes=[("All Files", "*.*")])
        if file_path:
            try:
                with open(file_path, 'r') as file:
                    content = file.read()
                    self.editor.delete('1.0', tk.END)
                    self.editor.insert('1.0', content)
                    self.current_file = file_path
                    self.root.title(f"Code Editor - {os.path.basename(file_path)}")
            except Exception as e:
                messagebox.showerror("Error", f"Could not open file: {e}")

    def save_file(self):
        if self.current_file:
            try:
                content = self.editor.get('1.0', tk.END)
                with open(self.current_file, 'w') as file:
                    file.write(content)
                return True
            except Exception as e:
                messagebox.showerror("Error", f"Could not save file: {e}")
                return False
        else:
            return self.save_as_file()

    def save_as_file(self):
        file_path = filedialog.asksaveasfilename(defaultextension=".txt",
                                                 filetypes=[("Text Files", "*.txt"), ("All Files", "*.*")])
        if file_path:
            try:
                content = self.editor.get('1.0', tk.END)
                with open(file_path, 'w') as file:
                    file.write(content)
                self.current_file = file_path
                self.root.title(f"Code Editor - {os.path.basename(file_path)}")
                return True
            except Exception as e:
                messagebox.showerror("Error", f"Could not save file: {e}")
                return False
        return False

    def run_code(self):
        if self.current_file:
            if not self.save_file():
                return
        else:
            if not self.save_as_file():
                return

        compiler = self.compiler_path.get()
        if not os.path.exists(compiler):
            messagebox.showerror("Error", f"Compiler not found: {compiler}")
            return
        try:
            result = subprocess.run([compiler, self.current_file], capture_output=True, text=True)
        
            self.output_text.delete('1.0', tk.END)
            self.assembly_text.delete('1.0', tk.END)
            self.symbols_table.delete(*self.symbols_table.get_children())

            self.output_text.insert('1.0', result.stdout)
            if result.stderr:
                self.output_text.insert(tk.END, f"\n\nErrors:\n{result.stderr}")

            try:
                error_log_file = f"./log/errors.txt"
                if os.path.exists(error_log_file):
                    with open(error_log_file, 'r') as f:
                        self.errors_text.insert('1.0', f.read())
            except Exception as e:
                self.errors_text.insert('1.0', f"Could not load assembly output: {e}")

            try:
                symbol_file = "log/symbol_table.txt"
                if os.path.exists(symbol_file):
                    with open(symbol_file, 'r') as f:
                        data = f.readlines()
                        rows = [ row.split() for row in data[2:] ]
                        for row in rows:
                            self.symbols_table.insert("", "end", values=row)
                        
            except Exception as e:
                self.symbols_text.insert('1.0', f"Could not load symbol table: {e}")

            self.notebook.select(1)

        except Exception as e:
            messagebox.showerror("Error", f"Error running compiler: {e}")

def main():
    root = tk.Tk()
    app = CodeEditorGUI(root)
    root.mainloop()

if __name__ == "__main__":
    main()
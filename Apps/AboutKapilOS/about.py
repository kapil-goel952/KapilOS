import tkinter as tk

root = tk.Tk()

root.title("About KapilOS")
root.geometry("500x350")

title = tk.Label(
    root,
    text="KapilOS",
    font=("Arial", 24, "bold")
)

title.pack(pady=20)

version = tk.Label(
    root,
    text="Version 0.1\nCodename: Genesis",
    font=("Arial", 14)
)

version.pack()

desc = tk.Label(
    root,
    text="KapilOS\nBuilt by Kapil Goel\nBased on Ubuntu 24.04 LTS",
    font=("Arial", 12),
    justify="center"
)

desc.pack(pady=20)

root.mainloop()

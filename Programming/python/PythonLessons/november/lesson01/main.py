import tkinter as tk

baseWindow = tk.Tk()
baseWindow.geometry('800x800')
lbl1 = tk.Label(baseWindow, text="Введите возраст(ты нахуй в моем коде ковыряешься): ",
                font="Arial 18", fg="#000000", bg="#FFE773")
lbl1.pack(fill='x')
baseWindow.mainloop()
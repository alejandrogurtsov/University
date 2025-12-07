import tkinter as tk
from tkinter import messagebox

questions = [
    "1. В какие страны/города вы уже путешествовали?",
    "2. Какая страна(город) произвела на вас самое сильно впечатление?",
    "3. Вы предпочитаете море, горы или города?",
    "4. Какой тип отдыха вам нравится? (пляжный, экскурсии, активный, смешанный)",
    "5. Как часто вы путешествуете?",
    "6. Предпочитаете путешествовать в одиночку, с друзьями или с семьёй?",
    "7. Каким транспортом вы чаще всего пользуетесь для путешествий?",
    "8. Где вы обычно останавливаетесь? (отель, хостел, квартира, у друзей/родственников)",
    "9. Какой бюджет вы обычно тратите на поездку?",
    "10. Страна или город мечты - куда вы хотите поехать больше всего?"
]

question_index = 0
answers = []

def next_question():
    global question_index

    answer = answer_entry.get().strip()
    if answer == "":
        messagebox.showwarning("Ошибка", "Введите ответ!")
        return

    answers.append(answer)
    answer_entry.delete(0, tk.END)

    question_index += 1

    if question_index < len(questions):
        question_label.config(text=questions[question_index])
    else:
        save_results()

def save_results():
    with open("results.txt", "w", encoding="utf-8") as file:
        file.write("Результаты анкеты:\n")
        for i in range(len(questions)):
            file.write(f"{questions[i]}: {answers[i]}\n")
        file.write("\n")

    messagebox.showinfo("Готово!", "Результаты анкеты сохранены в файл results.txt")
    baseWindow.destroy()

baseWindow = tk.Tk()
baseWindow.title("Анкета путешественника")
baseWindow.geometry("640x150")

question_label = tk.Label(baseWindow, text=questions[0], font=("Helvetica", 14))
question_label.pack(pady=20)

answer_entry = tk.Entry(baseWindow, width=60, font=("Helvetica", 12))
answer_entry.pack()

next_button = tk.Button(baseWindow, text="Далее", command=next_question, font=("Helvetica", 12))
next_button.pack(pady=10)

baseWindow.mainloop()
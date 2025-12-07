import tkinter as tk
from tkinter import messagebox

file = "questions.txt"
theme = ''

def load_q(file):
    global theme
    questions = []
    with open(file, 'r', encoding="utf-8") as f:
        lines = [line.strip() for line in f if line.strip]

    current_q = None
    answers = []
    correct_ans =[]

    for line in lines:
        if line.startswith('t:'):
            theme = line[2:].strip()
        if line.startswith('q:'):
            if current_q:
                questions.append((current_q,answers,correct_ans))
            current_q = line[2:].strip()
            answers=[]
            correct_ans=[]
        else:
            text = line
            is_correct = text.endswith("+")
            if is_correct:
                text = text[:-1].strip()

            answer_text = text[2:].strip()
            answers.append(answer_text)
            if is_correct:
                correct_ans.append(len(answers)-1)
    if current_q:
        questions.append((current_q, answers, correct_ans))

    return questions

questions = load_q(file)
current_idx = 0
correct_count = 0

answer_vars = []
answer_w =[]

def show_question():
    global answer_w, answer_vars

    for w in answers_frame.winfo_children():
        w.destroy()

    answer_vars=[]
    answer_w =[]

    q_text, answers, correct_ans = questions[current_idx]
    question_label.config(text=f'{current_idx+1}. {q_text}')

    if len(correct_ans) == 1:
        selected_var = tk.IntVar(value=-1)
        for i, ans in enumerate(answers):
            rb = tk.Radiobutton(
                answers_frame,
                text=ans,
                variable=selected_var,
                value=i,
                font=("Helvetica", 14),
                anchor="w"
            )
            rb.pack(fill="x", padx=20, pady=3)
        answer_vars.append(selected_var)
    else:

        for ans in answers:
            var = tk.IntVar()
            cb = tk.Checkbutton(answers_frame, text=ans, variable=var, font=("Helvetica",14), anchor="w")
            cb.pack(fill="x",padx=20,pady=3)
            answer_vars.append(var)
            answer_w.append(cb)

def check_answer():
    global current_idx, correct_count

    _, _, correct_ans = questions[current_idx]

    if len(correct_ans) == 1:
        selected = [answer_vars[0].get()]

        if selected[0] == -1:
            messagebox.showwarning("Ошибка", "Выберите вариант!")
            return
    else:
        selected = [i for i, v in enumerate(answer_vars) if v.get() == 1]
        if not selected:
            messagebox.showwarning("Ошибка", "Выберите хотя бы один вариант!")
            return

    if set(selected) == set(correct_ans):
        correct_count += 1

    current_idx += 1

    if current_idx < len(questions):
        show_question()
    else:
        finish_test()

def finish_test():
    total = len(questions)
    percent = correct_count / total * 100

    messagebox.showinfo(
        "Результат",
        f"Правильных ответов: {correct_count} из {total}\n"
        f"Процент: {percent}%"
    )

    baseWindow.destroy()

baseWindow = tk.Tk()
baseWindow.title(theme)
baseWindow.geometry("580x300")

question_label = tk.Label(baseWindow, text='', font=("Helvetica", 16))
question_label.pack(pady=10)

answers_frame = tk.Frame(baseWindow)
answers_frame.pack()

answer_button = tk.Button(baseWindow, text="Ответить", command=check_answer, font=("Helvetica", 14))
answer_button.pack(pady=20)

show_question()
baseWindow.mainloop()
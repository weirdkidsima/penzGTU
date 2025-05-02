from tkinter import *
from tkinter import ttk
import math

root = Tk()
root.title("Лабораторная работа №3")
root.geometry("600x600")

def make_labelEntry(varName, xLabelCoordinate, yLabelCoordinate, xEntryCoordinate, yEntryCoordinate):
    labelMark = Label(text=f"Введите значение {varName}: ", font="Consolas 12")
    labelMark.place(x=xLabelCoordinate, y=yLabelCoordinate)

    entryMark = Entry()
    entryMark.place(x=xEntryCoordinate, y=yEntryCoordinate)
    return entryMark

def make_button(xCoordinate, yCoordinate, func):
    btn = Button(text="Вычисление", command=func)
    btn.place(x=xCoordinate, y=yCoordinate)

def linear_algorithm(varX, varY, varZ):
    try:
        x = float(varX.get())
        y = float(varY.get())
        z = float(varZ.get())

        if z == 0:
            return "Ошибка: z не может быть равным 0"
        
        denominator = x - (2 * y) / (1 + x**2 * y**2)
        if denominator == 0:
            return "Ошибка: x не должно равняться 2y / (1 + x^2 * y^2)"
        
        if abs(x) < 1 and y < 0:
            return "Ошибка: Для |x| < 1, y должно быть неотрицательным"

        v = (1 + math.sin(x + y)**2) / abs(denominator) * (abs(x)**y) + math.cos(math.atan(1 / z))**2
        return f"Результат линейного алгоритма: v = {v:.4f}"
    
    except ValueError:
        return "Ошибка: некорректные данные"

def branching_algorithm(varX, varY):
    try:
        x = float(varX.get())
        y = float(varY.get())

        f_x = x**2
        xy = x * y

        if 0.5 < xy < 5:
            l = math.e**(f_x - abs(y))
        elif 0.1 < xy <= 0.5:
            l = math.sqrt(abs(f_x) + y)
        else:
            l = 2 * (f_x**2)

        return f"Результат разветвленного алгоритма: l = {l:.4f}"
    
    except ValueError:
        return "Ошибка: некорректные данные"

def main():
    global linearArgX, linearArgY, linearArgZ, result_linearLabel, branchingArgX, branchingArgY

    linearAlgoMark = ttk.Label(text="Линейный алгоритм", font="Consolas 24")
    linearAlgoMark.pack()

    linearArgX = make_labelEntry("x", 20, 50, 200, 55)
    linearArgY = make_labelEntry("y", 20, 85, 200, 90)
    linearArgZ = make_labelEntry("z", 20, 120, 200, 125)

    result_linearLabel = Label(text="Результат линейного алгоритма: ", font="Consolas 12")
    result_linearLabel.place(x=20, y=160)
    make_button(100, 190, lambda: result_linearLabel.config(text=linear_algorithm(linearArgX, linearArgY, linearArgZ)))

    branchingAlgoMark = Label(text="Разветвленный алгоритм", font="Consolas 24")
    branchingAlgoMark.pack(pady=185)

    branchingArgX = make_labelEntry("x", 20, 290, 200, 295)
    branchingArgY = make_labelEntry("y", 20, 325, 200, 330)

    result_branchingLable = Label(text="Результат разветвленного алгоритма: ", font="Consolas 12")
    result_branchingLable.place(x=20, y=365)
    make_button(100, 395, lambda: result_branchingLable.config(text=branching_algorithm(branchingArgX, branchingArgY)))

    root.mainloop()

main()
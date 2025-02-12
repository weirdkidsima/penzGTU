import math

def linear_algorithm():
    print("\n=== Линейный алгоритм ===")
    try:
        # Ввод данных
        x = float(input("Введите значение x: "))
        y = float(input("Введите значение y: "))
        z = float(input("Введите значение z: "))

        # Проверка на корректность
        if x == 0 or z == 0:
            print("Ошибка: x и z не могут быть равны 0")
            return

        # Вычисление
        v = (1 + math.sin(x + y)**2) / abs(x - (2 * y) / (1 + x**2 * y**2)) * (abs(x)**y) + math.cos(math.atan(1 / z))**2
        print(f"Результат: v = {v:.4f}")
    except ValueError:
        print("Ошибка: некорректные данные")

def branching_algorithm():
    print("\n=== Разветвляющийся алгоритм ===")
    try:
        # Ввод данных
        x = float(input("Введите значение x: "))
        y = float(input("Введите значение y: "))

        # Выбранная функция
        f_x = x**2

        # Вычисление
        xy = x * y
        if 0.5 < xy < 5:
            l = math.e**(f_x - abs(y))
        elif 0.1 < xy <= 0.5:
            l = math.sqrt(abs(f_x) + y)
        else:
            l = 2 * (f_x**2)
        
        print(f"Результат: l = {l:.4f}")
    except ValueError:
        print("Ошибка: некорректные данные. Попробуйте снова.")

def main():
    while True:
        print("\n=== Меню ===")
        print("1. Линейный алгоритм")
        print("2. Разветвляющийся алгоритм")
        print("0. Выход")
        
        choice = input("Выберите действие (0-2): ")
        
        if choice == "1":
            linear_algorithm()
        elif choice == "2":
            branching_algorithm()
        elif choice == "0":
            break
        else:
            print("Ошибка: некорректный выбор. Выбирать необходимо только из предложенных вариантов")
            
if __name__ == "__main__":
    main()

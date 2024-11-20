import numpy as np

# Определяем интегрируемую функцию
def integrand(x):
    return (1 + np.sin(np.pi * x)) / x

# Метод Симпсона
def simpson_integration(f, a, b, n):
    if n % 2 == 1:  # n должен быть чётным
        n += 1
    h = (b - a) / n
    total = f(a) + f(b)
    
    for i in range(1, n, 2):
        total += 4 * f(a + i * h)
    for i in range(2, n-1, 2):
        total += 2 * f(a + i * h)

    return total * h / 3

# Метод трапеций для оценки погрешности
def trapezoidal_integration(f, a, b, n):
    h = (b - a) / n
    total = 0.5 * (f(a) + f(b))
    
    for i in range(1, n):
        total += f(a + i * h)
    
    return total * h

# Параметры интегрирования
a = 1
b = 2
n = 100

# Вычисление интеграла по методу Симпсона
simpson_result = simpson_integration(integrand, a, b, n)

# Вычисление интеграла по методу трапеций для оценки погрешности
trapezoidal_result = trapezoidal_integration(integrand, a, b, n)
error = abs(simpson_result - trapezoidal_result)

# Выводим результаты
print(f"Значение интеграла по методу Симпсона: {simpson_result}")
print(f"Оценка погрешности: {error}")

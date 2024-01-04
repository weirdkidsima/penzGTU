import numpy as np
from scipy.optimize import minimize

def f(x):
    return -x[0] * x[1] * np.exp(-(x[0] + x[1]))

def gradient(x):
    dfdx1 = -(x[1] * np.exp(-(x[0] + x[1]))) - (x[0] * x[1] * np.exp(-(x[0] + x[1])))
    dfdx2 = -(x[0] * np.exp(-(x[0] + x[1]))) - (x[0] * x[1] * np.exp(-(x[0] + x[1])))
    return np.array([dfdx1, dfdx2])

def fletcher_rives(x0, tol=1e-5, max_iter=100):
    x = x0
    iterations = 0

    while iterations < max_iter:
        iterations += 1

        # вычисление градиента
        grad = gradient(x)

        # проверка сходимости
        if np.linalg.norm(grad) < tol:
            break

        # Вычисление направления поиска
        if iterations == 1:
            p = -grad
        else:
            beta = np.dot(grad, grad) / np.dot(grad_prev, grad_prev)
            p = -grad + beta * p_prev

        # вычисление размера шага линейным поиском
        alpha = minimize(lambda a: f(x + a * p), 0).x[0]

        # обновление точки
        x_prev = x
        x = x + alpha * p

        # обновление переменной для следующей итерации
        grad_prev = grad
        p_prev = p

    return x

# начальная точка
x0 = np.array([0, 1])

# решение кода и вывод результатов
result = fletcher_rives(x0)
print("миниуум найден в точке:", result)
print("минимальное значение функции f(x):", f(result))

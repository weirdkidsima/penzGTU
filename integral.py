import numpy as np
from scipy.integrate import quad

# Даём интегрируемую функцию
def integrand(x):
    return (1 + np.sin(np.pi * x)) / x

# Вычисляем определённый интеграл
result, error = quad(integrand, 1, 2)

# Выводим результат и оценку погрешности
print(f"Значение интеграла: {result}")
print(f"Оценка погрешности: {error}")

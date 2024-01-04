import numpy as np
from scipy.optimize import minimize
import matplotlib.pyplot as plt

# Определение функции f(x)
def objective_function(x):
    return -x[0] * x[1] * np.exp(-x[0] - x[1])

# Определение градиента функции f(x)
def gradient(x):
    df_dx1 = -x[1] * np.exp(-x[0] - x[1]) + x[0] * x[1] * np.exp(-x[0] - x[1])
    df_dx2 = -x[0] * np.exp(-x[0] - x[1]) + x[0] * x[1] * np.exp(-x[0] - x[1])
    return np.array([df_dx1, df_dx2])

# Начальная точка
x0 = np.array([0, 1])

# Метод Флетчера-Ривса (сопряженных градиентов)
result = minimize(objective_function, x0, method='CG', jac=gradient)

# Вывод графика функции
x1_vals = np.linspace(result.x[0] - 1, result.x[0] + 1, 100)
x2_vals = np.linspace(result.x[1] - 1, result.x[1] + 1, 100)
X1, X2 = np.meshgrid(x1_vals, x2_vals)
Z = -X1 * X2 * np.exp(-(X1 + X2))

plt.figure(figsize=(8, 6))
contour_plot = plt.contour(X1, X2, Z, levels=30, cmap='viridis')
plt.scatter(result.x[0], result.x[1], color='red', marker='x', label='точка минимума')
plt.title('                                                    График функции f(x)')
plt.xlabel('x1')
plt.ylabel('x2')
plt.legend()

# Добавление цветовой шкалы (colorbar)
plt.colorbar(contour_plot, label='Значения функции')

# Добавление текста в левый верхний угол
plt.figtext(0.05, 0.95, f'Минимальное значение функции: {result.fun:.4f}', color='black', fontsize=10, ha='left', va='top')
plt.figtext(0.05, 0.92, f'Минимум найден в точке: {result.x}', color= 'black', fontsize = 10, ha='left', va='top')
plt.show()

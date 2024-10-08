import numpy as np

def gauss_seidel(A, b, x0=None, tolerance=1e-10, max_iterations=1000):
    n = len(b)
    if x0 is None:
        x0 = np.zeros(n)
    
    x = x0.copy()
    
    for iteration in range(max_iterations):
        x_old = x.copy()
        
        for i in range(n):
            sum1 = np.dot(A[i, :i], x[:i])
            sum2 = np.dot(A[i, i+1:], x_old[i+1:])
            x[i] = (b[i] - sum1 - sum2) / A[i, i]
        
        # Проверка на сходимость
        if np.linalg.norm(x - x_old, ord=np.inf) < tolerance:
            return x, iteration + 1
    
    print("Максимальное количество итераций достигнуто.")
    return x, max_iterations

# Пример использования
if __name__ == "__main__":
    # Коэффициенты при x
    A = np.array([[10.05, 2.94, 2.53],
                  [5.41, 14.64, 4.41],
                  [3.88, 3.30, 8.34]], dtype=float)
    
    # Столбец свободных членов
    b = np.array([70.69, 115.38, 81.07], dtype=float)
    
    # Начальное приближение
    x0 = np.zeros(len(b))
    
    solution, iterations = gauss_seidel(A, b, x0)
    
    print("Решение:", solution)
    print("Количество итераций:", iterations)

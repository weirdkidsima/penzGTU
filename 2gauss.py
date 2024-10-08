import numpy as np

def gauss_elimination(A, b):
    n = len(b)
    
    for i in range(n):
        # Нормируем текущую строку
        max_row_index = np.argmax(np.abs(A[i:n, i])) + i
        A[[i, max_row_index]] = A[[max_row_index, i]]
        b[i], b[max_row_index] = b[max_row_index], b[i]
        
        for j in range(i + 1, n):
            factor = A[j][i] / A[i][i]
            A[j] = A[j] - factor * A[i]
            b[j] -= factor * b[i]

    
    x = np.zeros(n)
    for i in range(n - 1, -1, -1):
        x[i] = (b[i] - np.dot(A[i, i + 1:], x[i + 1:])) / A[i][i]

    return x


A = np.array([[9.15, 2.64, 2.23],
              [4.14, 10.83, 3.14],
              [5.63, 5.03, 13.56]], dtype=float)

b = np.array([67.17, 91.43, 125.40], dtype=float)

solution = gauss_elimination(A, b)
print("Решение системы:", solution)

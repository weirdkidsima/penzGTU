def create_relation_matrix(universe, relation):
    # Создаем матрицу размером n x n, где n - количество элементов в универсуме
    n = len(universe)
    matrix = [[0] * n for _ in range(n)]
    # Заполняем матрицу значениями 1, если пара (i, j) находится в отношении
    for i in range(n):
        for j in range(n):
            if (universe[i], universe[j]) in relation:
                matrix[i][j] = 1
    return matrix

def check_reflexivity(matrix):
    # Проверяем каждый элемент на диагонали матрицы на наличие единицы
    # Если хотя бы один элемент не равен 1, отношение не обладает свойством рефлексивности
    for i in range(len(matrix)):
        if matrix[i][i] != 1:
            return "Не рефлексивно"
    return "Рефлексивно"

def check_irreflexivity(matrix):
    # Проверяем каждый элемент на диагонали матрицы на отсутствие единицы
    # Если хотя бы один элемент равен 1, отношение не обладает свойством антирефлексивности
    for i in range(len(matrix)):
        if matrix[i][i] != 0:
            return "Не антирефлексивно"
    return "Антирефлексивно"

def check_symmetry(matrix):
    # Проверяем, равны ли соответствующие элементы относительно главной диагонали
    # Если хотя бы одна пара не равна, отношение не обладает свойством симметричности
    n = len(matrix)
    for i in range(n):
        for j in range(n):
            if matrix[i][j] != matrix[j][i]:
                return "Не симметрично"
    return "Симметрично"

def check_antisymmetry(matrix):
    # Проверяем, что если (i, j) и (j, i) в отношении, то i == j
    # Если найдется такая пара (i, j) != (j, i) и i != j, отношение не обладает свойством антисимметричности
    n = len(matrix)
    for i in range(n):
        for j in range(n):
            if i != j and matrix[i][j] == 1 and matrix[j][i] == 1:
                return "Не антисимметрично"
    return "Антисимметрично"

def check_transitivity(matrix):
    # Проверяем транзитивность отношения:
    # Если (i, j) и (j, k) в отношении, то (i, k) тоже должно быть в отношении
    for i in range(len(matrix)):
        for j in range(len(matrix)):
            if matrix[i][j] == 1:
                for k in range(len(matrix)):
                    if matrix[j][k] == 1 and matrix[i][k] != 1:
                        return "Не транзитивно"
    return "Транзитивно"

def check_antitransitivity(matrix):
    # Проверяем антитранзитивность отношения:
    # Если (i, j) и (j, k) в отношении, то (i, k) не должно быть в отношении
    for i in range(len(matrix)):
        for j in range(len(matrix)):
            if matrix[i][j] == 1:
                for k in range(len(matrix)):
                    if matrix[j][k] == 1 and matrix[i][k] == 1:
                        return "Не антитранзитивно"
    return "Антитранзитивно"

universe = [1, 2, 3, 4, 5]
relation = {(1, 1), (1, 2), (2, 2), (2, 1), (1, 3), (1, 5), (2, 3), (3, 1), (3, 2), (3, 3), (4, 4), (5, 1), (5, 5), (5, 3), (5, 4)}

# Создаем матрицу отношения
matrix = create_relation_matrix(universe, relation)
print("Матрица бинарного отношения:")
for row in matrix:
    print(*row)

print("\nСвойства:")
print("Рефлексивность:", check_reflexivity(matrix))
print("Антирефлексивность:", check_irreflexivity(matrix))
print("Симметричность:", check_symmetry(matrix))
print("Антисимметричность:", check_antisymmetry(matrix))
print("Транзитивность:", check_transitivity(matrix))
print("Антитранзитивность:", check_antitransitivity(matrix))

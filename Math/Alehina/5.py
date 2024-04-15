# Функция для создания матрицы бинарного отношения
def create_relation_matrix(relation, universe):
    matrix = []
    for i in range(1, len(universe) + 1):
        row = []
        for j in range(1, len(universe) + 1):
            if (i, j) in relation:
                row.append(1)
            else:
                row.append(0)
        matrix.append(row)
    return matrix

# Функция для проверки отношения на эквивалентность
def check_equivalence(relation_matrix):
    for i in range(len(relation_matrix)):
        if relation_matrix[i][i] != 1:  # Отношение не рефлексивно
            return False
        for j in range(len(relation_matrix)):
            if relation_matrix[i][j] != relation_matrix[j][i]:  # Отношение не симметрично
                return False
            for k in range(len(relation_matrix)):
                if relation_matrix[i][j] == 1 and relation_matrix[j][k] == 1 and relation_matrix[i][k] != 1:  # Отношение не транзитивно
                    return False
    return True

# Функция для нахождения классов эквивалентности
def find_equivalence_classes(relation_matrix):
    classes = []
    visited = set()
    for i in range(len(relation_matrix)):
        if i not in visited:
            equivalence_class = set()
            for j in range(len(relation_matrix)):
                if relation_matrix[i][j] == 1:
                    equivalence_class.add(j + 1)
                    visited.add(j)
            classes.append(equivalence_class)
    return classes

# Универсум и бинарное отношение
U = {1, 2, 3, 4, 5, 6}
R = {(1, 1), (1, 2), (2, 2), (2, 1), (3, 3), (4, 4), (5, 5), (4, 3), (3, 4)}

# Создание матрицы бинарного отношения
relation_matrix = create_relation_matrix(R, U)

# Проверка отношения на эквивалентность
is_equivalent = check_equivalence(relation_matrix)

if is_equivalent:
    print("Отношение является эквивалентным.")
else:
    print("Отношение не является эквивалентным.")

# Нахождение классов эквивалентности
equivalence_classes = find_equivalence_classes(relation_matrix)

print("Классы эквивалентности:")
for equivalence_class in equivalence_classes:
    print("{",*equivalence_class,"}")

# Вывод матрицы бинарного отношения
print("Матрица бинарного отношения:")
for row in relation_matrix:
    print(*row)

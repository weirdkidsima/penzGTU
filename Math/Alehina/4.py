import numpy as np

def create_relation_matrix(universe, relation):
    n = len(universe)
    matrix = np.zeros((n, n), dtype=bool)
    for i in range(n):
        for j in range(n):
            if (universe[i], universe[j]) in relation:
                matrix[i][j] = 1
    return matrix

def one(matrix1,matrix2):
    return np.logical_and(matrix1,matrix2).astype(int)

def two(matrix1, matrix2):
    return np.logical_and(matrix1, np.logical_not(matrix2)).astype(int)

def three(matrix1, matrix2, matrix3):
    return np.logical_xor((np.logical_and(matrix1,matrix2)),matrix3).astype(int)

def four(matrix1):
    return np.transpose(matrix1).astype(int)

def five(matrix1, matrix2):
    return np.dot(matrix1, matrix2).astype(int)

universe = [1, 2, 3, 4]
tao_bin = {(1,2),(2,3),(1,3),(4,2)}
ro_bin = {(1,2),(1,4),(3,4),(4,1)}
delta = np.array([
    [False,True,False,True],
    [True,False,True,True],
    [False,False,False,False],
    [True,True,True,True]
])


tao = create_relation_matrix(universe, tao_bin)
ro = create_relation_matrix(universe, ro_bin)

print("результат первого набора операций:")
print(one(delta, tao),"\n")
print("результат второго набора операций:")
print(two(delta, tao),"\n")
print("результат третьего набора операций:")
print(three(delta, tao, ro),"\n")
print("результат четвертого набора операций:\n")
print(four(tao),"\n")
print("результат пятого набора операций:")
print(five(tao, ro))

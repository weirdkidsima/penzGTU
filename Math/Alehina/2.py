from itertools import product # импорт библиотеки для работы с итераторами

A = {1, 2, 3, 4, 5}
B = {3, 4, 5, 6, 9, 10, 11, 12}
C= {5, 6, 7, 8, 9, 10, 13, 14}

# поиск булеана
def subsets(P):
    sets = []
    len_P = len(P)
    for i in range( 1 << len_P ):
        subset = [P[ bit] for bit in range(len_P) if i & (1 << bit)]
        sets.append(subset)
    return sets
print('булеан множества А:')
for j in subsets(list(A)):
    print(j)
    
# определение множества D1
D1 = A.symmetric_difference(B)
print ("полученное множество D1: ", D1)

# определение множества D2
D2 = C.difference(A.union(B))

print("полученное множество D2: ", D2)

# декартово  произведенме D2 на D1
print("декартово произведение D2 на D1: ", *product(D2, D1))
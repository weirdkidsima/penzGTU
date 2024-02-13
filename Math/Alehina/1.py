# множество А и В
A = {1, 4, 5, 7, 8}
B = {3, 5, 6, 10}

# универсальное множество U
U = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}

# объединение множеств А и В
union = A.union(B)
print("Объединение А и В:", union)

# пересечение множеств
intersection = A.intersection(B)
print("пересечение множеств А и В:", intersection)

#  разность множеств А и В
difference_ab = A.difference(B)
print("разность А и В:", difference_ab)

# разность множеств В и А
difference_ba = B.difference(A)
print("разность В и А:", difference_ba)

# дополнение A
complement_a = U.difference(A)
print("дополнение A:", complement_a)

# дополнение B
complement_b = U.difference(B)
print("дополнение B:", complement_b)

# симметрическая разность множеств А и В
symetric_difference = A.symmetric_difference(B)
print("симметрическая разность А и В:", symetric_difference)

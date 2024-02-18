# множество А и В
A = {1, 4, 5, 7, 8}
B = {3, 5, 6, 10}

# универсальное множество U
U = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}

# объединение множеств А и В
union = A.union(B)
print("Объединение А и В:", union)
print("Битовая шкала объединения А и В:", bin(int(''.join(map(str, [i in union for i in U]))[::-1], 2)))

# пересечение множеств
intersection = A.intersection(B)
print("Пересечение множеств А и В:", intersection)
print("Битовая шкала пересечения А и В:", bin(int(''.join(map(str, [i in intersection for i in U]))[::-1], 2)))

# разность множеств А и В
difference_ab = A.difference(B)
print("Разность А и В:", difference_ab)
print("Битовая шкала разности А и В:", bin(int(''.join(map(str, [i in difference_ab for i in U]))[::-1], 2)))

# разность множеств В и А
difference_ba = B.difference(A)
print("Разность В и А:", difference_ba)
print("Битовая шкала разности В и А:", bin(int(''.join(map(str, [i in difference_ba for i in U]))[::-1], 2)))

# дополнение A
complement_a = U.difference(A)
print("Дополнение A:", complement_a)
print("Битовая шкала дополнения A:", bin(int(''.join(map(str, [i in complement_a for i in U]))[::-1], 2)))

# дополнение B
complement_b = U.difference(B)
print("Дополнение B:", complement_b)
print("Битовая шкала дополнения B:", bin(int(''.join(map(str, [i in complement_b for i in U]))[::-1], 2)))

# симметрическая разность множеств А и В
symetric_difference = A.symmetric_difference(B)
print("Симметрическая разность А и В:", symetric_difference)
print("Битовая шкала симметрической разности А и В:", bin(int(''.join(map(str, [i in symetric_difference for i in U]))[::-1], 2)))

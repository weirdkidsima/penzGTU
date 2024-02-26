# множество А и В
A = {1, 4, 5, 7, 8}
B = {3, 5, 6, 10}

# универсальное множество U
U = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}

# Функция для вывода битовой шкалы множества
def print_bit_scale(s, name):
    bit_scale = []
    for i in range(1, max(U) + 1):
        if i in s:
            bit_scale.append('1')
        else:
            bit_scale.append('0')
    print(f"Битовая шкала для множества {name}: {''.join(bit_scale)}")

# Вывод битовых шкал для начальных множеств
print_bit_scale(A, "A")
print_bit_scale(B, "B")
print_bit_scale(U, "U")

# объединение множеств А и В
union = A.union(B)
print("Объединение А и В:", union)
print_bit_scale(union, "A ∪ B")

# пересечение множеств
intersection = A.intersection(B)
print("Пересечение множеств А и В:", intersection)
print_bit_scale(intersection, "A ∩ B")

# разность множеств А и В
difference_ab = A.difference(B)
print("Разность А и В:", difference_ab)
print_bit_scale(difference_ab, "A \ B")

# разность множеств В и А
difference_ba = B.difference(A)
print("Разность В и А:", difference_ba)
print_bit_scale(difference_ba, "B \ A")

# дополнение A
complement_a = U.difference(A)
print("Дополнение A:", complement_a)
print_bit_scale(complement_a, "A'")

# дополнение B
complement_b = U.difference(B)
print("Дополнение B:", complement_b)
print_bit_scale(complement_b, "B'")

# симметрическая разность множеств А и В
symmetric_difference = A.symmetric_difference(B)
print("Симметрическая разность А и В:", symmetric_difference)
print_bit_scale(symmetric_difference, "A Δ B")

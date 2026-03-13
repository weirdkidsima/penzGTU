def transform_pair(pair):
    """
    Преобразует пару битов по правилам:
    00 -> 00
    01 -> 01
    10 -> 11
    11 -> 10
    """
    if pair == '00':
        return '00'
    elif pair == '01':
        return '01'
    elif pair == '10':
        return '11'
    elif pair == '11':
        return '10'
    else:
        return pair  # на случай ошибки

def process_numbers(numbers, array_name, binary_9):
    """
    Обрабатывает массив чисел и выводит результаты
    """
    print(f"\n{'='*60}")
    print(f"ОБРАБОТКА МАССИВА {array_name}: {numbers}")
    print(f"{'='*60}")
    
    results = []
    
    for num in numbers:
        # Переводим текущее число в двоичную систему (4 бита)
        binary_num = format(num, '04b')
        print(f"\nЧисло {num} в двоичной системе: {binary_num}")
        
        # Складываем с binary_9 по модулю 2 (XOR)
        xor_result = ''
        for i in range(4):
            xor_result += str(int(binary_9[i]) ^ int(binary_num[i]))
        print(f"Результат XOR с {binary_9}: {xor_result}")
        
        # Делим на 2 части по 2 бита
        left_pair = xor_result[:2]  # первые 2 бита
        right_pair = xor_result[2:]  # вторые 2 бита
        print(f"Разбиение на пары: {left_pair} и {right_pair}")
        
        # Преобразуем пары по правилам
        transformed_left = transform_pair(left_pair)
        transformed_right = transform_pair(right_pair)
        print(f"После преобразования: {transformed_left} и {transformed_right}")
        
        # Объединяем результат
        transformed_binary = transformed_left + transformed_right
        print(f"Объединенный результат: {transformed_binary}")
        
        # Переводим в десятичную систему
        decimal_result = int(transformed_binary, 2)
        print(f"В десятичной системе: {decimal_result}")
        
        results.append(decimal_result)
    
    return results

def main():
    # Переводим число 9 в двоичную систему (4 бита)
    number_9 = 9
    binary_9 = format(number_9, '04b')
    print(f"Число 9 в двоичной системе (4 бита): {binary_9}")
    print(f"{'='*60}\n")
    
    # Массивы для обработки
    arrays = [
        ("№1", [10, 8, 13, 12, 6, 4]),
        ("№2", [7, 14, 15, 13, 15, 6]),
        ("№3", [13, 12, 6, 4, 10, 11])
    ]
    
    all_results = []
    
    # Обрабатываем каждый массив
    for array_name, numbers in arrays:
        results = process_numbers(numbers, array_name, binary_9)
        all_results.append((array_name, numbers, results))
    
    # Выводим итоговые результаты для всех массивов
    print(f"\n{'='*60}")
    print("ИТОГОВЫЕ РЕЗУЛЬТАТЫ ПО ВСЕМ МАССИВАМ")
    print(f"{'='*60}")
    
    for array_name, original_numbers, results in all_results:
        print(f"\nМассив {array_name}:")
        print("-" * 40)
        for i, num in enumerate(original_numbers):
            print(f"{num} -> {results[i]}")
    
    # Дополнительно выводим в виде строк для наглядности
    print(f"\n{'='*60}")
    print("РЕЗУЛЬТАТЫ В ВИДЕ СТРОК")
    print(f"{'='*60}")
    
    for array_name, original_numbers, results in all_results:
        result_string = "[" + ", ".join(map(str, results)) + "]"
        print(f"Массив {array_name}: {result_string}")

if __name__ == "__main__":
    main()
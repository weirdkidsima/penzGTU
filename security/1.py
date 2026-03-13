# Исходные данные
open_alphabet = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩ_ЬЫЭЮЯ"
encrypted_lines = [
    "УФАХФКАЧШЖЦФЧШБАНЖЬФШЛС",
    "ФШКФЬУЩШБАФШАЦЖШУВЬАКЛС",
    "ОАХФРФПАЧЛЗЛАЩЧШЦФОШБ",
    "ШЩШАЧФЧЛКОАЗЛЧХФРФОШБ",
    "ЧШЖСОАЙЦФНУФЙФАЫЖЦЕ"
]

# Тезаурус
thesaurus_lines = [
    "в_тридевятом_царстве".upper(),
    "в_тридесятом_государстве".upper(),
    "жил_был_славный_царь_дадон".upper(),
    "смолоду_был_грозен_он".upper(),
    "и_соседям_то_и_дело".upper(),
    "наносил_обиды_смело".upper(),
    "но_под_старость_захотел".upper(),
    "отдохнуть_от_ратных_дел".upper(),
    "и_покой_себе_устроить".upper(),
    "тут_соседи_беспокоить".upper(),
    "стали_грозного_царя".upper(),
    "страшный_вред_ему_творя".upper(),
    "чтоб_концы_своих_владений".upper(),
    "охранять_от_нападений".upper(),
    "должен_был_он_содержать".upper(),
    "многочисленную_рать".upper(),
    "воеводы_не_дремали".upper(),
    "но_никак_не_успевали".upper(),
    "ждут_бывало_с_юга_глядь".upper(),
    "ан_с_востока_лезет_рать".upper()
]


def find_matching_positions(enc_lines):
    """Находит пары позиций с одинаковыми символами в разных строках"""
    matches = []
    for i in range(len(enc_lines)):
        for j in range(i+1, len(enc_lines)):
            # Берем минимальную длину для сравнения
            min_len = min(len(enc_lines[i]), len(enc_lines[j]))
            for pos in range(min_len):
                if enc_lines[i][pos] == enc_lines[j][pos]:
                    matches.append((i, j, pos, enc_lines[i][pos]))
    return matches

# нахождения всех совпадений
matches = find_matching_positions(encrypted_lines)
print("Найденные совпадения в зашифрованном тексте:")
for i, j, pos, ch in matches[:10]:  # Покажем первые 10
    print(f"Строка {i+1} и {j+1}, позиция {pos}: '{ch}'")
print(f"Всего найдено {len(matches)} совпадений")



def find_thesaurus_matches(thesaurus, enc_match):
    """Ищет в тезаурусе строки с одинаковыми символами на заданных позициях"""
    enc_i, enc_j, pos, enc_char = enc_match
    
    results = []
    for t_i in range(len(thesaurus)):
        for t_j in range(t_i+1, len(thesaurus)):
            # Проверяем, достаточно ли длинные строки
            if pos < len(thesaurus[t_i]) and pos < len(thesaurus[t_j]):
                if thesaurus[t_i][pos] == thesaurus[t_j][pos]:
                    # Нашли совпадение в тезаурусе
                    results.append((t_i, t_j, pos, thesaurus[t_i][pos]))
    return results

# Возьмем несколько первых совпадений из зашифрованного текста
print("\n" + "="*50)
print("анализ совпадений")
print("="*50)

candidates = []  # Здесь будем хранить возможные сдвиги

for match_idx, enc_match in enumerate(matches[:10]):  # Анализируем первые 10 совпадений
    enc_i, enc_j, pos, enc_char = enc_match
    print(f"\nСовпадение {match_idx+1}: строки {enc_i+1} и {enc_j+1}, позиция {pos}, символ '{enc_char}'")
    
    # Ищем такие же позиции в тезаурусе
    thesaurus_matches = find_thesaurus_matches(thesaurus_lines, enc_match)
    
    if thesaurus_matches:
        print(f"  Найдено {len(thesaurus_matches)} совпадений в тезаурусе:")
        for t_match in thesaurus_matches:
            t_i, t_j, t_pos, t_char = t_match
            print(f"    Строки {t_i+1} и {t_j+1}, позиция {t_pos}: '{t_char}'")
            
            # Вычисляем возможный сдвиг
            try:
                idx_enc = open_alphabet.index(enc_char)
                idx_open = open_alphabet.index(t_char)
                shift = (idx_enc - idx_open) % len(open_alphabet)
                print(f"      → Возможный сдвиг: {shift}")
                candidates.append((shift, enc_match, t_match))
            except ValueError as e:
                print(f"      → Ошибка: символ '{t_char}' не найден в алфавите")
    else:
        print("  Совпадений в тезаурусе не найдено")

print("\n" + "="*50)
print("поиск наиболее частого сдвига")
print("="*50)

from collections import Counter
shift_counter = Counter([c[0] for c in candidates])

if shift_counter:
    most_common_shift = shift_counter.most_common(1)[0]
    print(f"Наиболее частый сдвиг: {most_common_shift[0]} (встречается {most_common_shift[1]} раз)")
    
    # Покажем все найденные сдвиги
    print("\nВсе найденные сдвиги:")
    for shift, count in shift_counter.most_common():
        print(f"  Сдвиг {shift}: {count} раз")
    
    # Берем самый частый сдвиг
    shift = most_common_shift[0]
else:
    print("Не удалось найти сдвиги")
    shift = 0


print("\n" + "="*50)
print("расшифровка")
print("="*50)

decrypt_map = {}
for i, ch in enumerate(open_alphabet):
    # Чтобы получить открытый текст из зашифрованного, нужно минусовать сдвиг
    # encrypted = open_alphabet[(i + shift) % N]
    # open_char = open_alphabet[(enc_index - shift) % N]
    decrypted_ch = open_alphabet[(i - shift) % len(open_alphabet)]
    decrypt_map[ch] = decrypted_ch

# Выводим алфавит соответствия
print("Алфавит соответствия (зашифрованный -> открытый):")
for ch in open_alphabet:
    print(f"{ch} -> {decrypt_map[ch]}")

# Расшифровываем все строки
print("\nРасшифрованные строки:")
for i, line in enumerate(encrypted_lines):
    decrypted = ''.join(decrypt_map[ch] for ch in line)
    print(f"Строка {i+1}: {decrypted}")
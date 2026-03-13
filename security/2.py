from collections import Counter
import re

class RussianTextDecryptor:
    def __init__(self, alphabet_frequencies):
        # Сохраняем частоты символов русского алфавита
        self.alphabet_frequencies = alphabet_frequencies
        self.alphabet = list(alphabet_frequencies.keys())
        self.cipher_text = ""
        self.target_phrase = ""
        
    def load_text(self, cipher_text):
        # Загружаем зашифрованный текст
        self.cipher_text = cipher_text
        
    def set_target_phrase(self, phrase):
        # Устанавливаем фразу, которую нужно расшифровать
        self.target_phrase = phrase
        
    def calculate_frequencies(self, text):
        # Подсчитываем частоту каждого символа в тексте
        # Оставляем только буквы и нижнее подчеркивание
        text = re.sub(r'[^А-Яа-я_]', '', text.upper())
        symbol_counts = Counter(text)  # Считаем количество каждого символа
        total_symbols = len(text)
        # Вычисляем вероятность каждого символа
        frequencies = {symbol: count / total_symbols for symbol, count in symbol_counts.items()}
        return frequencies, symbol_counts
    
    def find_mapping_by_frequency(self):
        # Находим соответствие символов на основе частотного анализа
        cipher_freqs, _ = self.calculate_frequencies(self.cipher_text)
        
        # Сортируем символы шифротекста по частоте (от самых частых к редким)
        sorted_cipher = sorted(cipher_freqs.items(), key=lambda x: x[1], reverse=True)
        # Сортируем символы алфавита по известным вероятностям
        sorted_alphabet = sorted(self.alphabet_frequencies.items(), key=lambda x: x[1], reverse=True)
        
        # Создаем соответствие: самый частый символ шифра -> самый частый символ алфавита
        mapping = {}
        
        for (cipher_char, _), (plain_char, _) in zip(sorted_cipher, sorted_alphabet):
            mapping[cipher_char] = plain_char  # для дешифровки
        
        return mapping, cipher_freqs
    
    def get_decrypt_code(self, mapping):
        # Формируем код для дешифровки (сортируем для удобства)
        return dict(sorted(mapping.items()))
    
    def decrypt_with_mapping(self, mapping, text=None):
        # Дешифруем текст, заменяя каждый символ по соответствию
        if text is None:
            text = self.target_phrase
        text = text.upper()
        decrypted = []
        for char in text:
            if char in mapping:
                decrypted.append(mapping[char])  # заменяем символ
            else:
                decrypted.append(char)  # оставляем как есть, если нет в словаре
        return ''.join(decrypted)
    
    def encrypt_text(self, mapping, text):
        # Шифруем текст, используя обратное соответствие
        # Сначала создаем обратное соответствие (открытый -> зашифрованный)
        reverse_mapping = {v: k for k, v in mapping.items()}
        
        text = text.upper()
        encrypted = []
        for char in text:
            if char in reverse_mapping:
                encrypted.append(reverse_mapping[char])
            else:
                encrypted.append(char)
        return ''.join(encrypted)
    
    def decrypt(self):
        # Основной метод дешифровки
        mapping, cipher_freqs = self.find_mapping_by_frequency()
        decrypted_phrase = self.decrypt_with_mapping(mapping)
        decrypt_code = self.get_decrypt_code(mapping)
        
        return {
            'mapping': mapping,
            'decrypt_code': decrypt_code,
            'cipher_frequencies': cipher_freqs,
            'decrypted_phrase': decrypted_phrase
        }


def main():
    # Таблица вероятностей символов русского алфавита по варианту
    alphabet_frequencies = {
        'А': 0.07193, 'Б': 0.01974, 'В': 0.0364, 'Г': 0.01184, 'Д': 0.03158,
        'Е': 0.05658, 'Ж': 0.00877, 'З': 0.0136, 'И': 0.0614, 'Й': 0.01228,
        'К': 0.03202, 'Л': 0.05, 'М': 0.03026, 'Н': 0.04693, 'О': 0.07675,
        'П': 0.01667, 'Р': 0.04079, 'С': 0.04386, 'Т': 0.0557, 'У': 0.03421,
        'Ф': 0.00219, 'Х': 0.00526, 'Ц': 0.00351, 'Ч': 0.01272, 'Ш': 0.0114,
        'Щ': 0.00219, '_': 0.14167, 'Ь': 0.02061, 'Ы': 0.02588, 'Э': 0.00044,
        'Ю': 0.00482, 'Я': 0.01798
    }
    
    # Создаем объект дешифровщика
    decryptor = RussianTextDecryptor(alphabet_frequencies)
    
    # Зашифрованный текст из задания
    cipher_text = """ОЭСЖДЯШЩ_ЖОРЫЯПЖУМДСОСЧФЧ_ЭЗ
ЫСНЛЮМЖЩСЖШ_ЭЦОМЖЧЗЖУМЖЩМШФ
АЫМЩВЯУИЖРОФЩЯЧФЭЗЖЦМЦЖЮЯГФ
Щ_ЭФЧФЭЗЖУЩМШСЩМЖЦМЦЖЮСЩФ
ГЮ_ЖУЩМГФЮЖЫЯЭЭЦФХЖН_ХЖЯРМЧИХ
УМЯЮЫ_ЖН_ХЖУМЮСЛЮЗЖЩ_ОИХ
Ш_ПЯГССЖЧФБ_СЖЬЧСШЛ
Ш_ЭЦОМЖЭЬМЧСЩЩМЛЖЬ_ТМЫ_Ш
ЩСЖЮ_ЖГЮ_ЖЩИЩСДЩССЖЬЧСШЛ
Р_ЭМРЩ_ЖНИЧ_ЖН_ЛЖТРМЧФ
СЭЮЗЖЫМУПЯЧЛЮЗЭЛЖПРСЖЩМЖО_ЧС
ФЖРЯШМЧЖЯП_ЕЯЖЛЖРЫЯПМ
ГЮ_ЖЮ_ЧЦЯЖОЖЙЮМЦ_ХЖНСУРСЧЦС
ФЖЭЧИДЩ_ЖНИЧ_ЖР_ЖЫМЭЭОСЮМ
ЭОСЫЦЩЯЧЖУМЖЭЮЫ_СШЖЭЮЫ_Х
ЯШЫСШЮСЖТЖЬ_РЖШ_ЭЦО_Х
ФЖОЭСЖЩМЖЩМДЖЫСРЯЮ
ОЖРИШЯЖ_П_ЩЗЖНЧСЭЮСЧ
ЩМДЖЫЯЦ_ЬМДЩИХЖН_Х
ФЖР_ЖЦ_ЩВМЖЭЮ_ЛЮЗ
Н_ПМЮИЫФЖЩСЖОИ
АЫМЩВЯУЯЖ_ЮРМЩМ
Н_ПМЮИЫФЖЩСЖОИ
О_ЫГМЧФЖЭЮМЫФЦФ
Ь_ЭЮЫ_ФЧФЖЫСРЯЮ
Ь_ЭЮ_ХЖЦМЖНЫМЮЖШЯЭЗК
ШИЖТРМЧФЖЮЫСЮФХЖРСЩЗ
ЦМЦЖЧФЦ_ОМЧЖАЫМЩВЯУ
Ь_ЧЦ_ОЩФЦЖЩМДЖЫ_ТРСЩЖНИЧЖБОМЮ_Ш
ЦМЦЖЩМДФЖНЫМЮЗЛЖЯШФЫМЧФ
ЯЧМЩИЖЭЖЬСЭЮЫИШФЖУЩМГЦМШФ
УОЯГМЧЖНЯЧМЮЖЦМЫЮСГЗЖОФУТМЧМ
УСШЧЛЖЮЫЛЭЧМЭЗЖЦМЦЖЩМДФЖПЫЯРФ
Щ_ЖУМЮЫСЕМЧФЖНМЫМНМЩИ
ЬЧ_БМЛЖФШЖР_ЭЮМЧМЭЗЖР_ЧЛ
ОСРЗЖНИЧФЖТЖЭБОМЮЦФЖН_СОИС
ЬЧ_БМЛЖФШЖР_ЭЮМЧМЭЗЖР_ЧЛ
ГЮ_ЖТЖШИЖЩМЖУФШЩФСЖЦОМЫЮФЫИ
ЯЖЩМДФБЖЯДЦФЖЩМЖШМЦЯДЦС
ГЮ_ЖЮЯЮЖБФЮЫФЮЗЖЬ_ТМЧЯХЖЦЖН_К
Ь_ОЭКРЯЖЭЮМЧФЖЭЧИДЩИЖЫСГФ
Щ_ЖЮФБЖНИЧЖЩМДЖНФОМЦЖ_ЮЦЫИЮИХ
ЭЧЯПМЖВМЫКЖ_ЮСВЖЭ_ЧРМЮМШ
ФЖЯШСЫСЮЗЖШИЖ_НСЕМЧФ
РЫМПЯЩИЖЭЖЦ_ЩЭЦФШФЖБО_ЭЮМШФ
ЫЯЦМЖН_ХВ_ОЖЦ_Ч_ЮЗЖЯЭЮМЧМ
ЭШСДМЧФЭЗЖОЖЦЯГЯЖЦ_ЩФЖЧКРФ
ФЖ_ЮЭЮЯЬФЧФЖНЯЭЯЫШМЩИ
ЩСШЩ_ПФСЖОСЫЩЯЧФЭЗЖЭЖЬ_ЧЛ
РМЖП_О_ЫЛЮЖСЕСЖЦМЦФС
ЩСШЩ_ПФСЖОСЫЩЯЧФЭЗЖЭЖЬ_ЧЛ
ЩСЖЭШСКЮЖГЮ_ЖЧФЖЦ_ШМЩРФЫИ
ГЯЮЗЖЯЮЫ_Ж_ЭОСЮФЧ_ЖЬЯДЦФ
ЯТЖШИЖЬ_ХРСШЖЧ_ШФЮЗЖЭЮСЩ_К
Ь_ЫМЖР_НЫМЮЗЭЛЖР_ЖЦМЫЮСГФ
ЦЮ_ЖЦФОСЫЖГФЭЮФЧЖОСЭЗЖФУНФЮИХ
РМЖТМЧЗЖСП_ЖЭЫМТСЩЖНЯЧМЮ_Ш
ФЖЦЧЛЮОЯЖОСЫЩ_ЭЮФЖЭРСЫТМЧФ
ОЭСЖЬЫ_ШСЧЗЦЩЯЧФЖЬСЫСРЖЩМШФ
ФЖЛРЫМШЖЬЫ_ЧСЮМЮЗЖШСДМЧМ
ФЖУМЧЬИЖЮИЭЛГФЖ_ЫЯРФХ
Ю_ПРМЖЭГФЮМЮЗЖШИЖЭЮМЧФЖЫМЩИ
Ц_ПРМЖНЖЩМЖЮ_ЖЩСЖН_ТЗЛЖО_ЧЛ
ЩСРМЫ_ШЖЬ_ШЩФЮЖОЭЛЖЫ_ЭЭФЛ
ЩСЖНЯРЗЖЩМЖЮ_ЖП_ЭЬ_РЩЛЖО_ЧЛ
ГЯТФСЖФУ_ЫОМЮЗЖШЯЩРФЫИ
ФЖЧСЭМЖЭФЩФСЖОСЫБЯДЦФ
ЯТЖЬ_ЭЮ_ФШЖШИЖП_Ч_О_К
ФЖО_ЮЖЩМЖЬ_ЧСЖПЫ_УЩ_ХЖЭСГФ
ЦЮ_ЖДЮИЦЖЮ_ГФЧЖО_ЫГМЖЭСЫРФЮ_
_ЩЖЭЬФЮЖОЖУСШЧСЖЭИЫ_Х
ШИЖОЖН_Ы_РФЩЭЦФХЖН_Х
ОЭСЖЬ_НИОМЧФЖЮЯЮ
П_ЫМЖЦЫ_ОМОИБЖЮСЧ
ЭЧФЧФЭЗЖОЖЬЫ_ЮЛТЩИХЖО_Х
Ю_ОМЫФЕСХЖЭГФЮМЮЗ
ЩСЖ_ЮРМЧФЖНЖШ_ЭЦОИ
ЬЫ_ЖРСЩЗЖН_Ы_РФЩМ
ЩСЖ_ЮРМЧФЖНЖШ_ЭЦОИ
_ЖЫЯЭЭЦФСЖДЮИЦФ
АЫМЩВЯУИЖЮЯЮЖЦМЦЖЮЯЮ
УМЖЫ_РФЩЯЖЭО_К
Щ_ГЩМЛЖЬМЧМЖЮСЩЗ
ЦЯЭМЛЖРЧФЩЩИХЖЯЭ
ФЖШ_ЧОФЧЖ_ЩЖЭОСЫЦЩЯОЖ_ГМШФ
ЩЯЖТЖНИЧЖРСЩСЦЖЭЦО_УЗЖРИШЖЧСЮЯГФХ
ОМШЖЩСЖОФРМЮЗЖЮМЦФБЖЭЫМТСЩФХ
ФУОСРМЧЖОЫМПЖОЖЮ_ЮЖРСЩЗЖЩСШМЧ_
О_ЮЖЭШСЫЦЧ_ЭЗЖНИЧФЖОЭСЖП_Ю_ОИ
РМЖНИЧФЖЧКРФЖОЖЩМДСЖОЫСШЛ
ЭЦМТФЖЦМЖРЛРЛЖОСРЗЖЩСРМЫ_Ш
РМЖНИЧФЖЧКРФЖОЖЩМДСЖОЫСШЛ
ШИЖР_ЧП_ЖШ_ЧГМЖ_ЮЭЮЯЬМЧФ
ФЖО_ЮЖЩМДЧФЖН_ЧЗД_СЖЬ_ЧС
УМНФЧЖУМЫЛРЖЛЖОЖЬЯДЦЯЖЮЯП_
РОМЖРЩЛЖШИЖНИЧФЖОЖЬСЫСЭЮЫСЧЦС
ЬЫФЧСПЖОУРЫСШЩЯЮЗЖЛЖЯЖЧМАСЮМ
ФЖЮ_ЧЗЦ_ЖЩСН_ЖУМЭОСЮФЧ_ЭЗ"""
    
    decryptor.load_text(cipher_text)
    target_phrase = "РМЖП_О_ЫЛЮЖСЕСЖЦМЦФС"
    decryptor.set_target_phrase(target_phrase)
    
    # Запускаем дешифровку
    result = decryptor.decrypt()
    
    # Выводим результаты
    print("ДЕШИФРОВАННАЯ ФРАЗА:")
    print(result['decrypted_phrase'])
    print()
    
    print("КОД АЛФАВИТА (ДЛЯ ДЕШИФРОВКИ):")
    print("зашифрованный -> открытый")
    for cipher_char, plain_char in sorted(result['decrypt_code'].items()):
        print(f"{cipher_char} -> {plain_char}")
    print()
    
    # Шифруем имя_отчество
    name_to_encrypt = "МАКСИМ_АЛЕКСАНДРОВИЧ"
    encrypted_name = decryptor.encrypt_text(result['mapping'], name_to_encrypt)
    print(f"ЗАШИФРОВАННОЕ ИМЯ: {name_to_encrypt} -> {encrypted_name}")

if __name__ == "__main__":
    main()
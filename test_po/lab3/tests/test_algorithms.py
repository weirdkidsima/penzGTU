import pytest
from tkinter import Entry
from src.lab3 import linear_algorithm, branching_algorithm

def entry_vidget(value):
    entry = Entry()
    entry.insert(0, str(value))
    assert entry.get() == str(value)
    return entry

# Тестовые данные для линейного алгоритма
@pytest.mark.parametrize('x, y, z, expected', [
    (1, 1, 2, "Ошибка: x не должно равняться 2y / (1 + x^2 * y^2)"),
    (1, 1, 0, "Ошибка: z не может быть равным 0"),
    (0.5, -1, 1, "Ошибка: Для |x| < 1, y должно быть неотрицательным"),
    (1, 2, 3, "Результат линейного алгоритма: v = 5.9996"),
    ("a", "-", "-", "Ошибка: некорректные данные")
])

def test_linearAlgo(x, y, z, expected):
    entryX, entryY, entryZ = entry_vidget(x), entry_vidget(y), entry_vidget(z)
    result = linear_algorithm(entryX, entryY, entryZ)
    assert result == expected

# Тестовые данные для разветвляющегося алгоритма
@pytest.mark.parametrize("x, y, expected", [
    ("abc", "-", "Ошибка: некорректные данные"),
    (0, 0, "Результат разветвленного алгоритма: l = 0.0000"),
    (1, 0.5, "Результат разветвленного алгоритма: l = 1.2247"),
    (0.1, 5, "Результат разветвленного алгоритма: l = 2.2383")
])

def test_branchingAlgo(x, y, expected):
    entryX, entryY = entry_vidget(x), entry_vidget(y)
    result = branching_algorithm(entryX, entryY)
    assert result == expected
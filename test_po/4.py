import math

def linear_algorithm(x, y, z):
    """
    Вычисляет значение по линейному алгоритму

    :param x: float
    :param y: float
    :param z: float
    :return: float или сообщение об ошибке

    >>> linear_algorithm(1, 1, 2)  # doctest: +ELLIPSIS
    Traceback (most recent call last):
    ...
    ValueError: х не должно равняться 2y / (1 + x^2 * y^2)

    >>> linear_algorithm(1, 1, 0)  # doctest: +ELLIPSIS
    Traceback (most recent call last):
    ...
    ValueError: z не может быть равным 0

    >>> linear_algorithm(0.5, -1, 1)  # doctest: +ELLIPSIS
    Traceback (most recent call last):
    ...
    ValueError: Для |x| < 1, у должно быть неотрицательным

    >>> linear_algorithm(1, 2, 3)
    5.9996

    >>> linear_algorithm('a', '-', '-')  # doctest: +ELLIPSIS
    Traceback (most recent call last):
    ...
    ValueError: некорректные данные
    """
    try:
        x = float(x)
        y = float(y)
        z = float(z)
    except (ValueError, TypeError):
        raise ValueError("некорректные данные")

    if z == 0:
        raise ValueError("z не может быть равным 0")
    
    if abs(x) < 1 and y < 0:
        raise ValueError("Для |x| < 1, у должно быть неотрицательным")
    
    denominator = abs(x - (2 * y) / (1 + x**2 * y**2))
    if denominator == 0:
        raise ValueError("х не должно равняться 2y / (1 + x^2 * y^2)")

    numerator = 1 + math.sin(x + y)**2
    term1 = (numerator / denominator) * x**abs(y)
    term2 = math.cos(math.atan(1 / z))**2
    result = term1 + term2
    
    return round(result, 4)

def branching_algorithm(x, y):
    """
    Вычисляет значение по разветвляющемуся алгоритму

    :param x: float
    :param y: float
    :return: float или сообщение об ошибке

    >>> branching_algorithm('abc', '-')  # doctest: +ELLIPSIS
    Traceback (most recent call last):
    ...
    ValueError: некорректные данные. Попробуйте снова

    >>> branching_algorithm(0, 0)
    0.0

    >>> branching_algorithm(1, 0.5)
    1.2247

    >>> branching_algorithm(0.1, 5)
    2.2383
    """
    try:
        x = float(x)
        y = float(y)
    except (ValueError, TypeError):
        raise ValueError("некорректные данные. Попробуйте снова")

    # Выбранная функция
    f_x = x**2

    # Вычисление
    xy = x * y
    if 0.5 < xy < 5:
        l = math.e**(f_x - abs(y))
    elif 0.1 < xy <= 0.5:
        l = math.sqrt(abs(f_x) + y)
    else:
        l = 2 * (f_x**2)

    return round(l, 4)

if __name__ == "__main__":
    import doctest
    doctest.testmod(verbose=True)
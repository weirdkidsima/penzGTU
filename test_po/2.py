import math
import pytest

def compute_expression(x, y, z):
    if z == 0:
        raise ValueError("z не может быть нулевым")
    
    denominator = abs(x - (2 * y) / (1 + x**2 * y**2))
    if denominator == 0:
        raise ValueError("знаменатель не может быть нулевым")
    
    numerator = 1 + math.sin(x + y)**2
    term1 = (numerator / denominator) * x**abs(y)
    term2 = math.cos(math.atan(1 / z))**2
    return term1 + term2

def test_compute_expression_basic():
    # x = 1, y = 0.5, z = 1
    assert math.isclose(compute_expression(1, 0.5, 1), 10.475, rel_tol=1e-5)


def test_compute_expression_small_values():
    # x = 0.1, y = 0.1, z = 1
    assert math.isclose(compute_expression(0.1, 0.1, 1), 8.758451278768947, rel_tol=1e-5)

def test_compute_expression_special_cases():
    # x = π/2, y = π/2, z = 1
    assert math.isclose(compute_expression(math.pi/2, math.pi/2, 1), 2.3026834406350747, rel_tol=1e-5)

if __name__ == "__main__":
    pytest.main()
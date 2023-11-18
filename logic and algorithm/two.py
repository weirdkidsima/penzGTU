import numpy as np

def warshall_algorithm(adj_matrix):
    n = len(adj_matrix)
    reach_matrix = np.copy(adj_matrix)

    for k in range(n):
        for i in range(n):
            for j in range(n):
                reach_matrix[i][j] = reach_matrix[i][j] or (reach_matrix[i][k] and reach_matrix[k][j])

    return reach_matrix

def floyd_warshall_algorithm(adj_matrix):
    n = len(adj_matrix)
    dist_matrix = np.copy(adj_matrix)
    pred_matrix = np.full_like(adj_matrix, -1, dtype=int)

    for k in range(n):
        for i in range(n):
            for j in range(n):
                if dist_matrix[i][k] + dist_matrix[k][j] < dist_matrix[i][j]:
                    dist_matrix[i][j] = dist_matrix[i][k] + dist_matrix[k][j]
                    pred_matrix[i][j] = k

    return dist_matrix, pred_matrix

def find_shortest_paths(pred_matrix, start, end):
    path = []
    k = pred_matrix[start][end]
    while k != -1:
        path.append(k)
        k = pred_matrix[start][k]
    path.reverse()
    return path

def compute_eccentricities(dist_matrix):
    eccentricities = np.max(dist_matrix, axis=1)
    radius = np.min(eccentricities)
    diameter = np.max(eccentricities)
    center = np.where(eccentricities == radius)[0]

    return eccentricities, radius, diameter, center

# Пример использования
adjacency_matrix = np.array([[0, 2, np.inf, 1],
                             [np.inf, 0, 3, np.inf],
                             [np.inf, np.inf, 0, 4],
                             [np.inf, np.inf, np.inf, 0]])

# Применяем алгоритм Уоршалла
reachability_matrix = warshall_algorithm(adjacency_matrix)
print("Матрица достижимости:")
print(reachability_matrix)

# Применяем алгоритм Флойда-Уоршелла
distance_matrix, predecessor_matrix = floyd_warshall_algorithm(adjacency_matrix)
print("\nМатрица весов кратчайших путей:")
print(distance_matrix)

print("\nМатрица предшествования:")
print(predecessor_matrix)

# Найдем кратчайший путь из вершины 0 в вершину 2
start_vertex = 0
end_vertex = 2
shortest_path = find_shortest_paths(predecessor_matrix, start_vertex, end_vertex)
print(f"\nКратчайший путь из вершины {start_vertex} в вершину {end_vertex}: {shortest_path}")

# Вычислим эксцентриситеты, радиус, диаметр и центр
eccentricities, radius, diameter, center = compute_eccentricities(distance_matrix)
print(f"\nЭксцентриситеты вершин: {eccentricities}")
print(f"Радиус графа: {radius}")
print(f"Диаметр графа: {diameter}")
print(f"Центр графа: {center}")

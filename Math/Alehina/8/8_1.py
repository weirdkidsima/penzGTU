import sys

def dijkstra(graph, start, end):
    nodes = set(graph.keys())
    dist = {node: float('inf') for node in nodes}
    dist[start] = 0
    prev = {node: None for node in nodes}
    unvisited = set(nodes)
    
    while unvisited:
        current = min(unvisited, key=lambda node: dist[node])
        unvisited.remove(current)
        
        for neighbor, weight in graph[current].items():
            alt = dist[current] + weight
            if alt < dist[neighbor]:
                dist[neighbor] = alt
                prev[neighbor] = current
    
    path = []
    node = end
    while node is not None:
        path.insert(0, node)
        node = prev[node]
    
    return dist[end], path

# Заданная матрица весов графа G
graph = {
    'x1': {'x2': 5, 'x3': 10, 'x4': 13},
    'x2': {'x3': 8, 'x4': 9, 'x5': 13},
    'x3': {'x4': 5, 'x5': 3, 'x6': 6},
    'x4': {'x5': 8, 'x6': 10},
    'x5': {'x6': 9},
    'x6': {}
}

start_node = 'x1'
end_node = 'x6'

min_distance, path = dijkstra(graph, start_node, end_node)

print(f"Минимальное расстояние от вершины {start_node} до вершины {end_node}: {min_distance}")
print(f"Минимальный путь: {' -> '.join(path)}")

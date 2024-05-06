import networkx as nx
import matplotlib.pyplot as plt

# Заданная матрица весов графа G
G = nx.Graph()
edges = [
    ('x1', 'x2', {'weight': 10}),
    ('x2', 'x3', {'weight': 6}),
    ('x1', 'x4', {'weight': 5}),
    ('x2', 'x4', {'weight': 2}),
    ('x3', 'x4', {'weight': 3}),
    ('x2', 'x5', {'weight': 4}),
    ('x3', 'x5', {'weight': 1}),
    ('x4', 'x5', {'weight': 6}),
    ('x2', 'x6', {'weight': 8}),
    ('x3', 'x6', {'weight': 1}),
    ('x5', 'x6', {'weight': 5}),
    ('x1', 'x7', {'weight': 14}),
    ('x4', 'x7', {'weight': 3}),
    ('x7', 'x6', {'weight': 2}),
]

G.add_edges_from(edges)

# Нахождение кратчайшего остова методом Краскала и вычисление его веса
mst = nx.minimum_spanning_tree(G)
mst_weight = sum([edge[2]['weight'] for edge in mst.edges(data=True)])

print(f"Кратчайший остов графа в виде списка ребер: {mst.edges()}")
print(f"Вес кратчайшего остова: {mst_weight}")

# Визуализация графа
pos = nx.spring_layout(G)  # Позиции вершин графа
plt.figure()

# Рисуем все ребра графа
nx.draw_networkx_edges(G, pos, edgelist=G.edges(), alpha=0.5)

# Рисуем ребра кратчайшего остова толще и красным цветом
nx.draw_networkx_edges(mst, pos, edgelist=mst.edges(), edge_color='r', width=2)

# Рисуем вершины графа
nx.draw_networkx_nodes(G, pos, node_size=300)

# Добавляем метки вершин
nx.draw_networkx_labels(G, pos)

plt.title("Кратчайший остов")
plt.axis('off')
plt.show()

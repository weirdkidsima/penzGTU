import networkx as nx
import matplotlib.pyplot as plt

# Создание случайного графа с 5 вершинами и 7 рёбрами
graph1 = nx.gnm_random_graph(5, 7)
graph1 = nx.relabel_nodes(graph1, {node: node+1 for node in graph1.nodes()})

# Создание случайного графа с 7 вершинами и 10 рёбрами
graph2 = nx.gnm_random_graph(7, 10)
graph2 = nx.relabel_nodes(graph2, {node: node+1 for node in graph2.nodes()})

# Объединение графов
union_graph = nx.compose(graph1, graph2)

# Рисование графов
plt.figure(figsize=(15, 5))

plt.subplot(131)
plt.title("граф 1")
nx.draw(graph1, with_labels=True, node_color='skyblue', font_weight='bold')

plt.subplot(132)
plt.title("граф 2")
nx.draw(graph2, with_labels=True, node_color='lightcoral', font_weight='bold')

plt.subplot(133)
plt.title("мультиграф")
nx.draw(union_graph, with_labels=True, node_color='lightgreen', font_weight='bold')

plt.show()

# Мультиграф
multi_graph = nx.MultiGraph(union_graph)

# Диаметр и радиус мультиграфа
diameter = nx.diameter(multi_graph)
radius = nx.radius(multi_graph)

# Центр мультиграфа
center = nx.center(multi_graph)

# Связность мультиграфа
connectivity = nx.is_connected(multi_graph)

# Число вершин, рёбер и компонент мультиграфа
num_nodes = multi_graph.number_of_nodes()
num_edges = multi_graph.number_of_edges()
num_components = nx.number_connected_components(multi_graph)

print("Диаметр мультиграфа:", diameter)
print("Радиус мультиграфа:", radius)
print("Центр мультиграфа:", center)
print("Связность мультиграфа:", connectivity)
print("Число вершин мультиграфа:", num_nodes)
print("Число рёбер мультиграфа:", num_edges)
print("Число компонент мультиграфа:", num_components)

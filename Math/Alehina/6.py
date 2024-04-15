import networkx as nx
import matplotlib.pyplot as plt

# Соответствия f и g
f = {(2, 3), (3, 4), (5, 3), (8, 9)}
g = {(1, 5), (3, 9), (4, 6), (5, 4), (7, 8)}

# Создание графа
graph = nx.DiGraph()

# Добавление ребер в граф
for pair in f:
    graph.add_edge(pair[0], pair[1], label='f')

for pair in g:
    graph.add_edge(pair[0], pair[1], label='g')

# Рисование графа
pos = nx.spring_layout(graph)
nx.draw(graph, pos, with_labels=True, node_size=1000, node_color='skyblue', font_size=12, font_weight='bold')
edge_labels = nx.get_edge_attributes(graph, 'label')
nx.draw_networkx_edge_labels(graph, pos, edge_labels=edge_labels)

plt.title("Граф соответствия")
plt.show()

# Определение характеристик соответствия
is_total = len(f) == len(set([pair[0] for pair in f])) == len(set([pair[1] for pair in f]))
is_functional = len(f) == len(set([pair[0] for pair in f]))
is_surjective = set([pair[1] for pair in f]) == set([pair[1] for pair in g])
is_injective = len(set([pair[1] for pair in f])) == len(f)
is_bijective = is_functional and is_surjective and is_injective

# Вывод характеристик соответствия
print("Характеристики соответствия:")
print("Всюду определенное:", is_total)
print("Функциональное:", is_functional)
print("Сюръективное:", is_surjective)
print("Инъективное:", is_injective)
print("Биективное:", is_bijective)

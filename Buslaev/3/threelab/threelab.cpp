#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <utility>

using namespace std;

const int INF = numeric_limits<int>::max();

class Graph {
public:
    Graph(int vertices) : vertices(vertices) {
        adjacencyMatrix.resize(vertices, vector<int>(vertices, 0));
    }

    void addEdge(int from, int to, int weight) {
        adjacencyMatrix[from][to] = weight;
    }

    void printEdgeList() {
        cout << "Список рёбер графа:\n";
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                if (adjacencyMatrix[i][j] != 0) {
                    cout << "Ребро (" << i << " -> " << j << ") с весом " << adjacencyMatrix[i][j] << "\n";
                }
            }
        }
    }

    void dijkstraShortestPath(int startVertex);
    void bellmanFordShortestPath(int startVertex);

private:
    int vertices;
    vector<vector<int>> adjacencyMatrix;
};

void Graph::dijkstraShortestPath(int startVertex) {
    vector<int> distance(vertices, INF);
    vector<int> parent(vertices, -1);
    distance[startVertex] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, startVertex });

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (int v = 0; v < vertices; ++v) {
            if (adjacencyMatrix[u][v] != 0) {
                int weight = adjacencyMatrix[u][v];
                if (distance[v] > distance[u] + weight) {
                    distance[v] = distance[u] + weight;
                    parent[v] = u;
                    pq.push({ distance[v], v });
                }
            }
        }
    }

    cout << "\nИспользование алгоритма Дейкстры:\n";
    for (int v = 0; v < vertices; ++v) {
        if (v != startVertex && distance[v] != INF) {
            cout << "Кратчайший путь из " << startVertex << " в " << v << ": ";
            int currentVertex = v;
            while (currentVertex != -1) {
                cout << currentVertex << " ";
                currentVertex = parent[currentVertex];
            }
            cout << "(Вес: " << distance[v] << ")" << endl;
        }
    }
}

void Graph::bellmanFordShortestPath(int startVertex) {
    vector<int> distance(vertices, INF);
    vector<int> parent(vertices, -1);
    distance[startVertex] = 0;

    vector<pair<pair<int, int>, int>> edges;
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            if (adjacencyMatrix[i][j] != 0) {
                edges.push_back({ {i, j}, adjacencyMatrix[i][j] });
            }
        }
    }

    for (int i = 1; i < vertices; ++i) {
        for (const auto& edge : edges) {
            int u = edge.first.first;
            int v = edge.first.second;
            int weight = edge.second;
            if (distance[u] != INF && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                parent[v] = u;
            }
        }
    }

    for (const auto& edge : edges) {
        int u = edge.first.first;
        int v = edge.first.second;
        int weight = edge.second;
        if (distance[u] != INF && distance[u] + weight < distance[v]) {
            cerr << "Граф содержит отрицательный цикл. Алгоритм Беллмана-Форда не применим.\n";
            return;
        }
    }

    cout << "\nИспользование алгоритма Беллмана-Форда:\n";
    for (int v = 0; v < vertices; ++v) {
        if (v != startVertex && distance[v] != INF) {
            cout << "Кратчайший путь из " << startVertex << " в " << v << ": ";
            int currentVertex = v;
            while (currentVertex != -1) {
                cout << currentVertex << " ";
                currentVertex = parent[currentVertex];
            }
            cout << "(Вес: " << distance[v] << ")" << endl;
        }
    }
}

int main() {
    setlocale(0, "RUS");
    Graph graph(5);

    // Заполнение графа значениями из предоставленной таблицы
    graph.addEdge(0, 1, 253);
    graph.addEdge(0, 4, 127);
    graph.addEdge(1, 0, 318);
    graph.addEdge(1, 2, 286);
    graph.addEdge(2, 0, 432);
    graph.addEdge(2, 1, 78);
    graph.addEdge(2, 3, 242);
    graph.addEdge(3, 1, 424);
    graph.addEdge(3, 4, 370);

    graph.printEdgeList();

    int startVertex = 2; // Исходная вершина для поиска кратчайших путей

    graph.dijkstraShortestPath(startVertex);
    graph.bellmanFordShortestPath(startVertex);

    system("pause");
    return 0;
}

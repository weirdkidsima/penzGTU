#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

const int INF = numeric_limits<int>::max();

void initializeGraph(vector<vector<int>>& graph, vector<vector<int>>& pred_matrix, vector<vector<bool>>& reach_matrix) {
    int n = graph.size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && graph[i][j] != INF) {
                pred_matrix[i][j] = i;
            }
            reach_matrix[i][j] = (i != j) && (graph[i][j] != INF);
        }
    }
}

void floydWarshall(vector<vector<int>>& graph, vector<vector<int>>& pred_matrix, vector<vector<bool>>& reach_matrix) {
    int n = graph.size();

    initializeGraph(graph, pred_matrix, reach_matrix);

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (graph[i][k] != INF && graph[k][j] != INF && graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                    pred_matrix[i][j] = pred_matrix[k][j];
                }

                reach_matrix[i][j] = reach_matrix[i][j] || (reach_matrix[i][k] && reach_matrix[k][j]);
            }
        }
    }
}

void printReachabilityMatrix(const vector<vector<bool>>& reach_matrix) {
    int n = reach_matrix.size();
    cout << "Матрица достижимости:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << reach_matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

void printShortestPathMatrix(const vector<vector<int>>& graph) {
    int n = graph.size();
    cout << "Матрица весов кратчайших путей:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (graph[i][j] == INF) {
                cout << "INF ";
            }
            else {
                cout << graph[i][j] << " ";
            }
        }
        cout << "\n";
    }
}

void printPredecessorMatrix(const vector<vector<int>>& pred_matrix) {
    int n = pred_matrix.size();
    cout << "Матрица предшествования:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (pred_matrix[i][j] != -1) {
                cout << pred_matrix[i][j] + 1 << " ";
            }
            else {
                cout << "- ";
            }
        }
        cout << "\n";
    }
}


void printShortestPath(int source, int destination, const vector<vector<int>>& pred_matrix) {
    cout << "Вершины, через которые проходит кратчайший путь из " << source + 1 << " в " << destination + 1 << ":\n";
    while (pred_matrix[source][destination] != -1) {
        cout << pred_matrix[source][destination] + 1 << " ";
        destination = pred_matrix[source][destination];

        if (source == destination) {
            break;
        }
    }
    cout << "\n";
}

void printEccentricities(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> eccentricities(n, 0);

    for (int i = 0; i < n; ++i) {
        int max_distance = 0;
        for (int j = 0; j < n; ++j) {
            if (graph[i][j] != INF && graph[i][j] > max_distance) {
                max_distance = graph[i][j];
            }
        }
        eccentricities[i] = max_distance;
    }

    int radius = *min_element(eccentricities.begin(), eccentricities.end());
    int diameter = *max_element(eccentricities.begin(), eccentricities.end());

    vector<int> center;
    for (int i = 0; i < n; ++i) {
        if (eccentricities[i] == radius) {
            center.push_back(i + 1);
        }
    }

    cout << "Эксцентриситеты вершин: ";
    for (int i = 0; i < n; ++i) {
        cout << eccentricities[i] << " ";
    }
    cout << "\n";

    cout << "Радиус графа: " << radius << "\n";
    cout << "Диаметр графа: " << diameter << "\n";

    cout << "Центр графа: ";
    for (int i = 0; i < center.size(); ++i) {
        cout << center[i] << " ";
    }
    cout << "\n";
}


int main() {
    setlocale(0, "RUS");
    vector<vector<int>> graph = {
        {0, INF, INF, INF, INF},
        {INF, 0, INF, 229, INF},
        {INF, INF, 0, INF, INF},
        {INF, 450, 217, 0, 116},
        {401, 410, INF, INF, 0}
    };
    int n = graph.size();

    vector<vector<int>> pred_matrix(n, vector<int>(n, -1));
    vector<vector<bool>> reach_matrix(n, vector<bool>(n, false));

    floydWarshall(graph, pred_matrix, reach_matrix);

    int source = 1; // Исходная вершина для поиска кратчайшего пути
    int destination = 4; // Целевая вершина для поиска кратчайшего пути
    printReachabilityMatrix(reach_matrix);
    printShortestPathMatrix(graph);
    printPredecessorMatrix(pred_matrix);
    printShortestPath(source, destination, pred_matrix);
    printEccentricities(graph);


    return 0;
}

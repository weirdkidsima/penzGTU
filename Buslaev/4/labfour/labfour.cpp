#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Graph {
private:
	int vertices;
	vector<vector<int>> adjacencyMatrix;
	int startVertex;
public:
	Graph(int vertices) : vertices(vertices), startVertex(0) {
		adjacencyMatrix.resize(vertices, vector<int>(vertices, 0));
	}

	void addEdge(int u, int v) {
		u = u - 1;
		v = v - 1;
		adjacencyMatrix[u][v] = 1;
		adjacencyMatrix[v][u] = 1;
	}
	void setStartVertex(int vertex) {
		if (vertex >= 0 && vertex < vertices) {
			startVertex = vertex;
		}
		else {
			cout << "Невозможная точка обхода" << endl;
		}
	}
	int getStartVertex() const {
		return startVertex;
	}
	void DFS() {
		vector<bool> visited(vertices, false);
		DFSUtil(startVertex, visited);
	}
	void DFSUtil(int vertex, vector<bool>& visited) {
		visited[vertex] = true;
		cout << vertex << " ";

		for (int i = 0; i < vertices; ++i) {
			if (adjacencyMatrix[vertex][i] && !visited[i]) {
				DFSUtil(i, visited);
			}
		}
	}

	void BSF() {
		vector<bool> visited(vertices, false);
		queue<int> bfsQueue;

		visited[startVertex] = true;
		bfsQueue.push(startVertex);

		while (!bfsQueue.empty()) {
			int currentVertex = bfsQueue.front();
			bfsQueue.pop();

			cout << currentVertex << " ";

			for (int i = 0; i < vertices; ++i) {
				if (adjacencyMatrix[currentVertex][i] && !visited[i]) {
					visited[i] = true;
					bfsQueue.push(i);
				}
			}
		}
	}
};

int main() {
	setlocale(0, "RUS");
	Graph graph(6);

	graph.addEdge(1,2);
	graph.addEdge(1,5);
	graph.addEdge(1,6);
	graph.addEdge(2,3);
	graph.addEdge(2,4);
	graph.addEdge(2,5);
	graph.addEdge(2,6);
	graph.addEdge(3,4);
	graph.addEdge(3,5);
	graph.addEdge(3,6);
	graph.addEdge(4,5);
	graph.addEdge(4,6);

	graph.setStartVertex(0);
	cout << "обход в глубину, начиная с вершины " << graph.getStartVertex() << ": ";
	graph.DFS();
	cout << endl;

	cout << "Обход в ширину, начиная с вершины " << graph.getStartVertex() << ": ";
	graph.BSF();
	cout << endl;

	system("pause");
	return 0;
}

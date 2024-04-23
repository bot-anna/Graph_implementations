#include <vector>
#include <iostream>
#include <queue>
#include <stack>

class Edge
{
private:
	int _to;
	int _from;
	double _weight;

public:
	Edge(int to, int from, double weight) : _to(to), _from(from), _weight(weight) {}
	double weight()
	{
		return _weight;
	}
	int from()
	{
		return _from;
	}
	int to()
	{
		return _to;
	}

	bool operator==(Edge& rhs)
	{
		return _weight == rhs._weight;
	}

	bool operator<(Edge& rhs)
	{
		return _weight < rhs._weight;
	}

	bool operator>(Edge& rhs)
	{
		return _weight > rhs._weight;
	}
};

class Graph
{
private:
	const int _vertices;
	int _edges;
	std::vector<std::vector<Edge>> _adjacencyList{};

public:
	Graph(int vertices) : _vertices(vertices), _edges(0)
	{
		for (int i = 0; i < _vertices; i++)
		{
			_adjacencyList.push_back(std::vector<Edge>());
		}
	}

	int vertices()
	{
		return _vertices;
	}

	int edges()
	{
		return _edges;
	}

	void addEdge(int from, int to, double weight)
	{
		Edge e(from, to, weight);
		_adjacencyList[from].push_back(e);
		_edges++;
	}

	std::vector<Edge> adjacent(int vertice)
	{
		return _adjacencyList[vertice];
	}

	

};

class ShortestPath
{
private:
	std::vector<Edge> edgeTo;
	std::vector<double> distanceTo;
	std::priority_queue<int> pq;
	std::stack<int> stack;

public:
	ShortestPath(Graph graph, int source)
	{
		double infinity = std::numeric_limits<double>::infinity();
		for (int i = 0; i < graph.vertices(); i++)
		{
			distanceTo.push_back(infinity);

		}
		distanceTo[source] = 0;


		stack.push(source);
		while (!stack.empty())
		{
			relax(graph, stack.top());
		}
	}

	void relax(Graph graph, int vertice)
	{
		stack.pop();

		for (Edge edge : graph.adjacent(vertice))
		{
			int w = edge.to();
			if (distanceTo[w] > (distanceTo[vertice] + edge.weight()))
			{
				distanceTo[w] = distanceTo[vertice] + edge.weight();
				edgeTo[w] = edge;
				if(stack.)
			}
		}
	}
};

bool end(int vertices, int edges, int queries, int starting_vertices)
{
	return (vertices == 0) && (edges == 0) && (queries == 0) && (starting_vertices == 0);
}

void shortest_path(Graph graph, int source)
{
	std::priority_queue<int> pq;
	std::vector<double> distanceTo;
	

}

int main()
{
	int vertices;
	int edges;
	int queries;
	int starting_vertice;

	std::cin >> vertices;
	std::cin >> edges;
	std::cin >> queries;
	std::cin >> starting_vertice;

	while (!end(vertices, edges, queries, starting_vertice))
	{
		Graph graph(vertices);
		int from;
		int to;
		int weight;
		for (int i = 0; i < edges; i++)
		{
			std::cin >> from;
			std::cin >> to;
			std::cin >> weight;

			graph.addEdge(from, to, (double)weight);
		}

		int source;

		for (int i = 0; i < queries; i++)
		{
			std::cin >> source;
			shortest_path(graph, source);
		}

	}



}
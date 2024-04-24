#include <vector>
#include <iostream>
#include <queue>
#include <string>
#include <limits>

/*
	solution for https://open.kattis.com/problems/shortestpath1
*/
class Edge
{
private:
	int _to;
	int _from;
	int _weight;

public:
	Edge(int from, int to, int weight) :  _from(from), _to(to), _weight(weight) {}
	int weight()
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
	std::vector<std::vector<Edge>> _adjacencyList;

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

	void addEdge(int from, int to, int weight)
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

typedef std::pair<int, int> DIpair;

class ShortestPath
{
private:
	std::vector<int> distanceTo;
	std::priority_queue<DIpair, std::vector<DIpair>, std::greater<DIpair>> pq;
	int query;

public:
	ShortestPath(Graph& graph, int source, int query) : query(query) //making this a reference is what made it run within acceptable time
	{
		int int_max = std::numeric_limits<int>::max();
		for (int i = 0; i < graph.vertices(); i++)
		{
			distanceTo.push_back(int_max);

		}
		distanceTo[source] = 0;

		pq.push(std::make_pair(0.0, source));

		while (!pq.empty())
		{
			int vertice = pq.top().second;
			relax(graph, vertice);
			if (vertice == query) break;
		}
	}

	void relax(Graph& graph, int vertice) //making this a reference is what made it run within acceptable time
	{
		pq.pop();

		for (Edge edge : graph.adjacent(vertice))
		{
			int w = edge.to();
			int oldDistance = distanceTo[vertice] + edge.weight();
			if (distanceTo[w] > oldDistance)
			{
				distanceTo[w] = distanceTo[vertice] + edge.weight();
				pq.push(std::make_pair(distanceTo[w], w));
			}
		}
	}

	int getDistanceTo(int vertice)
	{
		return distanceTo[vertice];
	}
};

bool end(int vertices, int edges, int queries, int starting_vertices)
{
	return (vertices == 0) && (edges == 0) && (queries == 0) && (starting_vertices == 0);
}

int main()
{
	int vertices;
	int edges;
	int queries;
	int starting_vertice;
	std::string out("");

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

			graph.addEdge(from, to, weight);
		}
		
		
		int query;

		for (int i = 0; i < queries; i++)
		{
			std::cin >> query;
			ShortestPath sp(graph, starting_vertice, query);
			int shortest_path = sp.getDistanceTo(query);
			if (shortest_path != std::numeric_limits<int>::max())
			{
				out += std::to_string(shortest_path);
			}
			else
			{
				out += "Impossible";
			}
			
			out += "\n";
		}

		std::cin >> vertices;
		std::cin >> edges;
		std::cin >> queries;
		std::cin >> starting_vertice;
		

	}

	std::cout << out;
}
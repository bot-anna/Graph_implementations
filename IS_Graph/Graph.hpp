#include <vector>

class Graph 
{
private:

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
	};


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
#include <iostream>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <list>
#include <vector>
int n, edges;
using namespace std;
bool ham(vector<int> graph[], vector<bool> visited, vector<int>& path, int v)
{
	if (path.size() == n)
		return true;
	for (auto av : graph[v])
	{
		if (visited[av] == false)
		{
			visited[av] = true;
			path.emplace_back(av);
			if (ham(graph, visited, path, av))
				return true;
			visited[av] = false;
			path.pop_back();
		}
	}
	return false;
}

void addEdge(vector<int> graph[],int u, int v)
{
	graph[u].emplace_back(v);
	graph[v].emplace_back(u);
}

int main()
{
	cin >> n >> edges;
	vector<int> graph[100];
	for (int i = 0; i < edges; i++) {
		int from = 0, to = 0;
		cin >> from >> to;
		addEdge(graph, from, to);
	}

	vector<bool> visited(n, false);
	vector<int> path;
	path.emplace_back(0);
	visited[0] = true;

	if (ham(graph, visited, path, 0))
	{
		for (int i : path)
			cout << i << " ";
		cout << path[0] << endl;
	}
	return 0;
}
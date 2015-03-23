#include <iostream>
#include <string>
#include <list>
#include <map>
#include <queue>

using namespace std;

/* DIRECTED GRAPH - to implement undirected graph just change the AddEdge API to include a verex in other adjacenct list */

/* Adjecency list is represented in vertex itself */
class Vertex {
private:
public:
	string vertexName;
	list<string> adjacencyList;
	Vertex(string name);
	void AddAdjacentVertex(string vertex);
};

/* Graph maintain a map of vertex list -> corresponding to vertex name its vertex object */
class Graph {
private:
	int numberOfVerticies;
	map<string, Vertex*> vertexList;
public:
	Graph();
	Vertex * AddVertex(string vertexName);
	void AddEdge(string firstVertex, string secondVertex);
	void PrintBFS(Vertex * startVertex);
	bool IsPathBetween(string first, string second);
};

Vertex::Vertex(string name) {
	vertexName = name;
}

void Vertex::AddAdjacentVertex(string vertex) {
	adjacencyList.push_back(vertex);
}

Graph::Graph() {
	numberOfVerticies = 0;
}

Vertex * Graph::AddVertex(string name) {
	Vertex * newVertex = new Vertex(name);
	vertexList.insert(make_pair(name, newVertex));
	numberOfVerticies++;
	return newVertex;
}

void Graph::AddEdge(string first, string second) {
	if (vertexList.find(first) != vertexList.end()) {
		((Vertex*)vertexList[first])->AddAdjacentVertex(second);
	}
}

/* BFS Traversal
	Explained stepwise
 */
void Graph::PrintBFS(Vertex * startVertex) {
	/* A queue and a map (hash table/map), queue for verticies while traversing and map for visisted */
	queue<Vertex *> elemQueue;
	map<string, bool> visited;
	Vertex * current;

	/* set visisted to false for everybody */
	for (map<string, Vertex*>::iterator i = vertexList.begin(); i != vertexList.end(); i++) {
		visited[(*i).first] = false;
	}

	/* visit the root first and add it to queue */
	visited[startVertex->vertexName] = true;
	cout << startVertex->vertexName << endl;
	elemQueue.push(startVertex);

	/* keep visiting everybody */
	while (elemQueue.size() != 0) {
		current = elemQueue.front();
		elemQueue.pop();
		/* Check all the adjacent if they are not visited, mark visted and add to Queue */
		for (list<string>::iterator j = current->adjacencyList.begin(); j != current->adjacencyList.end(); j++) {
			if (visited[*j] == false) {
				visited[*j] = true;
				cout << *j << endl;
				elemQueue.push(vertexList[*j]);
			}
		}
	}
}

/* Same as BFS but break in between if found */
bool Graph::IsPathBetween (string first, string second) {
	/* A queue and a map (hash table/map), queue for verticies while traversing and map for visisted */
	queue<Vertex *> elemQueue;
	map<string, bool> visited;
	Vertex * current;
	Vertex * startVertex = vertexList[first];
	Vertex * finish = vertexList[second];

	/* set visisted to false for everybody */
	for (map<string, Vertex*>::iterator i = vertexList.begin(); i != vertexList.end(); i++) {
		visited[(*i).first] = false;
	}

	/* visit the root first and add it to queue */
	visited[startVertex->vertexName] = true;
	elemQueue.push(startVertex);

	/* keep visiting everybody */
	while (elemQueue.size() != 0) {
		current = elemQueue.front();
		elemQueue.pop();
		/* Check all the adjacent if they are not visited, mark visted and add to Queue */
		for (list<string>::iterator j = current->adjacencyList.begin(); j != current->adjacencyList.end(); j++) {
			if (visited[*j] == false) {
				visited[*j] = true;
				if (current == finish)
					return true;
				elemQueue.push(vertexList[*j]);
			}
		}
	}

	return false;
}

int main () {
	Graph myGraph;
	Vertex * root = myGraph.AddVertex("one");
	myGraph.AddVertex("two");
	myGraph.AddVertex("three");
	myGraph.AddVertex("four");
	myGraph.AddVertex("five");
	myGraph.AddVertex("six");
	myGraph.AddVertex("seven");
	myGraph.AddEdge("one", "two");
	myGraph.AddEdge("one", "three");
	myGraph.AddEdge("one", "four");
	myGraph.AddEdge("two", "three");
	myGraph.AddEdge("two", "six");
	myGraph.AddEdge("two", "five");
	myGraph.AddEdge("five", "seven");
	myGraph.AddEdge("six", "two");
	myGraph.AddEdge("six", "seven");
	myGraph.AddEdge("seven", "one");
	myGraph.AddEdge("seven", "three");
	myGraph.PrintBFS(root);
	cout << myGraph.IsPathBetween("one", "two") << endl;
	return 0;
}
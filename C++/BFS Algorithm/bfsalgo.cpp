/* This code is based on graph implementatin 
and well known search technique in graph known as Breadth First Search(BFS)*/

// BFS algorithm in C++

#include <iostream>
#include <list>

using namespace std;

class Graph
{
    int numVertices;
    list<int> *adjLists;
    bool *visited;

public:
    Graph(int vertices);
    void addEdge(int src, int dest);
    void BFS(int startVertex);
};

// Create a graph with given vertices,
// and maintain an adjacency list
Graph::Graph(int vertices)
{
    numVertices = vertices;
    adjLists = new list<int>[vertices];
}

// Add edges to the graph
void Graph::addEdge(int src, int dest)
{
    adjLists[src].push_back(dest);
    adjLists[dest].push_back(src);
}

// BFS algorithm
void Graph::BFS(int startVertex)
{
    visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++)
        visited[i] = false;

    list<int> queue;

    visited[startVertex] = true;
    queue.push_back(startVertex);

    list<int>::iterator i;

    while (!queue.empty())
    {
        int currVertex = queue.front();
        cout << "Visited " << currVertex << " ";
        queue.pop_front();

        for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i)
        {
            int adjVertex = *i;
            if (!visited[adjVertex])
            {
                visited[adjVertex] = true;
                queue.push_back(adjVertex);
            }
        }
    }
}

int main()
{
    int n, x, y; //x and y are temperoray input elements
    cout << "no. of elements in graph:";
    cin >> n;
    Graph g(n);
    cout << "Enter edges in th graph:  \n Enter 0 0 when done. ";
    while (true)
    {
        cin >> x >> y;
        if (x == 0 && y == 0)
            break;
        g.addEdge(x, y);
    }
    cout << "Select the start vertex";
    cin >> x; //here x represents start vertex for bfs

    g.BFS(x);

    return 0;
}
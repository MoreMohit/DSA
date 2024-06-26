#include <iostream>
using namespace std;

class Graph
{
    int adjMatrix[20][20];
    int vertices, edges;

public:
    void accept()
    {
        int src, dest, cost, i, j;

        cout << "\nEnter the number of vertices: ";
        cin >> vertices;

        cout << "\nEnter the number of edges: ";
        cin >> edges;

        for (i = 0; i < vertices; i++)
        {
            for (j = 0; j < vertices; j++)
            {
                adjMatrix[i][j] = 0;
            }
        }

        for (i = 0; i < edges; i++)
        {
            cout << "\nEnter source and destination for edge " << i + 1 << ": ";
            cin >> src >> dest;

            cout << "\nEnter the cost of the edge: ";
            cin >> cost;

            adjMatrix[src][dest] = cost;
            adjMatrix[dest][src] = cost;
        }
    }

    void display()
    {
        int i, j;

        cout << "\nAdjacency Matrix:\n";

        for (i = 0; i < vertices; i++)
        {
            for (j = 0; j < vertices; j++)
            {
                cout << adjMatrix[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void dijkstra(int start)
    {
        int shortestDist[20], visited[20], parent[20];
        int minDist, next, i, j, cnt;

        for (i = 0; i < vertices; i++)
        {
            for (j = 0; j < vertices; j++)
            {
                if (adjMatrix[i][j] == 0)
                    adjMatrix[i][j] = 9999;
            }
        }

        for (i = 0; i < vertices; i++)
        {
            visited[i] = 0;
            parent[i] = start;
            shortestDist[i] = adjMatrix[start][i];
        }

        shortestDist[start] = 0;
        visited[start] = 1;
        cnt = vertices;

        while (cnt > 0)
        {
            minDist = 9999;

            for (i = 0; i < vertices; i++)
            {
                if (shortestDist[i] < minDist && !visited[i])
                {
                    minDist = shortestDist[i];
                    next = i;
                }
            }

            visited[next] = 1;

            for (i = 0; i < vertices; i++)
            {
                if (!visited[i] && shortestDist[i] > (minDist + adjMatrix[next][i]))
                {
                    shortestDist[i] = minDist + adjMatrix[next][i];
                    parent[i] = next;
                }
            }

            cnt--;
        }

        for (i = 0; i < vertices; i++)
        {
            cout << "\nDistance of vertex " << i << " from source " << start << " is " << shortestDist[i] << "\nPath: " << i;
            j = i;

            do
            {
                j = parent[j];
                cout << " <- " << j;
            } 
                while (j != start);
                cout << endl;
        }
    }
};

int main()
{
    int startVertex;
    Graph graph;

    graph.accept();
    graph.display();

    cout << "\nEnter the starting vertex: ";
    cin >> startVertex;

    graph.dijkstra(startVertex);

    return 0;
}



#include <list>
#include <queue>
#include <iostream>
using namespace std;
#define INF INT_MAX


class Graph{
    int tasks, resources;
    
    int **connected, **matching;
    int *distance;
    
    
public:
    Graph(int tasks, int resources);
    
    void showGraph();
    void addEdge(int u, int v);
    bool BFS();
    bool DFS(int u);
    int findPairVinMatching(int v);
    int findPairUinMatching(int u);
    void hopcroftKarp();
};

Graph::Graph(int tasks, int resources){
    this->tasks = tasks;
    this->resources = resources;
    connected = new int*[tasks+1];
    for (int i = 0; i <= tasks; i++) {
        connected[i] = new int[resources+1];
    }
    for (int i = 0; i <= tasks; i ++) {
        for (int j = 0; j <= resources; j++) {
            connected[i][j] = 0;
        }
    }
}

void Graph::addEdge(int u, int v)
{
    connected[u][v] = 1;
}

int Graph::findPairVinMatching(int v){
    for (int i = 1; i <= tasks; i++) {
        if (matching[i][v] == 1) {
            return i;
        }
    }
    return 0;
}

int Graph::findPairUinMatching(int u){
    for (int j = 1; j <= resources; j++) {
        if (matching[u][j] == 1) {
            return j;
        }
    }
    return 0;
}

bool Graph::DFS(int u){
    if (u != 0){
            for (int j = 1; j <= resources; j++) {
                if(connected[u][j] == 1){
                    if (distance[findPairVinMatching(j)] == distance[u]+1){
                        if (DFS(findPairVinMatching(j)) == true) {
                            for (int i = 0; i <= resources; i++) {
                                matching[u][i] = 0;
                            }
                            matching[u][j] = 1;
                            return true;
                        }
                    }
                }
        }
        distance[u] = INF;
        return false;
    }
    return true;
}

bool Graph::BFS(){
    queue<int> q;
    
    for (int u = 1; u <= tasks; u++){
        if (findPairUinMatching(u) == 0){
            distance[u] = 0;
            q.push(u);
        }
        else distance[u] = INF;
    }

    distance[0] = INF;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        if (distance[u] < distance[0])
        {
            
            for (int j = 1; j <= resources; j++) {
                if (connected[u][j] == 1) {
                    if (distance[findPairVinMatching(j)] == distance[0]) {
                        distance[findPairVinMatching(j)] = distance[u] + 1;
                        q.push(findPairVinMatching(j));
                    }
                }
            }
        }
    }
    
    return (distance[0] != INF);
}

void Graph::hopcroftKarp()
{
    matching = new int*[tasks+1];
    for (int i = 0; i <= tasks; i++) {
        matching[i] = new int[resources+1];
    }
    
    for (int i = 0; i <= tasks; i ++) {
        for (int j = 0; j <= resources; j++) {
            matching[i][j] = 0;
        }
    }
    
    distance = new int[tasks+1];

    while (BFS())
    {
        for (int u=1; u<=tasks; u++)
            DFS(u);
    }
    
    cout << "\nMatching:\n";
    for (int i = 1; i <= tasks; i++) {
        for (int j = 1; j <= resources; j++) {
            cout << matching[i][j] << " ";
        }
        cout << '\n';
    }
}


void Graph::showGraph(){
    for (int i = 1; i <= tasks; i++) {
        for (int j = 1 ; j <= resources; j++) {
            cout << connected[i][j]<< " ";
        }
        cout << '\n';
    }
}

int main()
{
    Graph g(4, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 1);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 1);
    g.addEdge(3, 4);
    g.addEdge(4, 4);
    cout<< "Start matrix:\n";
    g.showGraph();
    g.hopcroftKarp();
    
    return 0;
}







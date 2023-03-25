#include <limits.h>
#include <string.h>

#include <iostream>
#include <queue>

using namespace std;

#define V 6

bool bfs(int rGraph[V][V], int s, int t, int parent[]) {
    bool visited[V];
    memset(visited, 0, sizeof(visited));

    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++) {
            if (visited[v] == false && rGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return (visited[t] == true);
}
int fordFulkerson(int graph[V][V], int s, int t) {
    int u, v;

    int rGraph[V][V];
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];

    int parent[V];
    int max_flow = 0;


    int path[V], path_size = 0;
    while (bfs(rGraph, s, t, parent)) {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path[path_size] = v; //punem nodurile pe care le vizitam
            path_size++;
            path_flow = min(path_flow, rGraph[u][v]); //flow ul minim
        }
        path[path_size] = s;
        path_size++;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow; 
        }

        for (int i = path_size - 1; i >= 0; i--) {
            cout << path[i] << " ";
        }
        path_size = 0;
        cout << "Flow : " << path_flow << "\n";

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    int graph[V][V]
        = { { 0, 16, 13, 0, 0, 0 }, { 0, 0, 10, 12, 0, 0 },
            { 0, 4, 0, 0, 14, 0 },  { 0, 0, 9, 0, 0, 20 },
            { 0, 0, 0, 7, 0, 4 },   { 0, 0, 0, 0, 0, 0 } };
    cout << "Source 0, Slink 5\n";
    cout << "Max Flow: " << fordFulkerson(graph, 0, 5) << endl;
}
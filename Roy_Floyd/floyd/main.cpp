#include "Floyd.h"

int main() {
    int graph[100][100];
    int n;
    clock_t timpinceput, timpfinal;
    ifstream fin;
    CitireMatrice(fin, n, graph);
    //printMatrix(graph, n);
    timpinceput = clock();
    floydWarshall(graph, n);
    timpfinal = clock();
    cout << "Executia programului a durat " << (timpfinal - timpinceput) / CLOCKS_PER_SEC << " secunde";

}
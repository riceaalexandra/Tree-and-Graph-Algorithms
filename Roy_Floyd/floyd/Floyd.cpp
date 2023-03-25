#include "Floyd.h"

void CitireMatrice(ifstream& fin, int& V, int graph[][100]) {
    fin.open("data.txt", ios::in);
    fin >> V;
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            fin >> graph[i][j];
        }
    }
}
void printMatrix(int matrix[][100], int nr) {
    for (int i = 1; i <= nr; i++) {
        for (int j = 1; j <= nr; j++) {
            if (matrix[i][j] == INF)
                printf("%4s", "INF");
            else
                printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int graph[][100], int nr) {
    int matrix[100][100], i, j, k;

    for (i = 1; i <= nr; i++)
        for (j = 1; j <= nr; j++)
            matrix[i][j] = graph[i][j];
    for (k = 1; k <= nr; k++) {
        for (i = 1; i <= nr; i++) {
            for (j = 1; j <= nr; j++) {
                if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
        printf("Pentru k = %d \n", k);
        printMatrix(matrix, nr);
    }
    printf("Rezultatul este: \n");
    printMatrix(matrix, nr);
}
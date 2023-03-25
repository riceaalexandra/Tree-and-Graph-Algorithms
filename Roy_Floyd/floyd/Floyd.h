#pragma once
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>

using namespace std;
#define INF 999

void CitireMatrice(ifstream& fin, int& V, int graph[][100]);

void printMatrix(int matrix[][100], int nr);

void floydWarshall(int graph[][100], int nr);
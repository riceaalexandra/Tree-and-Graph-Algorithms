#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>
#include<fstream>
using namespace std;

static int size_min=0,size_max=0;

void swap(int* a, int* b);
void heapify_min(int array[], int i);
void heapify_max(int array[], int i);
void insert_min(int array[], int newNum);
void insert_max(int array[], int newNum);
void deleteRoot_min(int array[], int num);
void deleteRoot_max(int array[], int num);
void order_printArray(int array[]);
void print(int array[]);
void print_fisier(int array[]);
int nr_elem(int array[]);
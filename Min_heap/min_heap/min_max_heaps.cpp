#include "min_max_heaps.h"

void swap(int* a, int* b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void heapify_min(int array[], int i)
{
    if (size_min == 1)
    {
        printf("Single element in the heap");
    }
    else
    {
        int smallest = i;
        int l = 2 * i + 1;//copilul din stanga a lui smallest
        int r = 2 * i + 2;
        if (l < size_min && array[l] < array[smallest]) //
            smallest = l;
        if (r < size_min && array[r] < array[smallest])
            smallest = r;
        if (smallest != i)
        {
            swap(&array[i], &array[smallest]);
            heapify_min(array, smallest);
        }
    }
}

void heapify_max(int array[], int i)
{
    if (size_max == 1)
    {
        printf("Single element in the heap");
    }
    else
    {
        int largest = i;
        int l = 2 * i + 1;//copilul din stanga a lui smallest
        int r = 2 * i + 2;
        if (l < size_max && array[l] > array[largest]) //
            largest = l;
        if (r < size_max && array[r] > array[largest])
            largest = r;
        if (largest != i)
        {
            swap(&array[i], &array[largest]);
            heapify_max(array, largest);
        }
    }
}

void insert_min(int array[], int newNum)
{
    if (size_min == 0)
    {
        array[0] = newNum;
        size_min += 1;
    }
    else
    {
        array[size_min] = newNum;
        size_min += 1;
        for (int i = size_min; i >= 0; i--)
        {
            heapify_min(array, i);
        }
    }
}

void insert_max(int array[], int newNum)
{
    if (size_max == 0)
    {
        array[0] = newNum;
        size_max += 1;
    }
    else
    {
        array[size_max] = newNum;
        size_max += 1;
        for (int i = size_max; i >= 0; i--)
        {
            heapify_max(array, i);
        }
    }
}

void deleteRoot_min(int array[], int num)
{
    int i;
    for (i = 0; i < size_min; i++)
    {
        if (num == array[i])
            break;
    }

    swap(&array[i], &array[size_min - 1]);//pun urmatorul element in locul lui, iar apoi fac heapify
    size_min -= 1;
    for (int i = size_min; i >= 0; i--)
    {
        heapify_min(array, i);
    }
}

void deleteRoot_max(int array[], int num)
{
    int i;
    for (i = 0; i < size_max; i++)
    {
        if (num == array[i])
            break;
    }

    swap(&array[i], &array[size_max - 1]);
    size_max -= 1;
    for (int i = size_max; i >= 0; i--)
    {
        heapify_max(array, i);
    }
}

void order_printArray(int array[])
{
    for (int i = 0; i < size_max; ++i)
        printf("%d ", array[i]);
    printf("\n");
}

int nr_elem(int array[]) {
    int nr = 0;
    for (int i = 0; i < size_max; ++i)
        nr++;
    return nr;
}
//2           
//5 7        
//10 20 30 40 
//80         
void print(int array[]) {
    int nivel = 1;
    int i = 0, t = 1;
    int level = 0;
    while (i < size_min) {
        std::cout << "Nivelul:" << level << " ";
        for (int j = 1; j <= nivel; j++) {
            if (i < size_min) {
                std::cout << array[i] << " ";
                i++;
            }
            else
                break;
        }
        std::cout << "\n";
        nivel = nivel * 2;
        level++;

    }
}
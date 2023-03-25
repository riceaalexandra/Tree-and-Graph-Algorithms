#include "min_max_heaps.h"
ofstream fout("output.txt");

void print_fisier(int array[],int k) {
    for (int i = 0; i < k; i++) {
        fout << array[i] << " ";
    }
    fout << endl;
}

int main()
{
    int array_max[100], array_min[100];
    char option;
    int key;
    int i;
    while (true) {
        cout << "\n1.Adauga un nod";
        cout << "\n2.Sterge un nod";
        cout << "\n3.Order";
        cout << "\n4.Arborescenta";
        cout << "\n5.Iesire.";
        cout << "\n\nOptiunea dumneavoastra: ";
        scanf_s("%d", &i);
        switch (i)
        {
        case 1:
            cin >> key;
            insert_min(array_min, key);
            insert_max(array_max, key);
            break;
        case 2:
            cin >> key;
            deleteRoot_min(array_min, key);
            deleteRoot_max(array_max, key);
            break;
        case 3:
            printf("Min-Heap array:\n\n ");
            order_printArray(array_min);
            printf("\n\nMax-Heap array: \n\n");
            order_printArray(array_max);
            break;
        case 4:
            printf("Min-Heap array:\n\n ");
            print(array_min);
            printf("\n\nMax-Heap array: \n\n");
            cout << "\n\n";
            print(array_max);
            break;
        case 5:
            fout << "Min-Heap:\n";
            print_fisier(array_min, nr_elem(array_min));
            fout << "Max-Heap:\n";
            print_fisier(array_max, nr_elem(array_max));
            return 0;
            break;
        }
    }
    fout.close();
}

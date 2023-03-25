#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>
#include<fstream>
#include"AVL.h"

int main()
{
	int key;
	char option;
	NodeAVL* root = NULL;
	ifstream fin;
	fin.open("input.txt", ios::in);
	if (!fin) {
		cout << "Citirea/Afisarea din fisier nu a mers";
		exit(-1);
	}
	while (!fin.eof())
	{
		fin >> option;

		if (option == 'I')
		{
			fin >> key;
			root = insertAVLNode(root, key);
		}
		else if (option == 'D')
		{
			fin >> key;
			root = deleteAVLNode(root, key);
		}

	}

	fin.close();
	displayAVLTree(root, 10);

	system("PAUSE");
	return 0;
}

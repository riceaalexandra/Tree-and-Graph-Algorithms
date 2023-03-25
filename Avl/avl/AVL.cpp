#include "AVL.h"


NodeAVL* radacina;

int getLevelUtil(NodeAVL* node, int key, int level) {
	if (node == NULL) {
		return 0;
	}
	if (node->key == key)
		return level;

	int downLevel = getLevelUtil(node->left, key, level + 1);
	if (downLevel != 0) {
		return downLevel;
	}

	downLevel = getLevelUtil(node->right, key, level + 1);

	return downLevel;
}

int getLevel(NodeAVL* node, int key) {
	return getLevelUtil(node, key, 1);
}

int max(int a, int b)
{
	return (a > b ? a : b);
}

int maxPathLength(NodeAVL* node)
{
	if (node == NULL)
		return 0;
	return (max(maxPathLength(node->right), maxPathLength(node->left)) + 1);
}

void computeBalanceFactor(NodeAVL* node)
{
	int maxLeft = 0, maxRight = 0;

	if (node->left != NULL)
		maxLeft = maxPathLength(node->left);
	else
		maxLeft = 0;

	if (node->right != NULL)
		maxRight = maxPathLength(node->right);
	else
		maxRight = 0;

	node->echi = maxRight - maxLeft;
}

NodeAVL* leftRotation(NodeAVL* node)	
{
	NodeAVL* heavyChild;

	heavyChild = node->right;
	node->right = heavyChild->left;
	heavyChild->left = node;

	computeBalanceFactor(node);
	computeBalanceFactor(heavyChild);

	node = heavyChild;
	return node;
}

NodeAVL* rightRotation(NodeAVL* node)
{
	NodeAVL* heavyChild;

	heavyChild = node->left;
	node->left = heavyChild->right;
	heavyChild->right = node;

	computeBalanceFactor(node);
	computeBalanceFactor(heavyChild);

	node = heavyChild;
	return node;
}

NodeAVL* doubleLeftRotation(NodeAVL* node)
{
	node->right = rightRotation(node->right);
	node = leftRotation(node);
	return node;
}

NodeAVL* doubleRightRotation(NodeAVL* node)
{
	node->left = leftRotation(node->left);
	node = rightRotation(node);
	return node;
}

NodeAVL* balance(NodeAVL* node)
{
	NodeAVL* heavyChild;
	computeBalanceFactor(node);

	if (node->echi == -2)	
	{
		heavyChild = node->left;

		if (heavyChild->echi == 1) {
			printf("Nodul %d a fost rotit si era la nivelul %d \n", node->key, getLevel(radacina, node->key));
			node = doubleRightRotation(node);
			
		}//prima rotire la stanga, urm la dreapta
		else {
			printf("Nodul %d a fost rotit si era la nivelul %d \n", node->key, getLevel(radacina, node->key));
			node = rightRotation(node);
		}//ll
	}
	else
		if (node->echi == 2)		
		{
			heavyChild = node->right;

			if (heavyChild->echi == -1) {
						printf("Nodul %d a fost rotit si era la nivelul %d \n", node->key, getLevel(radacina, node->key));
				node = doubleLeftRotation(node);
			}//prima rotire la drepata, urm la stanga
			else {
						printf("Nodul %d a fost rotit si era la nivelul %d \n", node->key, getLevel(radacina, node->key));
				node = leftRotation(node); 
			}
		}

	return node;
}

NodeAVL* insertAVLNode(NodeAVL* node, int value)
{
	if (node == NULL)
	{
		node = new NodeAVL;
		node->key = value;
		node->echi = 0;
		node->left = NULL;
		node->right = NULL;
		
		return node;
	}
	else
		if (value < node->key)
			node->left = insertAVLNode(node->left, value);
		else
			if (value > node->key)
				node->right = insertAVLNode(node->right, value);
			else
				printf("The key %d already exists! \n", value);
	radacina = node;
	node = balance(node);

	return node;
}

void displayAVLTree(NodeAVL* node, int level)
{
	if (node != NULL)
	{
		displayAVLTree(node->right, level + 7);
		for (int i = 0; i < level; i++)
			printf(" ");

		printf("%d(%d) \n", node->key, node->echi);
		displayAVLTree(node->left, level + 7);
	}
}

NodeAVL* deleteAVLNode(NodeAVL* node, int value)
{
	if (node == NULL)
	{

		printf("Can't delete key %d, it is not in AVL tree!\n", value);
		return node;
	}

	if (value < node->key)
		node->left = deleteAVLNode(node->left, value);

	else if (value > node->key)
		node->right = deleteAVLNode(node->right, value);

	else
	{
		if ((node->left == NULL) || (node->right == NULL))
		{
			NodeAVL* temp;

			if (node->left != NULL)
				temp = node->left;
			else
				temp = node->right;

			if (temp == NULL)
				node = NULL;

			else
			{
				*node = *temp;
				free(temp);
			}
		}
		else
		{
			NodeAVL* temp = node->right;

			while (temp->left != NULL)
				temp = temp->left;

			node->key = temp->key;

			node->right = deleteAVLNode(node->right, temp->key);
		}
	}

	if (node != NULL)
		node = balance(node);

	return node;
}


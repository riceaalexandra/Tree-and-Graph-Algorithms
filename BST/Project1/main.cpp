#include"prototypes.h"

std::ifstream f("data.txt");
std::ofstream g("data1.txt");
void save(Node* root) {

    if (root != 0)
    {
        save(root->right);
        std::cout << root->data << " ";
        g << root->data;
        save(root->left);
    }
    g.close();
}


Node* load(Node* root) {
   
    int x;
    while (f >> x) {
        root = Add_Node(root, x);
    }
    return root;
    f.close();
}
int main()

{
    Node* root = NULL;
  
    root = load(root);
    save(root);
    int i, n, x;
   
    do {
        printf("\n1.Adauga un nod");
        printf("\n2.Sterge un nod");
        printf("\n3.Preorder");
        printf("\n4.Inorder");
        printf("\n5.Postorder");
        printf("\n6.Arborescenta");
        printf("\n\nOptiunea dumneavoastra: ");
        scanf_s("%d", &i);
        switch (i)
        {
        case 1:
            scanf_s("%d", &n);
            root = Add_Node(root, n);
            break;
        case 2:
            printf("\nAlegeti nodul pe care doriti sa-l stergeti");
            scanf_s("%d", &x);
            root = Delete(root, x);
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            inorder(root);
            break;
        case 5:
            postorder(root);
            break;
        case 6:
            Display(root, 0);
            break;
        }



    } while (i);
}


#include <iostream>

using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode
{
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
};

struct TrieNode* getNode(void)
{
    struct TrieNode* pNode = new TrieNode;

    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}

void insert(struct TrieNode* root, string key)
{
    struct TrieNode* pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = true;
}

bool search(struct TrieNode* root, string key)
{
    struct TrieNode* pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;

        pCrawl = pCrawl->children[index];
    }

    return (pCrawl->isEndOfWord);
}

bool isLeafNode(struct TrieNode* root)
{
    return root->isEndOfWord != false;
}

void display(struct TrieNode* root, char str[], int level, string prefix = "")
{

    if (isLeafNode(root))
    {
        cout << prefix;
        str[level] = NULL;
        cout << str << endl;
    }

    int i;
    for (i = 0; i < ALPHABET_SIZE; i++)
    {

        if (root->children[i])
        {
            str[level] = i + 'a';
            display(root->children[i], str, level + 1, prefix);
        }
    }
}

void prefix(struct TrieNode* root, string prefix) {
    struct TrieNode* pCrawl = root;
    int ok = 1, level=0;
    char str[20];
    for (int i = 0; i < prefix.length(); i++) {
        int index = prefix[i] - 'a';
        if (pCrawl->children[index] == NULL) {
            ok = 0;
        }
        pCrawl = pCrawl->children[index];
    }
    if (ok == 1) {
        display(pCrawl, str, level, prefix);
    }

}

int main()
{

    string keys[] = { "the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" };
    int n = sizeof(keys) / sizeof(keys[0]);

    struct TrieNode* root = getNode();

    for (int i = 0; i < n; i++)
        insert(root, keys[i]);
    prefix(root, "the");
    return 0;
}
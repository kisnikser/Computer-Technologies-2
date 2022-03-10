#include <iostream>

#include "BinTree.h"

using namespace std;

BinTree::BinTree()
{
    root = NULL;
}

BinTree::BinTree(int* keys, int size)
{
    root = NULL;

    for (int i = 0; i < size; i++)
    {
        AddLeaf(keys[i]);
    }
}

BinTree::~BinTree() {}

BinTree::node* BinTree::CreateLeaf(int key)
{
    node* n = new node;
    n->key = key;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void BinTree::AddLeaf(int key)
{
    AddLeafPrivate(key, root);
}

void BinTree::AddLeafPrivate(int key, node* ptr)
{
    if (root == NULL)
    {
        root = CreateLeaf(key);
    }
    else if (key < ptr->key)
    {
        if (ptr->left != NULL)
        {
            AddLeafPrivate(key, ptr->left);
        }
        else
        {
            ptr->left = CreateLeaf(key);
        }
    }
    else if (key > ptr->key)
    {
        if (ptr->right != NULL)
        {
            AddLeafPrivate(key, ptr->right);
        }
        else
        {
            ptr->right = CreateLeaf(key);
        }
    }
    else
    {
        cout << "The key " << key << " has already been added to the tree" << endl;
    }
}

int BinTree::SumTree()
{
    return SumTreePrivate(root);
}

int BinTree::SumTreePrivate(node* ptr)
{
    if (root == NULL)
    {
        cout << "The tree is empty" << endl;
        return -1000;
    }
    
    if (ptr == NULL)
    {
        return 0;
    }
    
    return (ptr->key + SumTreePrivate(ptr->left) + SumTreePrivate(ptr->right));
}
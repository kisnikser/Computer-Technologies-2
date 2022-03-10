#include <iostream>

#include "BinTree.h"

using namespace std;

BinTree::BinTree() // первый конструктор без аргументов
{
    root = NULL;
}

BinTree::BinTree(int* keys, int size) // конструтктор, инициализирующий дерево по заданному массиву
{
    root = NULL;

    for (int i = 0; i < size; i++)
    {
        AddLeaf(keys[i]);
    }
}

BinTree::~BinTree() // деструктор
{
    RemoveSubtree(root);
}

void BinTree::RemoveSubtree(node* ptr) // удаление поддерева для деструктора
{
    if (ptr != NULL)
    {
        if (ptr->left != NULL)
        {
            RemoveSubtree(ptr->left);
        }
        
        if (ptr->right != NULL)
        {
            RemoveSubtree(ptr->right);
        }

        cout << "Deleting the node containing key " << ptr->key << "..." << endl;
        delete ptr;
    }
}

BinTree::node* BinTree::CreateLeaf(int key) // создание "пустого" узла (отделен от всего дерева)
{
    node* n = new node;
    n->key = key;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void BinTree::AddLeaf(int key) // добавление узла к дереву
{
    AddLeafPrivate(key, root);
}

void BinTree::AddLeafPrivate(int key, node* ptr) // рекурсивный спуск по дереву с поиском места для нового узла
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
        cout << "The key " << key << " has already been added to the tree." << endl;
    }
}

int BinTree::SumTree() // вычисление суммы элементов дерева
{
    return SumTreePrivate(root);
}

int BinTree::SumTreePrivate(node* ptr) // рекурсивное вычисление суммы
{
    if (root == NULL)
    {
        cout << "The tree is empty." << endl;
        return -1000;
    }
    
    if (ptr == NULL)
    {
        return 0;
    }
    
    return (ptr->key + SumTreePrivate(ptr->left) + SumTreePrivate(ptr->right));
}

void BinTree::PrintInOrder() // вывод элементов дерева в порядке возрастания
{
    PrintInOrderPrivate(root);
    cout << endl;
}

void BinTree::PrintInOrderPrivate(node* ptr) // рекурсивный вывод в порядке возрастания
{
    if (root != NULL)
    {
        if (ptr->left != NULL)
        {
            PrintInOrderPrivate(ptr->left);
        }

        cout << ptr->key << " ";

        if (ptr->right != NULL)
        {
            PrintInOrderPrivate(ptr->right);
        }
    }
    else
    {
        cout << "The tree is empty.";
    }
}

BinTree::node* BinTree::ReturnNode(int key) // возвращает указатель на узел с заданным значением
{
    return ReturnNodePrivate(key, root);
}

BinTree::node* BinTree::ReturnNodePrivate(int key, node* ptr) // рекурсивный поиск узла с заданным значением
{
    if (ptr != NULL)
    {
        if (ptr->key == key)
        {
            return ptr;
        }
        else
        {
            if (key < ptr->key)
            {
                return ReturnNodePrivate(key, ptr->left);
            }
            else
            {
                return ReturnNodePrivate(key, ptr->right);
            }
        }
    }
    else
    {
        return NULL;
    }
}

int BinTree::ReturnRootKey() // возвращает значение корня дерева
{
    if (root != NULL)
    {
        return root->key;
    }
    else
    {
        return -1000;
    }
}

void BinTree::PrintChildren(int key) // выводит значения узла и его потомков
{
    node* ptr = ReturnNode(key);

    if (ptr != NULL)
    {
        cout << "Node = " << ptr->key << endl;

        if (ptr->left == NULL)
        {
            cout << "Left Child = NULL" << endl;
        }
        else
        {
            cout << "Left Child = " << ptr->left->key << endl;
        }

        if (ptr->right == NULL)
        {
            cout << "Right Child = NULL" << endl;
        }
        else
        {
            cout << "Right Child = " << ptr->right->key << endl;
        }
    }
    else
    {
        cout << "Key " << key << " is not in the tree." << endl;
    }
}

int BinTree::FindSmallest() // поиск наименьшего значения в дереве
{
    return FindSmallestPrivate(root);
}

int BinTree::FindSmallestPrivate(node* ptr) // рекурсивный спуск для поиска наименьшего значения
{
    if (root == NULL)
    {
        cout << "The tree is empty." << endl;
        return -1000;
    }
    else
    {
        if (ptr->left != NULL)
        {
            return FindSmallestPrivate(ptr->left);
        }
        else
        {
            return ptr->key;
        }
    }
}

int BinTree::FindGreatest() // поиск наибольшего значения в дереве
{
    return FindGreatestPrivate(root);
}

int BinTree::FindGreatestPrivate(node* ptr) // рекурсивный спуск для поиска наибольшего значения
{
    if (root == NULL)
    {
        cout << "The tree is empty." << endl;
        return -1000;
    }
    else
    {
        if (ptr->right != NULL)
        {
            return FindGreatestPrivate(ptr->right);
        }
        else
        {
            return ptr->key;
        }
    }
}

void BinTree::RemoveNode(int key) // удаляет из дерева узел с заданным значением
{
    RemoveNodePrivate(key, root);
}

void BinTree::RemoveNodePrivate(int key, node* parent) // рекурсивный поиск 
{
    if (root != NULL)
    {
        if (root->key == key)
        {
            RemoveRootMatch();
        }
        else
        {
            if (key < parent->key && parent->left != NULL) // значение находится левее данного узла
            {
                parent->left->key == key ?
                RemoveMatch(parent, parent->left, true) : // удаляем левого потомка
                RemoveNodePrivate(key, parent->left); // рекурсивно ищем значение левее
            }
            else if (key > parent->key && parent->right != NULL) // значение находится правее данного узла
            {
                parent->right->key == key ?
                RemoveMatch(parent, parent->right, false) : // удаляем правого потомка
                RemoveNodePrivate(key, parent->right); // рекурсивно ищем значение правее
            }
            else // в дереве нет такого значения
            {
                cout << "The key " << key << " was not found in the tree." << endl;
            }
        }
    }
    else
    {
        cout << "The tree is empty." << endl;
    }
}

void BinTree::RemoveRootMatch() // удаление корня дерева и перестройка оставшегося
{
    if (root != NULL)
    {
        node* delPtr = root;
        int rootKey = root->key;
        int smallestInRightSubtree;

        // 0 children
        if (root->left == NULL && root->right == NULL)
        {
            root = NULL;
            delete delPtr;
        }

        // 1 child
        else if (root->left == NULL && root->right != NULL)
        {
            root = root->right;
            delPtr->right = NULL; // отделяем старый корень от дерева
            delete delPtr;
            cout << "The root node with key " << rootKey << " was deleted. " << endl << 
                    "The new root contains key " << root->key << "." << endl;
        }

        else if (root->left != NULL && root->right == NULL)
        {
            root = root->left;
            delPtr->left = NULL; // отделяем старый корень от дерева
            delete delPtr;
            cout << "The root node with key " << rootKey << " was deleted. " << endl <<
                    "The new root contains key " << root->key << "." << endl;
        }

        // 2 children
        else
        {
            smallestInRightSubtree = FindSmallestPrivate(root->right);
            RemoveNodePrivate(smallestInRightSubtree, root); 
            root->key = smallestInRightSubtree; // новое значение корня - наименьшее значение из правого поддерева
            cout << "The root key containing key " << rootKey <<
                    " was overwritten with key " << root->key << "." << endl;
        }
    }
    else
    {
        cout << "Can not remove root. The tree is empty." << endl;
    }
}

void BinTree::RemoveMatch(node* parent, node* match, bool left) // удаление указанного узла
{
    if (root != NULL)
    {
        node* delPtr;
        int matchKey = match->key;
        int smallestInRightSubtree;

        // 0 children
        if (match->left == NULL && match->right == NULL)
        {
            delPtr = match;
            left == true ? parent->left = NULL : parent->right = NULL;
            delete delPtr;
            cout << "The node containing key " << matchKey << " was removed." << endl;

        }

        // 1 child
        else if (match->left == NULL && match ->right != NULL)
        {
            left == true ? parent->left = match->right : parent->right = match->right;
            match->right = NULL;
            delPtr = match;
            delete delPtr;
            cout << "The node containing key " << matchKey << " was removed." << endl;
        }
        else if (match->left != NULL && match ->right == NULL)
        {
            left == true ? parent->left = match->left : parent->right = match->left;
            match->left = NULL;
            delPtr = match;
            delete delPtr;
            cout << "The node containing key " << matchKey << " was removed." << endl;
        }

        // 2 children
        else
        {
            smallestInRightSubtree = FindSmallestPrivate(match->right);
            RemoveNodePrivate(smallestInRightSubtree, match);
            match->key = smallestInRightSubtree;
        }
    }
    else
    {
        cout << "Can not remove match. The tree is empty." << endl;
    }
}
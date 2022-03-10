#include <iostream>

#include "BinTree.cpp"

using namespace std;

int main()
{
    const int size = 5;
    int keys[size];

    cout << "Enter " << size << " elements separated by a space" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> keys[i];
    }

    BinTree myTree = BinTree(keys, size);
    
    cout << "The tree sum is equal to " << myTree.SumTree() << endl;

    return 0;
}
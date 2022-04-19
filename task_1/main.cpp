#include <iostream>

#include "BinTree.cpp"

using namespace std;

int main()
{
    BinTree myTree;

    cout << endl << "Printing the tree in order before adding numbers..." << endl;
    myTree.PrintInOrder();

    cout << endl << "Enter keys to add to the tree. Enter -1 to stop the process." << endl;
    int input = 0;
    while (input != -1)
    {
        cin >> input;
        if (input != -1)
        {
            myTree.AddLeaf(input);
        }
    }
    
    cout << endl << "Printing the tree in order after adding numbers..." << endl;
    myTree.PrintInOrder();

    cout << endl << "The tree sum is " << myTree.SumTree() << "." << endl << endl;

    cout << endl << "The greatest value is " << myTree.FindGreatest() << endl;

    cout << "Enter a key value you want to know the information about: ";
    int infoKey;
    cin >> infoKey;
    myTree.PrintChildren(infoKey);

    cout << endl << "Enter a key value to delete. Enter -1 to stop the process." << endl;
    input = 0;
    while (input != -1)
    {
        cout << endl << "Delete key: ";
        cin >> input;
        if (input != -1)
        {
            myTree.RemoveNode(input);
            cout << "Printing current tree condition..." << endl;
            myTree.PrintInOrder();
        }
    }

    return 0;
}
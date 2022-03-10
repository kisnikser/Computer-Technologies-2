class BinTree
{
    private:

        struct node
        {
            int key;
            node* left;
            node* right;
        };

        node* root;

        void RemoveSubtree(node* ptr);
        void AddLeafPrivate(int key, node* ptr);
        int SumTreePrivate(node* ptr);
        void PrintInOrderPrivate(node* ptr);
        node* ReturnNodePrivate(int key, node* ptr);
        int FindSmallestPrivate(node* ptr);
        int FindGreatestPrivate(node* ptr);
        void RemoveNodePrivate(int key, node* parent);
        void RemoveRootMatch();
        void RemoveMatch(node* parent, node* match, bool left);

    public:

        BinTree();
        BinTree(int* keys, int size);
        ~BinTree();

        node* CreateLeaf(int key);
        void AddLeaf(int key);
        int SumTree();
        void PrintInOrder();
        node* ReturnNode(int key);
        int ReturnRootKey();
        void PrintChildren(int key);
        int FindSmallest();
        int FindGreatest();
        void RemoveNode(int key);
};
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

        void AddLeafPrivate(int key, node* ptr);
        int SumTreePrivate(node* ptr);

    public:

        BinTree();
        BinTree(int* keys, int size);
        ~BinTree();
        node* CreateLeaf(int key);
        void AddLeaf(int key);
        int SumTree();
};
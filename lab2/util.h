typedef struct TreeNode {
    int data;
    struct TreeNode* right;
    struct TreeNode* left;
} TreeNode;

TreeNode* createNode(int data);

void freeTree(TreeNode* root);

TreeNode* rotateL(TreeNode* node);

TreeNode* rotateR(TreeNode* node);

TreeNode* search(TreeNode* root, int data);

TreeNode* insert(TreeNode* root, int data);

TreeNode* merge(TreeNode* left, TreeNode* right);

void splitTree(TreeNode* root, TreeNode** leftTree, TreeNode** rightTree, int data);
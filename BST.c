#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct BSTNode {
    int val;
    struct BSTNode *left;
    struct BSTNode *right;
}BSTNode;

typedef struct {
    BSTNode *root;
    int size;
}BST;

BST* bst_create(){
    BST *tree = malloc(sizeof(BST));
    tree->root = NULL;
    tree->size = 0;
    return tree;
}
BSTNode* node_create(int e) {
    BSTNode* newNode = malloc(sizeof(BSTNode));
    newNode->val= e;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int bst_get_size(BST *tree) {
    return tree->size;
}

bool bst_isEmpty(BST *tree) {
    return tree->size == 0;
}

//向二分搜索树添加元素：从根节点出发！（不包含重复元素） -若要包含，改变定义

//向以node为根的二分搜索树插入元素
//返回插入新节点后二分搜索树的根(包括root原来为空的情况）
BSTNode* add(BSTNode* node,int e,BST *tree) {
    //终止条件
    if (node==NULL) {
        tree->size++;
        return node_create(e);
    }
    if (e<node->val) {
        node->left=add(node->left,e,tree);
    }
    else if (e>node->val) {
        node->right=add(node->right,e,tree);
    }
    return node;
}
void bst_add(BST *tree, int e) {
   tree->root=add(tree->root,e,tree);
}

//看二分搜索树中是否包含元素e
//看以node为根的二分搜索树中是否包含元素e，递归函数
bool contains(BSTNode *node,int e) {
    if (node==NULL)return false;

    if (e==node->val)return true;

    else if (e<node->val) {
        return contains(node->left,e);
    }
    else {
        return contains(node->right,e);
    }
}

bool bst_contains(int e,BST *tree) {
    return contains(tree->root,e);
}

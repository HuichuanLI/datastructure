#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK 100

typedef struct BSTNode {
    int val;
    struct BSTNode *left;
    struct BSTNode *right;
}BSTNode;

typedef struct {
    BSTNode *root;
    int size;
}BST;

typedef struct {
    BSTNode* data[MAX_STACK];
    int top;
} Stack;

void stackInit(Stack *s);
int stackIsEmpty(Stack *s);
void stackPush(Stack *s, BSTNode* node);
BSTNode* stackPop(Stack *s);

#define MAX_QUEUE 100
typedef struct {
    BSTNode* data[MAX_QUEUE];
    int front;
    int rear;
} Queue;




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

//前序遍历以node为根节点的二分搜索树，递归算法
void preOrder(BST *tree,BSTNode *node) {
    if (node==NULL)return;

    printf("%d",node->val);
    preOrder(tree,node->left);
    preOrder(tree,node->right);
}

void bst_preOrder(BST *tree) {
    preOrder(tree,tree->root);
}

//非递归，栈实现前序遍历
void preOrderNR(BST *tree) {
    if(tree->root == NULL) return;
    Stack st;
    stackInit(&st);
    stackPush(&st, tree->root);

    while (!stackIsEmpty(&st)) {
        BSTNode* cur=stackPop(&st);
        printf("%d ", cur->val);
        if(cur->right != NULL){
            stackPush(&st, cur->right);
        }
        if(cur->left != NULL){
            stackPush(&st, cur->left);
        }
    }
}

//中序遍历:遍历以node为根节点的二分搜索树，递归算法
void inOrder(BST *tree,BSTNode *node) {
    if (node==NULL) return;

    inOrder(tree,node->left);
    printf("%d",node->val);//遍历父亲节点
    inOrder(tree,node->right);
}

void bst_inOrder(BST *tree) {
    inOrder(tree,tree->root);
}

//后序遍历(left,right,node)：遍历以node为根节点的二分搜索树，递归算法
void postOrder(BST *tree,BSTNode *node) {
    if (node==NULL)return;

    postOrder(tree,node->left);
    postOrder(tree,node->right);
    printf("%d",node->val);
}
void bst_postOrder(BST *tree) {
    postOrder(tree,tree->root);
}

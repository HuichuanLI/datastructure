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

//非递归二分搜索树添加元素
void add_U(BST *tree,int e) {
    //处理根节点为空的情况
    if (tree->root==NULL) {
        tree->root=node_create(e);
        tree->size++;
    }

    BSTNode *p=tree->root;//追踪父亲节点
    while (p!=NULL) {
        if (e<p->val) {
            if (p->left==NULL) {
                p->left=node_create(e);
                tree->size++;
                return ;
            }
            p=p->left;
        }

        if (e>p->val) {
            if (p->right==NULL) {
                p->right=node_create(e);
                tree->size++;
                return;
            }
            p=p->right;
        }
        else {
            return;
        }
    }
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
void preOrder(BSTNode *node) {
    if (node==NULL)return;

    printf("%d ",node->val);
    preOrder(node->left);
    preOrder(node->right);
}

void bst_preOrder(BST *tree) {
    preOrder(tree->root);
}

//中序遍历:遍历以node为根节点的二分搜索树，递归算法
void inOrder(BSTNode *node) {
    if (node==NULL) return;

    inOrder(node->left);
    printf("%d ",node->val);//遍历父亲节点
    inOrder(node->right);
}

void bst_inOrder(BST *tree) {
    inOrder(tree->root);
}

//后序遍历(left,right,node)：遍历以node为根节点的二分搜索树，递归算法
void postOrder(BSTNode *node) {
    if (node==NULL)return;

    postOrder(node->left);
    postOrder(node->right);
    printf("%d ",node->val);
}
void bst_postOrder(BST *tree) {
    postOrder(tree->root);
}

//寻找二分搜索树的最小值
int minimum(BSTNode *node) {
    if (node->left==NULL)
         return node->left->val;

    return minimum(node->left);
}

int bst_minimum(BST *tree) {
    if (tree->size==0)return -1;
    return minimum(tree->root);
}

//寻找二分搜索树的最大值
int maximum(BSTNode *node) {
    if (node->right==NULL)return node->right->val;

    return maximum(node->right);
}
int bst_maximum(BST *tree) {
    if (tree->size==0)return -1;
    return maximum(tree->root);
}

//删除以node为根的二分搜素树的最小值，递归算法，返回新的二分搜索树的新根
BSTNode* removeMin(BST *tree,BSTNode *node) {
    if (node->left==NULL) {
        BSTNode *rightNode=node->right;
        node->right=NULL;
        tree->size--;
        return rightNode;
    }
    node->left=removeMin(tree,node->left);
    return node;
}
//删除二分搜素树的最小值，返回最小值
int bst_removeMin(BST *tree) {
    int ret=minimum(tree->root);
    removeMin(tree,tree->root);
    return ret;
}




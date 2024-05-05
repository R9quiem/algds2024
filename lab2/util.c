#include <stdio.h>
#include <stdlib.h>
#include "lab2_pdp_10.h"

TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void freeTree(TreeNode* root) {
    if (root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

TreeNode* rotateL(TreeNode* node) {
    if (node == NULL || node->right == NULL)
        return node;

    TreeNode* oldRoot = node;
    TreeNode* newRoot = node->right;

    oldRoot->right = newRoot->left;
    newRoot->left = oldRoot;

    return newRoot;
}

TreeNode* rotateR(TreeNode* node) {
    if (node == NULL || node->left == NULL)
        return node;

    TreeNode* oldRoot = node;
    TreeNode* newRoot = node->left;

    oldRoot->left = newRoot->right;
    newRoot->right = oldRoot;

    return newRoot;
}

TreeNode* search(TreeNode* root, int data) {
    if (root == NULL || root->data == data)
        return root;

    if (data < root->data) {
        if (root->left == NULL)
            return root;
        if (data < root->left->data) {
            root->left->left = search(root->left->left, data);
            root = rotateR(root);
        }
        else if (data > root->left->data) {
            root->left->right = search(root->left->right, data);
            if (root->left->right != NULL)
                root->left = rotateL(root->left);
        }
        return (root->left == NULL) ? root : rotateR(root);
    }
    else {
        if (root->right == NULL)
            return root;
        if (data < root->right->data) {
            root->right->left = search(root->right->left, data);
            if (root->right->left != NULL)
                root->right = rotateR(root->right);
        }
        else if (data > root->right->data) {
            root->right->right = search(root->right->right, data);
            root = rotateL(root);
        }
        return (root->right == NULL) ? root : rotateL(root);
    }
}

TreeNode* insert(TreeNode* root, int data) {
    if (root == NULL) return createNode(data);

    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    else {
        return root;
    }

    return search(root, data);
}

TreeNode* merge(TreeNode* left, TreeNode* right) {
    if (left == NULL)
        return right;

    TreeNode* maxNode = left;
    while (maxNode->right != NULL)
        maxNode = maxNode->right;

    maxNode = search(left, maxNode->data);

    maxNode->right = right;

    return maxNode;
}

void splitTree(TreeNode* root, TreeNode** leftTree, TreeNode** rightTree, int data) {
    if (root == NULL) {
        *leftTree = NULL;
        *rightTree = NULL;
        return;
    }

    root = search(root, data);

    if (root->data == data) {
        *leftTree = root->left;
        *rightTree = root->right;
        root->left = NULL;
        root->right = NULL;
    }
    else if (root->data < data) {
        *leftTree = root;
        splitTree(root->right, &((*leftTree)->right), rightTree, data);
    }
    else {
        *rightTree = root;
        splitTree(root->left, leftTree, &((*rightTree)->left), data);
    }
}


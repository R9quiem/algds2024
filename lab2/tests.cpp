#include <gtest/gtest.h>

extern "C" {
#include "lab2_pdp_10.h"
}

TEST(CreateNodeTest, BasicTest) {
    TreeNode* node = createNode(5);
    ASSERT_NE(node, nullptr);
    EXPECT_EQ(node->data, 5);
    EXPECT_EQ(node->left, nullptr);
    EXPECT_EQ(node->right, nullptr);
    free(node); // Освобождаем память после теста
}

// Тестирование функции вставки элемента в дерево
TEST(InsertTest, BasicTest) {
    TreeNode* root = createNode(11);
    root->left = createNode(5);
    root->right = createNode(15);

    ASSERT_NE(root, nullptr);
    EXPECT_EQ(root->data, 11);
    EXPECT_EQ(root->left->data, 5);
    EXPECT_EQ(root->right->data, 15);

    freeTree(root); // Освобождаем память после теста
}

TEST(RotateLeftTest, BasicTest) {
    TreeNode* root = createNode(10);
    root->right = createNode(0);
    root->right->left = createNode(15);

    root = rotateL(root);

    EXPECT_EQ(root->data, 0);

    freeTree(root);
}
TEST(RotateRightTest, BasicTest) {
    TreeNode* root = createNode(20);
    root->left = createNode(0);
    root->left->right = createNode(15);

    root = rotateR(root);

    EXPECT_EQ(root->data, 0);

    freeTree(root);
}

TEST(MergeTest, BasicTest) {
    TreeNode* left = createNode(-10);
    left->left = createNode(-5);

    TreeNode* right = createNode(15);

    TreeNode* merged = merge(left, right);

    EXPECT_EQ(merged->data, -10);
    EXPECT_EQ(merged->right->data, 15);

    freeTree(merged);
}
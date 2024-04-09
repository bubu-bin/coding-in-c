#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

struct TreeNode *createNode(int value)
{
    TreeNode *node = malloc(sizeof(TreeNode));

    node->left = NULL;
    node->right = NULL;
    node->value = value;

    return node;
}

struct TreeNode *insert(struct TreeNode *root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (root->value > value)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

struct TreeNode *find(struct TreeNode *root, int value)
{
    if (root == NULL)
        return NULL;

    if (root->value == value)
        return root;

    if (root->value > value)
        return find(root->left, value);
    else
        return find(root->right, value);
}

void inOrderTraversal(struct TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrderTraversal(root->left);
    printf("%d\n", root->value);
    inOrderTraversal(root->right);
}

int main(int argc, char const *argv[])
{
    struct TreeNode *root = createNode(2);
    insert(root, 20);
    insert(root, 30);
    insert(root, 50);
    insert(root, 80);
    insert(root, 32);

    find(root, 80);
    inOrderTraversal(root);
    return 0;
}

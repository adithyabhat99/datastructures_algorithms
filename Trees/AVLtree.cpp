#include <bits/stdc++.h>
using namespace std;
struct tree
{
    int data, height;
    struct tree *left;
    struct tree *right;
};
typedef struct tree *node;
int h(node root)
{
    if (!root)
        return 0;
    return root->height;
}
node newNode(int i)
{
    node x = new tree;
    x->left = x->right = NULL;
    x->height = 1;
    x->data = i;
    return x;
}
node leftRotate(node x)
{
    node y = x->right;
    node t = y->left;
    y->left = x;
    x->right = t;
    x->height = max(h(x->left), h(x->right)) + 1;
    y->height = max(h(y->left), h(y->right)) + 1;
    return y;
}
node rightRotate(node x)
{
    node y = x->left;
    node t = y->right;
    y->right = x;
    x->left = t;
    x->height = max(h(x->left), h(x->right)) + 1;
    y->height = max(h(y->left), h(y->right)) + 1;
    return y;
}
int getBFactor(node root)
{
    if (!root)
        return 0;
    return h(root->left) - h(root->right);
}
node insert(node root, int i)
{
    if (!root)
        return newNode(i);
    if (i < root->data)
        root->left = insert(root->left, i);
    else if (i > root->data)
        root->right = insert(root->right, i);
    else
        return root;
    root->height = max(h(root->left), h(root->right)) + 1;
    int BF = getBFactor(root);
    if (BF > 1 && i < root->left->data)
    {
        return rightRotate(root);
    }
    if (BF < 1 && i > root->right->data)
    {
        return leftRotate(root);
    }
    if (BF > 1 && i > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (BF < -1 && i < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
void inorder(node root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    node root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 4);
    root = insert(root, 10);
    inorder(root);
    cout << endl;
    return 0;
}
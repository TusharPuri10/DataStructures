#include<iostream>
using namespace std;
class tree{
    public:
        int data;
        class tree* left;
        class tree* right;
        tree(int data)
        {
            this->data = data;
        }
};

void preorder_print(tree* n)//O(n) where n is the number of nodes
{
    if(n == NULL)
        return;
    cout << n->data << endl;
    preorder_print(n->left);
    preorder_print(n->right);
}

void inorder_print(tree *n)
{
    if(n == NULL)
        return;
    inorder_print(n->left);
    cout << n->data << endl;
    inorder_print(n->right);
}

void postorder_print(tree *n)
{
    if(n == NULL)
        return;
    postorder_print(n->left);
    postorder_print(n->right);
    cout << n->data << endl;
}

int main()
{
    tree* root = new tree(12);
    root->left = new tree(6);

    root->right = new tree(2);
    root->right->left = NULL;
    root->right->right = NULL;

    root->left->left = new tree(3);
    root->left->left->left = NULL;
    root->left->left->right = NULL;

    root->left->right = new tree(2);
    root->left->right->left = NULL;
    root->left->right->right = NULL;

    cout << "preorder_print\n";
    preorder_print(root);//root->left->right

    cout << "inorder_print\n";
    inorder_print(root);//left->root->right

    cout << "postorder_print\n";//left->right->root
    postorder_print(root);
}
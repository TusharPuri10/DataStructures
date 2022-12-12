#include <stdio.h>
#include <stdlib.h>
typedef struct tree_node
{
    struct tree_node* left;
    int info;
    struct tree_node* right;
}tree_node;

tree_node* insert_node(tree_node* root,int num)
{
    if(root == NULL)
    {
        tree_node* new_node = (tree_node*) malloc(sizeof(tree_node));
        new_node->left = NULL;
        new_node->info = num;
        new_node->right = NULL;
        return new_node;
    }
    else
    {
        if(root->info < num)
        {
            root->right=insert_node(root->right,num);
        }
        else if(num < root->info)
        {
            root->left=insert_node(root->left,num);
        }
        else
        {
            printf("There can be only one key of %d and it already exist in node of this tree_node",num);
        }
        return root;
    }
}
void preorder_print(tree_node* n)//O(n) where n is the number of nodes
{
    if(n == NULL)
        return;
    printf(", %d",n->info);
    preorder_print(n->left);
    preorder_print(n->right);
}
void inorder_print(tree_node* n)
{
    if(n == NULL)
        return;
    inorder_print(n->left);
    printf(", %d",n->info);
    inorder_print(n->right);
}
void postorder_print(tree_node* n)
{
    if(n == NULL)
        return;
    postorder_print(n->left);
    postorder_print(n->right);
    printf(", %d",n->info);
}
int main()
{
    tree_node* root = NULL;
    while(1)
    {
        int choice;
        printf("Options:\n");
        printf("1. Insert a new node\n");
        printf("2. preorder print tree_node\n");//root->left->right
        printf("3. inorder print tree_node\n");//left->root->right
        printf("4. postorder print tree_node\n");//left->right->root
        printf("5.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            int num;
            printf("Enter the value of the new node:");
            scanf("%d", &num);
            root = insert_node(root,num);
            break;
        case 2:
            preorder_print(root);
            break;
        case 3:
            inorder_print(root);
            break;
        case 4:
            postorder_print(root);
            break;
        case 5:
            exit(0);
        default:
            printf("Wrong input\n");
            break;
        }

    }

}
#include <stdio.h>
#include <stdlib.h>
typedef struct tree_type
{
    struct tree_type* left;
    int info;
    struct tree_type* right;
}tree_type;
void insert_tree(tree_type **root, tree_type* new_node)
{
    if(*root == NULL)
    {
        *root = new_node;
    }
    else
    {
        if((*root)->info < new_node->info)
        {
            insert_tree(&((*root)->right), new_node);
        }
        else if((*root)->info > new_node->info)
        {
            insert_tree(&((*root)->left), new_node);
        }
        else
        {
            printf("same key not allowed\n");
        }
    }
}
void inorder_traversal(tree_type *root)
{
    if(root == NULL)
    {
        return;
    }
    inorder_traversal(root->left);
    printf("%d,",root->info);
    inorder_traversal(root->right);
}
void preorder_traversal(tree_type *root)
{
    if(root == NULL)
    {
        return;
    }
    printf("%d,",root->info);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}
void postorder_traversal(tree_type *root)
{
    if(root == NULL)
    {
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d,",root->info);
}
void delete_node(tree_type* root,int key);
{
    if(()&&(root->right == NULL) && (root->left == NULL))
    {
        root = NULL
    }

}
int main()
{
    tree_type *root = NULL;
    while(1)
    {
        printf("Options:\n");
        printf("1. insert\n");
        printf("2. inorder_traversal\n");
        printf("3. postorder_traversal\n");
        printf("4. preorder_traversal\n");
        printf("5. delete\n");
        printf("6. exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int value;
            tree_type *new_node = (tree_type*) malloc(sizeof(tree_type));
            printf("Enter the value you want to insert:");
            scanf("%d", &value);
            new_node->info = value;
            new_node->left = NULL;
            new_node->right = NULL;
            insert_tree(&root, new_node);
            break;
        }
        case 2:
            inorder_traversal(root);
            break;
        case 3:
            postorder_traversal(root);
            break;
        case 4:
            preorder_traversal(root);
            break;
        case 5:
        {}
            int key;
            scanf("%d", &key);
            delete_node(root,key);
        }
        case 6:
            exit(0);
        default:
            printf("wrong input try again\n");
            break;
        }
    }
}
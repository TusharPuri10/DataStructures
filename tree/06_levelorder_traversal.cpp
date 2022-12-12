#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef struct tree_type
{
    struct tree_type* left;
    int info;
    struct tree_type* right;
}tree_type;

void insert_node(tree_type** root,tree_type* temp)
{
    if(*root == NULL)
    {
        *root = temp;
    }
    else
    {
        if((*root)->info < temp->info)
        {
            insert_node(&((*root)->right),temp);
        }
        else if((*root)->info > temp->info)
        {
            insert_node(&((*root)->left),temp);
        }
        else
        {
            printf("There can be only one key of %d and it already exist in node of this tree_node",temp->info);
        }
    }
}
void printvector(vector<vector<tree_type*> > a)
{
    for(int i=0; i<a.size(); i++)
    {
        for(int j=0; j<a[i].size(); j++)
            cout<<a[i][j]->info<<" ";
        cout<<endl;
    }
}
void levelorder_traversal(tree_type* root)
{
    vector<vector<tree_type*>> a;
    if(root==NULL)
        printvector(a);
    else
    {
        queue<tree_type*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            vector<tree_type*> level;
            for(int i = 0; i < size;i++)
            {
                tree_type* node = q.front();
                q.pop();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                level.push_back(node);
            }
            a.push_back(level);
        }
        printvector(a);
    }
    
}
int main()
{
    tree_type* root = NULL;
    while(1)
    {
        int choice;
        printf("Options:\n");
        printf("1. Insert a new node\n");
        printf("2. levelorder traversal\n");
        printf("3.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {// therse paranthesis are important because new variable is getting declared in case 1
            int num;
            printf("Enter the value of the new node:");
            scanf("%d", &num);
            tree_type* new_node = (tree_type*) malloc(sizeof(tree_type));
            new_node->left = NULL;
            new_node->info = num;
            new_node->right = NULL;
            insert_node(&root,new_node);
            break;
        }
        case 2:
            levelorder_traversal(root);
            break;
        case 3:
            exit(0);
        default:
            printf("wrong input try again\n");
        }

    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
}node;

node *tree;

node* createtree(node *tree, int data)
{
    if (tree == NULL)
    {
        node *temp;
        temp= (node*)malloc(sizeof(node));
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }

    if (data<(tree->data))
    {
        tree->left = createtree(tree->left, data);
    }

    else if (data>tree->data)
    {
        tree->right = createtree(tree->right, data);
    }
    return tree;
}

node* search(node *tree, int data)
{
    if(tree== NULL)
        printf("\nElement not found");
    else if(data<tree->data)
    {
        tree->left=search(tree->left, data);
    }
    else if(data>tree->data)
    {
        tree->right=search(tree->right, data);
    }
    else
        printf("\nElement found is: %d", tree->data);
    return tree;
}

void inorder(node *tree)
{
    if(tree!=NULL)
    {
        inorder(tree->left);
        printf("%d\t", tree->data);
        inorder(tree->right);
    }
}

void preorder(node *tree)
{
    if(tree!=NULL)
    {
        printf("%d\t", tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }
}

void postorder(node *tree)
{
    if(tree!=NULL)
    {
        postorder(tree->left);
        postorder(tree->right);
        printf("%d\t", tree->data);
    }
}

node* findMin(node *tree)
{
    if(tree==NULL)
    {
        return NULL;
    }
    if(tree->left)
        return findMin(tree->left);
    else
        return tree;
}

node* del(node*tree, int data)
{
    node *temp;
    if(tree==NULL)
    {
        printf("\nElement not found");
    }
    else if(data<tree->data)
    {
        tree->left = del(tree->left, data);
    }
    else if(data>tree->data)
    {
        tree->right = del(tree->right, data);
    }
    else
    {
        if(tree->right&&tree->left)
        {
            temp = findMin(tree->right);
            tree -> data = temp->data;
            tree -> right = del(tree->right,temp->data);
        }
        else
        {
            temp = tree;
            if(tree->left==NULL)
                tree = tree->right;
            else if(tree->right==NULL)
                tree = tree->left;
            free(temp);
        }
    }
    return tree;
}

int main()
{
    int data, ch, i, n;
    node *root=NULL;
    do
    {
        printf("\n1.Insertion in Binary Search Tree");
        printf("\n2.Search Element in Binary Search Tree");
        printf("\n3.Delete Element in Binary Search Tree");
        printf("\n4.Inorder\n5.Preorder\n6.Postorder\n7.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: printf("\nEnter the no.of element to be inserted: " );
                    scanf("%d", &n);
                    printf("\nEnter the values to create BST like(6,9,5,2,8,15,24,14,7,8,5,2)\n");
                    for(i=0; i<n; i++)
                    {
                        scanf("%d", &data);
                        root=createtree(root, data);
                    }
                    break;

            case 2: printf("\nEnter the element to search: ");
                    scanf("%d", &data);
                    root=search(root, data);
                    break;

            case 3: printf("\nEnter the element to delete: ");
                    scanf("%d", &data);
                    root=del(root, data);
                    break;

            case 4: printf("\nInorder Traversal: \n");
                    inorder(root);
                    break;

            case 5: printf("\nPreorder Traversal: \n");
                    preorder(root);
                    break;

            case 6: printf("\nPostorder Traversal: \n");
                    postorder(root);
                    break;

            case 7: printf("EXIT");
                    break;

            default:printf("\nWrong option");

            break;
        }
    }while(ch!=7);
}

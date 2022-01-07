#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct Node
{
    int data;
    struct Node *next;
}node;


node *createNode(int);
node *createList(node *);
void display(node *);
node *insertBeg(node *);
node *insertEnd(node *);
node *insertRandom(node *);
node *deleteBeg(node *);
node *deleteEnd(node *);
node *deleteRandom(node *);
node *Search(node *);
node *reverse(node *);

int main(int argc, char *argv[])
{
    node *head = NULL;
	int option;

    do
    {
         printf("\n\n **MAIN MENU **");
         printf("\n 1: Create a list");
         printf("\n 2: Display the list");
         printf("\n 3: Add a node at the beginning");
         printf("\n 4: Add a node at the end");
         printf("\n 5: Add a node at given position");
         printf("\n 6: Delete a node from the beginning");
         printf("\n 7: Delete a node from the end");
         printf("\n 8: Delete a node from given position");
         printf("\n 9: Search a node");
         printf("\n 10: Reverse of the list");
         printf("\n 11: End!!!");

         printf("\nEnter your option: ");
         scanf("%d", &option);

         switch(option)
         {
             case 1: head = createList(head);
                     break;

             case 2: display(head);
                     printf("\n\n");
                     break;

             case 3: head = insertBeg(head);
                     break;

             case 4: head = insertEnd(head);
                     break;

             case 5: head = insertRandom(head);
                     break;

             case 6: head = deleteBeg(head);
                     break;

             case 7: head = deleteEnd(head);
                     break;

             case 8: head = deleteRandom(head);
                     break;

             case 9: head = Search(head);
                     break;

             case 10: head = reverse(head);
                     break;

             case 11: printf("\nEnd!!!");
                      break;

            default: printf("\nInvalid choice!!!");
         }

    }
    while(option!=11);
}

//CREATING A NODE
node *createNode(int val)
{
    node  *newnode;
    newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

//CREATING A LIST
node *createList(node *head)
{
    node *newnode, *p;
    int v;
        printf("Enter the value: ");
        scanf("%d", &v);

        newnode=createNode(v);

        if(head==NULL)
        {
            head=newnode;
        }

        else
        {
            p=head;

            while(p->next)
                p = p->next;

            p->next=newnode;
        }
        printf("\nValue inserted.");
    return head;
}

void display(node *p)
{
    while(p!=NULL)
    {
        printf("\t%d", p->data);
        p = p->next;
    }
}

//INSERT AT BEGINNING
node *insertBeg(node *head)
{
    int v;
    node *newnode;

    printf("\nEnter the value: ");
    scanf("%d", &v);

    newnode=createNode(v);

    if(head==NULL)
    {
        head =newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
    return head;
}

//INSERT AT THE END
node *insertEnd(node *head)
{
    int v;
    node *newnode, *p;

    printf("\nEnter the value: ");
    scanf("%d",&v);

    newnode = createNode(v);
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        p=head;
        while(p->next)
            p=p->next;

        p->next=newnode;
    }
    return head;
}

//INSERT AT A RANDOM POSITION
node *insertRandom(node *head)
{
    int v,data;
    node *newnode, *p;

    printf("\nEnter the value: ");
    scanf("%d", &v);

    newnode = createNode(v);

    if(head==NULL)
    {
        head = newnode;
        return NULL;
    }
    else
    {
        printf("\nEnter node data after which you want to insert new data: ");
        scanf("%d",&data);

        p=head;

        while(p!=NULL && p->data!=data)
        {
            p=p->next;
            if(p==NULL)
            {
                printf("\nInsertion not possible");
                return head;
            }
        }
        newnode->next = p->next;
        p->next = newnode;
    }

    return head;
}

//DELETE AT BEGINNING
node *deleteBeg(node *head)
{
    node *tmp;
    if(head == NULL)
    {
        printf("\nList is empty. ");
        return NULL;
    }
    tmp = head;
    head = head->next;
    free(tmp);
    return head;
}

//DELETE AT END
node *deleteEnd(node *head)
{
    node *temp,*p;
    if(head==NULL)
    {
        printf("\nThe list is empty");
        return NULL;
    }
    if(head->next==NULL)
    {
        free(head);
        return NULL;
    }
    temp = head;
     while(temp->next != NULL)
     {
         p=temp;
         temp=temp->next;
     }

     free(temp);
     p->next=NULL;

     return head;
}

//DELETING AT RANDOM
node *deleteRandom(node *head)
{
    node *temp, *p;
    int val;
    printf("\nEnter value: ");
    scanf("%d", &val);

    if(head==NULL)
    {
        printf("\nList is empty.");
        return NULL;
    }

    if(head->data==val)
    {
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    p=head;

    while(p->next!=NULL && p->data!=val)
        p=p->next;

    if(p->next==NULL)
    {
        printf("\nNode with value %d not found", val);
        return head;
    }

    temp = p->next;
    p->next=temp->next;
    free(temp);
    return head;
}

//SEARCHING
node *Search(node *head)
{
    node *p;
    int i=0,flag,item;

    if(head==NULL)
    {
        printf("\nList is empty");
        return NULL;
    }

    else
    {
        p=head;
        printf("\nEnter item which you want to search: ");
        scanf("%d",&item);
        while (p!=NULL)
        {
            if(p->data==item)
            {
                printf("item found at location %d ",i+1);
                flag=0;
            }
            i++;
            p=p-> next;
        }

        if(flag!=0)
        {
           printf("Item not found\n");
        }
    }
         return head;
}

//REVERSING LIST
node *reverse(node *head)
{
    node *t1,*t2,*temp;
    t1=t2=NULL;

    if(head==NULL)
        printf("\nList is empty");

    else
    {
        while(head!=NULL)
        {
            t2=head->next;
            head->next = t1;
            t1 = head;
            head = t2;
        }

        head = t1;
        temp = head;
        printf("\nReversed linked list is: ");

        while(temp!=NULL)
        {
            printf("\n%d", temp->data);
            temp = temp->next;
        }
    }
    return head;
}

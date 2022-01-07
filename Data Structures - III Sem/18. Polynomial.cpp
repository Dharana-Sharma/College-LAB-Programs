#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Node
{
	int coef, exp;
	struct Node *next;
}node;

node* create_node(int,int);
node* createpoly(node*);
node* insert(node*, node*);
node* add(node*, node*);
int compute(node*, int);
void display(node*);

int main()
{
	node *poly1=NULL , *poly2=NULL , *poly3 = NULL;
	int ch;
	int x;
	int res;
	
	printf("             MENU\n");
	printf("---------------------------------------\n");
	printf("01. Compute value of a polynomial 1\n");
	printf("02. Compute value of a polynomial 2\n");
	printf("03. Display Polynomial 1\n");
	printf("04. Display Polynomial 2\n");
	printf("05. Add two polynomails\n");
	printf("06. EXIT\n");
	
	
	printf("\n Create First Polynomial: \n");
	poly1 = createpoly(poly1);
	printf("\n Create Second Polynomial: \n");
	poly2 = createpoly(poly2);
	
	do
	{
		printf("\n\nChoose your operation: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: printf("Enter value of x: ");
			        scanf("%d",&x);
			        res = compute(poly1, x);
			        display(poly1);
			        printf(" = %d",res);
					break;
			case 2: printf("Enter value of x: ");
			        scanf("%d",&x);
			        res = compute(poly2, x);
			        display(poly2);
			        printf(" = %d",res);
					break;
			case 3: printf("First polynomial:\n");
			        display(poly1);
			        break;
			case 4: printf("Second polynomial:\n");
			        display(poly2);
			        break;
			case 5: printf("Sum of Polynomials: \n");
			        poly3 = add(poly1 , poly2);
			        display(poly3);
			        break;
			case 6: break;
			default: printf("\n...........INVALID CHOICE...........\n");
		          printf("ENTER A NUMBER FROM 1 TO 6\n");
	    }
	}while(ch!=6);
	printf("\n.....EXIT......\n");
}
node* create_node(int c, int e)
{
	node *n_node;
	n_node=(node *)malloc(sizeof(node));
	if(n_node)
	{
		n_node->coef = c;
		n_node->exp = e;
		n_node->next = NULL;
	}
	return n_node;
}
node* createpoly(node *poly)
{
	node *newnode =NULL;
	int n;
	int i=1;
	int c, e;
	printf("Enter no. of terms: ");
	scanf("%d",&n);
	
	while(n--)
	{
		printf("Enter Coefficient and exponent %d: ",i++);
		scanf("%d%d",&c,&e);
		
		newnode = create_node(c,e);
		
		poly = insert(newnode,poly);
	}
	return poly;
}
node* insert(node *n,node *poly)
{
	node *p=poly;
	if(p==NULL)
	{
		poly = n;
		return poly;
	}
	if(poly->exp <= n->exp)
	{
		if(poly->exp == n->exp)
		   poly->coef += n->coef;
		else
		{
			n->next=poly;
			poly=n;
		}
		return poly;
    }
    while(p->next && p->next->exp > n->exp)
        p = p->next;
    if(p->next && p->next->exp == n->exp)
       p->next->coef += n->coef;
    else
    {
    	n->next = p->next;
    	p->next = n;
	}
	return poly;
}

node* add(node *p1, node *p2)
{
	node *p3 =NULL,*n=NULL;
	int c,e;
	
	while(p1 && p2)
	{
		if(p1->exp > p2->exp)
		{
			c = p1->coef;
			e = p1->exp;
			p1 = p1->next;
		}
		else if(p2->exp > p1->exp)
		{
			c = p2->coef;
			e = p2->exp;
			p2 = p2->next;
		}
		else
		{
			c = p1->coef + p2->coef;
			e = p1->exp;
			p1 = p1->next;
			p2 = p2->next;
		}
		n = create_node(c,e);
		p3 = insert(n,p3);
	}
	while(p1 || p2)
	{
		if(p1)
		{
			c = p1->coef;
			e = p1->exp;
			p1 = p1->next;
		}
		else
		{
			c = p2->coef;
			e = p2->exp;
			p2 = p2->next;
		}
		n = create_node(c,e);
		p3 = insert(n,p3);
	}
	return p3;
}
int compute(node *p,int x)
{
	int val = 0;
	while(p)
	{
		val += p->coef * pow(x , p->exp);
		p=p->next;
	}
	return val;
}

void display (node *p)
{
	while(p)
	{
		if(p->coef < 0)
		    printf("- ");
		if(p->exp == 0)
		    printf("%d ",abs(p->coef));
		else if (p->exp == 1)
		    printf("%dx ",abs(p->coef));
		else
		    printf("%dx^%d ",abs(p->coef), p->exp);
		if(p->next && p->next->coef >= 0)
		    printf("+ ");
		p=p->next;
	}
}

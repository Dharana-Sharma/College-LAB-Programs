#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void max_heapify(int a[],int i,int n)
{
	int child=2*i;
	if(child<=n) 
	{
		if(child+1<=n &&  a[child]<a[child+1])
		{
		 	child=child+1;
		}
		if(a[child]>a[i])
		{
			swap(&a[child],&a[i]);
			max_heapify(a,child,n);
		}
	}
}
void build_max_heap(int a[],int n)
{
	int i;
	for(i=n/2;i>=1;i--)
	{
		max_heapify(a,i,n);
	}
}
void heap_sort(int a[],int n)
{
	int i;
	build_max_heap(a,n);
	for(i=n;i>=2;i--)
	{
		swap(&a[1],&a[i]);
		max_heapify(a,1,i-1);
	}
}
void print(int a[],int n)
{
	int i;
	printf("SORTED: ");
	for(i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
	}
}
int main()
{
	int i,n,a[10];
	printf("ENTER THE NUMBER VALUES TO BE SORTED:");
	scanf("%d",&n);
	printf("ENTER THE VALUES TO BE SORTED:");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	heap_sort(a,n);
	print(a,n);
	return 0;
}


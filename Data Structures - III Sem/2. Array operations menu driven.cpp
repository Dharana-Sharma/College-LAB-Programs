#include<stdio.h>
#include<process.h>
void display(int arr[],int n) {
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}
int search(int arr[],int n,int x) {
	int i;
	for(i=0;i<n;i++)
		if(arr[i]==x)
			return i;
	return -1;
}
void swap(int *a, int *b) {
    int temp=*a;
    	*a=*b;
    	*b=temp;
}
void reverse(int arr[],int n) {
	int i,t;
	for(i=0;i<n/2;i++) {
		swap(&arr[i],&arr[n-i-1]);
	}
}
void sort(int arr[], int n) {
	int i,j;
    for(i=0;i<n-1;i++)
    {
    	for(j=0;j<n-i-1;j++)
        {
        	if(arr[j]>arr[j+1])
                swap(&arr[j],&arr[j+1]);
        }
    }
}
void insertBeginning(int arr[],int *n,int x) {
	int i;
	for(i=((*n)-1);i>=0;i--)
		arr[i+1]=arr[i];
	arr[0]=x;
	(*n)++;
}
void insertEnd(int arr[],int *n,int x) {
	arr[*n]=x;
	(*n)++;
}
void deleteBeginning(int arr[],int *n) {
	int i;
	for(i=0;i<(*n);i++)
		arr[i]=arr[i+1];
	(*n)--;
}
void deleteEnd(int arr[],int *n) {
	(*n)--;
}
void insertPosition(int arr[],int *n,int x,int pos) {
	int i;
	for(i=(*n)-1;i>=pos-1;i--)
		arr[i+1]=arr[i];
	arr[pos-1]=x;
	(*n)++;
}
void deletePosition(int arr[],int *n,int pos) {
	int i;
	for(i=pos-1;i<(*n);i++)
		arr[i]=arr[i+1];
	(*n)--;
}
int main() {
	int arr[10],n,c,i,s,pos;
	char ch;
	printf("Enter the no of elements in the array:");
	scanf("%d",&n);
	printf("Enter the elements of the array:");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	do {
		printf("_____MENU____\n");
		printf("1.Display the array\n");
		printf("2.Search an Element in the array\n");
		printf("3.Reverse an Array\n");
		printf("4.Sort the array\n");
		printf("5.Insert an element at the beginning\n");
		printf("6.Insert an element at the end\n");
		printf("7.Insert an element by position\n");
		printf("8.Delete an element from the beginning\n");
		printf("9.Delete an element from the end\n");
		printf("10.Delete an element by position\n");
		printf("11.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&c);
		switch(c) {
			case 1: printf("\n\tThe Array is:");
					display(arr,n);
					printf("\n\n");
					break;
					
			case 2: {
					printf("\n\tEnter the element to be searched:");
					scanf("%d",&s);
					int ans=search(arr,n,s);
					if(ans==-1)
						printf("\n\tThe Element is not present in the Array");
					else
						printf("\n\tThe element is present at %d Index\n",ans);
					printf("\n\n");
					break;
					}
			case 3: reverse(arr,n);
					printf("\n\tThe array after reversal:");
					display(arr,n);
					printf("\n\n");
					break;
					
			case 4: sort(arr,n);
					printf("\n\tThe Array after sorting:");
					display(arr,n);
					printf("\n\n");
					break;
					
			case 5: printf("\n\tEnter the element to be inserted at the beginning:");
					scanf("%d",&s);
					insertBeginning(arr,&n,s);
					printf("\n\tThe Array after insertion at the Beginning:");
					display(arr,n);
					printf("\n\n");
					break;
					
			case 6: printf("\n\tEnter the element to be inserted at the end:");
					scanf("%d",&s);
					insertEnd(arr,&n,s);
					printf("\n\tThe Array after insertion at the End:");
					display(arr,n);
					printf("\n\n");
					break;
					
			case 7: printf("\n\tEnter the position where the element is to be inserted:");
					scanf("%d",&pos);
					printf("\n\tEnter the element to be inserted:");
					scanf("%d",&s);
					insertPosition(arr,&n,s,pos);
					printf("\n\tThe Array after insertion:");
					display(arr,n);
					printf("\n\n");
					break;
					
			case 8: deleteBeginning(arr,&n);
					printf("\n\tThe Array after deletion at the Beginning:");
					display(arr,n);
					printf("\n\n");
					break;
					
			case 9: deleteEnd(arr,&n);
					printf("\n\tThe Array after deletion at the End:");
					display(arr,n);
					printf("\n\n");
					break;
					
			case 10: printf("\n\tEnter the position where the element is to deleted:");
					scanf("%d",&pos);
					deletePosition(arr,&n,pos);
					printf("\n\tThe Array after deletion:");
					display(arr,n);
					printf("\n\n");
					break;
					
			case 11: printf("\t\tEXIT!!");
					exit(0);
		}
	}while(1);
  return 0;
}
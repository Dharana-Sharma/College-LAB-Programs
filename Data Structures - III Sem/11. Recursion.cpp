#include<stdio.h>
#include<process.h>
#include<string.h>

void dec_bin(int );
int fact(int );
int fibo(int);
int sum(int);
void display_asc(int);
void display_desc(int);
void rev_str(char *str);
void toh(int ,char,char,char);

int main()
{
	int n,choice,i,m=0; 
	char *str;
	char source='A',temp='B',dest='C';
	
	printf("\n******MENU*******");
	printf("\n1.Decimal to Binary ");
	printf("\n2.Factorial ");
	printf("\n3.Fibonacci Series ");
	printf("\n4.Sum of n natural numbers ");
	printf("\n5.Display n natural no in ascending order ");
	printf("\n6.Display n natural no in descending order ");
	printf("\n7.String Reversal ");
	printf("\n8.Tower of Hanoi ");
	printf("\n9.Exit");
	printf("\n***************");
	
	while(1)
	{
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("\nEnter decimal number: ");
					scanf("%d",&n);
					printf("\nIn Binary: ");
					dec_bin(n);
					break;
			case 2: printf("\nEnter number to find factorial: ");
					scanf("%d",&n);
					printf("\nFactorial is:%d ",fact(n));
					break;
			case 3: printf("\nEnter the no of elements to show: ");
					scanf("%d",&n);
					printf("\nFibonacci series is:");
					for(i=0;i<=n;i++)
					{
						printf(" %d",fibo(m));
						m++;
					}
					break;
			case 4: printf("\nEnter the limit to find sum of: ");
					scanf("%d",&n);
					printf("\nSum is: %d",sum(n));
					break;
			case 5: printf("\nEnter limit to display numbers in ascending order: ");
					scanf("%d", &n);
					//display_asc( n);
					printf("\n Natural no in ascending order is: ",n);
					display_asc(n);
					break;
			case 6: printf("\nEnter limit to display numbers in descending order: ");
					scanf(" %d", &n);
					printf("\n Natural no in descending order is: ",n);
					display_desc(n);
					break;
			case 7: printf("\nEnter string : ");
					scanf("%s",&str);
					printf("\nReversed string is: ");
					rev_str(str);
					break;
			case 8: printf("\nEnter number of disks: ");
					scanf("%d",&n);
					printf("\nSequence is: ");
					toh(n,source,temp,dest);
					break;
			case 9: printf("\nEXIT!!");
					exit(0);
			default:printf("\nWrong choice");
			
		}
		printf("\n");	
	}
	return 0;
}
void dec_bin(int n)
{
	if(n==0)
		return;
	else
	{ 
		dec_bin(n/2);
		printf("%d",n%2);
	}
}
int fact(int n)
{
	if(n==1)
		return 1;
	else
		return(n*fact(n-1));
}
int fibo(int n)
{
	if(n==0 || n==1)
		return n;
	else
		return(fibo(n-1)+fibo(n-2));
}
int sum(int n)
{
	if(n==0)
		return 0;
	else
		return(n+sum(n-1));
}
void display_asc(int n)
{
	if(n==0)
		return;
	else
		display_asc(n-1);
		printf(" %d",n);
}
void display_desc(int n)
{
	if(n==0)
		return;
	else
		printf(" %d",n);
		display_desc(n-1);
}
void rev_str(char *str)
{
	if(*str!='\0')
	{
		rev_str(str+1);
		printf("%c",*str);
	}
}
void toh(int n,char source,char temp,char dest)
{
	if(n==1)
	{
		printf("\nMove disk %d from %c to %c",n,source,dest);
		return;
	}
	else
	{
		toh(n-1,source,dest,temp);
		printf("\nMove disk %d from %c to %c",n,source,dest);
		toh(n-1,temp,source,dest);
	}
	
}

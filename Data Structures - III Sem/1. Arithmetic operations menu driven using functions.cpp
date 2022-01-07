#include<stdio.h>
#include<conio.h>
#include<process.h>

int add(int x,int y)
	{
		return(x+y);
	}
	
int sub(int x,int y)
	{
		return(x-y);
	}
	
int mul(int x,int y)
	{
		return(x*y);
	}
	
int div(int x,int y)
	{
		return(x/y);
	}
	
int main()
{
   int x,y,ans,ch;
   printf("Enter the First Number : ");
   scanf("%d",&x);
   printf("\nEnter the Second Number : ");
   scanf("%d",&y);
   
   while(1)
   {
	   printf("\n----Menu----\n1.Addition\n2.Subtraction\n3.Multiply\n4.Divide\n5.Exit");
	   printf("\nEnter your choice : ");
	   scanf("%d",&ch);
   
   switch(ch)
   {
     case 1:  ans = add(x,y);
              printf("\nThe addition of 2 numbers is : %d",ans);
              break;
     case 2:
             ans = sub(x,y);
             printf("\nThe differnce of 2 numbers is : %d",ans);
             break;
     case 3:
             ans = mul(x,y);
             printf("\nThe product of 2 numbers is : %d",ans);
             break;
     
	 case 4: ans = div(x,y);
             printf("\nThe division of 2 numbers is : %d",ans);
             break;
              
    case 5:	 printf("\nExit");
             exit(0);
             
    default:printf("\nInvalid Choice\n");
            break;
    }
  }
  return 0;
}
/*Enter the First Number : 10

Enter the Second Number : 5

----Menu----
1.Addition
2.Subtraction
3.Multiply
4.Divide
5.Exit
Enter your choice : 1

The addition of 2 numbers is : 15
----Menu----
1.Addition
2.Subtraction
3.Multiply
4.Divide
5.Exit
Enter your choice : 2

The differnce of 2 numbers is : 5
----Menu----
1.Addition
2.Subtraction
3.Multiply
4.Divide
5.Exit
Enter your choice : 3

The product of 2 numbers is : 50
----Menu----
1.Addition
2.Subtraction
3.Multiply
4.Divide
5.Exit
Enter your choice : 4

The division of 2 numbers is : 2
----Menu----
1.Addition
2.Subtraction
3.Multiply
4.Divide
5.Exit
Enter your choice : 5

Exit
*/
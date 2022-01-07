#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#define MAX 5

typedef struct Stack
{
    int o_st[MAX];
    int top;
}s;

int isfull(s st)
{
    if(st.top==MAX-1)
    {
        return 1;
    }
    return 0;
}

int isempty(s st)
{
    if(st.top==-1)
    {
        return 1;
    }
    return 0;
}

void push(s*st, int value)
{
    if(isfull(*st))
    {
        printf("\nSTACK OVERLOADED");
        return;
    }
    st->o_st[++st->top]=value;
   
}

int pop(s*st)
{
    if(isempty(*st))
    {
        printf("\nSTACK UNDERFLOW");
        return -1;
    }
    return st->o_st[st->top--];
}


int calculation(char exp[MAX])
{
    int i, left, right;
    s st;
    st.top=-1;

    for(i=0 ; exp[i]!= '\0';i++)
    {
        if(isdigit(exp[i]))
        {
            push(&st, exp[i]-48);

        }
        else
        {
            right=pop(&st);
            left=pop(&st);

            switch (exp[i])
            {
            case '+': push(&st, left+right);
                      break;

            case '-': push(&st, left-right);
                      break;

            case '*': push(&st, left*right);
                      break;

            case '/': push(&st, left/right);
                      break;
            
            default: printf("INVALID CHOICE");
                    break;
            }
        }
    }
    return pop(&st);
}

int main()
{
    char exp[MAX];
    printf("ENTER POSTFIX EXPRESSION:");
    scanf("%s", exp);
    if (strlen(exp)>MAX)
    {
        printf("INVALID EXPRESSION");
    }
    else
        printf("RESULT:%d", calculation(exp));

    return 0;
}
/* Stack Operations */
#include<stdio.h>
#include<stdlib.h>
#define maxsize 4

void push(int s[], int *ptop, int ele)
{
    if (*ptop == (maxsize - 1))
        printf("\n\nstack is overflow");
    else
        s[++(*ptop)] = ele;
}

int pop(int s[], int *ptop)
{
    return s[(*ptop)--];
}

void palindrome(int s[], int top)
{
    int flag = 1, i, j;
    j = top;
    for (i = 0; i < top / 2; i++, j--)
        if (s[i] != s[j])
        {
            flag = 0;
            break;
        }
    if (flag == 1)
        printf("stack contents are palindrome");
    else
        printf("stack contents are not palindrome");
}

void display(int s[], int top)
{
    int i;
    if (top == -1)
    {
        printf("\n stack is empty");
        return;
    }
    else
    {
        printf("\n the stack contents are");
        for (i = top; i >= 0; i--)
            printf("\n[%d]", s[i]);
    }
}

void main()
{
    int s[maxsize], item, ch, top = -1;
    while (1)
    {
        printf("\n----------->MAIN MENU<	\n");
        printf("\n1---------->PUSH into the stack<	");
        printf("\n2---------->POP from the stack<	");
        printf("\n3---------->PALINDROME check using stack<	");
        printf("\n4----------> DISPLAY<	");
        printf("\n5---------->EXIT<	");
        printf("\n enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n Enter the element to be inserted");
            scanf("%d", &item);
            push(s, &top, item);
            break;
        case 2:
            if (top == -1)
                printf("\n stack under flow");
            else
            {
                item = pop(s, &top);
                printf("\n popped element is %d", item);
            }
            break;
        case 3:
            palindrome(s, top);
            break;
        case 4:
            display(s, top);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\n enter a valid choice");
        }
    }
}

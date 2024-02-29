#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 4

void insert(char q[], int *r, int *c)
{
    char item;
    if (*c == MAXSIZE)
    {
        printf("\n queue is full");
        return;
    }
    else
    {
        printf("enter the character to be inserted:");
        scanf(" %c", &item);
        *r = (*r + 1) % MAXSIZE;
        q[*r] = item;
        (*c)++;
    }
}

void deleteq(char q[], int *f, int *c)
{
    char item;
    if (*c == 0)
    {
        printf("\n queue is empty");
        return;
    }
    item = q[*f];
    printf("\n deleted item is: %c", item);
    *f = (*f + 1) % MAXSIZE;
    (*c)--;
}

void display(char q[], int f, int *c)
{
    int i;
    if (*c == 0)
        printf("\nqueue is empty");
    else
    {
        printf("\n contents of the queue are \n");
        for (i = 1; i <= *c; i++)
        {
            printf("%c \t", q[f]);
            f = (f + 1) % MAXSIZE;
        }
    }
}

int main()
{
    int ch, f = 0, r = -1, c = 0;
    char q[MAXSIZE];

    while (1)
    {
        printf("\n main menu");
        printf("\n1. insert");
        printf("\n2. delete");
        printf("\n3. display");
        printf("\n4. exit");
        printf("\n enter choice:");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert(q, &r, &c);
            break;
        case 2:
            deleteq(q, &f, &c);
            break;
        case 3:
            display(q, f, &c);
            break;
        case 4:
            exit(0);
        }
    }

    return 0;
}

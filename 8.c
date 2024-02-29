#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int ssn;
    char name[20];
    char desi[20];
    char dept[20];
    int sal;
    char ph[20];
    struct node *llink;
    struct node *rlink;
};

typedef struct node *NODE;

NODE insertfront(NODE first)
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));

    printf("Enter employee details:\n");
    printf("Enter SSN, Name, Dept, Designation, Salary, Phone No.:\n");
    scanf("%d", &temp->ssn);
    scanf("%s", temp->name);
    scanf("%s", temp->dept);
    scanf("%s", temp->desi);
    scanf("%d", &temp->sal);
    scanf("%s", temp->ph);

    if (first == NULL)
        return temp;

    temp->rlink = first;
    first->llink = temp;
    temp->llink = NULL;

    return temp;
}

NODE insertrear(NODE first)
{
    NODE temp, cur;
    temp = (NODE)malloc(sizeof(struct node));

    printf("\nEnter employee details:\n");
    printf("Enter SSN, Name, Dept, Designation, Salary, Phone No.:\n");
    scanf("%d", &temp->ssn);
    scanf("%s", temp->name);
    scanf("%s", temp->dept);
    scanf("%s", temp->desi);
    scanf("%d", &temp->sal);
    scanf("%s", temp->ph);

    if (first == NULL)
        return temp;

    cur = first;
    while (cur->rlink != NULL)
        cur = cur->rlink;

    cur->rlink = temp;
    temp->llink = cur;
    temp->rlink = NULL;

    return first;
}

NODE deletefront(NODE first)
{
    NODE temp;

    if (first == NULL)
    {
        printf("\nList is empty\n");
        return NULL;
    }

    if (first->rlink == NULL)
    {
        printf("\nEmployee details deleted - SSN: %d\n", first->ssn);
        free(first);
        return NULL;
    }

    temp = first->rlink;
    temp->llink = NULL;

    printf("\nEmployee details deleted - SSN: %d\n", first->ssn);
    free(first);

    return temp;
}

NODE deleterear(NODE first)
{
    NODE temp, cur;

    if (first == NULL)
    {
        printf("\nEmpty list\n");
        return NULL;
    }

    if (first->rlink == NULL)
    {
        printf("\nEmployee details deleted - SSN: %d\n", first->ssn);
        free(first);
        return NULL;
    }

    cur = first;
    while (cur->rlink != NULL)
        cur = cur->rlink;

    temp = cur->llink;
    printf("\nEmployee details deleted - SSN: %d\n", cur->ssn);
    temp->rlink = NULL;

    free(cur);

    return first;
}

void display(NODE first)
{
    NODE cur;
    int c = 0;

    if (first == NULL)
    {
        printf("\nList is empty\n");
        return;
    }

    cur = first;

    while (cur != NULL)
    {
        printf("\n%d\n%d\n%s\n%s\n%s\n%s\n", cur->ssn, cur->sal, cur->name, cur->dept, cur->desi, cur->ph);
        cur = cur->rlink;
        c++;
    }

    printf("\nNumber of employees: %d\n", c);
}

int main()
{
    NODE first;
    int ch;

    first = NULL;

    while (1)
    {
        printf("\n1. Insert Front\t2. Insert Rear\t3. Delete Front\n4. Delete Rear\t5. Display\t6. Exit");
        printf("\nEnter choice:");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            first = insertfront(first);
            break;
        case 2:
            first = insertrear(first);
            break;
        case 3:
            first = deletefront(first);
            break;
        case 4:
            first = deleterear(first);
            break;
        case 5:
            display(first);
            break;
        case 6:
            exit(0);
        }
    }

    return 0;
}

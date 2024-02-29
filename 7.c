#include<stdio.h>
#include<stdlib.h>

struct studentnode
{
    char usn[11];
    char name[30];
    char branch[5];
    int sem;
    char phno[11];
    struct studentnode *link;
};

typedef struct studentnode *NODE;

NODE getnode()
{
    NODE newnode;
    newnode = (NODE)malloc(sizeof(struct studentnode));
    if (newnode == NULL)
        return NULL;

    printf("\nEnter USN, Name, Branch, Sem, Ph.No:\n");
    scanf("%s%s%s", newnode->usn, newnode->name, newnode->branch);
    scanf("%d%s", &newnode->sem, newnode->phno);
    newnode->link = NULL;
    return newnode;
}

void display(NODE first)
{
    NODE cur;
    int count = 0;

    if (first == NULL)
        printf("\nEmpty list - no student data\n");
    else
    {
        cur = first;
        printf("\n \t\t Student Data\t\n");
        printf("\n USN \t NAME \t BRANCH \t SEM \t PH.NO");
        while (cur != NULL)
        {
            printf("\n%s \t %s\t %s\t %d\t %s\t", cur->usn, cur->name, cur->branch, cur->sem, cur->phno);
            cur = cur->link;
            count = count + 1;
        }
        printf("\nThe number of nodes in the list is %d", count);
    }
}

NODE insertfront(NODE first)
{
    NODE newnode;
    newnode = getnode();

    if (newnode == NULL)
        printf("Memory not available");
    else
    {
        newnode->link = first;
        first = newnode;
    }
    return first;
}

NODE insertrear(NODE first)
{
    NODE newnode, cur = first;
    newnode = getnode();

    if (newnode == NULL)
        return newnode;

    while (cur->link != NULL)
        cur = cur->link;

    cur->link = newnode;
    return first;
}

NODE deletefront(NODE first)
{
    NODE temp;

    if (first == NULL)
        printf("\nList is empty");
    else
    {
        temp = first;
        first = first->link;
        free(temp);
    }
    return first;
}

NODE deleterear(NODE first)
{
    NODE cur = first, prev = first;

    if (first == NULL)
    {
        printf("\nList is empty");
        return NULL;
    }

    if (first->link == NULL)
    {
        free(first);
        first = NULL;
    }
    else
    {
        while (cur->link != NULL)
        {
            prev = cur;
            cur = cur->link;
        }
        free(cur);
        prev->link = NULL;
    }
    return first;
}

NODE stacksimulation(NODE first)
{
    int ch;

    while (ch != 3)
    {
        printf("\nSLL used as stack");
        printf("\n1. Push (insert at front)\t2. Pop (delete at front)\t3. Exit");
        printf("\nEnter your choice:");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            first = insertfront(first);
            break;
        case 2:
            first = deletefront(first);
            break;
        case 3:
            return first;
        }
    }

    return first;
}

NODE createlist(NODE first)
{
    int i, n;

    printf("Enter the number of students to add to the list:");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        first = insertfront(first);

    return first;
}

int main()
{
    int ch;
    NODE first;
    first = NULL;

    printf("\n-------Student Database\t\n");

    while (1)
    {
        printf("\n1. Create\t2. Insert Front\t3. Insert Rear\t4. Delete Front");
        printf("\n5. Delete Rear\t6. Stack Simulation\t7. Display\t8. Exit");
        printf("\nEnter choice:");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            first = createlist(first);
            break;
        case 2:
            first = insertfront(first);
            break;
        case 3:
            first = insertrear(first);
            break;
        case 4:
            first = deletefront(first);
            break;
        case 5:
            first = deleterear(first);
            break;
        case 6:
            first = stacksimulation(first);
            break;
        case 7:
            display(first);
            break;
        case 8:
            exit(0);
        }
    }

    return 0;
}

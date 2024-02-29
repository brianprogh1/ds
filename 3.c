#include <stdio.h>
#include <stdlib.h>

#define maxsize 4

int push(int s[], int *top) {
    int ele;
    if (*top == (maxsize - 1)) {
        printf("\n\nStack is overflow");
        return -1;  // Indicate failure to push
    } else {
        printf("\nEnter an element to be pushed: ");
        scanf("%d", &ele);
        s[++(*top)] = ele;
        return 0;  // Indicate successful push
    }
}

int pop(int s[], int *top) {
    int ele;
    ele = s[(*top)--];
    return ele;
}

void palindrome(int v[], int top) {
    int flag = 0, i;
    for (i = 0; i < (top + 1); i++) {
        if (v[i] == pop(v, &top))
            flag = 1;
        else {
            flag = 0;
            break;
        }
    }
    if (flag)
        printf("Stack contents are palindrome\n");
    else
        printf("Stack contents are not palindrome\n");
}

void display(int s[], int top) {
    int i;
    if (top == -1) {
        printf("\nStack is empty\n");
        return;
    } else {
        printf("\nThe stack contents are");
        for (i = top; i >= 0; i--) {
            printf("\n[%d]", s[i]);
        }
        printf("\n");
    }
}

int main() {
    int s[maxsize], ele;
    int ch, top = -1;

    while (1) {
        printf("\n----------->MAIN MENU<\n");
        printf("1---------->PUSH into the stack\n");
        printf("2---------->POP from the stack\n");
        printf("3---------->PALINDROME check using stack\n");
        printf("4---------->DISPLAY\n");
        printf("5---------->EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                if (push(s, &top) == 0)
                    display(s, top);
                break;

            case 2:
                if (top == -1) {
                    printf("\nStack underflow\n");
                } else {
                    ele = pop(s, &top);
                    printf("\nPopped element is %d\n", ele);
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
                printf("\nEnter a valid choice\n");
                break;
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int q[SIZE], i, r = -1, f = 0, option, count = 0, j;

int main() {
    for (;;) {
        printf("\n 1.Insert 2.Delete\n 3.Display 4.Exit");
        printf("\nEnter your option:");
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (count == SIZE)
                    printf("\n Queue is Full\n");
                else {
                    r = (r + 1) % SIZE;
                    printf("\nEnter the item:");
                    scanf("%d", &q[r]);
                    count++;
                }
                break;

            case 2:
                if (count == 0)
                    printf("\nQueue is empty\n");
                else {
                    printf("\nDeleted item is: %d", q[f]);
                    count--;
                    f = (f + 1) % SIZE;
                }
                break;

            case 3:
                if (count == 0)
                    printf("\nQueue is Empty\n");
                else {
                    i = f;
                    for (j = 0; j < count; j++) {
                        printf(" %d", q[i]);
                        i = (i + 1) % SIZE;
                    }
                    printf("\n");
                }
                break;

            default:
                exit(0);
        }
    }
    return 0;
}

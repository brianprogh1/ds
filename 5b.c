#include <stdio.h>
#include <string.h>

int count = 0, n;

int tower(int n, char s, char t, char d)
{
    if (n == 1)
    {
        printf("\n Move disc 1 from %c to %c", s, d);
        count++;
        return 1;
    }
    
    tower(n - 1, s, d, t);
    printf("\n Move disc %d from %c to %c", n, s, d);
    count++;
    tower(n - 1, t, s, d);
}

int main()
{
    printf("\n Enter the no. of discs:");
    scanf("%d", &n);
    tower(n, 'A', 'B', 'C');
    printf("\n The no. of disc moves is: %d", count);
    getchar();
    return 0;
}

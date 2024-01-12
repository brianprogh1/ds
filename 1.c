#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Day{
    char *day;
    int date;
    char *desc;
};

struct Day *create(int n);
void read(struct Day *pcal, int n);
void display(struct Day *pcal, int n);
void freemem(struct Day *pcal, int n);

int main() {
    int n;
    struct Day *pcal;
    printf("Enter the number of days: ");
    scanf("%d", &n);
    pcal = create(n);
    read(pcal, n);
    display(pcal, n);
    return 0;
}

struct Day *create(int n) {
    struct Day *pcal = (struct Day*) malloc(n * sizeof(struct Day));
    if(pcal == NULL) {
        return NULL;
    }
    return pcal;
}

void read(struct Day *pcal, int n) {
    for(int i = 0; i < n; i++){
        printf("Enter the day name: ");
        pcal[i].day = (char *) malloc(15 * sizeof(char));
        scanf("%s", pcal[i].day);
        printf("Enter date: ");
        scanf("%d", &pcal[i].date);
        printf("Enter the Activity done: ");
        pcal[i].desc = (char *) malloc(50 * sizeof(char));
        scanf("%s", pcal[i].desc);
    }
}


void display(struct Day *pcal, int n) {
    for(int i = 0; i < n; i++) {
        printf("\n%s\t%d\t%s\n", pcal[i].day, pcal[i].date, pcal[i].desc);
    }
}


void freemem(struct Day *pcal, int n) {
    for(int i = 0; i < n; i++) {
        free(pcal[i].day);
        free(pcal[i].desc);
    }
    free(pcal);
}

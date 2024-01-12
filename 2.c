#include <stdio.h>

void readString(char str[], const char *prompt) {
    printf("%s", prompt);
    scanf("%s", str);
}

int stringLength(const char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int findPattern(const char str[], const char pat[], int start) {
    int i, j;
    int strLen = stringLength(str);
    int patLen = stringLength(pat);

    for (i = start; i <= strLen - patLen; i++) {
        for (j = 0; j < patLen; j++) {
            if (str[i + j] != pat[j]) {
                break;
            }
        }

        if (j == patLen) {
            return i;
        }
    }

    return -1; 
}

void replacePattern(char str[], const char pat[], const char rep[]) {
    int patIndex = 0;
    int repIndex = 0;
    int strIndex = 0;

    while (str[strIndex] != '\0') {
        patIndex = findPattern(str, pat, strIndex);

        if (patIndex == -1) {
            break;
        }

        while (strIndex < patIndex) {
            strIndex++;
        }

        while (rep[repIndex] != '\0') {
            str[strIndex++] = rep[repIndex++];
        }

        strIndex += stringLength(pat);
        repIndex = 0;
    }
}

int main() {
    char mainString[100], patternString[50], replaceString[50];

    readString(mainString, "Enter the main string: ");
    readString(patternString, "Enter the pattern string: ");
    readString(replaceString, "Enter the replace string: ");

    int patIndex = findPattern(mainString, patternString, 0);

    if (patIndex == -1) {
        printf("Pattern not found in the main string.\n");
    } else {
        replacePattern(mainString, patternString, replaceString);
        printf("String after replacement: %s\n", mainString);
    }

    return 0;
}

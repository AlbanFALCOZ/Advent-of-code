#include <stdio.h>
#include <string.h>


int checkCell(char s[], int indice, int comptLine) {

    if (s[indice] > '0' && s[indice] < '9') {
        printf("Cases adjacentes de %c : ", s[indice]);
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if (indice + i + j*11 != '\n') {
                    printf("%c ",s[indice+i+j*11]);
                }
            }
        }
    printf("\n");
    }
    return 0;
} 

void printTab(char s[]) {
    int compt = 0;
    int comptLine = 0;
    for (int i = 0; i < strlen(s); i++) {
        //if (compt%141 == 0) printf("A");
        //if (s[i+1] == '\n') printf(" %c  %d\n",s[i], i%140);
        if (s[i] == '\n') comptLine++;
        compt++;
        if (checkCell(s,i,comptLine)) {
            putchar(s[i]);
        }
    }
    
}



int main() {
    int c;
    int compt = 0;
    int comptLine = 0;
    char str[20000];
    while ((c = getchar()) != EOF) {
        str[compt++] = c;
    }
    printTab(str);
    return 0;
}


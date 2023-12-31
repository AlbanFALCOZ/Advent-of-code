#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main() {
    int c;
    int str[1000];
    int compt = -1;
    int comptBlue = 0;
    int comptGreen = 0;
    int comptRed = 0;
    int comptTot = 0;
    int comptGame = 1;
    bool test = true;

    while ((c = getchar()) != EOF) {
        int i = 0;
        while (c >= '0' && c <= '9') {
            str[i++] = c-'0';
            //printf("%c \n",c);
            c = getchar();
        }
        for (int j = 0; j < i; j++) {
            //printf("%c",str[j]);
            compt += str[j]*pow((double)10,(double)i-j-1);
        }
        if (c == 'g') {
            comptGreen += compt;
            compt = 0;
        }
        if (c == 'b') {
            comptBlue += compt;
            compt = 0;
        }
        if (c == 'd') {
            comptRed += compt;
            compt = 0;
        }
        if (c == ';') {
            printf("comptRed : %d; comptGreen : %d; comptBlue: %d\n",comptRed,comptGreen,comptBlue);
            if (comptRed > 12 || comptGreen > 13 || comptBlue > 14) test = false;
            comptBlue = comptGreen = comptRed = 0;
        }
        if (c == '\n') {
            printf("comptRed : %d; comptGreen : %d; comptBlue: %d\n",comptRed,comptGreen,comptBlue);
            if (comptRed > 12 || comptGreen > 13 || comptBlue > 14) test = false;
            if (test) {
                printf("Game N°%d possible : \n",comptGame);
                comptTot += comptGame;
            }
            test = true;
            comptGame++;
            comptBlue = comptGreen = comptRed = 0;
            compt = -comptGame;
            printf("Now game N°%d !\n",comptGame);
        }
    }
    printf("Nombre total de games possibles : %d", comptTot);
    return 0;
}
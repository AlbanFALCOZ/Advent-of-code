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
    int minGreen = 0;
    int minRed = 0;
    int minBlue = 0;
    int comptGame = 1;
    printf("Now game N°%d !\n",comptGame);

    while ((c = getchar()) != EOF) {
        int i = 0;
        while (c >= '0' && c <= '9') {
            str[i++] = c-'0';
            c = getchar();
        }
        for (int j = 0; j < i; j++) {
            compt += str[j]*pow((double)10,(double)i-j-1);
        }
        if (c == ':') compt = 0;
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
            if (comptRed > minRed) minRed = comptRed;
            if (comptBlue > minBlue) minBlue = comptBlue;
            if (comptGreen > minGreen) minGreen = comptGreen;
            printf("minRed : %d; minGreen : %d; minBlue: %d\n",minRed,minGreen,minBlue);
            comptBlue = comptGreen = comptRed = 0;
        }
        if (c == '\n') {
            printf("comptRed : %d; comptGreen : %d; comptBlue: %d\n",comptRed,comptGreen,comptBlue);
            if (comptRed > minRed) minRed = comptRed;
            if (comptBlue > minBlue) minBlue = comptBlue;
            if (comptGreen > minGreen) minGreen = comptGreen;
            printf("minRed : %d; minGreen : %d; minBlue: %d\n",minRed,minGreen,minBlue);
            comptBlue = comptGreen = comptRed = 0;
            comptTot += (minBlue * minGreen * minRed);
            minGreen = 0;
            minRed = 0;
            minBlue = 0;
            printf("Now game N°%d !\n",++comptGame);
        }
    }
    printf("Nombre total de games possibles : %d", comptTot);
    return 0;
}
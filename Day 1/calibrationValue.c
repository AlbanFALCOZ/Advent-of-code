#include <stdio.h>

int main(){
    int c;
    int numb1 = -1;
    int numb2 = -1;
    int compt = 0;
    int comptLine = 1;
    int comptCharLine = 0;
    char str[1000];
    while((c = getchar()) != EOF) {
        if (c == '\n') {
            //printf("Affichage de la ligne N°%d: ",comptLine++);
            for (int i = 0; i < comptCharLine; i++){
                //printf("%c",str[i]);
            }
            //printf("\n");
            int temp = -1;
            //printf("La ligne de char est : ");
            for (int i = 0; i < comptCharLine; i++){
                temp = -1;
                if (str[i] == 'o' && str[i+1] == 'n' && str[i+2] == 'e' && i+2 < comptCharLine) temp = 1;
                else if (str[i] == 't' && str[i+1] == 'w' && str[i+2] == 'o' && i+2 < comptCharLine) temp = 2;
                else if (str[i] == 't' && str[i+1] == 'h' && str[i+2] == 'r' && str[i+3] == 'e' && str[i+4] == 'e' && i+4 < comptCharLine) temp = 3; 
                else if (str[i] == 'f' && str[i+1] == 'o' && str[i+2] == 'u' && str[i+3] == 'r' && i+3 < comptCharLine) temp = 4;
                else if (str[i] == 'f' && str[i+1] == 'i' && str[i+2] == 'v' && str[i+3] == 'e' && i+3 < comptCharLine) temp = 5;
                else if (str[i] == 's' && str[i+1] == 'i' && str[i+2] == 'x' && i+2 < comptCharLine) temp = 6;
                else if (str[i] == 's' && str[i+1] == 'e' && str[i+2] == 'v' && str[i+3] == 'e' && str[i+4] == 'n' && i+4 < comptCharLine) temp = 7;
                else if (str[i] == 'e' && str[i+1] == 'i' && str[i+2] == 'g' && str[i+3] == 'h' && str[i+4] == 't' && i+4 < comptCharLine) temp = 8;
                else if (str[i] == 'n' && str[i+1] == 'i' && str[i+2] == 'n' && str[i+3] == 'e' && i+3 < comptCharLine) temp = 9;
                else if (str[i] >= '1' && str[i] <= '9') temp = str[i]-'0';
                if (temp != -1) {
                    //printf("Temp : %d    Chaine : %c%c%c%c%c\n",temp,str[i],str[i+1],str[i+2],str[i+3],str[i+4]);
                    (numb1 == -1)?(numb1 = temp):(numb2 = temp);
                } 
            }
            
            if (numb2 == -1) numb2 = numb1;
            //printf("Les deux nombres choisis sont : %d   %d\n",numb1,numb2);
            compt += (10*numb1 + numb2);
            numb1 = numb2 = -1;
            comptCharLine = 0;
            //printf("La somme est : %d\n",compt);
        }
        str[comptCharLine++] = c;
    }
    printf("La somme totale est : %d",compt);
    return 0;
}


int calculateLine(char str[]) {

}
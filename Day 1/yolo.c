#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fonction pour convertir les chiffres écrits en lettres en valeurs numériques
int convertToDigit(char *word) {
    if (strcmp(word, "one") == 0) return 1;
    if (strcmp(word, "two") == 0) return 2;
    if (strcmp(word, "three") == 0) return 3;
    if (strcmp(word, "four") == 0) return 4;
    if (strcmp(word, "five") == 0) return 5;
    if (strcmp(word, "six") == 0) return 6;
    if (strcmp(word, "seven") == 0) return 7;
    if (strcmp(word, "eight") == 0) return 8;
    if (strcmp(word, "nine") == 0) return 9;
    return -1; // Retourne -1 si le mot n'est pas un chiffre
}

// Fonction pour calculer la somme des valeurs de calibration
int calculateCalibrationSum(char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    char line[100]; // Assumption: each line has at most 100 characters
    int sum = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        // Utiliser sscanf pour extraire les premiers et derniers caractères
        char first[10], last[10];
        sscanf(line, "%[^0-9]%[0-9]", first, last);

        // Convertir les chiffres écrits en lettres en valeurs numériques
        int firstDigit = convertToDigit(first);
        int lastDigit = atoi(last);

        // Si la conversion a échoué, utiliser la valeur par défaut (0)
        if (firstDigit == -1) {
            firstDigit = 0;
        }

        // Calculer la valeur de calibration et l'ajouter à la somme
        int calibrationValue = firstDigit * 10 + lastDigit;
        sum += calibrationValue;
    }

    fclose(file);
    return sum;
}

int main() {
    char filename[] = "input"; // Remplacez par le nom de votre fichier

    int result = calculateCalibrationSum(filename);

    printf("La somme des valeurs de calibration est : %d\n", result);

    return 0;
}

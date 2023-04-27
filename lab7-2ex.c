#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define n 10

// Функция для ввода слов
void inputWords(char arr[][20]) {
printf("Введите %d слов:\n", n);
for (int i = 0; i < n; i++) {
scanf("%s", (arr + i));
for (int j = 0; j < strlen((arr + i)); j++) {
((arr + i) + j) = tolower(((arr + i) + j));
}
}
}

// Функция для вывода массива
void printArray(char arr[][20]) {
char (*ptr)[20] = arr;
for (int i = 0; i < n; i++) {
printf("%s ", *(ptr + i));
}
printf("\n");
}

// Функция для Comb Sort
void combSort(char arr[][20], int length) {
char (*ptr)[20] = arr; // Создаем указатель на массив для удобства указания элементов
int gap = length;
float shrink = 1.3;
int i, j;
char temp[20];
int iterations = 0;
int swapped = 1;

while (gap > 1 || swapped) {
    if (gap > 1) {
        gap = (int)(gap / shrink);
    }
    swapped = 0;
    for (i = 0, j = gap; j < length; i++, j++) {
        if (strcmp(*(ptr + i), *(ptr + j)) > 0) {
            strcpy(temp, *(ptr + i));
            strcpy(*(ptr + i), *(ptr + j));
            strcpy(*(ptr + j), temp);
            swapped = 1;
        }
        iterations++;
    }
}

printf("Comb Sort iterations: %d\n", iterations);
printArray(arr);
}

int main() {
char words[n][20];
int choice;

inputWords(words);
combSort(words, n);
return 0;
}
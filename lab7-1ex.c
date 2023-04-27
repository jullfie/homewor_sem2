
// Какой из алгоритмов отсортировал один и тот же словарь за наименьшее количество итераций?
// В данной конкретной программе невозможно сказать, какой из алгоритмов отсортировал словарь за наименьшее количество итераций, так как для этого нужно иметь конкретные данные о самих словах. У каждого алгоритма свои особенности и на разных данных они могут работать по-разному.

// Для любого ли словаря это выполняется?
// Нет, каждый алгоритм имеет свою эффективность в зависимости от данных. На разных данных разные алгоритмы могут работать быстрее или медленнее.

// При использовании функций из библиотеки <time.h> и подсчета времени работы каждой функции за одинаковое ли время выполнились алгоритмы?
// Нет, время выполнения каждого алгоритма зависит от данных и может отличаться на разных компьютерах и в разное время. Однако для определения относительной эффективности алгоритмов на конкретных данных такой подход может быть полезен.

// Программа для считывания 10 слов, хранения их в массиве и сортировки с помощью Selection Sort, Bubble Sort и Comb Sort
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define n 10

// Функция для ввода слов
void inputWords(char arr[][20]) {
printf("Введите %d слов:\n", n);
for (int i = 0; i < n; i++) {
scanf("%s", arr[i]);
for (int j = 0; j < strlen(arr[i]); j++) {
arr[i][j] = tolower(arr[i][j]);
}
}
}

// Функция для вывода массива
void printArray(char arr[][20]) {
for (int i = 0; i < n; i++) {
printf("%s ", arr[i]);
}
printf("\n");
}

// Функция для Selection Sort
void selectionSort(char arr[][20]) {
int i, j, minIndex;
char temp[20];
int iterations = 0;

for (i = 0; i < n - 1; i++) {
    minIndex = i;
    for (j = i + 1; j < n; j++) {
        if (strcmp(arr[j], arr[minIndex]) < 0)
            minIndex = j;
        iterations++;
    }
    strcpy(temp, arr[minIndex]);
    strcpy(arr[minIndex], arr[i]);
    strcpy(arr[i], temp);
}

printf("Selection Sort iterations: %d\n", iterations);
printArray(arr);
}

// Функция для Bubble Sort
void bubbleSort(char arr[][20]) {
int i, j;
char temp[20];
int iterations = 0;

for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
        if (strcmp(arr[j], arr[j + 1]) > 0) {
            strcpy(temp, arr[j]);
            strcpy(arr[j], arr[j + 1]);
            strcpy(arr[j + 1], temp);
        }
        iterations++;
    }
}

printf("Bubble Sort iterations: %d\n", iterations);
printArray(arr);
}

// Функция для Comb Sort
void combSort(char arr[][20]) {
int gap = n;
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
    for (i = 0, j = gap; j < n; i++, j++) {
        if (strcmp(arr[i], arr[j]) > 0) {
            strcpy(temp, arr[i]);
            strcpy(arr[i], arr[j]);
            strcpy(arr[j], temp);
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

printf("\nВыберите алгоритм сортировки:\n1. Selection Sort\n2. Bubble Sort\n3. Comb Sort\n4. Выполнить все алгоритмы\n");
scanf("%d", &choice);

switch (choice) {
    case 1:
        selectionSort(words);
        break;
    case 2:
        bubbleSort(words);
        break;
    case 3:
        combSort(words);
        break;
    case 4:
        selectionSort(words);
        bubbleSort(words);
        combSort(words);
        break;
    default:
        printf("Ошибка: некорректный выбор\n");
        break;
}

return 0;
}
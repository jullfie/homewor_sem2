
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

// Функция для поиска элемента в массиве
void findElement(int arr[ROWS][COLS], int element) {
    int row = -1, col = -1; // Инициализируем строку и столбец значением -1

    // Проходим по всем элементам массива
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // Если нашли искомый элемент, сохраняем индексы строки и столбца
            if (arr[i][j] == element) {
                row = i;
                col = j;
                // Выходим из циклов, т.к. элемент найден
                break;
            }
        }
        if (row != -1 && col != -1) {
            // Выходим из внешнего цикла, т.к. элемент найден
            break;
        }
    }

    // Выводим результаты поиска
    if (row == -1 || col == -1) {
        printf("Элемент не найден в массиве\n");
    } else {
        printf("Элемент найден в строке %d, столбце %d\n", row+1, col+1);
    }
}

int main() {
    int arr[ROWS][COLS];
    srand(time(NULL)); // Инициализируем генератор случайных чисел текущим временем

    // Заполняем массив случайными числами от 1 до 10
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            arr[i][j] = rand() % 10 + 1;
            printf("%d ", arr[i][j]); // Выводим массив на экран
        }
        printf("\n");
    }

    int element;
    printf("Введите элемент, который хотите найти: ");
    scanf("%d", &element);

    // Вызываем функцию поиска элемента
    findElement(arr, element);

    return 0;
}

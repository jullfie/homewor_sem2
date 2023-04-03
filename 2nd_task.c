#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// функция для получения целого числа от пользователя
int getInput() {
    int input;
    printf("Введите целое число: ");
    scanf("%d", &input);
    return input;
}

// функция для проверки входных данных
bool testInput(int input) {
    return (input >= 0 && input <= 100); // вернуть true, если число соответствует условию, иначе вернуть false
}

// функция для преобразования строки в целое число
int strToInt(int input) {
    return input;
}

// функция для вывода целого числа
void printInt(int n) {
    printf("Целое число: %d\n", n);
}

// основная функция программы
int main() {
    int input = getInput(); // вызываем функцию на получение целого числа
    if (testInput(input)) { // проверяем входные данные с помощью функции testInput
        int intInput = strToInt(input); // передаем значение, полученное от getInput(), функции strToInt() для преобразования в целое число
        printInt(intInput); // передаем результат, полученный от функции strToInt(), в функцию printInt() для вывода на экран
    } else {
        printf("Ошибка! Введенное число не соответствует условию.\n"); // выведем ошибку, если число не подходит
    }
    return 0;
}
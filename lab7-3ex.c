#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
char word[20];
char *ptr = word; // Указатель на начало слова
int vowels = 0;
int consonants = 0;

printf("Введите слово на латинице без заглавных символов: ");
scanf("%s", word);

// Перебор всех символов и определение, гласный это или согласный
while (*ptr) {
    if (*ptr == 'a' || *ptr == 'e' || *ptr == 'i' || *ptr == 'o' || *ptr == 'u') {
        vowels++;
    } else if (isalpha(*ptr)) { // Если это буква, но не гласная, то это согласная 
        consonants++;
    }
    ptr++; // Переход к следующему символу
}

printf("Количество гласных в слове: %d\n", vowels);
printf("Количество согласных в слове: %d\n", consonants);

return 0;
}
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define MAX_K 100
#define MAX_LENGTH 100

void extractAlphanumericSubstrings(char inputString[]) {
    int length = strlen(inputString);
    int i = 0;
    while (i < length) {
        while (i < length && !isalnum(inputString[i]) && !isspace(inputString[i])) {
            i++;
        }
        int start = i;
        while (i < length && (isalnum(inputString[i]) || isspace(inputString[i]))) {
            printf("%c", inputString[i]);
            i++;
        }
        printf("\n");
    }
}

void findDigitsSubstring(char inputString[]) {
    int length = strlen(inputString);
    int i = 0;
    int digitSubstringFound = 0;
    while (i < length) {
        int start = i;
        while (i < length && isdigit(inputString[i])) {
            if (digitSubstringFound == 0) {
                printf("Первая подстрока, содержащая только цифры: ");
                while (i < length && isdigit(inputString[i])) {
                    printf("%c", inputString[i]);
                    i++;
                }
                printf("\n");
                digitSubstringFound = 1;
            } else {
                i++;
            }
        }
        i++;
    }
    if (digitSubstringFound == 0) {
        printf("Нет подстроки, содержащей только цифры\n");
    }
}

void replaceDigitsWithLetters(char inputString[]) {
    printf("Преобразованная строка(цифры в буквы): ");
    int length = strlen(inputString);
    for (int i = 0; i < length; i++) {
        if (isdigit(inputString[i])) {
            inputString[i] = 'A' + (inputString[i] - '0');
        }
        printf("%c", inputString[i]);
    }
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    
    printf("Лабораторная работа №4\n");
    printf("Выполнил: Алексеев Фёдор Павлович\n");
    printf("Группа: БИТ232\n");
    
    int k;
    printf("Введите количество строк: ");
    scanf("%d", &k);
    if (k < 1 || k > MAX_K) {
        printf("Количество строк должно быть от 1 до %d\n", MAX_K);
        return 1;
    }

    char inputStrings[MAX_K][MAX_LENGTH];
    printf("Введите строки:\n");
    getchar();
    for (int i = 0; i < k; i++) {
        fgets(inputStrings[i], MAX_LENGTH, stdin);
    }
    printf("---------------------------\n");

    for (int i = 0; i < k; i++) {
        printf("Результат для строки %d:\n", i+1);
        extractAlphanumericSubstrings(inputStrings[i]);
        findDigitsSubstring(inputStrings[i]);
        replaceDigitsWithLetters(inputStrings[i]);
        printf("---------------------------\n");
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Функция для сортировки латинских букв в строке
void sortLatinCharacters(char *line) {
    int len = strlen(line);
    char temp;
    for (int i = 0; i < len; i++) {
        if (isalpha(line[i])) {
            for (int j = i + 1; j < len; j++) {
                if (isalpha(line[j])) {
                    if (tolower(line[i]) > tolower(line[j])) {
                        temp = line[i];
                        line[i] = line[j];
                        line[j] = temp;
                    }
                }
            }
        }
    }
}

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[50], outputFileName[50];
    char line[1000];

    // Ввод имени входного файла с клавиатуры
    printf("Введите имя входного файла: ");
    scanf("%s", inputFileName);

    // Открытие входного файла для чтения
    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Ошибка при открытии входного файла.\n");
        return 1;
    }

    // Ввод имени выходного файла с клавиатуры
    printf("Введите имя выходного файла: ");
    scanf("%s", outputFileName);

    // Открытие выходного файла для записи
    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Ошибка при открытии выходного файла.\n");
        return 1;
    }

    // Прочтение входного файла построчно, сортировка латинских букв и запись в выходной файл
    while (fgets(line, sizeof(line), inputFile)) {
        sortLatinCharacters(line);
        fputs(line, outputFile);
    }

    // Закрытие файлов
    fclose(inputFile);
    fclose(outputFile);

    printf("Преобразование файла завершено.\n");

    return 0;
}

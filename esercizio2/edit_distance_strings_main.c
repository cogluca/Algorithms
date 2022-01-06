#include <ctype.h>
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "edit_distance_strings_dynamic.h"

#define BUFFER_SIZE 128
#define ARRAY_SIZE 670000


int read_words_from_file(const char* file_name, char** word_array) {
    char buffer[BUFFER_SIZE];
    int size = 0;
    int buffer_length;

    if (file_name == NULL)
        printf("File name is null");

    FILE * actual_file = fopen(file_name, "r");

    if (word_array == NULL)
        printf("Array is null");

    if (actual_file == NULL)
        printf("Unable to open file");

    while (1) {

        fscanf(actual_file, "%s", buffer);

        buffer_length = strlen(buffer);

        if(feof(actual_file))
            break;

        if (buffer[buffer_length - 1] == ',' || buffer[buffer_length - 1] == '.' || buffer[buffer_length - 1] == ':')
            buffer[--buffer_length] = '\0';

        word_array[size] = (char*)malloc((buffer_length + 1) * sizeof(char));
        strcpy(word_array[size++], buffer);
    }
    return size;

}

void print_least_distance_words(char** word, char** dictionary, int dictionary_size) {

    int smallest_distance = INT8_MAX;
    int current_distance;
    char** curated_words;
    int result_size = 0;
    int i;

    curated_words = (char**) malloc(sizeof(char*) * dictionary_size);

    for (i = 0; i < dictionary_size; i++) {
        current_distance = edit_distance_strings_dyn(word, dictionary[i]);

        if (current_distance < smallest_distance) {
            result_size = 0;
            smallest_distance = current_distance;
        }

        if (current_distance == smallest_distance)
            curated_words[result_size++] = dictionary[i];

        if (smallest_distance == 0) break;
    }

    printf("%s \n", word);

    printf("Curated picks from dictionary are: \n");

    for (i = 0; i < result_size; i++) {
        printf("- %s \n", curated_words[i]);
    }

    printf("\n");

    free(curated_words);
}


int main() {

    char** correctme;
    int correctme_size;
    char correctme_filename[BUFFER_SIZE];

    char** dictionary;
    int dictionary_size;
    char dictionary_filename[BUFFER_SIZE];
/*
    printf("Insert name of file in need of correction: \n");
    scanf("%s", correctme_filename);

    printf("Insert dictionary: \n");
    scanf("%s", dictionary_filename);

*/
    strcpy(correctme_filename, "/Users/frankacarkan/Desktop/Algo/Lab/ex2data/Basis/correctme.txt");
    strcpy(dictionary_filename, "/Users/frankacarkan/Desktop/Algo/Lab/ex2data/Basis/dictionary.txt");

    correctme = (char**) malloc(sizeof(char*) * ARRAY_SIZE);
    dictionary = (char**) malloc(sizeof(char*) * ARRAY_SIZE);

    correctme_size = read_words_from_file(correctme_filename, correctme);
    dictionary_size = read_words_from_file(dictionary_filename, dictionary);

    //TODO: File loaded into correctme has 2 wita

    for(int i = 0; i < correctme_size; i++) {
        print_least_distance_words(correctme[i], dictionary, dictionary_size);
    }

    free(dictionary);
    free(correctme);

    return 0;
}


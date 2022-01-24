    #include <ctype.h>
    #include "string.h"
    #include "stdio.h"
    #include "stdlib.h"
    #include "edit_distance_strings_dynamic.h"

    #define BUFFER_SIZE 128
    #define ARRAY_SIZE 670000

    /**
     * Detects words from file and encloses them into an array
     * @param file_name file from which to retrieve words
     * @param word_array array to fill
     * @return returns size of filled array
     */

    int detect_words_from_file(const char* file_name, char** word_array) {
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

            if(word_array != NULL) {
                word_array[size] = (char *) malloc((buffer_length + 1) * sizeof(char));
                strcpy(word_array[size++], buffer);
            }
        }
        return size;

    }


    /**
     * Applies the edit distance algorithm by taking the array of words and the dictionary in input and comparing the current word to the possible alternatives in the dictionary, finally
     * prints the results, such thing is done instead of returning a corrected file because edit_distance as a mechanic doesn't provide a unique certain outcome but a range of possibilities
     * @param word current word to take onto examination
     * @param dictionary dictionary containing possible substitutions
     * @param dictionary_size size of dictionary
     */
    void print_smallest_distance_words(char** word, char** dictionary, int dictionary_size) {

        int smallest_distance = INT8_MAX;
        int current_distance;
        char** curated_words;
        int* distances;
        int distances_length;
        int result_size = 0;
        int i;
        char* pick;

        distances_length = 0;

        curated_words = (char**) malloc(sizeof(char*) * dictionary_size);
        distances = (int*) malloc(sizeof (int) * 30);
        pick = (char*) malloc(sizeof (char)* 30);

        for (i = 0; i < dictionary_size; i++) {
            current_distance = edit_distance_strings(*word, dictionary[i]);

            if(current_distance == 0) {
                smallest_distance = current_distance;
                curated_words[result_size++] = dictionary[i];
                distances[distances_length++] = current_distance;
                break;
            }

            if (current_distance < smallest_distance) {
                result_size = 0;
                distances_length = 0;
                smallest_distance = current_distance;
            }

            if (current_distance == smallest_distance) {
                curated_words[result_size++] = dictionary[i];
                distances[distances_length++] = current_distance;
            }

        }

        printf("%s \n", *word);

        for(int i = 0; i < distances_length; i++) {
            if(distances[i] == 0) {
                pick = curated_words[i];
                printf("Direct correspondence is %s \n", pick);
            }
        }


        printf("Curated picks from dictionary are: \n");

        for (i = 0; i < result_size; i++) {
            printf("- %s \n", curated_words[i]);
        }

        printf("\n");

        free(curated_words);
    }


    /**
     * Contains the logic for taking a file to correct and a dictionary in input, translating such elements onto data structures (namely arrays), apply the edit distance algorithms and finally print
     * the outcomes
     */
    int main() {

        char** correctme;
        int correctme_size;
        char correctme_filename[BUFFER_SIZE];

        char** dictionary;
        int dictionary_size;
        char dictionary_filename[BUFFER_SIZE];

        printf("Insert name of file in need of correction: \n");
        scanf("%s", correctme_filename);

        printf("Insert dictionary: \n");
        scanf("%s", dictionary_filename);

        correctme = (char**) malloc(sizeof(char*) * ARRAY_SIZE);
        dictionary = (char**) malloc(sizeof(char*) * ARRAY_SIZE);

        correctme_size = detect_words_from_file(correctme_filename, correctme);
        dictionary_size = detect_words_from_file(dictionary_filename, dictionary);

        for(int i = 0; i < correctme_size; i++) {
            print_smallest_distance_words(&correctme[i], dictionary, dictionary_size);
        }

        free(correctme);
        free(dictionary);

        return 0;
    }


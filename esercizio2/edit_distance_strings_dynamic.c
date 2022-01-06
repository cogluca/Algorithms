
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

/**
 * Compares two integer values to find the smallest one
 * @param one_op first elem to compare
 * @param second_op second element to compare
 * @return smallest integer between parameters
 */
int min_val (int one_op, int second_op) {
    return (one_op < second_op) ? one_op : second_op;
}



/**
 *
 * @param string_one
 * @param string_two
 * @param length_one
 * @param length_two
 * @param mapping_matrix
 * @return
 */
int _edit_distance_strings_dyn(char* string_one, char* string_two, int length_one, int length_two, int** mapping_matrix) {

    int dno_op;
    int dcanc;
    int dins;
    int distance_computation;

    if(mapping_matrix[length_one][length_two] >= 0) {
        return mapping_matrix[length_one][length_two];
    }

    if (length_one == 0) {
        mapping_matrix[length_one][length_two] = length_two;
        return length_two;
    }
    if(length_two == 0) {
        mapping_matrix[length_one][length_two] = length_one;
        return length_one;
    }

    if(string_one[0] == string_two[0])
        dno_op = _edit_distance_strings_dyn(string_one + 1, string_two + 1, length_one-1, length_two - 1, mapping_matrix);
    else
        dno_op = INT8_MAX;

    dcanc = 1 + _edit_distance_strings_dyn(string_one, string_two + 1, length_one, length_two - 1, mapping_matrix);

    dins = 1 + _edit_distance_strings_dyn(string_one + 1, string_two, length_one-1, length_two, mapping_matrix);

    distance_computation = min_val(dno_op, min_val(dcanc, dins));

    mapping_matrix[length_one][length_two] = distance_computation;

    return  mapping_matrix[length_one][length_two];

}

/**
 * Wrapper for internal call on method logic, creates the mapping matrix in which to store substring distances and checks for
 * null parameters
 * @param one_string first string to compare
 * @param another_string second string to compare
 * @return returns minimum edit distance to obtain string represented by one_string by modifying another_string
 */
int edit_distance_strings_dyn(char* one_string, char* another_string) {

    int len_one_string;
    int len_another_string;
    int** mapping_matrix;
    int resulting_distance;

    if(one_string == NULL || another_string == NULL) {
        printf("One of the two strings is null");
        exit(EXIT_FAILURE);
    }

    len_one_string = (int) strlen(one_string);
    len_another_string = (int) strlen(another_string);

    mapping_matrix = (int**) malloc(sizeof(int*) * (len_one_string + 1));

    for(int i = 0; i <= len_one_string; i++) {
        mapping_matrix[i] = (int*) malloc(sizeof(int) * (len_another_string +1));
        for(int j = 0; j <= len_another_string; j++) {
            mapping_matrix[i][j] = -1;
        }
    }

    resulting_distance = _edit_distance_strings_dyn(one_string, another_string, len_one_string, len_another_string, mapping_matrix);

    free(mapping_matrix);

    return resulting_distance;
}




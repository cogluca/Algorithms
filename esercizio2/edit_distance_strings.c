
#include "stdlib.h"
#include "stdio.h"
#include "string.h"



/**
 * Compares two integer values and calculates if first is smaller than second
 * @param one_op first integer
 * @param second_op second integer
 * @return returns the smallest integer between the given inputs
 */

int min_val (int one_op, int second_op) {
    return (one_op < second_op) ? one_op : second_op;
}

/**
 * Internal call containing the actual algorithm logic, recursively calculates deletion, isertion and do nothing operations to transform the second word into the first one
 * @param string_one
 * @param string_two
 * @return returns the minimum of the three basic operations calculated, such value represets the workload to obtain first string from second one
 */
int _edit_distance_strings(char* string_one, char* string_two) {

    int dno_op;
    int dcanc;
    int dins;

    if (strlen(string_one) == 0)
        return strlen(string_two);
    if(strlen(string_two) == 0)
        return strlen(string_one);

    if(string_one[0] == string_two[0])
        dno_op = _edit_distance_strings(string_one + 1, string_two + 1);
    else
        dno_op = INT8_MAX;

    dcanc = 1 + _edit_distance_strings(string_one, string_two + 1);

    dins = 1 + _edit_distance_strings(string_one + 1, string_two);

    return min_val(dno_op, min_val(dcanc, dins));

}

//Wrapper containing a preventive check for null values in input, after such control executes internal method with actual logic

int edit_distance_strings(char* one_string, char* another_string) {

    if(one_string == NULL || another_string == NULL) {
        printf("One of the two strings is null");
        exit(EXIT_FAILURE);
    }

     return _edit_distance_strings(one_string, another_string);

}



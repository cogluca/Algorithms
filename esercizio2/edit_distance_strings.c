
#include "stdlib.h"
#include "stdio.h"
#include "string.h"





int min_val (int one_op, int second_op) {
    return (one_op < second_op) ? one_op : second_op;
}

int _edit_distance_strings(char* string_one, char* string_two) {

    int dno_op;
    int dcanc;
    int dins;

    if (strlen(string_one) == 0)
        return strlen(string_two);
    if(strlen(string_two) == 0)
        return strlen(string_one);

    if(string_one[0] == string_two[0])
        dno_op = _edit_distance_strings(string_one+1, string_two+1);
    else
        dno_op = INT8_MAX;

    dcanc = 1 + _edit_distance_strings(string_one, string_two+1);

    dins = 1 + _edit_distance_strings(string_one+1, string_two);

    return min_val(dno_op, min_val(dcanc, dins));

}


int edit_distance_strings(char* one_string, char* another_string) {

    if(one_string == NULL || another_string == NULL) {
        printf("One of the two strings is null");
        exit(EXIT_FAILURE);
    }

     return _edit_distance_strings(one_string, another_string);

}



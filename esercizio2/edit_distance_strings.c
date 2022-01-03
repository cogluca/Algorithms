
#include "stdlib.h"
#include "stdio.h"
#include "string.h"





int min_val (int one_op, int second_op) {
    return (one_op < second_op) ? one_op : second_op;
}

int _edit_distance_strings(char *string_one, char *string_two) {

    int dno_op;
    int dcanc;
    int dins;

    if (string_one == NULL)
        return strlen(string_two);
    if(string_two == NULL)
        return strlen(string_one);

    if(string_one[0] == string_two[0])
        dno_op = _edit_distance_strings(string_one+1, string_two+1);

    dcanc = 1 + _edit_distance_strings(string_one, string_two+1);

    dins = 1 + _edit_distance_strings(string_one+1, string_two);

    return min_val(dno_op, min_val(dcanc, dins));

}






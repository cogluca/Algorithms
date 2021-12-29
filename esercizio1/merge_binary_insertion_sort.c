
#include "stdio.h"
#include "stdlib.h"

int binary_search(void **array, int left_bound, int right_bound, int elem_to_move,
                  int (*compare)(void*, void*)) {

    if (right_bound <= left_bound)
        if (compare(array[left_bound], array[elem_to_move]) > 0) {
            return left_bound + 1;
        }else {
            return left_bound;
        }

    int middle;
    middle = (left_bound + right_bound) / 2;


    if (compare(array[middle], array[elem_to_move]) == 0)
        return middle;
    if (compare(array[elem_to_move], array[middle]) > 0)
        return binary_search(array, middle + 1, right_bound, elem_to_move, compare);
    if (compare(array[elem_to_move], array[middle]) > 0)
        return binary_search(array, left_bound, middle - 1, elem_to_move, compare);

}


void
binary_insertion_sort(void **array, int left_bound, int right_bound, int (*compare)(void *, void *)) {
    if (right_bound - left_bound <= 1)
        return;

    int i, loc, j;
    void *selected_elem;

    for (i = left_bound + 1; i < right_bound; ++i) {
        loc = binary_search(array, left_bound, i-1, i, compare);
        selected_elem = array[i];
        j = i - 1;


        while (j >= loc) {
            array[j + 1] = array[j];
            j--;
        }
        array[loc] = selected_elem;
    }
}


void merge(void **array, int left_bound, int approx_middle, int right_bound, int (*compare)(void*, void*)) {

    int i1, i2, j;
    void **buffer = (void**) malloc(sizeof(void**)* (right_bound - left_bound + 2));

    i1 = left_bound;
    i2 = approx_middle + 1;
    j = 0;

    while (i1 <= approx_middle && i2 <= right_bound) {
        if (compare(array[i1], array[i2]) > 0) {
            buffer[j++] = array[i1++];
        } else {
            buffer[j++] = array[i2++];
        }
    }

    while (i1 <= approx_middle) {
        buffer[j++] = array[i1++];
    }

    while (i2 <= right_bound) {
        buffer[j++] = array[i2++];
    }

    for (j = left_bound; j <= right_bound; j++) {
        array[j] = buffer[j - left_bound];
    }

    free(buffer);
}

void merge_binary_insertion_sort(void **array, int left_bound, int right_bound, int k,
                                 int (*compare)(void*, void*)) {

    if (right_bound - left_bound <= 0)
        return;

    int m = (left_bound + right_bound) / 2;

    if (m - left_bound <= k)
        binary_insertion_sort(array, left_bound, m, compare);
    else {
        merge_binary_insertion_sort(array, left_bound, m, k, compare);
    }
    if ((right_bound - (m + 1)) <= k) {
        binary_insertion_sort(array, m + 1, right_bound+1, compare);
    }
    else
        merge_binary_insertion_sort(array, m + 1, right_bound, k, compare);

    merge(array, left_bound, m, right_bound, compare);
}



void merge_binary_insertion_sort_entry(void **array,int array_size,int k,int (*compare)(void*,void*)){
    if (array == NULL){
        fprintf(stderr,"merge_binaryInsertion_sort: the array is a null pointer");
        exit(EXIT_FAILURE);
    }

    if (array_size < 0){
        fprintf(stderr,"merge_binaryInsertion_sort: the array size is negative");
        exit(EXIT_FAILURE);
    }

    if (compare == NULL){
        fprintf(stderr,"merge_binaryInsertion_sort: compare function is a null pointer");
        exit(EXIT_FAILURE);
    }

    if(array_size <= 1){
        return;
    }

    merge_binary_insertion_sort(array,0,array_size-1,k,compare);
}

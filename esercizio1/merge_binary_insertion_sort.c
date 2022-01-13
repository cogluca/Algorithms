
    #include "stdio.h"
    #include "stdlib.h"

    /**
     * Searches for the position at which to insert the element taken into consideration, search happens recursively metaphoriclly
     * to the left and to the right of a newfound mmiddle until the variable middle corresponds to the required index
     *
     * @param array reference to array taken into consideration
     * @param left_bound defines the smallest index of the subarray and therefore the left boundary
     * @param right_bound defines the biggest index of the subarray and therefore the right boundary
     * @param elem_to_move defines the index of the element that we're moving
     * @param compare generic pointer to comparator function, it will refer to a specifc comparator defined for current data type
     * @return returns the index at which to place the actual element to move (not the index "elem_to_move")
     */
    int binary_search(void **array, int left_bound, int right_bound, int elem_to_move,
                      int (*compare)(void*, void*)) {

        if (right_bound <= left_bound) //what is this ?
            if (compare(array[left_bound], array[elem_to_move]) > 0) {
                return left_bound + 1;
            }else{
                return left_bound;
            }

        int middle;
        middle = (left_bound + right_bound) / 2;


        if (compare(array[middle], array[elem_to_move]) == 0)
            return middle;
        if (compare(array[elem_to_move], array[middle]) < 0)
            return binary_search(array, middle + 1, right_bound, elem_to_move, compare);
        if (compare(array[elem_to_move], array[middle]) > 0)
            return binary_search(array, left_bound, middle - 1, elem_to_move, compare);
    return 0;
    }

    /**
     * Binary insertion sort main mechanism, makes use of binary search to retrieve the location on the sub array to which
     * we want to move a given element in an iteration, moves forward all the elements from that wanted position and finally places
     * the element in the retrieved position
     *
     * @param array reference to array taken into consideration
     * @param left_bound defines the smallest index of the subarray and therefore the left boundary
     * @param right_bound defines the biggest index of the subarray and therefore the right boundary
     * @param compare generic pointer to comparator function, it will refer to a specifc comparator defined for current data type
     */
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


    /**
     * Merge function, part of the merge sort mechanisms
     * @param array reference to array taken into consideration
     * @param left_bound defines the smallest index of the subarray and therefore the left boundary
     * @param approx_middle
     * @param right_bound defines the biggest index of the subarray and therefore the right boundary
     * @param compare generic pointer to comparator function, it will refer to a specifc comparator defined for current data type
     */
    void merge(void **array, int left_bound, int approx_middle, int right_bound, int (*compare)(void*, void*)) {

        int first_split_index, second_split_index, buffer_index;

        void **buffer = (void**) malloc(sizeof(void**)* (right_bound - left_bound + 2));

        first_split_index = left_bound;
        second_split_index = approx_middle + 1;
        buffer_index = 0;

        while (first_split_index <= approx_middle && second_split_index <= right_bound) {
            if (compare(array[first_split_index], array[second_split_index]) > 0) {
                buffer[buffer_index++] = array[first_split_index++];
            } else {
                buffer[buffer_index++] = array[second_split_index++];
            }
        }

        while (first_split_index <= approx_middle) {
            buffer[buffer_index++] = array[first_split_index++];
        }

        while (second_split_index <= right_bound) {
            buffer[buffer_index++] = array[second_split_index++];
        }

        for (buffer_index = left_bound; buffer_index <= right_bound; buffer_index++) {
            array[buffer_index] = buffer[buffer_index - left_bound];
        }

        free(buffer);
    }

    /**
     * Actual algorithm, it starts by breaking down the array into smaller ones, if parameter k is reached proceed onto
     * calling the binary insertion, otherwise reduces the size recursively until k is met, finally it merges back the entire array
     * @param array reference to array taken into consideration
     * @param left_bound what can currently (on specific call) can be considered the left bound, depends on recursive calls
     * @param right_bound what can currently (on specific call) can be considered the right bound, depends on recursive calls
     * @param k parameter to discern between recursive splitting up and binary insertion sort application
     * @param compare reference to the comparator function, dependent on specific data being processed
     */

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


    /**
     * Intro point for the merge binary insertion sort, considers edge cases that result in failure, if those are overcome
     * move onto calling the actual algorithm
     * @param array reference to array taken into consideration
     * @param array_size size of array
     * @param k value for binary insertion discernment
     * @param compare comparator function specific to types taken into consideration
     */

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

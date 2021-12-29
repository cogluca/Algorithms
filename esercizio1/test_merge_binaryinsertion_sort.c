
#include "merge_binary_insertion_sort.h"
#include "unity.h"

void setUp(void) {}

void tearDown(void) {
}

int comp_int(void *a, void *b){
    return *(int*)a < *(int*)b;
}

void test_sorted_int_array() {
    int arr[] = {1,2,3,4,5,6,7};
    int* array[] = {&arr[0],&arr[1],&arr[2],&arr[3],&arr[4],&arr[5],&arr[6]};
    int* correct_array[] = {&arr[0],&arr[1],&arr[2],&arr[3],&arr[4],&arr[5],&arr[6]};

    merge_binary_insertion_sort((void**) array, 0, 6,1,comp_int);
    TEST_ASSERT_EQUAL_PTR_ARRAY((void**)correct_array, (void**)array,7);
}

void test_unsorted_int_array() {
    int arr[] = {1,2,3,4,5,6,7};
    int* array[] = {&arr[0],&arr[4],&arr[1],&arr[6],&arr[2],&arr[5],&arr[3]};
    int* correct_array[] = {&arr[0],&arr[1],&arr[2],&arr[3],&arr[4],&arr[5],&arr[6]};


    merge_binary_insertion_sort_entry((void**) array, 7,3,comp_int);

    TEST_ASSERT_EQUAL_PTR_ARRAY((void**)correct_array,(void**) array,7);
}


int main(){
    UNITY_BEGIN();

    RUN_TEST(test_sorted_int_array);
    RUN_TEST(test_unsorted_int_array);

    return UNITY_END();
}
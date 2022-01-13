
    #include "merge_binary_insertion_sort.h"
    #include "unity.h"

    void setUp(void) {}

    void tearDown(void) {
    }

    int comp_int(void *a, void *b) {

        if (*(int *) a < *(int *) b)
            return (1);
        else if (*(int *) a > *(int *) b)
            return (-1);
        else
            return (0);

        //return *(int*)a < *(int*)b;
    }

    void test_sorted_int_array() {
        int arr[] = {1, 2, 3, 4, 5, 6, 7};
        int *array[] = {&arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &arr[6]};
        int *correct_array[] = {&arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &arr[6]};
        merge_binary_insertion_sort((void **) array, 0, 6, 2, comp_int);

        TEST_ASSERT_EQUAL_PTR_ARRAY((void **) correct_array, (void **) array, 7);
    }

    void test_unsorted_int_array() {
        int arr[] = {1, 2, 3, 4, 5, 6, 7};
        int *array[] = {&arr[0], &arr[4], &arr[1], &arr[6], &arr[2], &arr[5], &arr[3]};
        int *array2[] = {&arr[0], &arr[4], &arr[1], &arr[6], &arr[2], &arr[5], &arr[3]};
        int *correct_array[] = {&arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &arr[6]};



        for (int i = 0; i <= 8; i++) {

            printf("for k = %d\n", i);

            for(int ii = 0; ii < 7; ii++){
                array[ii] = array2[ii];
                printf("%d ", *array[ii]);
                printf("\n");
            }
            printf("\n");

            merge_binary_insertion_sort_entry((void **) array, 7, i, comp_int);

            for(int ii = 0; ii < 7; ii++){
                printf("%d ", *array[ii]);
                printf("\n");
            }
            printf("\n");



        }

        TEST_ASSERT_EQUAL_PTR_ARRAY((void **) correct_array, (void **) array, 7);

    }


    int main() {
        UNITY_BEGIN();

        RUN_TEST(test_sorted_int_array);
        RUN_TEST(test_unsorted_int_array);

        return UNITY_END();
    }



#include "edit_distance_strings.h"
#include "unity.h"

void setUp(void) {}

void tearDown(void) {
}


void test_same_strings() {

    char* one_string = "pioppo";
    char* another_string = "pioppo";

    int distance = 0;

    TEST_ASSERT_EQUAL_INT(distance, _edit_distance_strings(one_string, another_string));

}


void test_one_absent() {

    char* one_string = NULL;
    char* another_string = "Franco";

    int distance = 6;

    TEST_ASSERT_EQUAL_INT(distance, _edit_distance_strings(one_string, another_string));

}


void test_second_absent() {

    char* one_string = "Franco";
    char* another_string = NULL;

    int distance = 6;

    TEST_ASSERT_EQUAL_INT(distance, _edit_distance_strings(one_string, another_string));

}


void test_different_strings() {

    char* one_string = "casa";
    char* another_string = "cassa";

    int distance = 1;

    TEST_ASSERT_EQUAL_INT(distance, _edit_distance_strings(one_string, another_string));

}




int main() {
    UNITY_BEGIN();

    RUN_TEST(test_sorted_int_array);
    RUN_TEST(test_unsorted_int_array);

    return UNITY_END();
}
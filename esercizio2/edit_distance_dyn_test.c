#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "edit_distance_strings_dynamic.h"
#include "unity.h"

void setUp(void) {}

void tearDown(void) {
}


void test_same_strings() {

    char* one_string = "pioppo";
    char* another_string = "pioppo";

    int distance = 0;

    TEST_ASSERT_EQUAL_INT(distance, edit_distance_strings_dyn(one_string, another_string));

}


void test_one_absent() {

    char* one_string = "";
    char* another_string = "Franco";

    int distance = 6;

    TEST_ASSERT_EQUAL_INT(distance, edit_distance_strings_dyn(one_string, another_string));

}


void test_second_absent() {

    char* one_string = "Franco";
    char* another_string = "";

    int distance = 6;

    TEST_ASSERT_EQUAL_INT(distance, edit_distance_strings_dyn(one_string, another_string));

}


void test_different_strings() {

    char* one_string = "casa";
    char* another_string = "cassa";

    int distance = 1;

    TEST_ASSERT_EQUAL_INT(distance, edit_distance_strings_dyn(one_string, another_string));

}


int main() {
    UNITY_BEGIN();

    RUN_TEST(test_different_strings);
    RUN_TEST(test_one_absent);
    RUN_TEST(test_same_strings);
    RUN_TEST(test_second_absent);

    return UNITY_END();
}
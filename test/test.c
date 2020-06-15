#include "ctest.h"
#include "sort.h"
#include "word_splitting.h"
#include <stdlib.h>
#include <string.h>

CTEST(work_with_string, ignoring_characters)
{
    // Given
    char* stroka_1 = "шла саша по шоссе и сосала сушку";
    char* stroka_2 = "apple fortune bananas";
    char* stroka_3 = "";
    char* stroka_4 = " apple fortune eggs";
    char* stroka_5 = " яблоко фортуна яйца";
    char* stroka_6 = "123 apple ihhi";
    char* stroka_7 = "яблоко банан груша @";
    char* stroka_8 = "rice  money";
    char* stroka_9 = "блокнот  деньги  сыр";

    // When
    int result_1 = ignoring_characters(stroka_1);
    int result_2 = ignoring_characters(stroka_2);
    int result_3 = ignoring_characters(stroka_3);
    int result_4 = ignoring_characters(stroka_4);
    int result_5 = ignoring_characters(stroka_5);
    int result_6 = ignoring_characters(stroka_6);
    int result_7 = ignoring_characters(stroka_7);
    int result_8 = ignoring_characters(stroka_8);
    int result_9 = ignoring_characters(stroka_9);

    // Then
    int expected_1 = 0;
    int expected_2 = 0;
    int expected_3 = 1;
    int expected_4 = 4;
    int expected_5 = 4;
    int expected_6 = 2;
    int expected_7 = 2;
    int expected_8 = 3;
    int expected_9 = 3;

    ASSERT_EQUAL(expected_1, result_1);
    ASSERT_EQUAL(expected_2, result_2);
    ASSERT_EQUAL(expected_3, result_3);
    ASSERT_EQUAL(expected_4, result_4);
    ASSERT_EQUAL(expected_5, result_5);
    ASSERT_EQUAL(expected_6, result_6);
    ASSERT_EQUAL(expected_7, result_7);
    ASSERT_EQUAL(expected_8, result_8);
    ASSERT_EQUAL(expected_9, result_9);
}
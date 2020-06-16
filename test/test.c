#include "ctest.h"
#include "sort.h"
#include "word_splitting.h"
#include <stdlib.h>
#include <string.h>

CTEST(work_with_string_latin_words, ignoring_characters)
{
    // Given
    char* stroka_1 = "apple fortune bananas";
    char* stroka_2 = "";
    char* stroka_3 = " apple fortune eggs";
    char* stroka_4 = "123 apple ihhi";
    char* stroka_5 = "rice  money";

    // When
    int result_1 = ignoring_characters(stroka_1);
    int result_2 = ignoring_characters(stroka_2);
    int result_3 = ignoring_characters(stroka_3);
    int result_4 = ignoring_characters(stroka_4);
    int result_5 = ignoring_characters(stroka_5);

    // Then
    int expected_1 = 0;
    int expected_2 = 1;
    int expected_3 = 4;
    int expected_4 = 2;
    int expected_5 = 3;

    ASSERT_EQUAL(expected_1, result_1);
    ASSERT_EQUAL(expected_2, result_2);
    ASSERT_EQUAL(expected_3, result_3);
    ASSERT_EQUAL(expected_4, result_4);
    ASSERT_EQUAL(expected_5, result_5);
}

CTEST(work_with_string_russian_words, ignoring_characters)
{
    // Given
    char* stroka_1 = "батон булка хлеб";
    char* stroka_2 = "";
    char* stroka_3 = " яйцо ананас банан";
    char* stroka_4 = "яблоко киви 125";
    char* stroka_5 = "рис  груша";

    // When
    int result_1 = ignoring_characters(stroka_1);
    int result_2 = ignoring_characters(stroka_2);
    int result_3 = ignoring_characters(stroka_3);
    int result_4 = ignoring_characters(stroka_4);
    int result_5 = ignoring_characters(stroka_5);

    // Then
    int expected_1 = 0;
    int expected_2 = 1;
    int expected_3 = 4;
    int expected_4 = 2;
    int expected_5 = 3;

    ASSERT_EQUAL(expected_1, result_1);
    ASSERT_EQUAL(expected_2, result_2);
    ASSERT_EQUAL(expected_3, result_3);
    ASSERT_EQUAL(expected_4, result_4);
    ASSERT_EQUAL(expected_5, result_5);
}
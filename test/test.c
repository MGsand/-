#include "ctest.h"
#include "sort.h"
#include "word_splitting.h"
#include <stdio.h>
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

CTEST(work_with_string_latin_words, working_splitting)
{
    printf("\n");
    // Given
    int i;
    char* stroka_1 = (char*)malloc(19 * sizeof(char));
    strcpy(stroka_1, "apple fortune eggs\0");
    int* word_1 = (int*)malloc(3 * sizeof(int));
    // When
    word_splitting(stroka_1, word_1);
    // Then
    int expected_1[3] = {0, 6, 14};
    char* expected_2 = (char*)malloc(19 * sizeof(char));
    strcpy(expected_2, "apple fortune eggs\0");
    for (i = 0; i < 19; i++) {
        if (expected_2[i] == ' ')
            expected_2[i] = 0;
    }
    // Comprassion
    for (i = 0; i < 3; i++)
        ASSERT_EQUAL(expected_1[i], word_1[i]);
    ASSERT_STR(expected_2, stroka_1);
    printf("\n");
    // Given
    char* stroka_2 = (char*)malloc(36 * sizeof(char));
    strcpy(stroka_2, "Red Orange Yellow Green Blue Violet\0");
    int* word_2 = (int*)malloc(6 * sizeof(int));
    // When
    word_splitting(stroka_2, word_2);
    // Then
    int expected_3[6] = {0, 4, 11, 18, 24, 29};
    char* expected_4 = (char*)malloc(36 * sizeof(char));
    strcpy(expected_4, "Red Orange Yellow Green Blue Violet\0");
    for (i = 0; i < 36; i++) {
        if (expected_4[i] == ' ')
            expected_4[i] = 0;
    }
    // Comprassion
    for (i = 0; i < 6; i++)
        ASSERT_EQUAL(expected_3[i], word_2[i]);
    ASSERT_STR(expected_4, stroka_2);
}

CTEST(work_with_string_russian_words, working_splitting)
{
    printf("\n");
    // Given
    int i;
    char* stroka_1 = (char*)malloc(36 * sizeof(char));
    strcpy(stroka_1, "Тимур и его команда\0");
    int* word_1 = (int*)malloc(4 * sizeof(int));
    // When
    word_splitting(stroka_1, word_1);
    // Then
    int expected_1[4] = {0, 11, 14, 21};
    char* expected_2 = (char*)malloc(36 * sizeof(char));
    strcpy(expected_2, "Тимур и его команда\0");
    for (i = 0; i < 36; i++) {
        if (expected_2[i] == ' ')
            expected_2[i] = 0;
    }
    // Comprassion
    for (i = 0; i < 4; i++)
        ASSERT_EQUAL(expected_1[i], word_1[i]);
    ASSERT_STR(expected_2, stroka_1);
    printf("\n");
    // Given
    char* stroka_2 = (char*)malloc(81 * sizeof(char));
    strcpy(stroka_2, "Каждый охотник желает знать где сидит фазан\0");
    int* word_2 = (int*)malloc(7 * sizeof(int));
    // When
    word_splitting(stroka_2, word_2);
    // Then
    int expected_3[7] = {0, 13, 28, 41, 52, 59, 70};
    char* expected_4 = (char*)malloc(81 * sizeof(char));
    strcpy(expected_4, "Каждый охотник желает знать где сидит фазан\0");
    for (i = 0; i < 81; i++) {
        if (expected_4[i] == ' ')
            expected_4[i] = 0;
    }
    // Comprassion
    for (i = 0; i < 7; i++)
        ASSERT_EQUAL(expected_3[i], word_2[i]);
    ASSERT_STR(expected_4, stroka_2);
}

CTEST(sorting_latin_word, ShakerSort)
{
    printf("\n");
    // Given
    int i;
    char* stroka_1 = (char*)malloc(19 * sizeof(char));
    strcpy(stroka_1, "apple fortune eggs\0");
    for (i = 0; i < 19; i++) {
        if (stroka_1[i] == ' ')
            stroka_1[i] = 0;
    }
    int temp_1[3] = {0, 6, 14};
    int* word_1 = temp_1;
    // When
    ShakerSort(stroka_1, 3, word_1);
    // Then
    int expected_1[3] = {0, 14, 6};
    // Comprassion
    for (i = 0; i < 3; i++)
        ASSERT_EQUAL(expected_1[i], word_1[i]);
    printf("\n");
    // Given
    char* stroka_2 = (char*)malloc(36 * sizeof(char));
    strcpy(stroka_2, "Red Orange Yellow Green Blue Violet\0");
    for (i = 0; i < 36; i++) {
        if (stroka_2[i] == ' ')
            stroka_2[i] = 0;
    }
    int temp_2[6] = {0, 4, 11, 18, 24, 29};
    int* word_2 = temp_2;
    // When
    ShakerSort(stroka_2, 6, word_2);
    // Then
    int expected_2[6] = {24, 18, 4, 0, 29, 11};
    // Comprassion
    for (i = 0; i < 6; i++)
        ASSERT_EQUAL(expected_2[i], word_2[i]);
    printf("\n");
    // Given
    char* stroka_3 = (char*)malloc(36 * sizeof(char));
    strcpy(stroka_3, "Red orange Yellow green Blue violet\0");
    for (i = 0; i < 36; i++) {
        if (stroka_3[i] == ' ')
            stroka_3[i] = 0;
    }
    int temp_3[6] = {0, 4, 11, 18, 24, 29};
    int* word_3 = temp_3;
    // When
    ShakerSort(stroka_3, 6, word_3);
    // Then
    int expected_3[6] = {24, 0, 11, 18, 4, 29};
    // Comprassion
    for (i = 0; i < 6; i++)
        ASSERT_EQUAL(expected_3[i], word_3[i]);
}

CTEST(sorting_russian_words, ShakerSort)
{
    printf("\n");
    // Given
    int i;
    char* stroka_1 = (char*)malloc(36 * sizeof(char));
    strcpy(stroka_1, "Тимур и его команда\0");
    for (i = 0; i < 36; i++) {
        if (stroka_1[i] == ' ')
            stroka_1[i] = 0;
    }
    int temp_1[4] = {0, 11, 14, 21};
    int* word_1 = temp_1;
    // When
    ShakerSort(stroka_1, 4, word_1);
    // Then
    int expected_1[4] = {0, 14, 11, 21};
    // Comprassion
    for (i = 0; i < 4; i++)
        ASSERT_EQUAL(expected_1[i], word_1[i]);

    printf("\n");
    // Given
    char* stroka_2 = (char*)malloc(81 * sizeof(char));
    strcpy(stroka_2, "каждый охотник желает знать где сидит фазан\0");
    for (i = 0; i < 81; i++) {
        if (stroka_2[i] == ' ')
            stroka_2[i] = 0;
    }
    int temp_2[7] = {0, 13, 28, 41, 52, 59, 70};
    int* word_2 = temp_2;
    // When
    ShakerSort(stroka_2, 7, word_2);
    // Then
    int expected_2[7] = {52, 28, 41, 0, 13, 59, 70};
    // Comprassion
    for (i = 0; i < 7; i++)
        ASSERT_EQUAL(expected_2[i], word_2[i]);

    printf("\n");
    // Given
    char* stroka_3 = (char*)malloc(85 * sizeof(char));
    strcpy(stroka_3, "Каждый Охотник Желает Знать Где Сидит Глухарь\0");
    for (i = 0; i < 85; i++) {
        if (stroka_3[i] == ' ')
            stroka_3[i] = 0;
    }
    int temp_3[7] = {0, 13, 28, 41, 52, 59, 70};
    int* word_3 = temp_3;
    // When
    ShakerSort(stroka_3, 7, word_3);
    // Then
    int expected_3[7] = {52, 70, 28, 41, 0, 13, 59};
    // Comprassion
    for (i = 0; i < 7; i++)
        ASSERT_EQUAL(expected_3[i], word_3[i]);
}
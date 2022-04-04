#include <stdlib.h>
#include <stdio.h>

#include "print.h"

/*
ERROR_OK 0
ERROR_CREATE_MATRIX 1
ERROR_MEMORY_ISNT_ALLOCATED 2
ERROR_PASSING_NULL_VALUES 3
 3
 4
...
*/


void ErrorMessange(enum error code) {
    switch (code) {
    case null_type:
        printf("\nYou don't enter type of matrices or error of type.\n");
        break;
    case null_matrix_one:
        printf("\nYou don't enter matrix one.\n");
        break;
    case null_matrix_two:
        printf("\nYou don't enter matrix two.\n");
        break;
    case non_line_or_column:
        printf("\nYou don't enter line or column of matrices.\n");
        break;
    case null_ringinfo:
        printf("\nYou are missing data.");
        break;
    case impossible_conditions:
        printf("\nCannot be performed due to the size of the matrices.");
        break;
    case error_size_of_line:
        printf("\nYou enter the wrong line number.\n");
        break;
    default:
        break;
    }
}
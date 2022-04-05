#include <stdio.h>
#include <sys/types.h>
#include <time.h>

#include "matrix.h"
#include "print.h"

#define Type_Error {if (type != 'I' && type != 'F') ErrorMessange(null_type);}

int main () {
    size_t exit = 1;

    Matrix* matrix_1 = NULL;
    Matrix* matrix_2 = NULL;
    Matrix* matrix_res = NULL;
    RingInfo* ring_info = NULL;  
    size_t* error = (size_t*)malloc(sizeof(size_t));
    *error = 0;

    srand(time(NULL));
     

    //Sum matrix
    printf("______________________________________________________________________________\n");
    printf("\nSum matrix.\n");
    printf("\nTest Int of type.\n");
    char type = 'I';
    ring_info = Create(type, Sum_Matrix_I, Mult_Matrix_I, Mult_Matrix_by_Scalar_I, Transp_Matrix_I, Line_Comb_I, error);
    ERROR_OK;

    printf("Test 1.\n");
    matrix_1 = Get_Matrix_Zero(5, 4, ring_info, error);
    ERROR_OK;
    matrix_2 = Get_Matrix_Random(5, 4, ring_info, error);
    ERROR_OK;
    matrix_res = ring_info->Sum_Matrix(matrix_1, matrix_2, error);
    ERROR_OK;

    printf("\tMatrix 1: \n");
    Matrix_Print(matrix_1, ring_info);
    printf("\tMatrix 2: \n");
    Matrix_Print(matrix_2, ring_info);
    printf("\tResult: \n"); 
    Matrix_Print(matrix_res, ring_info);

    printf("Test 2.\n");
    Free_Matrix(matrix_1);
    matrix_1 = Get_Matrix_Random(5, 4, ring_info, error);
    ERROR_OK;
    Free_Matrix(matrix_2);
    matrix_2 = Get_Matrix_Random(5, 4, ring_info, error);
    ERROR_OK;
    Free_Matrix(matrix_res);
    matrix_res = ring_info->Sum_Matrix(matrix_1, matrix_2, error);
    ERROR_OK;

    printf("\tMatrix 1: \n");
    Matrix_Print(matrix_1, ring_info);
    printf("\tMatrix 2: \n");
    Matrix_Print(matrix_2, ring_info);
    printf("\tResult: \n"); 
    Matrix_Print(matrix_res, ring_info);

    printf("\nTest Double of type.\n");
    type = 'F';
    free(ring_info);
    ring_info = Create(type, Sum_Matrix_F, Mult_Matrix_F, Mult_Matrix_by_Scalar_F, Transp_Matrix_F, Line_Comb_F, error);
    ERROR_OK;
    
    printf("Test 1.\n");
    matrix_1 = Get_Matrix_Zero(5, 4, ring_info, error);
    ERROR_OK;
    matrix_2 = Get_Matrix_Random(5, 4, ring_info, error);
    ERROR_OK;
    matrix_res = ring_info->Sum_Matrix(matrix_1, matrix_2, error);
    ERROR_OK;

    printf("\tMatrix 1: \n");
    Matrix_Print(matrix_1, ring_info);
    printf("\tMatrix 2: \n");
    Matrix_Print(matrix_2, ring_info);
    printf("\tResult: \n"); 
    Matrix_Print(matrix_res, ring_info);

    printf("Test 2.\n");
    Free_Matrix(matrix_1);
    matrix_1 = Get_Matrix_Random(5, 4, ring_info, error);
    ERROR_OK;
    Free_Matrix(matrix_2);
    matrix_2 = Get_Matrix_Random(5, 4, ring_info, error);
    ERROR_OK;
    Free_Matrix(matrix_res);
    matrix_res = ring_info->Sum_Matrix(matrix_1, matrix_2, error);
    ERROR_OK;

    printf("\tMatrix 1: \n");
    Matrix_Print(matrix_1, ring_info);
    printf("\tMatrix 2: \n");
    Matrix_Print(matrix_2, ring_info);
    printf("\tResult: \n"); 
    Matrix_Print(matrix_res, ring_info);

    //Mult Matrix
    printf("______________________________________________________________________________\n");
    printf("\nMult matrix.\n");
    printf("\nTest Int of type.\n");
    type = 'I';
    free(ring_info);
    ring_info = Create(type, Sum_Matrix_I, Mult_Matrix_I, Mult_Matrix_by_Scalar_I, Transp_Matrix_I, Line_Comb_I, error);
    ERROR_OK;

    printf("Test 1.\n");
    matrix_1 = Get_Matrix_One(5, 4, ring_info, error);
    ERROR_OK;
    matrix_2 = Get_Matrix_Random(4, 3, ring_info, error);
    ERROR_OK;
    matrix_res = ring_info->Mult_Matrix(matrix_1, matrix_2, error);
    ERROR_OK;

    printf("\tMatrix 1: \n");
    Matrix_Print(matrix_1, ring_info);
    printf("\tMatrix 2: \n");
    Matrix_Print(matrix_2, ring_info);
    printf("\tResult: \n"); 
    Matrix_Print(matrix_res, ring_info);

    printf("Test 2.\n");
    Free_Matrix(matrix_1);
    matrix_1 = Get_Matrix_Random(5, 4, ring_info, error);
    ERROR_OK;
    Free_Matrix(matrix_2);
    matrix_2 = Get_Matrix_Random(4, 3, ring_info, error);
    ERROR_OK;
    Free_Matrix(matrix_res);
    matrix_res = ring_info->Mult_Matrix(matrix_1, matrix_2, error);
    ERROR_OK;

    printf("\tMatrix 1: \n");
    Matrix_Print(matrix_1, ring_info);
    printf("\tMatrix 2: \n");
    Matrix_Print(matrix_2, ring_info);
    printf("\tResult: \n"); 
    Matrix_Print(matrix_res, ring_info);

    printf("\nTest Double of type.\n");
    type = 'F';
    free(ring_info);
    ring_info = Create(type, Sum_Matrix_F, Mult_Matrix_F, Mult_Matrix_by_Scalar_F, Transp_Matrix_F, Line_Comb_F, error);
    ERROR_OK;

    printf("Test 1.\n");
    matrix_1 = Get_Matrix_One(5, 4, ring_info, error);
    ERROR_OK;
    matrix_2 = Get_Matrix_Random(4, 3, ring_info, error);
    ERROR_OK;
    matrix_res = ring_info->Mult_Matrix(matrix_1, matrix_2, error);
    ERROR_OK;

    printf("\tMatrix 1: \n");
    Matrix_Print(matrix_1, ring_info);
    printf("\tMatrix 2: \n");
    Matrix_Print(matrix_2, ring_info);
    printf("\tResult: \n"); 
    Matrix_Print(matrix_res, ring_info);

    printf("Test 2.\n");
    Free_Matrix(matrix_1);
    matrix_1 = Get_Matrix_Random(5, 4, ring_info, error);
    ERROR_OK;
    Free_Matrix(matrix_2);
    matrix_2 = Get_Matrix_Random(4, 3, ring_info, error);
    ERROR_OK;
    Free_Matrix(matrix_res);
    matrix_res = ring_info->Mult_Matrix(matrix_1, matrix_2, error);
    ERROR_OK;

    printf("\tMatrix 1: \n");
    Matrix_Print(matrix_1, ring_info);
    printf("\tMatrix 2: \n");
    Matrix_Print(matrix_2, ring_info);
    printf("\tResult: \n"); 
    Matrix_Print(matrix_res, ring_info);

    // Mult Matrix by Scalar
    printf("______________________________________________________________________________\n");
    printf("Mult Matrix by Scalar.\n");
    printf("Test Int of type.\n");







    
    return 0;   
}
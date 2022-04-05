#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>

#include "matrix.h"
#include "print.h"

#define Type_Error {if (type != 'I' && type != 'F') ErrorMessange(null_type);}
#define ring_info_i {char type = 'I';\
        free(ring_info);\
        ring_info = Create(type, Sum_Matrix_I, Mult_Matrix_I, Mult_Matrix_by_Scalar_I, Transp_Matrix_I, Line_Comb_I, error);\
        ERROR_OK;}
#define ring_info_f {type = 'F';\
        free(ring_info);\
        ring_info = Create(type, Sum_Matrix_F, Mult_Matrix_F, Mult_Matrix_by_Scalar_F, Transp_Matrix_F, Line_Comb_F, error);\
        ERROR_OK;}

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
    ring_info_f;
    
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
    ring_info_i;

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
    ring_info_f;

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
    printf("\nMult Matrix by Scalar.\n");
    printf("\nTest Int of type.\n");
    ring_info_i;

    printf("Test 1.\n");
    int scalar_i = 0;
    Free_Matrix(matrix_1);
    matrix_1 = Get_Matrix_Random(5, 4, ring_info, error);
    ERROR_OK;
    matrix_1 = ring_info->Mult_Matrix_by_Scalar(matrix_1, ((void*)&scalar_i), error);
    ERROR_OK;

    printf("\tMatrix 1: \n");
    Matrix_Print(matrix_1, ring_info);

    printf("Test 2.\n");
    scalar_i = 10;
    Free_Matrix(matrix_1);
    matrix_1 = Get_Matrix_Random(5, 4, ring_info, error);
    ERROR_OK;
    matrix_1 = ring_info->Mult_Matrix_by_Scalar(matrix_1, ((void*)&scalar_i), error);
    ERROR_OK; 
    
    printf("\tMatrix 1: \n");
    Matrix_Print(matrix_1, ring_info);

    printf("Test 3.\n");
    scalar_i = -1;
    Free_Matrix(matrix_1);
    matrix_1 = Get_Matrix_Random(5, 4, ring_info, error);
    ERROR_OK;
    matrix_1 = ring_info->Mult_Matrix_by_Scalar(matrix_1, ((void*)&scalar_i), error);
    ERROR_OK; 
    
    printf("\tMatrix 1: \n");
    Matrix_Print(matrix_1, ring_info);

    printf("\nTest Double of type.\n");
    ring_info_f;

    printf("Test 1.\n");
    double scalar_f = 0;
    Free_Matrix(matrix_1);
    matrix_1 = Get_Matrix_Random(5, 4, ring_info, error);
    ERROR_OK;
    matrix_1 = ring_info->Mult_Matrix_by_Scalar(matrix_1, ((void*)&scalar_f), error);
    ERROR_OK; 
    
    printf("\tMatrix 1: \n");
    Matrix_Print(matrix_1, ring_info);

    printf("Test 2.\n");
    scalar_f = 10;
    Free_Matrix(matrix_1);
    matrix_1 = Get_Matrix_Random(5, 4, ring_info, error);
    ERROR_OK;
    matrix_1 = ring_info->Mult_Matrix_by_Scalar(matrix_1, ((void*)&scalar_f), error);
    ERROR_OK; 
    
    printf("\tMatrix 1: \n");
    Matrix_Print(matrix_1, ring_info);

    printf("Test 3.\n");
    scalar_f = -1;
    Free_Matrix(matrix_1);
    matrix_1 = Get_Matrix_Random(5, 4, ring_info, error);
    ERROR_OK;
    matrix_1 = ring_info->Mult_Matrix_by_Scalar(matrix_1, ((void*)&scalar_f), error);
    ERROR_OK; 
    
    printf("\tMatrix 1: \n");
    Matrix_Print(matrix_1, ring_info);

    // Transp Matrix
    printf("______________________________________________________________________________\n");
    printf("\nTransp Matrix.\n");
    printf("\nTest Int of type.\n");
    ring_info_i;

    printf("Test 1.\n");
    Free_Matrix(matrix_1);
    matrix_1 = Get_Matrix_One(5, 4, ring_info, error);
    ERROR_OK;
    Free_Matrix(matrix_res);
    matrix_res = ring_info->Transp_Matrix(matrix_1, error);
    ERROR_OK;

    printf("\tMatrix 1: \n");
    Matrix_Print(matrix_1, ring_info);
    printf("\tResult: \n"); 
    Matrix_Print(matrix_res, ring_info);

    printf("Test 2.\n");
    Free_Matrix(matrix_1);
    matrix_1 = Get_Matrix_Random(5, 4, ring_info, error);
    ERROR_OK;
    Free_Matrix(matrix_res);
    matrix_res = ring_info->Transp_Matrix(matrix_1, error);
    ERROR_OK;

    printf("\tMatrix 1: \n");
    Matrix_Print(matrix_1, ring_info);
    printf("\tResult: \n"); 
    Matrix_Print(matrix_res, ring_info);

    printf("\nTest Double of type.\n");
    ring_info_f;

    printf("Test 1.\n");
    Free_Matrix(matrix_1);
    matrix_1 = Get_Matrix_One(5, 4, ring_info, error);
    ERROR_OK;
    Free_Matrix(matrix_res);
    matrix_res = ring_info->Transp_Matrix(matrix_1, error);
    ERROR_OK;

    printf("\tMatrix 1: \n");
    Matrix_Print(matrix_1, ring_info);
    printf("\tResult: \n"); 
    Matrix_Print(matrix_res, ring_info);

    printf("Test 2.\n");
    Free_Matrix(matrix_1);
    matrix_1 = Get_Matrix_Random(5, 4, ring_info, error);
    ERROR_OK;
    Free_Matrix(matrix_res);
    matrix_res = ring_info->Transp_Matrix(matrix_1, error);
    ERROR_OK;

    printf("\tMatrix 1: \n");
    Matrix_Print(matrix_1, ring_info);
    printf("\tResult: \n"); 
    Matrix_Print(matrix_res, ring_info);

    // Line_Comb
    printf("______________________________________________________________________________\n");
    printf("\nLine Comb.\n");
    printf("\nTest Int of type.\n");
    ring_info_i;
    
    printf("Test 1.\n");
    Free_Matrix(matrix_1);
    matrix_1 = Get_Matrix_One(5, 4, ring_info, error);
    ERROR_OK;
    LineComb* scalar;
    scalar = (LineComb*)malloc(sizeof(LineComb));
    scalar->scalar = (void*)malloc(sizeof(int)*4);
    scalar->scalar_number = 0;
    for (int i = 0; i < 4; i++){
        ((int*)scalar->scalar)[i] = 1;
    }
    
    Free_Matrix(matrix_res);
    matrix_res = ring_info->Line_Comb(matrix_1, scalar, error);
    ERROR_OK;

    printf("\tMatrix 1: \n");
    Matrix_Print(matrix_1, ring_info);
    printf("\tResult: \n"); 
    Matrix_Print(matrix_res, ring_info);
    free(scalar->scalar);
    free(scalar);

    printf("Test 2.\n");
    Free_Matrix(matrix_1);
    matrix_1 = Get_Matrix_One(5, 4, ring_info, error);
    ERROR_OK;
    scalar = (LineComb*)malloc(sizeof(LineComb));
    scalar->scalar = (void*)malloc(sizeof(int)*4);
    scalar->scalar_number = 1;
    for (int i = 0; i < 4; i++){
        ((int*)scalar->scalar)[i] = 10;
    }
    
    Free_Matrix(matrix_res);
    matrix_res = ring_info->Line_Comb(matrix_1, scalar, error);
    ERROR_OK;

    printf("\tMatrix 1: \n");
    Matrix_Print(matrix_1, ring_info);
    printf("\tResult: \n"); 
    Matrix_Print(matrix_res, ring_info);
    free(scalar->scalar);
    free(scalar);

    printf("Test 3.\n");
    Free_Matrix(matrix_1);
    matrix_1 = Get_Matrix_One(5, 4, ring_info, error);
    ERROR_OK;
    scalar = (LineComb*)malloc(sizeof(LineComb));
    scalar->scalar = (void*)malloc(sizeof(int)*4);
    scalar->scalar_number = 3;
    for (int i = 0; i < 4; i++){
        ((int*)scalar->scalar)[i] = -1;
    }
    
    Free_Matrix(matrix_res);
    matrix_res = ring_info->Line_Comb(matrix_1, scalar, error);
    ERROR_OK;

    printf("\tMatrix 1: \n");
    Matrix_Print(matrix_1, ring_info);
    printf("\tResult: \n"); 
    Matrix_Print(matrix_res, ring_info);
    free(scalar->scalar);
    free(scalar);

    printf("\nTest Double of type.\n");
    ring_info_f;

    printf("Test 1.\n");
    Free_Matrix(matrix_1);
    matrix_1 = Get_Matrix_One(5, 4, ring_info, error);
    ERROR_OK;
    scalar = (LineComb*)malloc(sizeof(LineComb));
    scalar->scalar = (void*)malloc(sizeof(double)*4);
    scalar->scalar_number = 0;
    for (int i = 0; i < 4; i++){
        ((double*)scalar->scalar)[i] = 1;
    }
    
    Free_Matrix(matrix_res);
    matrix_res = ring_info->Line_Comb(matrix_1, scalar, error);
    ERROR_OK;

    printf("\tMatrix 1: \n");
    Matrix_Print(matrix_1, ring_info);
    printf("\tResult: \n"); 
    Matrix_Print(matrix_res, ring_info);
    free(scalar->scalar);
    free(scalar);

    printf("Test 2.\n");
    Free_Matrix(matrix_1);
    matrix_1 = Get_Matrix_One(5, 4, ring_info, error);
    ERROR_OK;
    scalar = (LineComb*)malloc(sizeof(LineComb));
    scalar->scalar = (void*)malloc(sizeof(double)*4);
    scalar->scalar_number = 2;
    for (int i = 0; i < 4; i++){
        ((double*)scalar->scalar)[i] = 10;
    }
    
    Free_Matrix(matrix_res);
    matrix_res = ring_info->Line_Comb(matrix_1, scalar, error);
    ERROR_OK;

    printf("\tMatrix 1: \n");
    Matrix_Print(matrix_1, ring_info);
    printf("\tResult: \n"); 
    Matrix_Print(matrix_res, ring_info);
    free(scalar->scalar);
    free(scalar);

    printf("Test 3.\n");
    Free_Matrix(matrix_1);
    matrix_1 = Get_Matrix_One(5, 4, ring_info, error);
    ERROR_OK;
    scalar = (LineComb*)malloc(sizeof(LineComb));
    scalar->scalar = (void*)malloc(sizeof(double)*4);
    scalar->scalar_number = 3;
    for (int i = 0; i < 4; i++){
        ((double*)scalar->scalar)[i] = -1;
    }
    
    Free_Matrix(matrix_res);
    matrix_res = ring_info->Line_Comb(matrix_1, scalar, error);
    ERROR_OK;

    printf("\tMatrix 1: \n");
    Matrix_Print(matrix_1, ring_info);
    printf("\tResult: \n"); 
    Matrix_Print(matrix_res, ring_info);
    free(scalar->scalar);
    free(scalar);

    return 0;   
}
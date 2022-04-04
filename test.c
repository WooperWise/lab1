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
    printf("Sum matrix.\n");
    printf("Int\n");
    char type = 'I';
    ring_info = Create(type, Sum_Matrix_I, Mult_Matrix_I, Mult_Matrix_by_Scalar_I, Transp_Matrix_I, Line_Comb_I, error);
    ERROR_OK;

    matrix_1 = Get_Matrix_Zero(10, 5, ring_info, error);
    ERROR_OK;
    matrix_2 = Get_Matrix_Random(10, 5, ring_info, error);
    ERROR_OK;
    matrix_res = ring_info->Sum_Matrix(matrix_1, matrix_2, error);
    ERROR_OK;

    printf("Matrix 1: \n");
    Matrix_Print(matrix_1, ring_info);
    printf("Matrix 2: \n");
    Matrix_Print(matrix_2, ring_info);
    printf("Result: \n"); 
    Matrix_Print(matrix_res, ring_info);

    Free_Matrix(matrix_1);
    matrix_1 = Get_Matrix_Random(10, 5, ring_info, error);
    ERROR_OK;
    Free_Matrix(matrix_2);
    matrix_2 = Get_Matrix_Random(10, 5, ring_info, error);
    ERROR_OK;
    Free_Matrix(matrix_res);
    matrix_res = ring_info->Sum_Matrix(matrix_1, matrix_2, error);
    ERROR_OK;

    printf("Matrix 1: \n");
    Matrix_Print(matrix_1, ring_info);
    printf("Matrix 2: \n");
    Matrix_Print(matrix_2, ring_info);
    printf("Result: \n"); 
    Matrix_Print(matrix_res, ring_info);

    printf("Double\n");
    type = 'F';
    ring_info = Create(type, Sum_Matrix_I, Mult_Matrix_I, Mult_Matrix_by_Scalar_I, Transp_Matrix_I, Line_Comb_I, error);
    ERROR_OK;

    matrix_1 = Get_Matrix_Zero(10, 5, ring_info, error);
    ERROR_OK;
    matrix_2 = Get_Matrix_Random(10, 5, ring_info, error);
    ERROR_OK;
    matrix_res = ring_info->Sum_Matrix(matrix_1, matrix_2, error);
    ERROR_OK;

    printf("Matrix 1: \n");
    Matrix_Print(matrix_1, ring_info);
    printf("Matrix 2: \n");
    Matrix_Print(matrix_2, ring_info);
    printf("Result: \n"); 
    Matrix_Print(matrix_res, ring_info);

    Free_Matrix(matrix_1);
    matrix_1 = Get_Matrix_Random(10, 5, ring_info, error);
    ERROR_OK;
    Free_Matrix(matrix_2);
    matrix_2 = Get_Matrix_Random(10, 5, ring_info, error);
    ERROR_OK;
    Free_Matrix(matrix_res);
    matrix_res = ring_info->Sum_Matrix(matrix_1, matrix_2, error);
    ERROR_OK;

    printf("Matrix 1: \n");
    Matrix_Print(matrix_1, ring_info);
    printf("Matrix 2: \n");
    Matrix_Print(matrix_2, ring_info);
    printf("Result: \n"); 
    Matrix_Print(matrix_res, ring_info);

    //Mult Matrix
    printf("______________________________________________________________________________\n");
    printf("Mult matrix.\n");
    printf("Int\n");
    type = 'F';
    ring_info = Create(type, Sum_Matrix_I, Mult_Matrix_I, Mult_Matrix_by_Scalar_I, Transp_Matrix_I, Line_Comb_I, error);
    ERROR_OK;

    matrix_1 = Get_Matrix_One(10, 5, ring_info, error);
    ERROR_OK;
    matrix_2 = Get_Matrix_Random(5, 4, ring_info, error);
    ERROR_OK;
    matrix_res = ring_info->Mult_Matrix(matrix_1, matrix_2, error);
    ERROR_OK;

    printf("Matrix 1: \n");
    Matrix_Print(matrix_1, ring_info);
    printf("Matrix 2: \n");
    Matrix_Print(matrix_2, ring_info);
    printf("Result: \n"); 
    Matrix_Print(matrix_res, ring_info);

    Free_Matrix(matrix_1);
    matrix_1 = Get_Matrix_Random(10, 5, ring_info, error);
    ERROR_OK;
    Free_Matrix(matrix_2);
    matrix_2 = Get_Matrix_Random(5, 4, ring_info, error);
    ERROR_OK;
    Free_Matrix(matrix_res);
    matrix_res = ring_info->Mult_Matrix(matrix_1, matrix_2, error);
    ERROR_OK;

    printf("Matrix 1: \n");
    Matrix_Print(matrix_1, ring_info);
    printf("Matrix 2: \n");
    Matrix_Print(matrix_2, ring_info);
    printf("Result: \n"); 
    Matrix_Print(matrix_res, ring_info);

    printf("Double\n");
    type = 'F';
    ring_info = Create(type, Sum_Matrix_I, Mult_Matrix_I, Mult_Matrix_by_Scalar_I, Transp_Matrix_I, Line_Comb_I, error);
    ERROR_OK;

    matrix_1 = Get_Matrix_One(10, 5, ring_info, error);
    ERROR_OK;
    matrix_2 = Get_Matrix_Random(5, 4, ring_info, error);
    ERROR_OK;
    matrix_res = ring_info->Mult_Matrix(matrix_1, matrix_2, error);
    ERROR_OK;

    printf("Matrix 1: \n");
    Matrix_Print(matrix_1, ring_info);
    printf("Matrix 2: \n");
    Matrix_Print(matrix_2, ring_info);
    printf("Result: \n"); 
    Matrix_Print(matrix_res, ring_info);

    Free_Matrix(matrix_1);
    matrix_1 = Get_Matrix_Random(10, 5, ring_info, error);
    ERROR_OK;
    Free_Matrix(matrix_2);
    matrix_2 = Get_Matrix_Random(5, 4, ring_info, error);
    ERROR_OK;
    Free_Matrix(matrix_res);
    matrix_res = ring_info->Mult_Matrix(matrix_1, matrix_2, error);
    ERROR_OK;

    printf("Matrix 1: \n");
    Matrix_Print(matrix_1, ring_info);
    printf("Matrix 2: \n");
    Matrix_Print(matrix_2, ring_info);
    printf("Result: \n"); 
    Matrix_Print(matrix_res, ring_info);









    
    return 0;   
}
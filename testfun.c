#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "matrix.h"
#include "testfun.h"

Matrix* matrix_get_int (size_t l, size_t c) {
    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
    matrix->line = l;
    matrix->column = c;
    matrix->array = (void**)malloc(sizeof(void*)*matrix->line);
    for (int i = 0; i < matrix->line; i++) {
        matrix->array[i] = (void*)malloc(sizeof(int)*matrix->column);
    }
    return matrix;
};

Matrix* matrix_get_double (size_t l, size_t c) {
    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
    matrix->line = l;
    matrix->column = c;
    matrix->array = (void**)malloc(sizeof(void*)*matrix->line);
    for (int i = 0; i < matrix->line; i++) {
        matrix->array[i] = (void*)malloc(sizeof(double)*matrix->column);
    }
    return matrix;
};

void sum_test_1 (size_t* exit, RingInfo* r, size_t* error) {
    Matrix* mat1 = matrix_get_int(4, 5);
    Matrix* mat2 = matrix_get_int(4, 5);
    Matrix* res;
    Matrix* answer = matrix_get_int(4, 5);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            ((int**)mat1->array)[i][j] = 0;
            ((int**)mat2->array)[i][j] = j + 1; 
        }
    }
    res = (Matrix*)r->Sum_Matrix((void*)mat1, (void*)mat2, error);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) { 
            ((int**)answer->array)[i][j] = j + 1;
            if (((int**)res->array)[i][j] != ((int**)answer->array)[i][j]) *exit = 0;
        }
    }
    Matrix_Erase(mat1);
    Matrix_Erase(mat2);
    Matrix_Erase(res);
    Matrix_Erase(answer);
}

void sum_test_2 (size_t* exit, RingInfo* r, size_t* error) {
    Matrix* mat1 = matrix_get_int(4, 5);
    Matrix* mat2 = matrix_get_int(4, 5);
    Matrix* res;
    Matrix* answer = matrix_get_int(4, 5);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            ((int**)mat1->array)[i][j] = j + 2;
            ((int**)mat2->array)[i][j] = j + 1; 
        }
    }
    res = (Matrix*)r->Sum_Matrix((void*)mat1, (void*)mat2, error);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) { 
            ((int**)answer->array)[i][j] = j + j + 3;
            if (((int**)res->array)[i][j] != ((int**)answer->array)[i][j]) *exit = 0;
        }
    }
    Matrix_Erase(mat1);
    Matrix_Erase(mat2);
    Matrix_Erase(res);
    Matrix_Erase(answer);
}

void sum_test_3 (size_t* exit, RingInfo* r, size_t* error) {
    Matrix* mat1 = matrix_get_double(4, 5);
    Matrix* mat2 = matrix_get_double(4, 5);
    Matrix* res;
    Matrix* answer = matrix_get_double(4, 5);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            ((double**)mat1->array)[i][j] = 0.0;
            ((double**)mat2->array)[i][j] = (double)(j + 1) / 10;
        }
    }
    res = (Matrix*)r->Sum_Matrix((void*)mat1, (void*)mat2, error);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            ((double**)answer->array)[i][j] = (double)(j + 1) / 10;
            if (((double**)res->array)[i][j] != ((double**)answer->array)[i][j]) *exit = 0;
        }
    }
    Matrix_Erase(mat1);
    Matrix_Erase(mat2);
    Matrix_Erase(res);
    Matrix_Erase(answer);
}

void sum_test_4 (size_t* exit, RingInfo* r, size_t* error) {
    Matrix* mat1 = matrix_get_double(4, 5);
    Matrix* mat2 = matrix_get_double(4, 5);
    Matrix* res;
    Matrix* answer = matrix_get_double(4, 5);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            ((double**)mat1->array)[i][j] = (double)(j + 2) / 10;
            ((double**)mat2->array)[i][j] = (double)(j + 1) / 10;
        }
    }
    res = (Matrix*)r->Sum_Matrix((void*)mat1, (void*)mat2, error);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            ((double**)answer->array)[i][j] = ((double)(j + 2) / 10) + ((double)(j + 1) / 10);
            if (((double**)res->array)[i][j] != ((double**)answer->array)[i][j]) *exit = 0;
        }
    }
    Matrix_Erase(mat1);
    Matrix_Erase(mat2);
    Matrix_Erase(res);
    Matrix_Erase(answer);
}

void mult_test_5 (size_t* exit, RingInfo* r, size_t* error) {
    Matrix* mat1 = matrix_get_int(5, 4);
    Matrix* mat2 = matrix_get_int(4, 3);
    Matrix* res;
    Matrix* answer = matrix_get_int(5, 3);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j) {((int**)mat1->array)[i][j] = 1;}
            else {((int**)mat1->array)[i][j] = 0;}
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            ((int**)mat2->array)[i][j] = j + 1;
        }
    }
    res = (Matrix*)r->Mult_Matrix((void*)mat1, (void*)mat2, error);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            if (i > 3) {((int**)answer->array)[i][j] = 0;}
            else {((int**)answer->array)[i][j] = j + 1;}
            if (((int**)res->array)[i][j] != ((int**)answer->array)[i][j]) *exit = 0;
        }
    }
    Matrix_Erase(mat1);
    Matrix_Erase(mat2);
    Matrix_Erase(res);
    Matrix_Erase(answer);
}

void mult_test_6 (size_t* exit, RingInfo* r, size_t* error) {
    Matrix* mat1 = matrix_get_int(5, 4);
    Matrix* mat2 = matrix_get_int(4, 3);
    Matrix* res;
    Matrix* answer = matrix_get_int(5, 3);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            ((int**)mat1->array)[i][j] = j + 1;
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            ((int**)mat2->array)[i][j] = j + 2;
        }
    }
    res = (Matrix*)r->Mult_Matrix((void*)mat1, (void*)mat2, error);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            ((int**)answer->array)[i][j] = (j + 2) * 10;
            if (((int**)res->array)[i][j] != ((int**)answer->array)[i][j]) *exit = 0;
        }
    }
    Matrix_Erase(mat1);
    Matrix_Erase(mat2);
    Matrix_Erase(res);
    Matrix_Erase(answer);
}

void mult_test_7 (size_t* exit, RingInfo* r, size_t* error) {
    Matrix* mat1 = matrix_get_double(5, 4);
    Matrix* mat2 = matrix_get_double(4, 3);
    Matrix* res;
    Matrix* answer = matrix_get_double(5, 3);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j) {((double**)mat1->array)[i][j] = 1.0;}
            else {((double**)mat1->array)[i][j] = 0.0;}
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            ((double**)mat2->array)[i][j] = (double)(j + 1) / 10;
        }
    }
    res = (Matrix*)r->Mult_Matrix((void*)mat1, (void*)mat2, error);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            if (i > 3) {((double**)answer->array)[i][j] = 0.0;}
            else {((double**)answer->array)[i][j] = (double)(j + 1) / 10;}
            if (((double**)res->array)[i][j] != ((double**)answer->array)[i][j]) *exit = 0;
        }
    }
    Matrix_Erase(mat1);
    Matrix_Erase(mat2);
    Matrix_Erase(res);
    Matrix_Erase(answer);
}

void mult_test_8 (size_t* exit, RingInfo* r, size_t* error) {
    Matrix* mat1 = matrix_get_double(5, 4);
    Matrix* mat2 = matrix_get_double(4, 3);
    Matrix* res;
    Matrix* answer = matrix_get_double(5, 3);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            ((double**)mat1->array)[i][j] = (double)(j + 1) / 10;
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            ((double**)mat2->array)[i][j] = (double)(j + 2) / 10;
        }
    }
    res = (Matrix*)r->Mult_Matrix((void*)mat1, (void*)mat2, error);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            ((double**)answer->array)[i][j] = (double)(j + 2) / 10;
            if (((double**)res->array)[i][j] != ((double**)answer->array)[i][j]) *exit = 0;
        }
    }
    Matrix_Erase(mat1);
    Matrix_Erase(mat2);
    Matrix_Erase(res);
    Matrix_Erase(answer);
}

void mult_by_scalar_test_9 (size_t* exit, RingInfo* r, size_t* error) {
    int scalar = 0;
    Matrix* mat1 = matrix_get_int(5, 4);
    Matrix* answer = matrix_get_int(5, 4);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            ((int**)mat1->array)[i][j] = j + 1;
        }
    }
    mat1 = (Matrix*)r->Mult_Matrix_by_Scalar((void*)mat1, (void*)(&scalar), error);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            ((int**)answer->array)[i][j] = 0;
            if (((int**)mat1->array)[i][j] != ((int**)answer->array)[i][j]) *exit = 0;
        }
    }
    Matrix_Erase(mat1);
    Matrix_Erase(answer);
}

void mult_by_scalar_test_10 (size_t* exit, RingInfo* r, size_t* error) {
    int scalar = 10;
    Matrix* mat1 = matrix_get_int(5, 4);
    Matrix* answer = matrix_get_int(5, 4);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            ((int**)mat1->array)[i][j] = j + 1;
        }
    }
    mat1 = (Matrix*)r->Mult_Matrix_by_Scalar((void*)mat1, (void*)(&scalar), error);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            ((int**)answer->array)[i][j] = (j + 1) * 10;
            if (((int**)mat1->array)[i][j] != ((int**)answer->array)[i][j]) *exit = 0;
        }
    }
    Matrix_Erase(mat1);
    Matrix_Erase(answer);
}

void mult_by_scalar_test_11 (size_t* exit, RingInfo* r, size_t* error) {
    int scalar = -1;
    Matrix* mat1 = matrix_get_int(5, 4);
    Matrix* answer = matrix_get_int(5, 4);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            ((int**)mat1->array)[i][j] = j + 1;
        }
    }
    mat1 = (Matrix*)r->Mult_Matrix_by_Scalar((void*)mat1, (void*)(&scalar), error);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            ((int**)answer->array)[i][j] = -(j + 1);
            if (((int**)mat1->array)[i][j] != ((int**)answer->array)[i][j]) *exit = 0;
        }
    }
    Matrix_Erase(mat1);
    Matrix_Erase(answer);
}

void mult_by_scalar_test_12 (size_t* exit, RingInfo* r, size_t* error) {
    double scalar = 0.0;
    Matrix* mat1 = matrix_get_double(5, 4);
    Matrix* answer = matrix_get_double(5, 4);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            ((double**)mat1->array)[i][j] = (double)(j + 1) / 10;
        }
    }
    mat1 = (Matrix*)r->Mult_Matrix_by_Scalar((void*)mat1, (void*)(&scalar), error);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            ((double**)answer->array)[i][j] = 0.0;
            if (((double**)mat1->array)[i][j] != ((double**)answer->array)[i][j]) *exit = 0;
        }
    }
    Matrix_Erase(mat1);
    Matrix_Erase(answer);
}

void mult_by_scalar_test_13 (size_t* exit, RingInfo* r, size_t* error) {
    double scalar = 10.0;
    Matrix* mat1 = matrix_get_double(5, 4);
    Matrix* answer = matrix_get_double(5, 4);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            ((double**)mat1->array)[i][j] = (double)(j + 1) / 10;
        }
    }
    mat1 = (Matrix*)r->Mult_Matrix_by_Scalar((void*)mat1, (void*)(&scalar), error);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            ((double**)answer->array)[i][j] = j + 1;
            if (((double**)mat1->array)[i][j] != ((double**)answer->array)[i][j]) *exit = 0;
        }
    }
    Matrix_Erase(mat1);
    Matrix_Erase(answer);
}

void mult_by_scalar_test_14 (size_t* exit, RingInfo* r, size_t* error) {
    double scalar = -1.0;
    Matrix* mat1 = matrix_get_double(5, 4);
    Matrix* answer = matrix_get_double(5, 4);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            ((double**)mat1->array)[i][j] = (double)(j + 1) / 10;
        }
    }
    mat1 = (Matrix*)r->Mult_Matrix_by_Scalar((void*)mat1, (void*)(&scalar), error);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            ((double**)answer->array)[i][j] = -((double)(j + 1) / 10);
            if (((double**)mat1->array)[i][j] != ((double**)answer->array)[i][j]) *exit = 0;
        }
    }
    Matrix_Erase(mat1);
    Matrix_Erase(answer);
}

void transp_test_15 (size_t* exit, RingInfo* r, size_t* error) {
    Matrix* mat1 = matrix_get_int(5, 4);
    Matrix* res;
    Matrix* answer = matrix_get_int(4, 5);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j) {((int**)mat1->array)[i][j] = 1;}
            else {((int**)mat1->array)[i][j] = 0;}
        }
    }
    res = (Matrix*)r->Transp_Matrix((void*)mat1, error);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == j) {((int**)answer->array)[i][j] = 1;}
            else {((int**)answer->array)[i][j] = 0;}
            if (((int**)res->array)[i][j] != ((int**)answer->array)[i][j]) *exit = 0;
        }
    }
    Matrix_Erase(mat1);
    Matrix_Erase(res);
    Matrix_Erase(answer);
}

void transp_test_16 (size_t* exit, RingInfo* r, size_t* error) {
    Matrix* mat1 = matrix_get_int(5, 4);
    Matrix* res;
    Matrix* answer = matrix_get_int(4, 5);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            ((int**)mat1->array)[i][j] = j + 1;
        }
    }
    res = (Matrix*)r->Transp_Matrix((void*)mat1, error);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            ((int**)answer->array)[i][j] = i + 1;
            if (((int**)res->array)[i][j] != ((int**)answer->array)[i][j]) *exit = 0;
        }
    }
    Matrix_Erase(mat1);
    Matrix_Erase(res);
    Matrix_Erase(answer);
}

void transp_test_17 (size_t* exit, RingInfo* r, size_t* error) {
    Matrix* mat1 = matrix_get_double(5, 4);
    Matrix* res;
    Matrix* answer = matrix_get_double(4, 5);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j) {((double**)mat1->array)[i][j] = 1.0;}
            else {((double**)mat1->array)[i][j] = 0.0;}
        }
    }
    res = (Matrix*)r->Transp_Matrix((void*)mat1, error);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == j) {((double**)answer->array)[i][j] = 1.0;}
            else {((double**)answer->array)[i][j] = 0.0;}
            if (((double**)res->array)[i][j] != ((double**)answer->array)[i][j]) *exit = 0;
        }
    }
    Matrix_Erase(mat1);
    Matrix_Erase(res);
    Matrix_Erase(answer);
}

void transp_test_18 (size_t* exit, RingInfo* r, size_t* error) {
    Matrix* mat1 = matrix_get_double(5, 4);
    Matrix* res;
    Matrix* answer = matrix_get_double(4, 5);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            ((double**)mat1->array)[i][j] = (double)(j + 1) / 10;
        }
    }
    res = (Matrix*)r->Transp_Matrix((void*)mat1, error);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            ((double**)answer->array)[i][j] = (double)(i + 1) / 10;
            if (((double**)res->array)[i][j] != ((double**)answer->array)[i][j]) *exit = 0;
        }
    }
    Matrix_Erase(mat1);
    Matrix_Erase(res);
    Matrix_Erase(answer);
}

void line_comb_test_19 (size_t* exit, RingInfo* r, size_t* error) {
    LineComb* scalar = (LineComb*)malloc(sizeof(LineComb));
    scalar->scalar_number = 0;
    scalar->scalar = (void*)malloc(sizeof(int)*4);
    for (int i = 0; i < 4; i++) ((int*)scalar->scalar)[i] = 0;
    Matrix* mat1 = matrix_get_int(5, 4);
    Matrix* res;
    Matrix* answer = matrix_get_int(5, 4);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j) {((int**)mat1->array)[i][j] = 1;}
            else {((int**)mat1->array)[i][j] = 0;}
        }
    }
    res = (Matrix*)r->Line_Comb((void*)mat1, scalar, error);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j) {((int**)answer->array)[i][j] = 1;}
            else {((int**)answer->array)[i][j] = 0;}
            if (((int**)res->array)[i][j] != ((int**)answer->array)[i][j]) *exit = 0;
        }
    }
    free(scalar->scalar);
    free(scalar);
    Matrix_Erase(mat1);
    Matrix_Erase(res);
    Matrix_Erase(answer);
}

void line_comb_test_20 (size_t* exit, RingInfo* r, size_t* error) {
    LineComb* scalar = (LineComb*)malloc(sizeof(LineComb));
    scalar->scalar_number = 1;
    scalar->scalar = (void*)malloc(sizeof(int)*4);
    for (int i = 0; i < 4; i++) ((int*)scalar->scalar)[i] = 10;
    Matrix* mat1 = matrix_get_int(5, 4);
    Matrix* res;
    Matrix* answer = matrix_get_int(5, 4);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j) {((int**)mat1->array)[i][j] = 1;}
            else {((int**)mat1->array)[i][j] = 0;}
        }
    }
    res = (Matrix*)r->Line_Comb((void*)mat1, scalar, error);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j) {((int**)answer->array)[i][j] = 1;}
            else {((int**)answer->array)[i][j] = 0;}
            if ((i == scalar->scalar_number) && (i != j)) ((int**)answer->array)[i][j] += 10;
            if (((int**)res->array)[i][j] != ((int**)answer->array)[i][j]) *exit = 0;
        }
    }
    free(scalar->scalar);
    free(scalar);
    Matrix_Erase(mat1);
    Matrix_Erase(res);
    Matrix_Erase(answer);
}

void line_comb_test_21 (size_t* exit, RingInfo* r, size_t* error) {
    LineComb* scalar = (LineComb*)malloc(sizeof(LineComb));
    scalar->scalar_number = 2;
    scalar->scalar = (void*)malloc(sizeof(int)*4);
    for (int i = 0; i < 4; i++) ((int*)scalar->scalar)[i] = -1;
    Matrix* mat1 = matrix_get_int(5, 4);
    Matrix* res;
    Matrix* answer = matrix_get_int(5, 4);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j) {((int**)mat1->array)[i][j] = 1;}
            else {((int**)mat1->array)[i][j] = 0;}
        }
    }
    res = (Matrix*)r->Line_Comb((void*)mat1, scalar, error);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j) {((int**)answer->array)[i][j] = 1;}
            else {((int**)answer->array)[i][j] = 0;}
            if ((i == scalar->scalar_number) && (i != j)) ((int**)answer->array)[i][j] += (-1);
            if (((int**)res->array)[i][j] != ((int**)answer->array)[i][j]) *exit = 0;
        }
    }
    free(scalar->scalar);
    free(scalar);
    Matrix_Erase(mat1);
    Matrix_Erase(res);
    Matrix_Erase(answer);
}

void line_comb_test_22 (size_t* exit, RingInfo* r, size_t* error) {
    LineComb* scalar = (LineComb*)malloc(sizeof(LineComb));
    scalar->scalar_number = 0;
    scalar->scalar = (void*)malloc(sizeof(double)*4);
    for (int i = 0; i < 4; i++) ((double*)scalar->scalar)[i] = 0.0;
    Matrix* mat1 = matrix_get_double(5, 4);
    Matrix* res;
    Matrix* answer = matrix_get_double(5, 4);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j) {((double**)mat1->array)[i][j] = 0.1;}
            else {((double**)mat1->array)[i][j] = 0;}
        }
    }
    res = (Matrix*)r->Line_Comb((void*)mat1, scalar, error);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j) {((double**)answer->array)[i][j] = 0.1;}
            else {((double**)answer->array)[i][j] = 0.0;}
            if (((double**)res->array)[i][j] != ((double**)answer->array)[i][j]) *exit = 0;
        }
    }
    free(scalar->scalar);
    free(scalar);
    Matrix_Erase(mat1);
    Matrix_Erase(res);
    Matrix_Erase(answer);
}

void line_comb_test_23 (size_t* exit, RingInfo* r, size_t* error) {
    LineComb* scalar = (LineComb*)malloc(sizeof(LineComb));
    scalar->scalar_number = 1;
    scalar->scalar = (void*)malloc(sizeof(double)*4);
    for (int i = 0; i < 4; i++) ((double*)scalar->scalar)[i] = 10.0;
    Matrix* mat1 = matrix_get_double(5, 4);
    Matrix* res;
    Matrix* answer = matrix_get_double(5, 4);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j) {((double**)mat1->array)[i][j] = 0.1;}
            else {((double**)mat1->array)[i][j] = 0;}
        }
    }
    res = (Matrix*)r->Line_Comb((void*)mat1, scalar, error);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j) {((double**)answer->array)[i][j] = 0.1;}
            else {((double**)answer->array)[i][j] = 0.0;}
            if ((i == scalar->scalar_number) && (i != j)) ((double**)answer->array)[i][j] += 1.0;
            if (((double**)res->array)[i][j] != ((double**)answer->array)[i][j]) *exit = 0;
        }
    }
    free(scalar->scalar);
    free(scalar);
    Matrix_Erase(mat1);
    Matrix_Erase(res);
    Matrix_Erase(answer);
}

void line_comb_test_24 (size_t* exit, RingInfo* r, size_t* error) {
    LineComb* scalar = (LineComb*)malloc(sizeof(LineComb));
    scalar->scalar_number = 2;
    scalar->scalar = (void*)malloc(sizeof(double)*4);
    for (int i = 0; i < 4; i++) ((double*)scalar->scalar)[i] = -1.0;
    Matrix* mat1 = matrix_get_double(5, 4);
    Matrix* res;
    Matrix* answer = matrix_get_double(5, 4);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j) {((double**)mat1->array)[i][j] = 0.1;}
            else {((double**)mat1->array)[i][j] = 0;}
        }
    }
    res = (Matrix*)r->Line_Comb((void*)mat1, scalar, error);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j) {((double**)answer->array)[i][j] = 0.1;}
            else {((double**)answer->array)[i][j] = 0.0;}
            if ((i == scalar->scalar_number) && (i != j)) ((double**)answer->array)[i][j] += (-0.1);
            if (((double**)res->array)[i][j] != ((double**)answer->array)[i][j]) *exit = 0;
        }
    }
    free(scalar->scalar);
    free(scalar);
    Matrix_Erase(mat1);
    Matrix_Erase(res);
    Matrix_Erase(answer);
}

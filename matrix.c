#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "print.h"
#include "matrix.h"

RingInfo* Create (
    char type,
    void* (*Sum_Matrix) (void*, void*, size_t*),
    void* (*Mult_Matrix) (void*, void*, size_t*),
    void* (*Mult_Matrix_by_Scalar) (void*, void*, size_t*),
    void* (*Transp_Matrix) (void*, size_t*),
    void* (*Line_Comb) (void*, LineComb*, size_t*),
    size_t* error
) {
    RingInfo *ring_info = (RingInfo*)malloc(sizeof(RingInfo));
    error_2(ring_info);

    RN_insert(type); 
    RN_insert(Sum_Matrix); 
    RN_insert(Mult_Matrix);
    RN_insert(Mult_Matrix_by_Scalar);
    RN_insert(Transp_Matrix); 
    RN_insert(Line_Comb);

    return ring_info;
}

void Matrix_Erase (void* matrix) {
    Matrix* matrix_erase = (Matrix*)matrix;
    for (int i = 0; i < matrix_erase->line; i++) {
        free(matrix_erase->array[i]);
    }
    free(matrix_erase->array);
    free(matrix_erase);
}

void* Get_Matrix (size_t line, size_t column, RingInfo* ring_info, size_t* error) {
    if ((line == 0) || (column == 0) || (ring_info == NULL)) {
        *error = 3;
        return NULL;
    }
    size_t flag = 0;
    if (ring_info->type == 'I') flag = 1;
    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
    error_2(matrix);

    matrix->line = line;
    matrix->column = column;

    matrix->array = (void**)malloc(sizeof(void*)*line);
    error_2(matrix->array);

    if (flag == 1) {
        for (int i = 0; i < line; i++) {
            matrix->array[i] = (void*)malloc(sizeof(int)*column);
            error_2(matrix->array[i]); 
        }
        enter; 
        for (int i = 0; i < line; i++) { 
            for (int j = 0; j < column; j++) { 
                scanf("%d", &(((int**)matrix->array)[i][j]));
            } 
        }
    } else {
        for (int i = 0; i < line; i++) {
            matrix->array[i] = (void*)malloc(sizeof(double)*column);
            error_2(matrix->array[i]);
        }
        enter;
        for (int i = 0; i < line; i++) {
            for (int j = 0; j < column; j++) {
                scanf("%lf", &(((double**)matrix->array)[i][j]));
            } 
        }
    }

    return (void*)matrix;
}

LineComb* Get_Scalar (size_t number, RingInfo* ring_info, size_t column, size_t* error) {
    LineComb* scalar = (LineComb*)malloc(sizeof(LineComb));
    error_2(scalar);
    scalar->scalar_number = number;
    int flag = 0;
    if (ring_info->type == 'I') flag = 1;

    if (flag == 1) {
        scalar->scalar = (void*)malloc(sizeof(int)*column);
        enter;
        for (int i = 0; i < column; i++) {
            scanf("%d", &(((int*)scalar->scalar))[i]);
        }
    } else {
        scalar->scalar = (void*)malloc(sizeof(double)*column);
        enter;
         for (int i = 0; i < scalar->scalar_number; i++) {
            scanf("%lf", &(((double*)scalar->scalar))[i]);
        }
    }

    return scalar;
}

void* Sum_Matrix_I(void* matrix_1, void* matrix_2, size_t* error) {
    Matrix* i_matrix_1 = (Matrix*)matrix_1;
    Matrix* i_matrix_2 = (Matrix*)matrix_2;
    Matrix* res = (Matrix*)malloc(sizeof(Matrix));
    error_2(res);
    res->line = i_matrix_1->line;
    res->column = i_matrix_1->column;

    res->array = (void**)malloc(sizeof(void*)*res->line);
    error_2(res->array);
    for (int i = 0; i < res->line; i++) {
        res->array[i] = (void*)malloc(sizeof(int)*res->column);
        error_2(res->array[i]); 
    }
    for (int i = 0; i < res->line; i++) { 
        for (int j = 0; j < res->column; j++) { 
            ((int**)res->array)[i][j] = 0;
            ((int**)res->array)[i][j] = ((int**)i_matrix_1->array)[i][j] + ((int**)i_matrix_2->array)[i][j];
        } 
    }

    return (void*)res; 
}

void* Sum_Matrix_F(void* matrix_1, void* matrix_2, size_t* error) {
    Matrix* f_matrix_1 = (Matrix*)matrix_1;
    Matrix* f_matrix_2 = (Matrix*)matrix_2;
    Matrix* res = (Matrix*)malloc(sizeof(Matrix));
    error_2(res);
    res->line = f_matrix_1->line;
    res->column = f_matrix_1->column;

    res->array = (void**)malloc(sizeof(void*)*res->line);
    error_2(res->array);
    for (int i = 0; i < res->line; i++) {
        res->array[i] = (void*)malloc(sizeof(double)*res->column);
        error_2(res->array[i]); 
    }
    for (int i = 0; i < res->line; i++) { 
        for (int j = 0; j < res->column; j++) { 
            ((double**)res->array)[i][j] = 0;
            ((double**)res->array)[i][j] = ((double**)f_matrix_1->array)[i][j] + ((double**)f_matrix_2->array)[i][j];
        } 
    }

    return (void*)res; 
}

void* Mult_Matrix_I (void* matrix_1, void* matrix_2, size_t* error) {
    Matrix* i_matrix_1 = (Matrix*)matrix_1;
    Matrix* i_matrix_2 = (Matrix*)matrix_2;
    Matrix* res = (Matrix*)malloc(sizeof(Matrix));
    error_2(res);
    res->line = i_matrix_1->line;
    res->column = i_matrix_2->column;

    res->array = (void**)malloc(sizeof(void*)*res->line);
    error_2(res->array);
    for (int i = 0; i < res->line; i++) {
        res->array[i] = (void*)malloc(sizeof(int)*res->column);
        error_2(res->array[i]); 
    }
    for (int i = 0; i < res->line; i++) { 
        for (int j = 0; j < res->column; j++) {
            ((int**)res->array)[i][j] = 0;
            for (int k = 0; k < i_matrix_1->column; k++) {
                ((int**)res->array)[i][j] += ((int**)i_matrix_1->array)[i][k] * ((int**)i_matrix_2->array)[k][j];
            }
        } 
    }

    return (void*)res;
}

void* Mult_Matrix_F (void* matrix_1, void* matrix_2, size_t* error) {
    Matrix* f_matrix_1 = (Matrix*)matrix_1;
    Matrix* f_matrix_2 = (Matrix*)matrix_2;
    Matrix* res = (Matrix*)malloc(sizeof(Matrix));
    error_2(res);
    res->line = f_matrix_1->line;
    res->column = f_matrix_2->column;

    res->array = (void**)malloc(sizeof(void*)*res->line);
    error_2(res->array);
    for (int i = 0; i < res->line; i++) {
        res->array[i] = (void*)malloc(sizeof(double)*res->column);
        error_2(res->array[i]); 
    }
    for (int i = 0; i < res->line; i++) { 
        for (int j = 0; j < res->column; j++) {
            ((double**)res->array)[i][j] = 0;
            for (int k = 0; k < f_matrix_1->column; k++) {
                ((double**)res->array)[i][j] += ((double**)f_matrix_1->array)[i][k] * ((double**)f_matrix_2->array)[k][j];
            }
        } 
    }

    return (void*)res;
}

void* Transp_Matrix_I (void* matrix, size_t* error) {
    Matrix* i_matrix = (Matrix*)matrix;
    Matrix* res = (Matrix*)malloc(sizeof(Matrix));
    error_2(res);
    res->line = i_matrix->column;
    res->column =i_matrix->line;

    res->array = (void**)malloc(sizeof(void*)*res->line);
    error_2(res->array);
    for (int i = 0; i < res->line; i++) {
        res->array[i] = (void*)malloc(sizeof(int)*res->column);
        error_2(res->array[i]); 
    }
    for (int i = 0; i < res->line; i++) { 
        for (int j = 0; j < res->column; j++) {
            ((int**)res->array)[i][j] = ((int**)i_matrix->array)[j][i];
        }
    }

    return (void*)res;
}

void* Transp_Matrix_F (void* matrix, size_t* error) {
    Matrix* f_matrix = (Matrix*)matrix;
    Matrix* res = (Matrix*)malloc(sizeof(Matrix));
    error_2(res);
    res->line = f_matrix->column;
    res->column =f_matrix->line;

    res->array = (void**)malloc(sizeof(void*)*res->line);
    error_2(res->array);
    for (int i = 0; i < res->line; i++) {
            res->array[i] = (void*)malloc(sizeof(double)*res->column);
            error_2(res->array[i]); 
        }
    for (int i = 0; i < res->line; i++) { 
        for (int j = 0; j < res->column; j++) {
            ((double**)res->array)[i][j] = ((double**)f_matrix->array)[j][i];
        }
    }

    return (void*)res;
}


void* Line_Comb_I (void* matrix, LineComb* scalar, size_t* error) {
    Matrix* i_matrix = (Matrix*)matrix;
    Matrix* res = (Matrix*)malloc(sizeof(Matrix));
    error_2(res);
    res->line = i_matrix->line;
    res->column = i_matrix->column;

    res->array = (void**)malloc(sizeof(void*)*res->line);
    error_2(res->array);
    for (int i = 0; i < res->line; i++) {
        res->array[i] = (void*)malloc(sizeof(int)*res->column);
        error_2(res->array[0]); 
    }
    
    for (int i = 0; i < res->line; i++) {   
        for (int j = 0; j < res->column; j++) {
            ((int**)res->array)[i][j] = ((int**)i_matrix->array)[i][j];
        }
    }
    for (int i = 0; i < res->line; i++) {
        for (int k = 0; k < res->column; k++) {
            if (i != scalar->scalar_number) {
                ((int**)res->array)[scalar->scalar_number][k] += ((int**)i_matrix->array)[i][k] * ((int*)scalar->scalar)[k];
            }
        }
    }

    return (void*)res;
}

void* Line_Comb_F (void* matrix, LineComb* scalar, size_t* error) {
    Matrix* f_matrix = (Matrix*)matrix;
    Matrix* res = (Matrix*)malloc(sizeof(Matrix*));
    error_2(res);
    res->line = f_matrix->line;
    res->column = f_matrix->column;

    res->array = (void**)malloc(sizeof(void*)*res->line);
    error_2(res->array);
    for (int i = 0; i < res->line; i++) {
        res->array[i] = (void*)malloc(sizeof(double)*res->column);
        error_2(res->array[0]); 
    }
    
    for (int i = 0; i < res->line; i++) {   
        for (int j = 0; j < res->column; j++) {
            ((double**)res->array)[i][j] = ((double**)f_matrix->array)[i][j];
        }
    }
    for (int i = 0; i < res->line; i++) {
        for (int k = 0; k < res->column; k++) {
            if (i != scalar->scalar_number) {
                ((double**)res->array)[scalar->scalar_number][k] += ((double**)f_matrix->array)[i][k] * ((double*)scalar->scalar)[k];
            }
        }
    }

    return (void*)res;
}

void Matrix_Print (void* matrix, RingInfo* ring_info) {
    int flag = 0;
    if (ring_info->type == 'I') flag = 1;

    if (flag == 1) {
        Matrix* i_matrix = (Matrix*)matrix;
        for (int i = 0; i < i_matrix->line; i++){
            for (int j = 0; j < i_matrix->column; j++) {
                printf("%d \t \t", ((int**)i_matrix->array)[i][j]);
            }
            printf("\n");
        }
    } else {
        Matrix* f_matrix = (Matrix*)matrix;
        for (int i = 0; i < f_matrix->line; i++){
            for (int j = 0; j < f_matrix->column; j++) {
                printf("%lf \t \t", ((double**)f_matrix->array)[i][j]);
            }
            printf("\n");
        }
    }
}

void* Mult_Matrix_by_Scalar_I (void* matrix, void* scalar, size_t* error) {
    int* scalar_i = (int*)scalar;
    Matrix* matrix_i = (Matrix*)matrix;

    for (int i = 0; i < matrix_i->line; i++){
        for (int j = 0; j < matrix_i-> column; j++){
            ((int**)matrix_i->array)[i][j] *= *scalar_i; 
        }
    }

    return (void*)matrix_i;
}

void* Mult_Matrix_by_Scalar_F (void* matrix, void* scalar, size_t* error) {
    double* scalar_f = (double*)scalar;
    Matrix* matrix_f = (Matrix*)matrix;

    for (int i = 0; i < matrix_f->line; i++){
        for (int j = 0; j < matrix_f-> column; j++){
            ((double**)matrix_f->array)[i][j] *= *scalar_f; 
        }
    }

    return (void*)matrix_f;
}

void* Get_Matrix_Random (size_t line, size_t column, RingInfo* ring_info, size_t* error) {
    if ((line == 0) || (column == 0) || (ring_info == NULL)) {
        *error = 3;
        return NULL;
    }
    size_t flag = 0;
    if (ring_info->type == 'I') flag = 1;
    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
    error_2(matrix);

    matrix->line = line;
    matrix->column = column;

    matrix->array = (void**)malloc(sizeof(void*)*line);
    error_2(matrix->array);

    if (flag == 1) {
        for (int i = 0; i < line; i++) {
            matrix->array[i] = (void*)malloc(sizeof(int)*column);
            error_2(matrix->array[i]); 
        }
        for (int i = 0; i < line; i++) { 
            for (int j = 0; j < column; j++) { 
                ((int**)matrix->array)[i][j] = rand() % 100;
            } 
        } 
    } else {
        for (int i = 0; i < line; i++) {
            matrix->array[i] = (void*)malloc(sizeof(double)*column);
            error_2(matrix->array[i]);
        }
        for (int i = 0; i < line; i++) {
            for (int j = 0; j < column; j++) {
            ((double**)matrix->array)[i][j] = (double)(rand() % 1000000) / 100000;
            } 
        }
    }

    return (void*)matrix;
}

void* Get_Matrix_One (size_t line, size_t column, RingInfo* ring_info, size_t* error) {
    if ((line == 0) || (column == 0) || (ring_info == NULL)) {
        *error = 3;
        return NULL;
    }
    size_t flag = 0;
    if (ring_info->type == 'I') flag = 1;
    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
    error_2(matrix);

    matrix->line = line;
    matrix->column = column;

    matrix->array = (void**)malloc(sizeof(void*)*line);
    error_2(matrix->array);

    if (flag == 1) {
        for (int i = 0; i < line; i++) {
            matrix->array[i] = (void*)malloc(sizeof(int)*column);
            error_2(matrix->array[i]); 
        }
        for (int i = 0; i < line; i++) { 
            for (int j = 0; j < column; j++) { 
                if (i == j) {((int**)matrix->array)[i][j] = 1;} else {((int**)matrix->array)[i][j] = 0;} ;
            } 
        } 
    } else {
        for (int i = 0; i < line; i++) {
            matrix->array[i] = (void*)malloc(sizeof(double)*column);
            error_2(matrix->array[i]);
        }
        for (int i = 0; i < line; i++) {
            for (int j = 0; j < column; j++) {
                if (i == j) {((double**)matrix->array)[i][j] = 1.0;} else {((double**)matrix->array)[i][j] = 0.0;}
            } 
        }
    }

    return (void*)matrix;
}

void* Get_Matrix_Zero (size_t line, size_t column, RingInfo* ring_info, size_t* error) {
    if ((line == 0) || (column == 0) || (ring_info == NULL)) {
        *error = 3;
        return NULL;
    }
    size_t flag = 0;
    if (ring_info->type == 'I') flag = 1;
    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
    error_2(matrix);

    matrix->line = line;
    matrix->column = column;

    matrix->array = (void**)malloc(sizeof(void*)*line);
    error_2(matrix->array);

    if (flag == 1) {
        for (int i = 0; i < line; i++) {
            matrix->array[i] = (void*)malloc(sizeof(int)*column);
            error_2(matrix->array[i]); 
        }
        for (int i = 0; i < line; i++) { 
            for (int j = 0; j < column; j++) { 
                ((int**)matrix->array)[i][j] = 0;
            } 
        } 
    } else {
        for (int i = 0; i < line; i++) {
            matrix->array[i] = (void*)malloc(sizeof(double)*column);
            error_2(matrix->array[i]);
        }
        for (int i = 0; i < line; i++) {
            for (int j = 0; j < column; j++) {
                ((double**)matrix->array)[i][j] = 0.0;
            } 
        }
    }

    return (void*)matrix;
}
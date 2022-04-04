#pragma once

#include <stdlib.h>

// Структуры

typedef struct {
    void** array;
    size_t line;
    size_t column;
} Matrix;

typedef struct {
    void* scalar;
    size_t scalar_number;
} LineComb;

typedef struct RingInfo {
    char type;
    void* (*Sum_Matrix) (void*, void*, size_t*);
    void* (*Mult_Matrix) (void*, void*, size_t*);
    void* (*Mult_Matrix_by_Scalar) (void*, void*, size_t*);
    void* (*Transp_Matrix) (void*, size_t*);
    void* (*Line_Comb) (void*, LineComb*, size_t*);
} RingInfo;

RingInfo* Create (
    char type,
    void* (*Sum_Matrix) (void*, void*, size_t*),
    void* (*Mult_Matrix) (void*, void*, size_t*),
    void* (*Mult_Matrix_by_Scalar) (void*, void*, size_t*),
    void* (*Transp_Matrix) (void*, size_t*),
    void* (*Line_Comb) (void*, LineComb*, size_t*),
    size_t* error
);

// Макросы

#define RN_insert(info) (ring_info->info = info)
#define error_2(tmp) {if (tmp == NULL) {*error = 2; return NULL;}}
#define ERROR_OK {if (*error != 0) return *error;}
#define Free_Matrix(matrix) {if (matrix != NULL) Matrix_Erase(matrix);}
#define enter {stdin->_IO_read_ptr = stdin->_IO_read_end;}
// Функции

void* Get_Matrix (size_t line, size_t column, RingInfo* ring_info, size_t* error);
void* Get_Matrix_Random (size_t line, size_t column, RingInfo* ring_info, size_t* error);
LineComb* Get_Scalar (size_t number, RingInfo* ring_info, size_t column, size_t* error);
void Matrix_Erase (void* matrix);
void* Sum_Matrix_I(void* matrix_1, void* matrix_2, size_t* error);
void* Sum_Matrix_F(void* matrix_1, void* matrix_2, size_t* error);
void* Mult_Matrix_I (void* matrix_1, void* matrix_2, size_t* error);
void* Mult_Matrix_F (void* matrix_1, void* matrix_2, size_t* error);
void* Mult_Matrix_by_Scalar_I (void* matrix, void* scalar, size_t* error);
void* Mult_Matrix_by_Scalar_F (void* matrix, void* scalar, size_t* error);
void* Transp_Matrix_I (void* matrix, size_t* error);
void* Transp_Matrix_F (void* matrix, size_t* error);
void* Line_Comb_I (void* matrix, LineComb* scalar, size_t* error);
void* Line_Comb_F (void* matrix, LineComb* scalar, size_t* error);
void Matrix_Print (void* matrix, RingInfo* ring_info);
void* Get_Matrix_One (size_t line, size_t column, RingInfo* ring_info, size_t* error);
void* Get_Matrix_Zero (size_t line, size_t column, RingInfo* ring_info, size_t* error);
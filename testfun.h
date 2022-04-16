#pragma once

#include <stdlib.h>
#include "matrix.h"
#include "print.h"

#define ring_info_i {char type = 'I';\
        free(ring_info);\
        ring_info = Create(type, Sum_Matrix_I, Mult_Matrix_I, Mult_Matrix_by_Scalar_I, Transp_Matrix_I, Line_Comb_I, error);}
#define ring_info_f {type = 'F';\
        free(ring_info);\
        ring_info = Create(type, Sum_Matrix_F, Mult_Matrix_F, Mult_Matrix_by_Scalar_F, Transp_Matrix_F, Line_Comb_F, error);}
#define OK(num) {if (exit == 0) return num;}

Matrix* matrix_get_int (size_t l, size_t c);
Matrix* matrix_get_double (size_t l, size_t c);
void sum_test_1 (size_t* exit, RingInfo* r, size_t* error);
void sum_test_2 (size_t* exit, RingInfo* r, size_t* error);
void sum_test_3 (size_t* exit, RingInfo* r, size_t* error);
void sum_test_4 (size_t* exit, RingInfo* r, size_t* error);
void mult_test_5 (size_t* exit, RingInfo* r, size_t* error);
void mult_test_6 (size_t* exit, RingInfo* r, size_t* error);
void mult_test_7 (size_t* exit, RingInfo* r, size_t* error);
void mult_test_8 (size_t* exit, RingInfo* r, size_t* error);
void mult_by_scalar_test_9 (size_t* exit, RingInfo* r, size_t* error);
void mult_by_scalar_test_10 (size_t* exit, RingInfo* r, size_t* error);
void mult_by_scalar_test_11 (size_t* exit, RingInfo* r, size_t* error);
void mult_by_scalar_test_12 (size_t* exit, RingInfo* r, size_t* error);
void mult_by_scalar_test_13 (size_t* exit, RingInfo* r, size_t* error);
void mult_by_scalar_test_14 (size_t* exit, RingInfo* r, size_t* error);
void transp_test_15 (size_t* exit, RingInfo* r, size_t* error);
void transp_test_16 (size_t* exit, RingInfo* r, size_t* error);
void transp_test_17 (size_t* exit, RingInfo* r, size_t* error);
void transp_test_18 (size_t* exit, RingInfo* r, size_t* error);
void line_comb_test_19 (size_t* exit, RingInfo* r, size_t* error);
void line_comb_test_20 (size_t* exit, RingInfo* r, size_t* error);
void line_comb_test_21 (size_t* exit, RingInfo* r, size_t* error);
void line_comb_test_22 (size_t* exit, RingInfo* r, size_t* error);
void line_comb_test_23 (size_t* exit, RingInfo* r, size_t* error);
void line_comb_test_24 (size_t* exit, RingInfo* r, size_t* error);
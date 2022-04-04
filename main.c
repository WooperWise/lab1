#include <stdio.h>
#include <sys/types.h>
#include <time.h>

#include "matrix.h"
#include "print.h"

int main () {
    size_t exit = 1;

    Matrix* matrix_1 = NULL;
    Matrix* matrix_2 = NULL;
    Matrix* matrix_res = NULL;
    RingInfo* ring_info = NULL;  
    size_t* error = (size_t*)malloc(sizeof(size_t));
    *error = 0;

    p_hello();

    srand(time(NULL));

    while (exit == 1) {

        p_info();
        char key = 0;
        enter;
        scanf("%c", &key);
        enter;
        switch (key) {
        
        case 'i':
            p_menue();
            break;
        case '1': // ввод данных
            p_type ();
            char type = 0;
            scanf("%c", &type);
            enter;
            if (type != 'I' && type != 'F') {
                ErrorMessange(null_type);
                break;
            }

            if (ring_info != NULL) free(ring_info);

            if (type == 'I') {
                ring_info = Create(type, Sum_Matrix_I, Mult_Matrix_I, Mult_Matrix_by_Scalar_I, Transp_Matrix_I, Line_Comb_I, error);
                ERROR_OK;
            } else {
                ring_info = Create(type, Sum_Matrix_F, Mult_Matrix_F, Mult_Matrix_by_Scalar_F, Transp_Matrix_F, Line_Comb_F, error);
                ERROR_OK;
            } 
            
            size_t line_1 = 0, line_2 = 0, column_1 = 0, column_2 = 0;

            p_line_and_column();
            enter;
            scanf("%lu %lu", &line_1, &column_1);
            if (line_1 <= 0 || column_1 <= 0) {
                ErrorMessange(non_line_or_column);
                break;
            }

            if (matrix_1 != NULL) Matrix_Erase(matrix_1);
            matrix_1 = Get_Matrix(line_1, column_1, ring_info, error);

            ERROR_OK;
            
            p_line_and_column();
            enter;
            scanf("%lu %lu", &line_2, &column_2);
            if (line_2 <= 0 || column_2 <= 0) {
                ErrorMessange(non_line_or_column);
                break;
            }
            if (matrix_2 != NULL) Matrix_Erase(matrix_2);
            matrix_2 = Get_Matrix(line_2, column_2, ring_info, error);

            ERROR_OK;

            break;
        case '2': // сумма матриц
            if ((matrix_1 == NULL) || (matrix_2 == NULL) || (ring_info == NULL)) {
                ErrorMessange(null_ringinfo);
                break;
            }
            if (matrix_res != NULL) Matrix_Erase(matrix_res);
            if ((matrix_1->line != matrix_2->line) || (matrix_1->column != matrix_2->column)) {
                ErrorMessange(impossible_conditions);
                break;
            }

            matrix_res = ring_info->Sum_Matrix(matrix_1, matrix_2, error);

            ERROR_OK;

            p_good();
            p_result();

            Matrix_Print(matrix_res, ring_info);
            break;
        case '3': // умножение матриц
            if ((matrix_1 == NULL) || (matrix_2 == NULL) || (ring_info == NULL)) {
                ErrorMessange(null_ringinfo);
                break;
            }
            if (matrix_1->column != matrix_2->line) {
                ErrorMessange(impossible_conditions);
                break;
            }
            if (matrix_res != NULL) Matrix_Erase(matrix_res);

            matrix_res = ring_info->Mult_Matrix(matrix_1, matrix_2, error);

            ERROR_OK;
            
            p_good();
            p_result();

            Matrix_Print(matrix_res, ring_info);
            break;
        case '4': // умножение на скаляр
            if ((matrix_1 == NULL) || (ring_info == NULL)) {
                ErrorMessange(null_ringinfo);
                break;
            }

            p_scalar_for_mult ();
            if (ring_info->type == 'I') {
                int scalar = 0;
                scanf("%d", &scalar);

                matrix_1 = ring_info->Mult_Matrix_by_Scalar(matrix_1, ((void*)&scalar), error);

                ERROR_OK;

                p_good ();
                p_result();

                Matrix_Print(matrix_1, ring_info);
                break;
            } else {
                double scalar = 0;
                scanf("%lf", &scalar);

                matrix_1 = ring_info->Mult_Matrix_by_Scalar(matrix_1, ((void*)&scalar), error);

                ERROR_OK;

                p_good ();
                p_result();

                Matrix_Print(matrix_1, ring_info);
                break;
            }
        case '5': // транспонирование матрицы
            if ((matrix_1 == NULL) || (ring_info == NULL)) {
                ErrorMessange(null_ringinfo);
                break;
            }

            if (matrix_res != NULL) Matrix_Erase(matrix_res);
            matrix_res = ring_info->Transp_Matrix(matrix_1, error);

            ERROR_OK;

            p_good();
            Matrix_Print(matrix_res, ring_info);
            break;
        case '6': // линейная комбинация
            if ((matrix_1 == NULL) || (ring_info == NULL)) {
                ErrorMessange(null_ringinfo);
                break;
            }

            p_number_for_linecomb();

            size_t number = 0;
            scanf("%ld", &number);
            
            p_scalar_for_linecomb();

            if (matrix_1->line < number - 1) {
                ErrorMessange(error_size_of_line);
                break;
            }

            LineComb* scalar_lc = Get_Scalar(number, ring_info, matrix_1->column, error);

            ERROR_OK;

            if (matrix_res != NULL) Matrix_Erase(matrix_res);
            matrix_res = ring_info->Line_Comb(matrix_1, scalar_lc, error);

            ERROR_OK;

            p_good();
            Matrix_Print(matrix_res, ring_info);
            free(scalar_lc->scalar);
            free(scalar_lc);
            break;
        case '7': // вывод матриц
            if ((matrix_1 == NULL) || (ring_info == NULL) || (matrix_2 == NULL)) {
                ErrorMessange(null_ringinfo);
                break;
            }

            p_matrix_one();
            Matrix_Print(matrix_1, ring_info);

            p_matrix_two();
            Matrix_Print(matrix_2, ring_info);

            break;
        case '8': // получение рандомной матрицы
            p_type ();
            char type_r = 0;
            scanf("%c", &type_r);
            enter;
            if (type_r != 'I' && type_r != 'F') {
                ErrorMessange(null_type);
                break;
            }
            
            if (ring_info != NULL) free(ring_info);

            if (type_r == 'I') {
                ring_info = Create(type_r, Sum_Matrix_I, Mult_Matrix_I, Mult_Matrix_by_Scalar_I, Transp_Matrix_I, Line_Comb_I, error);
                ERROR_OK;
            } else {
                ring_info = Create(type_r, Sum_Matrix_F, Mult_Matrix_F, Mult_Matrix_by_Scalar_F, Transp_Matrix_F, Line_Comb_F, error);
                ERROR_OK;
            } 
            
            size_t line1 = 0, line2 = 0, column1 = 0, column2 = 0;

            p_line_and_column();
            enter;
            scanf("%lu %lu", &line1, &column1);
            if (line1 <= 0 || column1 <= 0) {
                ErrorMessange(non_line_or_column);
                break;
            }
            if (matrix_1 != NULL) Matrix_Erase(matrix_1);
            matrix_1 = Get_Matrix_Random(line1, column1, ring_info, error);

            ERROR_OK;
            
            p_line_and_column();
            enter;
            scanf("%lu %lu", &line2, &column2);
            if (line2 <= 0 || column2 <= 0) {
                ErrorMessange(non_line_or_column);
                break;
            }
            if (matrix_2 != NULL) Matrix_Erase(matrix_2);
            matrix_2 = Get_Matrix_Random(line2, column2, ring_info, error);

            ERROR_OK;

            break;
        case '9': // выход
            exit = 0;
            break;
        }
    }
    Free_Matrix(matrix_1);
    Free_Matrix(matrix_2);
    Free_Matrix(matrix_res);
    if (ring_info != NULL) free(ring_info);
    free(error);

    return 0;
}
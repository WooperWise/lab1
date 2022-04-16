#include <stdio.h>
#include <stdlib.h>
#include "testfun.h"

int main () {
    size_t exit = 1;
    char type = 'I';
    size_t* error = 0;
    RingInfo* ring_info = Create(type, Sum_Matrix_I, Mult_Matrix_I, Mult_Matrix_by_Scalar_I, Transp_Matrix_I, Line_Comb_I, error);

    //Sum matrix
    printf("______________________________________________________________________________\n");
    printf("\nSum matrix.\n");

    sum_test_1(&exit, ring_info, error);
    OK(1);
    printf("Test 1: OK.\n");
  
    sum_test_2(&exit, ring_info, error);
    OK(2);
    printf("Test 2: OK.\n");
    
    ring_info_f;
    
    sum_test_3(&exit, ring_info, error);
    OK(3);
    printf("Test 3: OK.\n");

    sum_test_4(&exit, ring_info, error);
    OK(4);
    printf("Test 4: OK.\n");

    //Mult Matrix
    printf("______________________________________________________________________________\n");
    printf("\nMult matrix.\n");
    ring_info_i;

    mult_test_5(&exit, ring_info, error);
    OK(5);
    printf("Test 5: OK.\n");

    mult_test_6(&exit, ring_info, error);
    OK(6);
    printf("Test 6: OK.\n");

    ring_info_f;

    mult_test_7(&exit, ring_info, error);
    OK(7);
    printf("Test 7: OK.\n");
    
    mult_test_8(&exit, ring_info, error);
    OK(8);
    printf("Test 8: OK.\n");
    
    // Mult Matrix by Scalar
    printf("______________________________________________________________________________\n");
    printf("\nMult Matrix by Scalar.\n");
    ring_info_i;
    
    mult_by_scalar_test_9(&exit, ring_info, error);
    OK(9);
    printf("Test 9: OK.\n");

   mult_by_scalar_test_10(&exit, ring_info, error);
    OK(10);
    printf("Test 10: OK.\n");

    mult_by_scalar_test_11(&exit, ring_info, error);
    OK(11);
    printf("Test 11: OK.\n");

    ring_info_f;

    mult_by_scalar_test_12(&exit, ring_info, error);
    OK(12);
    printf("Test 12: OK.\n");

    mult_by_scalar_test_13(&exit, ring_info, error);
    OK(13);
    printf("Test 13: OK.\n");

    mult_by_scalar_test_14(&exit, ring_info, error);
    OK(14);
    printf("Test 14: OK.\n");

    // Transp Matrix
    printf("______________________________________________________________________________\n");
    printf("\nTransp Matrix.\n");
    ring_info_i;

    transp_test_15(&exit, ring_info, error);
    OK(15);
    printf("Test 15: OK.\n");

    transp_test_16(&exit, ring_info, error);
    OK(16);
    printf("Test 16: OK.\n");

    ring_info_f;

    transp_test_17(&exit, ring_info, error);
    OK(17);
    printf("Test 17: OK.\n");

    transp_test_18(&exit, ring_info, error);
    OK(18);
    printf("Test 18: OK.\n");

    // Line_Comb
    printf("______________________________________________________________________________\n");
    printf("\nLine Comb.\n");
    ring_info_i;

    line_comb_test_19(&exit, ring_info, error);
    OK(19);
    printf("Test 19: OK.\n");

    line_comb_test_20(&exit, ring_info, error);
    OK(20);
    printf("Test 20: OK.\n");

    line_comb_test_21(&exit, ring_info, error);
    OK(21);
    printf("Test 21: OK.\n");

    ring_info_f;

    line_comb_test_22(&exit, ring_info, error);
    OK(22);
    printf("Test 22: OK.\n");

    line_comb_test_23(&exit, ring_info, error);
    OK(23);
    printf("Test 23: OK.\n");

    line_comb_test_24(&exit, ring_info, error);
    OK(24);
    printf("Test 24: OK.\n");

    return 0;
}
    

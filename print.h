#pragma once

enum error {
    ok = 0, null_type, null_matrix_one, null_matrix_two, 
    non_line_or_column, null_ringinfo, impossible_conditions,
    error_size_of_line
};

void ErrorMessange(enum error code);

void p_hello ();
void p_info ();
void p_menue ();
void p_type ();
void p_line_and_column ();
void p_good ();
void p_scalar_for_mult ();
void p_number_for_linecomb ();
void p_scalar_for_linecomb ();
void p_result ();
void p_matrix_one ();
void p_matrix_two ();
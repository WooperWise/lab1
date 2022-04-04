#include <stdio.h>

// Текст для вывода (p ~ print)

void p_hello () {
    printf(
        "◣◥◣◥◤◢◤◢◣◥◣◥◤◢◣◥◣◥◤◢◤◢◣◥ \n"
        "   Welcome to Lab №1   \n"
        "◣◥◣◥◤◢◤◥◣◥◤◢◤◢◣◥◣◥◤◢◤◢◣◥ \n"
    );
};

void p_info () {
    printf(
        "\n"
        "╔══════════════════════════════╗ \n"
        "║   Enter i for information.   ║ \n"
        "╚══════════════════════════════╝ \n"
        "Enter: ");
}

void p_menue () {
    printf(
        "\n"
        "╔════════════════════════════════════════════════╗ \n"
        "║    1   ==>   Get Matrices.                     ║ \n"
        "║ ────────────────────────────────────────────── ║ \n"
        "║    2   ==>   Sum Matrices.                     ║ \n"
        "║ ────────────────────────────────────────────── ║ \n"
        "║    3   ==>   Multiply Matrices.                ║ \n"
        "║ ────────────────────────────────────────────── ║ \n"
        "║    4   ==>   Multiply Matrices by Scalar.      ║ \n"
        "║ ────────────────────────────────────────────── ║ \n"
        "║    5   ==>   Matrix Transposition.             ║ \n"
        "║ ────────────────────────────────────────────── ║ \n"
        "║    6   ==>   Linear Combination of Matrices.   ║ \n"
        "║ ────────────────────────────────────────────── ║ \n"
        "║    7   ==>   Print.                            ║ \n"
        "║ ────────────────────────────────────────────── ║ \n"
        "║    8   ==>   Get Matrices of Random.           ║ \n"
        "║ ────────────────────────────────────────────── ║ \n"
        "║    9   ==>   Exit.                             ║ \n"
        "╚════════════════════════════════════════════════╝ \n"
        );
}

void p_type () {
    printf(
        "\n"
        "╔════════════════════╗ \n"
        "║   Enter the Type.  ║ \n"
        "╚════════════════════╝ \n"
        "Enter: ");
}

void p_line_and_column () {
    printf(
        "\n"
        "╔═══════════════════════════════════╗ \n"
        "║   Enter the line and the column.  ║ \n"
        "╚═══════════════════════════════════╝ \n"
        "Enter: ");
}


void p_good () {
    printf(
        "\n"
        "╔═══════════════════╗ \n"
        "║   Successfully.   ║ \n"
        "╚═══════════════════╝ \n"
        );
}

void p_scalar_for_mult () {
    printf(
        "\n"
        "╔═════════════════════════════════════════╗ \n"
        "║   Enter the scalar for mult of matrix.  ║ \n"
        "╚═════════════════════════════════════════╝ \n"
        "Enter: ");
}

void p_number_for_linecomb () {
    printf(
        "\n"
        "╔══════════════════════════════════════════════╗ \n"
        "║   Enter the number for line comb of matrix.  ║ \n"
        "╚══════════════════════════════════════════════╝ \n"
        "Enter: ");
}

void p_scalar_for_linecomb () {
    printf(
        "\n"
        "╔═══════════════════════════════════════════════╗ \n"
        "║   Enter the scalars for line comb of matrix.  ║ \n"
        "╚═══════════════════════════════════════════════╝ \n"
        "Enter: ");
}

void p_result () {
    printf(
        "\n"
        "╔════════════╗ \n"
        "║   Result.  ║ \n"
        "╚════════════╝ \n"
        );
}

void p_matrix_one () {
    printf(
        "\n"
        "╔═══════════════╗ \n"
        "║  Matrix one.  ║ \n"
        "╚═══════════════╝ \n"
        );
}

void p_matrix_two () {
    printf(
        "\n"
        "╔═══════════════╗ \n"
        "║  Matrix two.  ║ \n"
        "╚═══════════════╝ \n"
        );
}
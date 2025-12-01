#include <stdio.h>
#include "../include/operations.h"

int main() {
    printf("Teste de Soma\n");

    BigInt* num1 = bigint_create("99999999999999999999");
    BigInt* num2 = bigint_create("1");

    printf("Numero 1: "); bigint_print(num1);
    printf("Numero 2: "); bigint_print(num2);

    BigInt* resultado = bigint_sum(num1, num2);

    printf("Soma:     ");
    bigint_print(resultado);

    bigint_destroy(num1);
    bigint_destroy(num2);
    bigint_destroy(resultado);

    return 0;
}
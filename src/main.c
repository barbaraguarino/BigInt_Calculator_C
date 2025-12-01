#include <stdio.h>
#include "../include/bigint.h"

int main() {
    printf("Teste da BigInt Calculator\n");

    char valor_gigante[] = "1234567890123456548745154748548754688548487455154478485484487848454848784545487451215454845478901234567890";

    printf("Criando BigInt com valor: %s\n", valor_gigante);
    BigInt* num1 = bigint_create(valor_gigante);

    printf("Resultado armazenado na lista: ");
    bigint_print(num1);

    BigInt* num2 = bigint_create("-98765434125445587454874548745877455622145587455874587455121548475454587455848454548475512256225548521");
    printf("Teste negativo: ");
    bigint_print(num2);

    bigint_destroy(num1);
    bigint_destroy(num2);

    printf("Memória liberada. Fim do programa.\n");
    return 0;
}
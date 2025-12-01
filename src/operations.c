#include <stdlib.h>
#include <stdio.h>
#include "../include/operations.h"

BigInt* bigint_sum(BigInt* a, BigInt* b) {

    BigInt* result = bigint_create("");

    Node* ptrA = a->tail;
    Node* ptrB = b->tail;

    int carry = 0;

    while (ptrA != NULL || ptrB != NULL || carry > 0) {
        int sum = carry;

        if (ptrA != NULL) {
            sum += ptrA->digit;
            ptrA = ptrA->prev;
        }

        if (ptrB != NULL) {
            sum += ptrB->digit;
            ptrB = ptrB->prev;
        }

        int digit_to_store = sum % 10;
        carry = sum / 10;

        bigint_push_front(result, (short)digit_to_store);
    }

    return result;
}
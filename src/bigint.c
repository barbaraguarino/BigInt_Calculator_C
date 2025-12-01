#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/bigint.h"

static Node *create_node(short value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr,"Erro: Falha ao alocar memória para novo nó.\n");
        exit(1);
    }

    new_node -> digit = value;
    new_node -> next = NULL;
    new_node -> prev = NULL;

    return new_node;
}

BigInt *bigint_create(const char *value_str) {
    BigInt *new_bigint = (BigInt *)malloc(sizeof(BigInt));
    if (new_bigint == NULL) {
        fprintf(stderr, "Erro: Falha ao alocar o BigInt.\n");
        exit(1);
    }

    new_bigint -> head = NULL;
    new_bigint -> tail = NULL;
    new_bigint -> size = 0;
    new_bigint -> is_negative = false;

    if (value_str == NULL || strlen(value_str) == 0) {
        return new_bigint;
    }

    int start_index = 0;
    if (value_str[0] == '-') {
        new_bigint -> is_negative = true;
        start_index = 1;
    }else if (value_str[0] == '+') {
        start_index = 1;
    }

    for (int i = start_index; value_str[i] != '\0'; i++) {
        if (!isdigit(value_str[i])) {
            continue;
        }

        short digit = (short)(value_str[i] - '0');

        Node *new_node = create_node(digit);
        if (new_bigint -> head == NULL) {
            new_bigint -> head = new_node;
            new_bigint -> tail = new_node;
        }else {
            new_bigint -> tail -> next = new_node;
            new_node -> prev = new_bigint -> tail;
            new_bigint -> tail = new_node;
        }

        new_bigint -> size++;
    }
    return new_bigint;
}

void bigint_print(const BigInt* num) {
    if (num == NULL) {
        printf("Não existe número.\n");
        return;
    }

    if (num->is_negative) {
        printf("-");
    }

    Node* current = num->head;

    while (current != NULL) {
        printf("%d", current->digit);
        current = current->next;
    }

    printf("\n");
}

void bigint_destroy(BigInt* num) {
    if (num == NULL) return;

    Node* current = num->head;

    while (current != NULL) {
        Node* next_node_backup = current->next;

        free(current);

        current = next_node_backup;
    }

    free(num);
}

void bigint_push_front(BigInt* num, short value) {
    Node* new_node = create_node(value);

    if (num->head == NULL) {
        num->head = new_node;
        num->tail = new_node;
    }else {
        new_node -> next = num->head;
        num -> head -> prev = new_node;
        num -> head = new_node;
    }

    num -> size++;
}
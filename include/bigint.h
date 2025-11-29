#ifndef BIGINT_H
#define BIGINT_H

#include <stdbool.h>

// Definição do Nó da Lista
typedef struct Node {
  short int digit;
  struct Node *next;
  struct Node *prev;
} Node;

// Definição da Lista
typedef struct {
  Node *head;
  Node *tail;
  int size;
  bool is_negative;
} BigInt;

// Criar uma lista vazia
BigInt *bigint_create(const char *value_string);

// Imprime o número na tela
void bigint_print(const BigInt *num);

// Libera a memória
void bigint_destroy(BigInt *num);

#endif
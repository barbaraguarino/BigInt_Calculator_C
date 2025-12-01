#ifndef BIGINT_H
#define BIGINT_H

#include "imports.h"

typedef struct Node {
  short int digit;
  struct Node *next;
  struct Node *prev;
} Node;

typedef struct {
  Node *head;
  Node *tail;
  int size;
  bool is_negative;
} BigInt;

BigInt *bigint_create(const char *value_string);

void bigint_push_front(BigInt* num, short value);

void bigint_print(const BigInt *num);

void bigint_destroy(BigInt *num);

#endif
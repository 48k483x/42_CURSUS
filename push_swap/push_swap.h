#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>

typedef struct node {
    int data;
    struct node *next;
} stack;

 // 5 -> 4 -> 3 -> 2 -> 1 -> NULL
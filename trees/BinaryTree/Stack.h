#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

struct Stack {
    int size;
    int top;
    struct Node **data;
};

void createStack(struct Stack *newStack, int size) {
    newStack->size = size;
    newStack->top = -1;
    newStack->data = (struct Node **)malloc(newStack->size * sizeof(struct Node *));
}

void push(struct Stack *stack, struct Node *address) {
    if (stack->top == stack->size - 1) {
        printf("Stack overflow.\n");
    } else {
        stack->top++;
        stack->data[stack->top] = address;
    }
}

struct Node *pop(struct Stack *stack) {
    struct Node *address = NULL;

    if (stack->top == -1) {
        printf("Stack underflow.\n");
    } else {
        address = stack->data[stack->top];
        stack->top--;
    }

    return address;
}

int isEmptyStack(struct Stack stack) {
    return stack.top == -1;
}

int isFullStack(struct Stack stack) {
    return stack.top == stack.size - 1;
}

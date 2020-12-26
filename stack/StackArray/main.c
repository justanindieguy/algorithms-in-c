#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int size;
    int top;
    int *stack;
};

/*--------------- PROTOTYPES ---------------*/
void create(struct Stack *someStack);
void display(struct Stack someStack);
void push(struct Stack *someStack, int value);
int pop(struct Stack *someStack);
int peek(struct Stack someStack, int index);
int isEmpty(struct Stack someStack);
int isFull(struct Stack someStack);
int getTop(struct Stack someStack);

/*--------------- FUNCTIONS ---------------*/
void create(struct Stack *someStack) {

    printf("Enter size of Stack: ");
    scanf_s("%d", &someStack->size);
    someStack->top = -1;
    someStack->stack = (int *)malloc(someStack->size * sizeof(int));
}

void display(struct Stack someStack) {

    int i;

    for (i = someStack.top; i >= 0; i--) {
        printf("%d ", someStack.stack[i]);
        printf("\n");
    }
}

void push(struct Stack *someStack, int value) {

    if (someStack->top == someStack->size - 1) {
        printf("Stack overflow.\n");
    } else {
        someStack->top++;
        someStack->stack[someStack->top] = value;
    }
}

int pop(struct Stack *someStack) {

    int value = -1;

    if (someStack->top == -1) {
        printf("Stack underflow.\n");
    } else {
        value = someStack->stack[someStack->top];
        someStack->top--;
    }

    return value;
}

int peek(struct Stack someStack, int index) {

    int value = -1;

    if (someStack.top - index + 1 < 0) {
        printf("Invalid index.\n");
    } else {
        value = someStack.stack[someStack.top - index + 1];
    }

    return value;
}

int isEmpty(struct Stack someStack) {
    return someStack.top == -1;
}

int isFull(struct Stack someStack) {
    return someStack.top == someStack.size - 1;
}

int getTop(struct Stack someStack) {

    if (!isEmpty(someStack)) {
        return someStack.stack[someStack.top];
    }

    return -1;
}

/*--------------- MAIN ---------------*/
int main() {

    struct Stack newStack;
    create(&newStack);

    push(&newStack, 10);
    push(&newStack, 20);
    push(&newStack, 30);
    push(&newStack, 40);

    printf("\nDisplay:\n");
    display(newStack);

    return 0;
}

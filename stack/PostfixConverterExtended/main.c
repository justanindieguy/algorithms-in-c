#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node *next;
};

void push(struct Node **top, char data);
char pop(struct Node **top);
char getTop(struct Node *top);
int isEmpty(struct Node *top);
int isOperand(char character);
int getPrecedence(char character);
int getStackPrecedence(char character);
char *convert(char *infix);

void push(struct Node **top, char data) {

    struct Node *temp = malloc(sizeof(struct Node));

    if (temp == NULL) {
        printf("Stack overflow.\n");
    } else {
        temp->data = data;
        temp->next = *top;
        (*top) = temp;
    }
}

char pop(struct Node **top) {

    struct Node *aux;
    char value = -1;

    if (*top != NULL) {
        value = (*top)->data;
        aux = *top;
        *top = (*top)->next;
        free(aux);
    } else {
        printf("Stack is empty.\n");
    }

    return value;
}

char getTop(struct Node *top) {

    char value = -1;

    if (top != NULL) {
        value = top->data;
    }

    return value;
}

int isEmpty(struct Node *top) {

    if (top == NULL) {
        return 1;
    } else {
        return 0;
    }
}

int isOperand(char character) {

    if (character == '+' || character == '-' ||
        character == '*' || character == '/' ||
        character == '^' || character == '(' ||
        character == ')') {

        return 0;
    }

    return 1;
}

int getPrecedence(char character) {

    if (character == '+' || character == '-') {
        return 1;
    } else if (character == '*' || character == '/') {
        return 3;
    } else if (character == '^') {
        return 6;
    } else if (character == '(') {
        return 7;
    }

    return 0;
}

int getStackPrecedence(char character) {

    if (character == '+' || character == '-') {
        return 2;
    } else if (character == '*' || character == '/') {
        return 4;
    } else if (character == '^') {
        return 5;
    }

    return 0;
}

char *convert(char *infix) {

    int i = 0, j = 0;
    int len = strlen(infix);
    char currentChar, stackTop;
    char *postfix = malloc((len + 1) * sizeof(char));
    struct Node *stack = NULL;

    while (infix[i] != '\0') {

        currentChar = infix[i];
        stackTop = getTop(stack);

        if (isOperand(currentChar)) {

            postfix[j] = currentChar;
            i++;
            j++;

        } else {

            if (currentChar == ')') {
                
                while (getPrecedence(currentChar) != getStackPrecedence(stackTop)) {
                    postfix[j] = pop(&stack);
                    stackTop = getTop(stack);
                    j++;
                }

                pop(&stack);
                i++;

            } else {

                if (getPrecedence(currentChar) > getStackPrecedence(stackTop)) {

                    push(&stack, currentChar);
                    i++;

                } else {

                    postfix[j] = pop(&stack);
                    j++;
                }
            }
        }
    }

    while (!isEmpty(stack)) {

        postfix[j] = pop(&stack);
        j++;
    }

    postfix[j] = '\0';
    return postfix;
}

int main() {

    char *infix = "(a+b)*c-d^e^f";
    char *postfix = convert(infix);

    printf("Infix expression:\n");
    printf("%s\n", infix);

    printf("\nPostfix expression:\n");
    printf("%s\n", postfix);

    return 0;
}

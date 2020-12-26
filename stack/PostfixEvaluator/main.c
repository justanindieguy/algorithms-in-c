#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void push(struct Node **top, int data);
int pop(struct Node **top);
int getTop(struct Node *top);
int isEmpty(struct Node *top);
void display(struct Node *top);
int evaluate(char *postfix);
int isOperand(char character);
int convertToInt(char character);

void push(struct Node **top, int data) {

    struct Node *temp = malloc(sizeof(struct Node));

    if (temp == NULL) {
        printf("Stack overflow.\n");
    } else {
        temp->data = data;
        temp->next = (*top);
        (*top) = temp;
    }
}

int pop(struct Node **top) {

    int value = -1;
    struct Node *aux;

    if (isEmpty(*top)) {
        printf("Stack is empty.\n");
    } else {
        aux = (*top);
        value = aux->data;
        (*top) = aux->next;
        free(aux);
    }

    return value;
}

int getTop(struct Node *top) {

    int value = -1;

    if (!isEmpty(top)) {
        value = top->data;
    }

    return value;
}

int isEmpty(struct Node *top) {

    if (top == NULL) {
        return 1;
    }

    return 0;
}

void display(struct Node *top) {

    struct Node *aux = top;

    while (aux != NULL) {
        printf("%d ", aux->data);
        aux = aux->next;
    }

    printf("\n");
}

int evaluate(char *postfix) {

    struct Node *stack = NULL;
    char currentChar;
    int i, firstOperand, secondOperand, result = -1;

    for (i = 0; postfix[i] != '\0'; i++) {

        currentChar = postfix[i];
        
        if (isOperand(currentChar)) {
            push(&stack, convertToInt(currentChar));
        } else {
            secondOperand = pop(&stack);
            firstOperand = pop(&stack);

            switch (currentChar) {
                case '+':
                    result = firstOperand + secondOperand;
                    break;
                case '-':
                    result = firstOperand - secondOperand;
                    break;
                case '*':
                    result = firstOperand * secondOperand;
                    break;
                case '/':
                    result = firstOperand / secondOperand;
                    break;
            }

            push(&stack, result);
        }
    }

    return pop(&stack);
}

int isOperand(char character) {
    
    if (character == '+' || character == '-'
        || character == '*' || character == '/'
        || character == '^' || character == '=') {
        return 0;
    }

    return 1;
}

int convertToInt(char character) {
    return character - '0';
}

int main() {

    char *postfix = "234*+82/-";
    printf("Postfix: %s\n", postfix);
    printf("Result: %d\n", evaluate(postfix));

    return 0;
}

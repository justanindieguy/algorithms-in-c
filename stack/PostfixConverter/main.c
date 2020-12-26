#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node *next;
};

/*--------------- PROTOTYPES ---------------*/
void push(struct Node **top, char data);
char pop(struct Node **top);
char getTop(struct Node *top);
int isEmpty(struct Node *top);
void display(struct Node *currentNode);
int isOperand(char character);
int getPrecedence(char operator);
char *convert(char *infix);

/*--------------- FUNCTIONS ---------------*/
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
    }

    return 0;
}

void display(struct Node *currentNode) {

    struct Node *aux = currentNode;

    while (aux != NULL) {
        printf("%c ", aux->data);
        aux = aux->next;
    }

    printf("\n");
}

int isOperand(char character) {

    if (character == '+' || character == '-' || character == '*' || character == '/') {
        return 0;
    }

    return 1;
}

int getPrecedence(char operator) {
    
    if (operator == '+' || operator == '-') {
        return 1;
    } else if (operator == '*' || operator == '/') {
        return 2;
    }

    return 0;
}

char *convert(char *infix) {

    int i = 0, j = 0;
    char *postfix;
    int len = strlen(infix);
    postfix = malloc((len + 1) * sizeof(char));
    struct Node *stack = NULL;
    char currentChar, stackTop;

    while (infix[i] != '\0') {

        currentChar = infix[i];
        stackTop = getTop(stack);        
        
        if (isOperand(currentChar)) {

            postfix[j] = currentChar;
            i++;
            j++;

        } else {

            if (getPrecedence(currentChar) > getPrecedence(stackTop)) {

                push(&stack, currentChar);
                i++;

            } else {

                postfix[j] = pop(&stack);
                j++;
            }
        }
    }

    while (!isEmpty(stack)) {

        postfix[j] = pop(&stack);
        j++;
    }

    postfix[i] = '\0';
    return postfix;
}

/*--------------- MAIN ---------------*/
int main() {

    char *infix = "a+b*c-d/e";
    char *postfix = convert(infix);

    printf("Infix expression:\n");
    printf("%s\n", infix);

    printf("\nPostfix expression:\n");
    printf("%s\n", postfix);

    return 0;
}

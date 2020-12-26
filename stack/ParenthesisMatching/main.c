#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node *next;
};

/*--------------- PROTOTYPES ---------------*/
void push(struct Node **top, char data);
char pop(struct Node **top);
char getTop(struct Node *stack);
void display(struct Node *stack);
int isBalanced(struct Node *stack, char *exp);
int checkMatch(char open, char close);

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
        printf("Stack empty.\n");
    }

    return value;
}

char getTop(struct Node *stack) {

    char value = -1;

    if (stack != NULL) {
        value = stack->data;
    } else {
        printf("The stack is empty.\n");
    }

    return value;
}

void display(struct Node *stack) {

    struct Node *aux = stack;

    while (aux != NULL) {
        printf("%c ", aux->data);
        aux = aux->next;
    }

    printf("\n");
}

int isBalanced(struct Node *stack, char *exp) {

    int i;
    char open;

    for (i = 0; exp[i] != '\0'; i++) {

        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[') {

            push(&stack, exp[i]);

        } else if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {

            if (stack == NULL) {
                return 0;
            }

            open = pop(&stack);

            if (!checkMatch(open, exp[i])) {
                return 0;
            }

        }
    }

    if (stack == NULL) {
        return 1;
    }

    return 0;
}

int checkMatch(char open, char close) {

    int result = 1;

    switch (close) {
        case '}':
            if (open != '{') {
                result = 0;
            }
            break;
        case ')':
            if (open != '(') {
                result = 0;
            }
            break;
        case ']':
            if (open != '[') {
                result = 0;
            }
            break;
    }

    return result;
}

/*--------------- MAIN ---------------*/
int main() {

    char *exp = "{([a+b]*[c-d])/e}";
    struct Node *newStack = NULL;

    if (isBalanced(newStack, exp)) {
        printf("The stack is balanced.\n");
    } else {
        printf("The stack is not balanced.\n");
    }

    return 0;
}

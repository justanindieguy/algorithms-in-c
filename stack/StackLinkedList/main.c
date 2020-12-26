#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *top = NULL;

/*--------------- PROTOTYPES ---------------*/
void push(int value);
int pop();
void display();

/*--------------- FUNCTIONS ---------------*/
void push(int value) {
    
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    if (temp == NULL) {
        printf("Stack is full.\n");
    } else {
        temp->data = value;
        temp->next = top;
        top = temp;
    }
}

int pop() {

    int value = -1;
    struct Node *aux = (struct Node *)malloc(sizeof(struct Node));

    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        aux = top;
        top = top->next;
        value = aux->data;
        free(aux);
    }

    return value;
}

void display() {

    struct Node *aux = top;

    while (aux != NULL) {
        printf("%d ", aux->data);
        aux = aux->next;
    }

    printf("\n");
}

/*--------------- MAIN ---------------*/
int main() {

    push(10);
    push(20);
    push(30);
    display();
    printf("Pop: %d", pop());

    return 0;
}

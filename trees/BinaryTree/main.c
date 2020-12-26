#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"
#include "Node.h"

struct Node *root = NULL;

void createTree() {
    struct Node *aux, *temp;
    int value;
    struct Queue queue;
    createQueue(&queue, 100);

    printf("Enter root value: ");
    scanf_s("%d", &value);

    root = malloc(sizeof(struct Node));
    root->data = value;
    root->lchild = root->rchild = NULL;
    enqueue(&queue, root);

    while (!isEmpty(queue)) {
        aux = dequeue(&queue);

        printf("Enter left child of %d: ", aux->data);
        scanf_s("%d", &value);
        if (value != -1) {
            temp = malloc(sizeof(struct Node));
            temp->data = value;
            temp->lchild = temp->rchild = NULL;

            aux->lchild = temp;
            enqueue(&queue, temp);
        }

        printf("Enter right child of %d: ", aux->data);
        scanf_s("%d", &value);
        if (value != -1) {
            temp = malloc(sizeof(struct Node));
            temp->data = value;
            temp->lchild = temp->rchild = NULL;

            aux->rchild = temp;
            enqueue(&queue, temp);
        }
    }
}

void preorder(struct Node *root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void inorder(struct Node *root) {
    if (root) {
        inorder(root->lchild);
        printf("%d ", root->data);
        inorder(root->rchild);
    }
}

void postorder(struct Node *root) {
    if (root) {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d ", root->data);
    }
}

void iPreorder(struct Node *root) {
    struct Stack stack;
    createStack(&stack, 100);

    while (root || !isEmptyStack(stack)) {
        if (root) {
            printf("%d ", root->data);
            push(&stack, root);
            root = root->lchild;
        } else {
            root = pop(&stack);
            root = root->rchild;
        }
    }

    printf("\n");
}

void iInorder(struct Node *root) {
    struct Stack stack;
    createStack(&stack, 100);

    while (root || !isEmptyStack(stack)) {
        if (root) {
            push(&stack, root);
            root = root->lchild;
        } else {
            root = pop(&stack);
            printf("%d ", root->data);
            root = root->rchild;
        }
    }
}

void levelorder(struct Node *root) {
    struct Queue queue;
    createQueue(&queue, 100);

    printf("%d ", root->data);
    enqueue(&queue, root);

    while (!isEmpty(queue)) {
        root = dequeue(&queue);

        if (root->lchild) {
            printf("%d ", root->lchild->data);
            enqueue(&queue, root->lchild);
        }

        if (root->rchild) {
            printf("%d ", root->rchild->data);
            enqueue(&queue, root->rchild);
        }
    }

    printf("\n");
}

int count(struct Node *root) {
    int x, y;

    if (root) {
        x = count(root->lchild);
        y = count(root->rchild);
        return x + y + 1;
    }

    return 0;
}

int countLeaf(struct Node *root) {
    int x, y;

    if (root) {
        x = countLeaf(root->lchild);
        y = countLeaf(root->rchild);

        if (!root->lchild && !root->rchild) {
            return x + y + 1;
        }

        return x + y;
    }

    return 0;
}

int countDeg2(struct Node *root) {
    int x, y;

    if (root) {
        x = countDeg2(root->lchild);
        y = countDeg2(root->rchild);

        if (root->lchild && root->rchild) {
            return x + y + 1;
        }

        return x + y;
    }

    return 0;
}

int countDeg1or2(struct Node *root) {
    int x, y;

    if (root) {
        x = countDeg1or2(root->lchild);
        y = countDeg1or2(root->rchild);

        if (root->lchild || root->rchild) {
            return x + y + 1;
        }

        return x + y;
    }

    return 0;
}

int countDeg1(struct Node *root) {
    int x, y;

    if (root) {
        x = countDeg1(root->lchild);
        y = countDeg1(root->rchild);

        if ((root->lchild && !root->rchild) || (!root->lchild && root->rchild)) {
            return x + y + 1;
        }

        return x + y;
    }

    return 0;
}

int height(struct Node *root) {
    int x, y;

    if (!root) {
        return -1;
    }

    x = height(root->lchild);
    y = height(root->rchild);

    if (x > y) {
        return x + 1;
    } else {
        return y + 1;
    }
}

int main() {
    createTree();

    printf("Count: %d\n", count(root));
    printf("Height: %d\n", height(root));
    printf("Leaf nodes: %d\n", countLeaf(root));
    printf("Nodes with degree 2: %d\n", countDeg2(root));
    printf("Nodes with degree 1 or 2: %d\n", countDeg1or2(root));
    printf("Nodes with degree 1: %d\n", countDeg1(root));

    /*
    printf("Preorder:\n");
    preorder(root);

    printf("\nInorder:\n");
    inorder(root);

    printf("\nPostorder:\n");
    postorder(root);

    printf("Levelorder:\n");
    levelorder(root);
    */

    return 0;
}

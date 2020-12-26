#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL;

struct Node *createNode(int value) {
    struct Node *newNode;
    newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->lchild = newNode->rchild = NULL;

    return newNode;
}

void insert(int key) {
    struct Node *aux = root;
    struct Node *tail = malloc(sizeof(struct Node));
    struct Node *newNode;

    if (root == NULL) {
        newNode = createNode(key);
        root = newNode;
        return;
    }

    while (aux) {
        tail = aux;

        if (key < aux->data) {
            aux = aux->lchild;
        } else if (key > aux->data) {
            aux = aux->rchild;
        } else {
            return;
        }
    }

    newNode = createNode(key);

    if (key < tail->data) {
        tail->lchild = newNode;
    } else {
        tail->rchild = newNode;
    }
}

struct Node *rInsert(struct Node *aux, int key) {
    if (!aux) {
        return createNode(key);
    }

    if (key < aux->data) {
        aux->lchild = rInsert(aux->lchild, key);
    } else if (key > aux->data) {
        aux->rchild = rInsert(aux->rchild, key);
    }

    return aux;
}

int countNodes(struct Node *aux) {
    if (!aux) {
        return 0;
    }

    return countNodes(aux->lchild) + countNodes(aux->rchild) + 1;
}

int getHeight(struct Node *aux) {
    int x, y;

    if (aux) {
        x = getHeight(aux->lchild);
        y = getHeight(aux->rchild);

        return x > y ? x + 1 : y + 1;
    }

    return -1;
}

struct Node *search(int key) {
    struct Node *aux = root;

    while (aux) {
        if (key == aux->data) {
            return aux;
        } else if (key < aux->data) {
            aux = aux->lchild;
        } else {
            aux = aux->rchild;
        }
    }

    return NULL;
}

struct Node *rSearch(struct Node *aux, int key) {
    if (aux == NULL) {
        return NULL;
    }

    if (key == aux->data) {
        return aux;
    } else if (key < aux->data) {
        return rSearch(aux->lchild, key);
    } else if (key > aux->data) {
        return rSearch(aux->rchild, key);
    }
}

void inorder(struct Node *root) {
    if (root) {
        inorder(root->lchild);
        printf("%d ", root->data);
        inorder(root->rchild);
    }
}

int main() {
    struct Node *temp;
    int numbers[] = { 10, 5, 20, 8, 30 };

    int i;
    for (i = 0; i < 5; i++) {
        if (i == 0) {
            root = rInsert(root, numbers[i]);
        } else {
            rInsert(root, numbers[i]);
        }
    }

    inorder(root);
    printf("\n");

    temp = rSearch(root, 5);
    if (temp) {
        printf("Element %d is found!\n", temp->data);
    } else {
        printf("Element is not found...\n");
    }

    printf("Number of nodes: %d\n", countNodes(root));
    printf("Height of the tree: %d", getHeight(root));

    return 0;
}

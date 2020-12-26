#include <stdio.h>
#include <stdlib.h>

struct Node *createNode(int data);
struct Node *rInsert(struct Node *aux, int data);
void preorder(struct Node *aux);
void inorder(struct Node *aux);
int getNodeHeight(struct Node *aux);
int getBalanceFactor(struct Node *aux);
struct Node *llRotation(struct Node *aux);
struct Node *lrRotation(struct Node *aux);
struct Node *rrRotation(struct Node *aux);
struct Node *rlRotation(struct Node *aux);

struct Node {
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
} *root = NULL;

struct Node *createNode(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode) {
        newNode->data = data;
        newNode->height = 1;
        newNode->lchild = newNode->rchild = NULL;

        return newNode;
    }

    return NULL;
}

int getNodeHeight(struct Node *aux) {
    int leftHeight, rightHeight;

    leftHeight = aux && aux->lchild ? aux->lchild->height : 0;
    rightHeight = aux && aux->rchild ? aux->rchild->height : 0;

    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

int getBalanceFactor(struct Node *aux) {
    int leftHeight, rightHeight;

    leftHeight = aux && aux->lchild ? aux->lchild->height : 0;
    rightHeight = aux && aux->rchild ? aux->rchild->height : 0;

    return leftHeight - rightHeight;
}

struct Node *llRotation(struct Node *aux) {
    struct Node *leftChild = aux->lchild;
    struct Node *leftRightChild = leftChild->rchild;

    leftChild->rchild = aux;
    aux->lchild = leftRightChild;

    leftChild->height = getNodeHeight(leftChild);
    aux->height = getNodeHeight(aux);

    if (root = aux)
        root = leftChild;

    return leftChild;
}

struct Node *lrRotation(struct Node *aux) {
    struct Node *auxLeftChild = aux->lchild;
    struct Node *auxLeftRightChild = auxLeftChild->rchild;

    auxLeftChild->rchild = auxLeftRightChild->lchild;
    aux->lchild = auxLeftRightChild->rchild;
    auxLeftRightChild->lchild = auxLeftChild;
    auxLeftRightChild->rchild = aux;

    auxLeftRightChild->height = getNodeHeight(auxLeftRightChild);
    auxLeftChild->height = getNodeHeight(auxLeftChild);
    aux->height = getNodeHeight(aux);

    if (root = aux)
        root = auxLeftRightChild;

    return auxLeftRightChild;
}

struct Node *rrRotation(struct Node *aux) {
    struct Node *rightChild = aux->rchild;
    struct Node *rightLeftChild = rightChild->lchild;

    rightChild->lchild = aux;
    aux->rchild = rightLeftChild;

    rightChild->height = getNodeHeight(rightChild);
    aux->height = getNodeHeight(aux);

    if (root == aux)
        root = rightChild;

    return rightChild;
}

struct Node *rlRotation(struct Node *aux) {
    struct Node *auxRightChild = aux->rchild;
    struct Node *auxRightLeftChild = auxRightChild->lchild;

    aux->rchild = auxRightLeftChild->lchild;
    auxRightChild->lchild = auxRightLeftChild->rchild;
    auxRightLeftChild->lchild = aux;
    auxRightLeftChild->rchild = auxRightChild;

    auxRightLeftChild->height = getNodeHeight(auxRightLeftChild);
    auxRightChild->height = getNodeHeight(auxRightChild);
    aux->height = getNodeHeight(aux);

    if (root = aux)
        root = auxRightLeftChild;

    return auxRightLeftChild;
}

void preorder(struct Node *aux) {
    if (aux == NULL)
        return;

    printf("%d ", aux->data);
    preorder(aux->lchild);
    preorder(aux->rchild);
}

void inorder(struct Node *aux) {
    if (aux == NULL)
        return;

    inorder(aux->lchild);
    printf("%d ", aux->data);
    inorder(aux->rchild);
}

struct Node *rInsert(struct Node *aux, int data) {
    if (aux == NULL) {
        return createNode(data);
    }

    if (data < aux->data)
        aux->lchild = rInsert(aux->lchild, data);
    else if (data > aux->data)
        aux->rchild = rInsert(aux->rchild, data);

    aux->height = getNodeHeight(aux);

    if (getBalanceFactor(aux) == 2 && getBalanceFactor(aux->lchild) == 1)
        return llRotation(aux);
    else if (getBalanceFactor(aux) == 2 && getBalanceFactor(aux->lchild) == -1)
        return lrRotation(aux);
    else if (getBalanceFactor(aux) == -2 && getBalanceFactor(aux->rchild) == -1)
        return rrRotation(aux);
    else if (getBalanceFactor(aux) == -2 && getBalanceFactor(aux->rchild) == 1)
        return rlRotation(aux);

    return aux;
}

int main() {
    root = rInsert(root, 10);
    rInsert(root, 20);
    rInsert(root, 30);
    rInsert(root, 25);
    rInsert(root, 28);
    rInsert(root, 27);
    rInsert(root, 5);

    printf("Preorder traversal:\n");
    preorder(root);

    return 0;
}
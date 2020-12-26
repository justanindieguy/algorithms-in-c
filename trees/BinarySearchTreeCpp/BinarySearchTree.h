#pragma once
#include <iostream>
#include <limits>
#include "Node.h"
#include "Stack.h"

class BinarySearchTree {
private:
    Node *root;

    Node *rInsert(Node *aux, int value);
    Node *rDelete(Node *aux, int key);
    Node *rSearch(Node *aux, int key);
    int countNodes(Node *aux);
    int getHeight(Node *aux);
    Node *inPre(Node *aux);
    Node *inSucc(Node *aux);
    void inorder(Node *aux);
    void postorder(Node *aux);

public:
    BinarySearchTree() {
        root = nullptr;
    }

    void insert(int value);
    void rInsert(int value);
    void rDelete(int key);
    Node *search(int key);
    Node *rSearch(int key);
    int countNodes();
    int getHeight();
    void inorder();
    void postorder();
    void createFromPreorder(int pre[], int size);
    void createFromPostorder(int post[], int size);
};

void BinarySearchTree::insert(int value) {
    Node *aux = root;
    Node *tail = nullptr;
    Node *newNode;

    if (root == nullptr) {
        newNode = new Node(value);
        root = newNode;
        return;
    }

    while (aux != nullptr) {
        tail = aux;

        if (value < aux->data) {
            aux = aux->lchild;
        } else if (value > aux->data) {
            aux = aux->rchild;
        } else {
            return;
        }
    }

    newNode = new Node(value);

    if (value < tail->data) {
        tail->lchild = newNode;
    } else if (value > tail->data) {
        tail->rchild = newNode;
    }
}

Node *BinarySearchTree::rInsert(Node *aux, int value) {
    if (aux == nullptr) {
        return new Node(value);
    }

    if (value < aux->data) {
        aux->lchild = rInsert(aux->lchild, value);
    } else if (value > aux->data) {
        aux->rchild = rInsert(aux->rchild, value);
    }

    return aux;
}

void BinarySearchTree::rInsert(int value) {
    if (!root) {
        root = rInsert(nullptr, value);
    } else {
        rInsert(root, value);
    }
}

Node *BinarySearchTree::rDelete(Node *aux, int key) {
    Node *temp;

    if (!aux) {
        return nullptr;
    }

    if (!aux->lchild && !aux->rchild) {
        if (aux == root) {
            root = nullptr;
        }

        delete aux;
        return nullptr;
    }

    if (key < aux->data) {
        aux->lchild = rDelete(aux->lchild, key);
    } else if (key > aux->data) {
        aux->rchild = rDelete(aux->rchild, key);
    } else {
        if (getHeight(aux->lchild) > getHeight(aux->rchild)) {
            temp = inPre(aux->lchild);
            aux->data = temp->data;
            aux->lchild = rDelete(aux->lchild, temp->data);
        } else {
            temp = inSucc(aux->rchild);
            aux->data = temp->data;
            aux->rchild = rDelete(aux->rchild, temp->data);
        }
    }

    return aux;
}

void BinarySearchTree::rDelete(int key) {
    rDelete(root, key);
}

Node *BinarySearchTree::search(int key) {
    Node *aux = root;

    while (aux) {
        if (key == aux->data) {
            return aux;
        } else if (key < aux->data) {
            aux = aux->lchild;
        } else if (key > aux->data) {
            aux = aux->rchild;
        }
    }

    return nullptr;
}

Node *BinarySearchTree::rSearch(Node *aux, int key) {
    if (!aux) {
        return nullptr;
    }

    if (key == aux->data) {
        return aux;
    } else if (key < aux->data) {
        return rSearch(aux->lchild, key);
    } else if (key > aux->data) {
        return rSearch(aux->rchild, key);
    }
}

Node *BinarySearchTree::rSearch(int key) {
    return rSearch(root, key);
}

int BinarySearchTree::countNodes(Node *aux) {
    if (!aux) {
        return 0;
    }

    return countNodes(aux->lchild) + countNodes(aux->rchild) + 1;
}

int BinarySearchTree::countNodes() {
    return countNodes(root);
}

int BinarySearchTree::getHeight(Node *aux) {
    int x, y;

    if (aux) {
        x = getHeight(aux->lchild);
        y = getHeight(aux->rchild);

        return x > y ? x + 1 : y + 1;
    }

    return -1;
}

int BinarySearchTree::getHeight() {
    return getHeight(root);
}

Node *BinarySearchTree::inPre(Node *aux) {
    while (aux && aux->rchild) {
        aux = aux->rchild;
    }

    return aux;
}

Node *BinarySearchTree::inSucc(Node *aux) {
    while (aux && aux->lchild) {
        aux = aux->lchild;
    }

    return aux;
}

void BinarySearchTree::inorder(Node *aux) {
    if (aux) {
        inorder(aux->lchild);
        std::cout << aux->data << " ";
        inorder(aux->rchild);
    }
}

void BinarySearchTree::inorder() {
    inorder(root);
    std::cout << std::endl;
}

void BinarySearchTree::postorder(Node *aux) {
    if (aux) {
        postorder(aux->lchild);
        postorder(aux->rchild);
        std::cout << aux->data << " ";
    }
}

void BinarySearchTree::postorder() {
    postorder(root);
    std::cout << std::endl;
}

void BinarySearchTree::createFromPreorder(int pre[], int size) {
    int i = 0;
    constexpr int inf = std::numeric_limits<int>::max();
    Node *aux, *temp;
    Stack stk;

    root = new Node(pre[i++]);
    aux = root;

    while (i < size) {
        // Left child case.
        if (pre[i] < aux->data) {
            temp = new Node(pre[i++]);
            aux->lchild = temp;
            stk.push(aux);
            aux = temp;
        } else {
            int compareValue = stk.isEmpty() ? inf : stk.getTop()->data;

            // Right child case.
            if ((pre[i] > aux->data) && (pre[i] < compareValue)) {
                temp = new Node(pre[i++]);
                aux->rchild = temp;
                aux = temp;
            } else {
                aux = stk.pop();
            }
        }
    }
}

void BinarySearchTree::createFromPostorder(int post[], int size) {
    int i = size - 1;
    constexpr int negativeInf = std::numeric_limits<int>::min();
    Node *aux, *temp;
    Stack stk;

    root = new Node(post[i--]);
    aux = root;

    while (i >= 0) {
        if (post[i] > aux->data) {
            temp = new Node(post[i--]);
            aux->rchild = temp;
            stk.push(aux);
            aux = temp;
        } else {
            int compareValue = stk.isEmpty() ? negativeInf : stk.getTop()->data;

            if ((post[i] > compareValue) && (post[i] < aux->data)) {
                temp = new Node(post[i--]);
                aux->lchild = temp;
                aux = temp;
            } else {
                aux = stk.pop();
            }
        }
    }
}

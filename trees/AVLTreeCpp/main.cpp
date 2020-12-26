#include <iostream>

class Node {
public:
    Node *lchild;
    int data;
    int height;
    Node *rchild;
};

class AVLTree {
public:
    AVLTree() {
        root = nullptr;
    }

    // Insert
    void insert(int key);

    // Delete
    void deleteNode(int key);

    // Traversals.
    void inorder();
    void preorder();
    void postorder();

private:
    Node *root;

    // Helper methods for inserting/deleting.
    int getNodeHeight(Node *aux);
    int getBalanceFactor(Node *aux);
    Node *llRotation(Node *aux);
    Node *lrRotation(Node *aux);
    Node *rrRotation(Node *aux);
    Node *rlRotation(Node *aux);
    Node *getInorderPredecessor(Node *aux);
    Node *getInorderSuccessor(Node *aux);
    Node *createNewNode(int key);

    // Insert
    Node *rInsert(Node *aux, int key);

    // Delete
    Node *deleteNode(Node *aux, int key);

    // Traversals.
    void inorder(Node *aux);
    void preorder(Node *aux);
    void postorder(Node *aux);
};

int AVLTree::getNodeHeight(Node *aux) {
    int leftHeight;
    int rightHeight;

    leftHeight = (aux && aux->lchild) ? aux->lchild->height : 0;
    rightHeight = (aux && aux->rchild) ? aux->rchild->height : 0;

    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

int AVLTree::getBalanceFactor(Node *aux) {
    int leftHeight;
    int rightHeight;

    leftHeight = (aux && aux->lchild) ? aux->lchild->height : 0;
    rightHeight = (aux && aux->rchild) ? aux->rchild->height : 0;

    return leftHeight - rightHeight;
}

Node *AVLTree::createNewNode(int key) {
    Node *newNode = new Node;

    if (newNode) {
        newNode->data = key;
        newNode->height = 1;
        newNode->lchild = newNode->rchild = 0;

        return newNode;
    }

    return nullptr;
}

Node *AVLTree::llRotation(Node *aux) {
    Node *leftChild = aux->lchild;
    Node *leftRightChild = leftChild->rchild;

    leftChild->rchild = aux;
    aux->lchild = leftRightChild;

    // Update height
    aux->height = getNodeHeight(aux);
    leftChild->height = getNodeHeight(leftChild);

    if (root == aux)
        root = leftChild;

    return leftChild;
}

Node *AVLTree::lrRotation(Node *aux) {
    Node *leftChild = aux->lchild;
    Node *leftRightChild = leftChild->rchild;

    aux->lchild = leftRightChild->rchild;
    leftChild->rchild = leftRightChild->lchild;

    leftRightChild->lchild = leftChild;
    leftRightChild->rchild = aux;

    // Update height
    leftRightChild->height = getNodeHeight(leftRightChild);
    leftChild->height = getNodeHeight(leftChild);
    aux->height = getNodeHeight(aux);

    if (root == aux)
        root = leftRightChild;

    return leftRightChild;
}

Node *AVLTree::rrRotation(Node *aux) {
    Node *rightChild = aux->rchild;
    Node *rightLeftChild = rightChild->lchild;

    rightChild->lchild = aux;
    aux->rchild = rightLeftChild;

    // Update height.
    rightChild->height = getNodeHeight(rightChild);
    aux->height = getNodeHeight(aux);

    if (root == aux)
        root = rightChild;

    return rightChild;
}

Node *AVLTree::rlRotation(Node *aux) {
    Node *rightChild = aux->rchild;
    Node *rightLeftChild = rightChild->lchild;

    aux->rchild = rightLeftChild->lchild;
    rightChild->lchild = rightLeftChild->rchild;

    rightLeftChild->lchild = aux;
    rightLeftChild->rchild = rightChild;

    // Update height.
    rightLeftChild->height = getNodeHeight(rightLeftChild);
    rightChild->height = getNodeHeight(rightChild);
    aux->height = getNodeHeight(aux);

    if (root == aux)
        root = rightLeftChild;

    return rightLeftChild;
}

void AVLTree::insert(int key) {
    if (root == nullptr)
        root = rInsert(root, key);
    else
        rInsert(root, key);
}

Node *AVLTree::rInsert(Node *aux, int key) {
    if (aux == nullptr) {
        return createNewNode(key);
    }

    if (key < aux->data) {
        aux->lchild = rInsert(aux->lchild, key);
    } else if (key > aux->data) {
        aux->rchild = rInsert(aux->rchild, key);
    }

    // Update height.
    aux->height = getNodeHeight(aux);

    // Balance factor and rotation.
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

void AVLTree::deleteNode(int key) {
    deleteNode(root, key);
}

Node *AVLTree::deleteNode(Node *aux, int key) {
    Node *temp;

    if (aux == nullptr)
        return nullptr;

    if (aux->lchild == nullptr && aux->rchild == nullptr) {
        if (root == aux)
            root = nullptr;

        delete aux;
        return nullptr;
    }

    if (key < aux->data)
        aux->lchild = deleteNode(aux->lchild, key);
    else if (key > aux->data)
        aux->rchild = deleteNode(aux->rchild, key);
    else {
        if (getNodeHeight(aux->lchild) > getNodeHeight(aux->rchild)) {
            temp = getInorderPredecessor(aux->lchild);
            aux->data = temp->data;
            aux->lchild = deleteNode(aux->lchild, temp->data);
        } else {
            temp = getInorderSuccessor(aux->rchild);
            aux->data = temp->data;
            aux->rchild = deleteNode(aux->rchild, temp->data);
        }
    }

    // Update height.
    aux->height = getNodeHeight(aux);

    if (getBalanceFactor(aux) == 2 && getBalanceFactor(aux->lchild) == 1) // LL Rotation
        return llRotation(aux);
    else if (getBalanceFactor(aux) == 2 && getBalanceFactor(aux->lchild) == -1) // L-1 Rotation
        return lrRotation(aux);
    else if (getBalanceFactor(aux) == -2 && getBalanceFactor(aux->rchild) == -1) // R-1 Rotation
        return rrRotation(aux);
    else if (getBalanceFactor(aux) == -2 && getBalanceFactor(aux->rchild) == 1) // R1 Rotation
        return rlRotation(aux);
    else if (getBalanceFactor(aux) == 2 && getBalanceFactor(aux->lchild) == 0) // L0 Rotation
        return llRotation(aux);
    else if (getBalanceFactor(aux) == 2 && getBalanceFactor(aux->rchild) == 0) // R0 Rotation
        return rrRotation(aux);

    return aux;
}

Node *AVLTree::getInorderPredecessor(Node *aux) {
    while (aux && aux->rchild != nullptr) {
        aux = aux->rchild;
    }

    return aux;
}

Node *AVLTree::getInorderSuccessor(Node *aux) {
    while (aux && aux->lchild != nullptr) {
        aux = aux->lchild;
    }

    return aux;
}

void AVLTree::inorder() {
    if (root != nullptr) {
        inorder(root);
        std::cout << std::endl;
    }
}

void AVLTree::inorder(Node *aux) {
    if (aux == nullptr)
        return;

    inorder(aux->lchild);
    std::cout << aux->data << " ";
    inorder(aux->rchild);
}

void AVLTree::preorder() {
    if (root != nullptr) {
        preorder(root);
        std::cout << std::endl;
    }
}

void AVLTree::preorder(Node *aux) {
    if (aux == nullptr)
        return;

    std::cout << aux->data << " ";
    preorder(aux->lchild);
    preorder(aux->rchild);
}

void AVLTree::postorder() {
    if (root != nullptr) {
        postorder(root);
        std::cout << std::endl;
    }
}

void AVLTree::postorder(Node *aux) {
    if (aux == nullptr)
        return;

    postorder(aux->lchild);
    postorder(aux->rchild);
    std::cout << aux->data << " ";
}

int main() {
    AVLTree *myTree = new AVLTree;

    int keys[] = { 30, 10, 40, 5, 20 };
    int keysLength = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < keysLength; i++) {
        myTree->insert(keys[i]);
    }

    myTree->deleteNode(40);

    std::cout << "Preorder:" << std::endl;
    myTree->preorder();

    std::cout << "Inorder:" << std::endl;
    myTree->inorder();

    return 0;
}
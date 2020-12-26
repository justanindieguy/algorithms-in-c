#include <iostream>
#include "Node.h"
#include "Queue.h"
#include "Stack.h"

class Tree {
private:
    Node *root;

public:
    Tree() {
        root = NULL;
    }

    void createTree();

    void preorder();
    void preorder(Node *root);

    void iPreorder();
    void iPreorder(Node *root);

    void inorder();
    void inorder(Node *root);

    void postorder();
    void postorder(Node *root);

    void levelorder();
    void levelorder(Node *root);

    int count();
    int count(Node *root);

    int getHeight();
    int getHeight(Node *root);
};

void Tree::createTree() {
    Node *aux, *temp;
    int value;
    Queue queue(100);

    std::cout << "Enter root value: ";
    std::cin >> value;

    root = new Node;
    root->data = value;
    root->lchild = root->rchild = NULL;
    queue.enqueue(root);

    while (!queue.isEmpty()) {
        aux = queue.dequeue();

        std::cout << "Enter left child of " << aux->data << ": ";
        std::cin >> value;
        if (value != -1) {
            temp = new Node;
            temp->data = value;
            temp->lchild = temp->rchild = NULL;
            aux->lchild = temp;
            queue.enqueue(temp);
        }

        std::cout << "Enter right child of " << aux->data << ": ";
        std::cin >> value;
        if (value != -1) {
            temp = new Node;
            temp->data = value;
            temp->lchild = temp->rchild = NULL;
            aux->rchild = temp;
            queue.enqueue(temp);
        }
    }
}

// ************
// * Preorder *
// ************
void Tree::preorder() {
    preorder(root);
    std::cout << std::endl;
}

void Tree::preorder(Node *root) {
    if (root) {
        std::cout << root->data << " ";
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void Tree::iPreorder() {
    iPreorder(root);
}

void Tree::iPreorder(Node *root) {
    Stack stack(100);

    while (root != NULL || !stack.isEmpty()) {
        if (root) {
            std::cout << root->data << " ";
            stack.push(root);
            root = root->lchild;
        } else {
            root = stack.pop();
            root = root->rchild;
        }
    }

    std::cout << std::endl;
}

// ***********
// * Inorder *
// ***********
void Tree::inorder() {
    inorder(root);
    std::cout << std::endl;
}

void Tree::inorder(Node *root) {
    if (root) {
        inorder(root->lchild);
        std::cout << root->data << " ";
        inorder(root->rchild);
    }
}

// *************
// * Postorder *
// *************
void Tree::postorder() {
    postorder(root);
    std::cout << std::endl;
}

void Tree::postorder(Node *root) {
    if (root) {
        postorder(root->lchild);
        postorder(root->rchild);
        std::cout << root->data << " ";
    }
}

// **************
// * Levelorder *
// **************
void Tree::levelorder() {
    levelorder(root);
}

void Tree::levelorder(Node *root) {
    Queue queue(100);

    std::cout << root->data << " ";
    queue.enqueue(root);

    while (!queue.isEmpty()) {
        root = queue.dequeue();

        if (root->lchild) {
            std::cout << root->lchild->data << " ";
            queue.enqueue(root->lchild);
        }

        if (root->rchild) {
            std::cout << root->rchild->data << " ";
            queue.enqueue(root->rchild);
        }
    }

    std::cout << std::endl;
}

// *********
// * Count *
// *********
int Tree::count() {
    return count(root);
}

int Tree::count(Node *root) {
    int x, y;

    if (root) {
        x = count(root->lchild);
        y = count(root->rchild);
        return x + y + 1;
    }

    return 0;
}

// **************
// * Get Height *
// **************
int Tree::getHeight() {
    return getHeight(root);
}

int Tree::getHeight(Node *root) {
    int x, y;

    if (!root) {
        return -1;
    }

    x = getHeight(root->lchild);
    y = getHeight(root->rchild);
    
    if (x > y) {
        return x + 1;
    } else {
        return y + 1;
    }
}

int main() {
    Tree myTree;

    myTree.createTree();

    std::cout << "Preorder:" << std::endl;
    myTree.iPreorder();

    std::cout << "Inorder:" << std::endl;
    myTree.inorder();

    std::cout << "Postorder:" << std::endl;
    myTree.postorder();

    std::cout << "Levelorder:" << std::endl;
    myTree.levelorder();

    std::cout << "Number of nodes: " << myTree.count() << std::endl;

    std::cout << "Height of the tree: " << myTree.getHeight() << std::endl;

    return 0;
}

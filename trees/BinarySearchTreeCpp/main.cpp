#include <iostream>
#include "BinarySearchTree.h"

int main() {
    BinarySearchTree myTree;
    int numbers[] = { 10, 5, 20, 8, 30 };

    for (int i = 0; i < 5; i++) {
        myTree.rInsert(numbers[i]);
    }

    if (myTree.rSearch(10)) {
        std::cout << "Node found." << std::endl;
    } else {
        std::cout << "Node not found." << std::endl;
    }

    std::cout << "Number of nodes: " << myTree.countNodes() << std::endl;
    std::cout << "Height: " << myTree.getHeight() << std::endl;

    myTree.rDelete(10);
    myTree.inorder();

    // BST from preorder traversal.
    std::cout << "BST from preorder" << std::endl << std::flush;
    int pre[] = { 30, 20, 10, 15, 25, 40, 50, 45 };
    int size = sizeof(pre) / sizeof(pre[0]);

    BinarySearchTree preTree;
    preTree.createFromPreorder(pre, size);
    preTree.inorder();

    // BST from postorder traversal.
    std::cout << "BST from postorder" << std::endl << std::flush;
    int post[] = { 15, 10, 25, 20, 45, 50, 40, 30 };
    int postSize = sizeof(post) / sizeof(post[0]);

    BinarySearchTree postTree;
    postTree.createFromPostorder(post, postSize);
    postTree.inorder();

    return 0;
}
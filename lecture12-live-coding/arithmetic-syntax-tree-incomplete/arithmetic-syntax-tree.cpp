#include <iostream>

#include "arithmetic-syntax-tree.h"

using namespace std;

// Internal function to print the contents of a node (used below)
void printNode(NodeType type, int value) {
    switch (type) {
    case Const:
        cout << value;
        break;
    case Add:
        cout << "+";
        break;
    case Mult:
        cout << "*";
        break;
    default:
        throw logic_error("BUG! This should not happen!");
    }
}

// Constructor for leaf nodes (constants)
ArithmeticSyntaxTree::ArithmeticSyntaxTree(unsigned int value) {
    // TODO
}

// Constructor for internal nodes (left + right, or left * right)
ArithmeticSyntaxTree::ArithmeticSyntaxTree(NodeType type,
                                           ArithmeticSyntaxTree *left,
                                           ArithmeticSyntaxTree *right) {
    // TODO
}

// Destructor.  We delete the left and right descendants
ArithmeticSyntaxTree::~ArithmeticSyntaxTree() {
    // Uncomment the following line see the order in which nodes are destroyed
    // cout << "Destroying: "; printNode(this->type, this->value); cout << endl;
    // TODO
}

// Size of a tree
unsigned int ArithmeticSyntaxTree::size(void) {
    // TODO
    return 0;
}

// Height of a tree
unsigned int ArithmeticSyntaxTree::height(void) {
    // TODO
    return 0;
}

// The number of leaves can be computed in a similar fashion to
// size() and height()
unsigned int ArithmeticSyntaxTree::leaves(void) {
    // TODO
    return 0;
}

// Pre-order traversal method: first print a node, then keep traversing
void ArithmeticSyntaxTree::traversePre(void) {
    // TODO
}

// In-order traversal method: first traverse the left descendant (unless we
// have reached a leaf), then print the current node, then traverse the right
// descendant
void ArithmeticSyntaxTree::traverseIn(void) {
    // TODO
}

// Post-order traversal method: first traverse the left descendant (unless we
// have reached a leaf), then traverse the right descendant, 
// then print the current node.
void ArithmeticSyntaxTree::traversePost(void) {
    // TODO
}
// Compute the value of the expression represented in the tree
unsigned int ArithmeticSyntaxTree::evaluate() {
    // TODO
    return 0;
}


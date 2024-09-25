#include <iostream>

using namespace std;

// Listing the node
struct Node{
    int val;    // Contains the value
    Node *left; // Pointer to the next element in the list
    Node *right; // Pointer to the previous element in the list
};

// Class tree
class tree{
    public:
        tree(void);
        ~tree(void);

        void fibonacci(int n);
        int size();
        int depth();
        int leaf();
        void print();

    private:
        Node *root;
        Node *aux(int n);
        int size(Node *node);
        int depth(Node *node);
        int leaf(Node *node);
        void print(Node *leaf);
};

tree::tree(){
    root = NULL;
}
tree::~tree(){}

void tree::fibonacci(int n){
    root = new Node;
    
    if(n<=1){
        root->val = 1;
        root->right = NULL;
        root->left = NULL;
    } else {
        root->left = aux(n-1);
        root->right = aux(n-2);
        root->val = root->left->val + root->right->val;
    }
}

Node *tree::aux(int n){
    Node *node = new Node();
    
    if (n <= 1) {
        node->val = 1;
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    node->left = aux(n - 1);
    node->right = aux(n - 2);
    node->val = node->left->val + node->right->val;
    return node;
}

int tree::size(){
    if(root == NULL) return 0;

    return 1 + size(root->left) + size(root->right);
}

int tree::size(Node *node){
    if(node != NULL){
        return 1 + size(node->left) + size(node->right);
    } else return 0;
}

int tree::depth(){
    if (root == NULL)
        return 0;
    else {
        int left_depth =  depth(root->left);
        int right_depth = depth(root->right);

        if (left_depth > right_depth)
            return left_depth + 1;
        else 
            return right_depth + 1;
    }
}

int tree::depth(Node *node){
    if (node == NULL)
        return 0;
    else {
        int left_depth =  depth(node->left);
        int right_depth = depth(node->right);

        if (left_depth > right_depth)
            return left_depth + 1;
        else
            return right_depth + 1;
    }
}

int tree::leaf(){
    if (root == NULL)
        return 0;
    else if (root->left == NULL && root->right == NULL)
        return 1;
    else
        return leaf(root->left) + leaf(root->right);
}

int tree::leaf(Node *node){
    if (node == NULL)
        return 0;
    else if (node->left == NULL && node->right == NULL)
        return 1;
    else
        return leaf(node->left) + leaf(node->right);
}

void tree::print(){
    print(root);
    cout << endl;
}

void tree::print(Node *node){
    if(node != NULL){
        cout << node->val << " ";
        print(node->left);
        print(node->right);
    }
}

int main(){
    int n;
    tree t;
    cin >> n;
    t.fibonacci(n);


    cout << "Call tree in pre-order: ";
    t.print();
    cout << "Call tree size: " << t.size() << endl;
    cout << "Call tree depth: " << t.depth() << endl;
    cout << "Call tree leafs: " << t.leaf() << endl;
    return 0;
}

// g++ ex11.cpp
// ./a.out

#include "ex04-library.h"
#include <iostream>

using namespace std;

//Do not modify
template<class T>
void Node<T>::printNode(){
	cout << "Name: " << name << ", value: " << value ;
	cout << ", children: " << children.size() << endl;
}

//Exercise 4 (a) Check and correct if necessary
template<class T>
Node<T>::Node(string name, T value) : name(name), value(value){}

//Exercise 4 (b) Implement getName, getValue, and addChild
template<class T>
string Node<T>::getName(){
	//put your code here
	return this->name;
}

template<class T>
T Node<T>::getValue(){
	//put your code here
	return this->value;
}

template<class T>
void Node<T>::addChild(Node<T> * child){
	//put your code here
	children.push_back(child);
}

//Exercise 4 (c) Implement this method
template<class T>
void Node<T>::printLeafNodes(){
	//put your code here
	if (children.empty()) {
        // This is a leaf node
        cout << this->name << ' ' << this->value << ' ';
    } else {
        // Non-leaf node, recursively invoke on children
        for (int i = 0; i < children.size(); i++) {
            children[i]->printLeafNodes();
        }
    }
}

//Exercise 4 (d) Implement this method
template<class T>
int Node<T>::countMembersOfSubTree(){
	//put your code here
	int count = 1;  // Count the current node

    // Recursively count members in the subtree for each child
    for (int i = 0; i < children.size(); i++) {
        count += children[i]->countMembersOfSubTree();
    }

    return count;
}

//Do not modify
template class Node<string>;
#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
using namespace std;

template <typename T>
class Node {
private:
    T value;  // The value stored in the node.
    vector<Node<T>*> children;  // The children of this node.

public:
    Node(T v) : value(v) {}  // Constructor

    ~Node() {
        children.clear();  // Clear children to avoid memory leaks.
    }

    void add_child(const Node<T>& child) {
        children.push_back(new Node<T>(child));  // Add a new child node.
    }

    T get_value() const { return value; }  // Get the value of the node.

    vector<Node<T>*> get_children() const { return children; }  // Get the children of the node.
};

#endif // NODE_HPP

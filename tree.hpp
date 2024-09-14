#ifndef TREE_HPP
#define TREE_HPP

#include <iomanip>
#include "node.hpp"
#include <iostream>
#include <queue>
#include <SFML/Graphics.hpp>
using namespace std;

const float NODE_RADIUS = 50.0f;  // Radius for node drawing in SFML.

template<typename T, int K = 2>
class Tree {
private:
    Node<T> *root;  // Root node of the tree.
    int k;  // Maximum number of children per node.
    bool is_binary_tree;  // Indicates if the tree is binary.

    // Vectors to store nodes during different traversals.
    vector<Node<T> *> pre_order_nodes;
    vector<Node<T> *> post_order_nodes;
    vector<Node<T> *> in_order_nodes;
    vector<Node<T> *> bfs_nodes;
    vector<Node<T> *> dfs_nodes;
    vector<Node<T> *> heap_nodes;

    void pre_order_helper(Node<T> *root, vector<Node<T> *> &preOrderNodes) {
        if (root == nullptr) return;  // Base case: if the current node is null, return.

        preOrderNodes.push_back(root);  // Visit the current node and add it to the result list.
        for (auto child : root->get_children()) {  // Iterate over all children of the current node.
            pre_order_helper(child, preOrderNodes);  // Recursively apply pre-order traversal to each child.
        }
    }

    void post_order_helper(Node<T> *root, vector<Node<T> *> &postOrderNodes) {
        if (root == nullptr) return;  // Base case: if the current node is null, return.

        for (auto child : root->get_children()) {  // Iterate over all children of the current node.
            post_order_helper(child, postOrderNodes);  // Recursively apply post-order traversal to each child.
        }
        postOrderNodes.push_back(root);  // Visit the current node after its children.
    }

    void in_order_helper(Node<T> *root, vector<Node<T> *> &inOrderNodes) {
        if (root == nullptr) return;  // Base case: if the current node is null, return.

        auto children = root->get_children();  // Get the children of the current node.
        if (children.size() > 0) {  // If there are children, traverse the first child.
            in_order_helper(children[0], inOrderNodes);
        }
        inOrderNodes.push_back(root);  // Visit the current node.
        if (children.size() > 1) {  // If there is a second child, traverse it.
            in_order_helper(children[1], inOrderNodes);
        }
    }

    void bfs_helper(Node<T> *root, vector<Node<T> *> &bfsNodes) {
        if (root == nullptr) return;  // Base case: if the current node is null, return.

        queue<Node<T> *> q;  // Queue for BFS.
        q.push(root);  // Start with the root node.
        while (!q.empty()) {
            Node<T> *curr = q.front();  // Get the next node in the queue.
            q.pop();  // Remove the node from the queue.
            bfsNodes.push_back(curr);  // Visit the current node.
            for (auto child : curr->get_children()) {  // Add all children to the queue.
                q.push(child);
            }
        }
    }

    void dfs_helper(Node<T> *root, vector<Node<T> *> &dfsNodes) {
        if (root == nullptr) return; // Base case: if the current node is null, return.

        dfsNodes.push_back(root); // Visit the current node and add it to the result list.

        for (auto child : root->get_children()) { // Iterate over all children of the current node.
            dfs_helper(child, dfsNodes); // Recursively apply DFS to each child.
        }
    }

    void heap_helper(Node<T> *root, vector<Node<T> *> &heapNodes) {
        if (root == nullptr) return; // Base case: if the current node is null, return.

        dfs_helper(root, heapNodes); // Use DFS to gather all nodes.

        // Create a max-heap based on node values.
        auto comp = [](Node<T> *lhs, Node<T> *rhs) {
            return lhs->get_value() < rhs->get_value(); // This will make the largest value the root of the heap.
        };

        make_heap(heapNodes.begin(), heapNodes.end(), comp); // Transform into a heap.
        sort_heap(heapNodes.begin(), heapNodes.end(), comp); // Sort into heap order.
        reverse(heapNodes.begin(), heapNodes.end()); // Reverse to get the largest element first.
    }

public:
    Tree() : root(nullptr), is_binary_tree(K == 2) {
        k = K;  // Initialize k to the specified maximum number of children.
    }

    ~Tree() { delete_tree(root); }  // Destructor to clean up the tree.

    int get_k() const { return k; }  // Get the maximum number of children per node.

    Node<T> *get_root() const { return root; }  // Get the root node of the tree.

    void add_root(const Node<T> &node) {
        if (root != nullptr) {
            throw runtime_error("The root node already exists.");  // If a root already exists, throw an error.
        }
        root = new Node<T>(node.get_value());  // Set the root node.
    }

    void add_sub_node(const Node<T> &parent, const Node<T> &child) {
        if (root == nullptr) {
            throw runtime_error("Root node not found");  // If the root does not exist, throw an error.
        }

        Node<T> *parent_ptr = find_node(root, parent.get_value());  // Find the parent node in the tree.
        if (parent_ptr == nullptr) {
            throw runtime_error("Parent node not found.");  // If the parent node is not found, throw an error.
        }

        if (parent_ptr->get_children().size() >= get_k()) {
            throw runtime_error("Node has reached the maximum number of children");  // Check if the parent can accept more children.
        }

        parent_ptr->add_child(child);  // Add the new child to the parent node.
    }

    Node<T> *find_node(Node<T> *node, const T &value) {
        if (node == nullptr) return nullptr;  // Base case: if the current node is null, return nullptr.

        if (node->get_value() == value) return node;  // If the current node matches the value, return it.

        for (auto child : node->get_children()) {  // Iterate over all children of the current node.
            Node<T> *found = find_node(child, value);  // Recursively search for the node in the subtree.
            if (found != nullptr) return found;  // If the node is found, return it.
        }
        return nullptr;  // Node not found in this subtree.
    }

    void delete_tree(Node<T> *node) {
        if (node == nullptr) return;  // Base case: if the current node is null, return.

        for (auto child : node->get_children()) {  // Recursively delete all children of the current node.
            delete_tree(child);
        }
        delete node;  // Delete the current node.
    }

    class iterator {
    private:
        typename vector<Node<T>*>::iterator it;  // Underlying iterator for the vector.

    public:
        iterator(typename vector<Node<T>*>::iterator iter) : it(iter) {}  // Constructor

        iterator& operator++() {
            ++it;  // Increment the iterator.
            return *this;
        }

        bool operator!=(const iterator& other) const {
            return it != other.it;  // Compare two iterators for inequality.
        }

        Node<T>& operator*() const {
            return **it;  // Dereference the iterator to access the node.
        }

        Node<T>* operator->() const {
            return *it;  // Access the node pointer.
        }
    };

    iterator begin_pre_order() {
        if (K != 2){return begin_dfs_scan();}
        pre_order_nodes.clear();  // Clear any existing nodes in the traversal.
        pre_order_helper(root, pre_order_nodes);  // Perform pre-order traversal.
        return iterator(pre_order_nodes.begin());
    }

    iterator end_pre_order() {
        if (K != 2){return end_dfs_scan();}
        return iterator(pre_order_nodes.end());  // Return the end of the traversal.
    }

    iterator begin_post_order() {
        if (K != 2){return begin_dfs_scan();}
        post_order_nodes.clear();  // Clear any existing nodes in the traversal.
        post_order_helper(root, post_order_nodes);  // Perform post-order traversal.
        return iterator(post_order_nodes.begin());
    }

    iterator end_post_order() {
        if (K != 2){return end_dfs_scan();}
        return iterator(post_order_nodes.end());  // Return the end of the traversal.
    }

    iterator begin_in_order() {
        if (K != 2){return begin_dfs_scan();}
        in_order_nodes.clear();  // Clear any existing nodes in the traversal.
        in_order_helper(root, in_order_nodes);  // Perform in-order traversal.
        return iterator(in_order_nodes.begin());
    }

    iterator end_in_order() {
        if (K != 2){return end_dfs_scan();}
        return iterator(in_order_nodes.end());  // Return the end of the traversal.
    }

    iterator begin_bfs_scan() {
        bfs_nodes.clear();  // Clear any existing nodes in the traversal.
        bfs_helper(root, bfs_nodes);  // Perform BFS traversal.
        return iterator(bfs_nodes.begin());
    }

    iterator end_bfs_scan() {
        return iterator(bfs_nodes.end());  // Return the end of the traversal.
    }

    iterator begin_dfs_scan() {
        dfs_nodes.clear();  // Clear any existing nodes in the traversal.
        dfs_helper(root, dfs_nodes);  // Perform DFS traversal.
        return iterator(dfs_nodes.begin());
    }

    iterator end_dfs_scan() {
        return iterator(dfs_nodes.end());  // Return the end of the traversal.
    }

    iterator begin_heap() {
        heap_nodes.clear();  // Clear any existing nodes in the traversal.
        heap_helper(root, heap_nodes);  // Perform heap traversal.
        return iterator(heap_nodes.begin());
    }

    iterator end_heap() {
        return iterator(heap_nodes.end());  // Return the end of the traversal.
    }

    iterator begin() { return begin_bfs_scan(); }  // Default traversal is BFS.
    iterator end() { return end_bfs_scan(); }

    friend ostream &operator<<(ostream &os, Tree<T, K> &tree) {
        Node<T> *root = tree.get_root();

        if (root == nullptr) {
            os << "Empty Tree" << endl;  // If the tree is empty, print a message.
            return os;
        }

        os << "Starting The GUI..." << endl;  // Message indicating GUI launch.

        sf::Font font;
        if (!font.loadFromFile("arial.ttf")) {
            cerr << "Failed to load font file 'arial.ttf'" << endl;  // Error if font file is not found.
            return os;
        }

        sf::RenderWindow window(sf::VideoMode(750, 650), "EX2");  // Create the SFML window.
        window.setVerticalSyncEnabled(true);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();  // Close the window on event.
            }

            window.clear(sf::Color::White);
            tree.drawTree(window, font);  // Draw the tree in the window.
            window.display();
        }

        return os;
    }

    void drawTree(sf::RenderWindow &window, sf::Font &font) {
        if (this->root == nullptr) return;  // If the tree is empty, do nothing.

        map<Node<T>*, sf::Vector2f> positions;  // Map to store positions of nodes.
        float start_x = window.getSize().x / 2;
        float start_y = NODE_RADIUS * 2;
        calculate_positions(this->root, positions, start_x, start_y, window.getSize().x / 4);

        for (auto &entry : positions) {  // Draw all nodes.
            draw_node(window, entry.first, entry.second, font, positions);
        }
    }

    void calculate_positions(Node<T> *node, map<Node<T>*, sf::Vector2f> &positions, float x, float y, float horizontal_spacing) {
        if (node == nullptr) return;  // Base case: if the current node is null, return.

        positions[node] = sf::Vector2f(x, y);  // Store the position of the current node.
        float child_x = x - ((node->get_children().size() - 1) * horizontal_spacing / 2);
        float child_y = y + NODE_RADIUS * 3;

        for (auto child : node->get_children()) {  // Recursively calculate positions for all children.
            calculate_positions(child, positions, child_x, child_y, horizontal_spacing / 2);
            child_x += horizontal_spacing;
        }
    }

    void draw_node(sf::RenderWindow &window, Node<T> *node, sf::Vector2f position, sf::Font &font, const map<Node<T>*, sf::Vector2f> &positions) {
        sf::CircleShape circle(NODE_RADIUS);
        circle.setFillColor(sf::Color(48, 155, 141));  // Set the color of the node.
        circle.setOrigin(NODE_RADIUS, NODE_RADIUS);
        circle.setPosition(position);

        sf::Text text;
        text.setFont(font);
        if constexpr (is_same<T, string>::value) {
            text.setString(node->get_value());  // If the value is a string, set it directly.
        } else {
            ostringstream oss;
            oss << fixed << setprecision(1) << node->get_value();  // Format the value for display.
            text.setString(oss.str());
        }
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::Black);  // Set the text color to black.
        text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
        text.setPosition(position);

        window.draw(circle);  // Draw the node circle.
        window.draw(text);  // Draw the node value.

        for (auto child : node->get_children()) {  // Draw lines to all children.
            sf::Vertex line[] = {
                sf::Vertex(position),
                sf::Vertex(positions.at(child))
            };
            window.draw(line, 2, sf::Lines);
        }
    }
};

#endif // TREE_HPP

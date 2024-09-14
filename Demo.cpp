/**
 * Demo app for Ex4
 */
#include <iostream>

#include "complex.hpp"
#include "node.hpp"
#include "tree.hpp"

using namespace std;

int main(){

    Node<double> root_node = Node(1.1);
    Tree<double> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    Node<double> n1 = Node(1.2);
    Node<double> n2 = Node(1.3);
    Node<double> n3 = Node(1.4);
    Node<double> n4 = Node(1.5);
    Node<double> n5 = Node(1.6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    // The tree should look like:
    /**
     *       root = 1.1
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.6
     */

    cout << "Pre-Order Traversal:" << endl;
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
    {
        cout << node->get_value() << ", ";
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    cout<<""<<endl;

    cout << "Post-Order Traversal:" << endl;
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
    {
        cout << node->get_value() << ", ";
    } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1
    cout<<""<<endl;

    cout << "In-Order Traversal:" << endl;
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
    {
        cout << node->get_value() << ", ";
    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3
    cout<<""<<endl;

    cout << "BFS Traversal:" << endl;
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
    {
        cout << node->get_value() << ", ";
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout<<""<<endl;

    cout << "DFS Traversal:" << endl;
    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
        cout << node->get_value() << ", ";;
    }
    cout<<""<<endl;

    cout << "Heap Traversal:" << endl;
    for (auto node = tree.begin_heap(); node != tree.end_heap(); ++node) {
        cout << node->get_value() << ", ";
    }
    cout<<""<<endl;

    for (auto node : tree){
        cout << node.get_value() << ", ";
    } // same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout<<""<<endl;




    Complex cRoot(1,1);
    Complex c1(2,2);
    Complex c2(3,3);
    Complex c3(4,4);
    Complex c4(5,5);
    Complex c5(6,6);
    Complex c6(7,7);

    Node<Complex> c_root = Node(cRoot);
    Node<Complex> cNode1 = Node(c1);
    Node<Complex> cNode2 = Node(c2);
    Node<Complex> cNode3 = Node(c3);
    Node<Complex> cNode4 = Node(c4);
    Node<Complex> cNode5 = Node(c5);
    Node<Complex> cNode6 = Node(c6);
    Tree<Complex> cTree;

    cTree.add_root(c_root);
    cTree.add_sub_node(c_root, cNode1);
    cTree.add_sub_node(c_root, cNode2);
    cTree.add_sub_node(cNode1, cNode3);
    cTree.add_sub_node(cNode1, cNode4);
    cTree.add_sub_node(cNode2, cNode5);
    cTree.add_sub_node(cNode2, cNode6);



    // The tree should look like:
    /**
     *           root = 1+1i
     *          /       \
     *        2+2i      3+3i
     *        /  \      /  \
     *     4+4i  5+5i 6+6i  7+7i
     */
    cout<<""<<endl;
    cout<<""<<endl;

    cout<< "         COMPLEX        "<<endl;
    cout << "Pre-Order Traversal:" << endl;
    for (auto node = cTree.begin_pre_order(); node != cTree.end_pre_order(); ++node){
        cout << node->get_value()<< ", ";
    } // prints: 1+1i, 2+2i, 4+4i, 5+5i, 3+3i, 6+6i, 7+7i
    cout<<""<<endl;

    cout << "Post-Order Traversal:" << endl;
    for (auto node = cTree.begin_post_order(); node != cTree.end_post_order(); ++node)
    {
        cout << node->get_value() << ", ";
    } // prints: 4+4i, 5+5i, 2+2i, 6+6i, 7+7i, 3+3i, 1+1i
    cout<<""<<endl;

    cout << "In-Order Traversal:" << endl;
    for (auto node = cTree.begin_in_order(); node != cTree.end_in_order(); ++node)
    {
        cout << node->get_value() << ", ";
    } // prints: 4+4i, 2+2i, 5+5i, 1+1i, 6+6i, 3+3i, 7+7i
    cout<<""<<endl;

    cout << "BFS Traversal:" << endl;
    for (auto node = cTree.begin_bfs_scan(); node != cTree.end_bfs_scan(); ++node) {
        cout << node->get_value() << ", ";
    } // prints: 1+1i, 2+2i, 3+3i, 4+4i, 5+5i, 6+6i, 7+7i
    cout<<""<<endl;

    cout << "DFS Traversal:" << endl;
    for (auto node = cTree.begin_dfs_scan(); node != cTree.end_dfs_scan(); ++node) {
        cout << node->get_value() << ", ";
    } // prints: 1+1i, 2+2i, 4+4i, 5+5i, 3+3i, 6+6i, 7+7i
    cout<<""<<endl;



    for (auto node : cTree){
        cout << node.get_value() << ", ";
    } // same as BFS: 1+1i, 2+2i, 3+3i, 4+4i, 5+5i, 6+6i, 7+7i
    cout<<""<<endl;

    Tree<double,3> three_ary_tree; // 3-ary tree.
    three_ary_tree.add_root(root_node);
    three_ary_tree.add_sub_node(root_node, n1);
    three_ary_tree.add_sub_node(root_node, n2);
    three_ary_tree.add_sub_node(root_node, n3);
    three_ary_tree.add_sub_node(n1, n4);
    three_ary_tree.add_sub_node(n2, n5);

     // The tree should look like:
    /**
     *       root = 1.1
     *     /      |     \
     *    1.2    1.3    1.4
     *   /        |
     *  1.5      1.6
     */

    // Should print the graph using GUI.
    cout << tree;
    cout << cTree;
    cout << three_ary_tree;

}
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "node.hpp"
#include "tree.hpp"

TEST_CASE("Test Tree Construction and Root Addition") {
    Tree<int> tree;
    CHECK(tree.get_root() == nullptr);

    Node<int> root_node(10);
    tree.add_root(root_node);
    CHECK(tree.get_root()->get_value() == 10);
}

TEST_CASE("Test Add Sub Node") {
    Tree<int> tree;
    Node<int> root_node(10);
    tree.add_root(root_node);

    Node<int> child_node1(20);
    Node<int> child_node2(30);

    tree.add_sub_node(root_node, child_node1);
    tree.add_sub_node(root_node, child_node2);

    auto root = tree.get_root();
    CHECK(root->get_children().size() == 2);
    CHECK(root->get_children()[0]->get_value() == 20);
    CHECK(root->get_children()[1]->get_value() == 30);
}

TEST_CASE("Test Find Node") {
    Tree<int> tree;
    Node<int> root_node(10);
    tree.add_root(root_node);

    Node<int> child_node(20);
    tree.add_sub_node(root_node, child_node);

    auto found_node = tree.find_node(tree.get_root(), 20);
    CHECK(found_node != nullptr);
    CHECK(found_node->get_value() == 20);

    auto not_found_node = tree.find_node(tree.get_root(), 30);
    CHECK(not_found_node == nullptr);
}

TEST_CASE("Test Pre-Order Traversal") {
    Tree<int> tree;
    Node<int> root_node(1);
    tree.add_root(root_node);

    Node<int> n1(2), n2(3), n3(4), n4(5);
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);

    vector<int> expected_values = {1, 2, 4, 5, 3};
    size_t index = 0;

    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
        CHECK((*it).get_value() == expected_values[index]);
        index++;
    }
    CHECK(index == expected_values.size());
}

TEST_CASE("Test Post-Order Traversal") {
    Tree<int> tree;
    Node<int> root_node(1);
    tree.add_root(root_node);

    Node<int> n1(2), n2(3), n3(4), n4(5);
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);

    vector<int> expected_values = {4, 5, 2, 3, 1};
    size_t index = 0;

    for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it) {
        CHECK((*it).get_value() == expected_values[index]);
        index++;
    }
    CHECK(index == expected_values.size());
}

TEST_CASE("Test In-Order Traversal") {
    Tree<int> tree;
    Node<int> root_node(1);
    tree.add_root(root_node);

    Node<int> n1(2), n2(3), n3(4), n4(5);
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);

    vector<int> expected_values = {4, 2, 5, 1, 3};
    size_t index = 0;

    for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it) {
        CHECK((*it).get_value() == expected_values[index]);
        index++;
    }
    CHECK(index == expected_values.size());
}

TEST_CASE("Test BFS Traversal") {
    Tree<int> tree;
    Node<int> root_node(1);
    tree.add_root(root_node);

    Node<int> n1(2), n2(3), n3(4), n4(5);
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);

    vector<int> expected_values = {1, 2, 3, 4, 5};
    size_t index = 0;

    for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
        CHECK((*it).get_value() == expected_values[index]);
        index++;
    }
    CHECK(index == expected_values.size());
}

TEST_CASE("Test DFS Traversal") {
    Tree<int> tree;
    Node<int> root_node(1);
    tree.add_root(root_node);

    Node<int> n1(2), n2(3), n3(4), n4(5);
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);

    vector<int> expected_values = {1, 2, 4, 5, 3};
    size_t index = 0;

    for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) {
        CHECK((*it).get_value() == expected_values[index]);
        index++;
    }
    CHECK(index == expected_values.size());
}

TEST_CASE("Test Heap Traversal") {
    Tree<int> tree;
    Node<int> root_node(3);
    tree.add_root(root_node);

    Node<int> n1(1), n2(4), n3(2);
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);

    vector<int> expected_values = {4, 3, 2, 1}; // As a max-heap
    size_t index = 0;

    for (auto it = tree.begin_heap(); it != tree.end_heap(); ++it) {
        CHECK((*it).get_value() == expected_values[index]);
        index++;
    }
    CHECK(index == expected_values.size());
}

TEST_CASE("Test 3-ary Tree Traversals (Pre-Order, Post-Order, In-Order should default to DFS)") {
    Tree<int, 3> tree; // 3-ary tree.
    Node<int> root_node(1);
    tree.add_root(root_node);

    Node<int> n1(2), n2(3), n3(4), n4(5), n5(6), n6(7), n7(8), n8(9);

    // Adding children to the root node
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(root_node, n3);

    // Adding children to the first child of the root
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n1, n5);
    tree.add_sub_node(n1, n6);

    // Adding children to the second child of the root
    tree.add_sub_node(n2, n7);
    tree.add_sub_node(n2, n8);

    /*
     * The tree structure is as follows:
     *          1
     *       /  |  \
     *      2   3   4
     *    / | \  |\
     *   5  6  7 8 9
     */

    SUBCASE("Pre-Order Traversal of 3-ary Tree defaults to DFS") {
        vector<int> expected_values = {1, 2, 5, 6, 7, 3, 8, 9, 4};
        size_t index = 0;
        for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
            CHECK((*it).get_value() == expected_values[index]);
            index++;
        }
        CHECK(index == expected_values.size());
    }

    SUBCASE("Post-Order Traversal of 3-ary Tree defaults to DFS") {
        vector<int> expected_values = {1, 2, 5, 6, 7, 3, 8, 9, 4};
        size_t index = 0;
        for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it) {
            CHECK((*it).get_value() == expected_values[index]);
            index++;
        }
        CHECK(index == expected_values.size());
    }

    SUBCASE("In-Order Traversal of 3-ary Tree defaults to DFS") {
        vector<int> expected_values = {1, 2, 5, 6, 7, 3, 8, 9, 4};
        size_t index = 0;
        for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it) {
            CHECK((*it).get_value() == expected_values[index]);
            index++;
        }
        CHECK(index == expected_values.size());
    }

    SUBCASE("BFS Traversal of 3-ary Tree") {
        vector<int> expected_values = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        size_t index = 0;
        for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
            CHECK((*it).get_value() == expected_values[index]);
            index++;
        }
        CHECK(index == expected_values.size());
    }

    SUBCASE("DFS Traversal of 3-ary Tree") {
        vector<int> expected_values = {1, 2, 5, 6, 7, 3, 8, 9, 4};
        size_t index = 0;
        for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) {
            CHECK((*it).get_value() == expected_values[index]);
            index++;
        }
        CHECK(index == expected_values.size());
    }

    SUBCASE("Heap Traversal of 3-ary Tree") {
        vector<int> expected_values = {9, 8, 7, 6, 5, 4, 3, 2, 1}; // As a max-heap
        size_t index = 0;
        for (auto it = tree.begin_heap(); it != tree.end_heap(); ++it) {
            CHECK((*it).get_value() == expected_values[index]);
            index++;
        }
        CHECK(index == expected_values.size());
    }
}

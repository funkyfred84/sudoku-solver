#ifdef STAND_ALONE
#   define BOOST_TEST_MODULE sudoku_test
#endif

#include <boost/test/unit_test.hpp>
#include "../src/sudoku/backtrackingtree.h"
#include "../src/sudoku/sudoku.h"
#include <array>
#include <stdint.h>
#include <memory>

BOOST_AUTO_TEST_SUITE(backtrackingtree_test)

BOOST_AUTO_TEST_CASE(create) {
    Sudoku b;
    TreeElement<Sudoku> root(b);
}

BOOST_AUTO_TEST_CASE(value) {
    Sudoku a;
    TreeElement<Sudoku> root(a);
    Sudoku t = root.value();
    BOOST_CHECK_EQUAL(a == t, true);
    std::array<uint8_t, 81> field;
    for (size_t i = 0; i < 81; ++i) {
        field[i] = i;
    }
    Sudoku b(field);
    TreeElement<Sudoku> child(b);
}

BOOST_AUTO_TEST_CASE(setparent) {
    std::shared_ptr<TreeElement<Sudoku>> root = std::make_shared<TreeElement<Sudoku>>(TreeElement<Sudoku>(Sudoku()));
    std::shared_ptr<TreeElement<Sudoku>> child = std::make_shared<TreeElement<Sudoku>>(TreeElement<Sudoku>(Sudoku()));
    child->parent(root);
}

BOOST_AUTO_TEST_CASE(getparent) {
    std::shared_ptr<TreeElement<Sudoku>> root = std::make_shared<TreeElement<Sudoku>>(TreeElement<Sudoku>(Sudoku()));
    std::shared_ptr<TreeElement<Sudoku>> child = std::make_shared<TreeElement<Sudoku>>(TreeElement<Sudoku>(Sudoku()));
    child->parent(root);
    std::weak_ptr<TreeElement<Sudoku>> parent = child->parent();
    std::shared_ptr<TreeElement<Sudoku>> actualRoot = parent.lock();
    BOOST_CHECK_EQUAL(actualRoot->value() == root->value(), true);
}

BOOST_AUTO_TEST_CASE(addchild) {
    std::shared_ptr<TreeElement<Sudoku>> root = std::make_shared<TreeElement<Sudoku>>(TreeElement<Sudoku>(Sudoku()));
    std::shared_ptr<TreeElement<Sudoku>> child = std::make_shared<TreeElement<Sudoku>>(TreeElement<Sudoku>(Sudoku()));
    root->add_child(child);
}

BOOST_AUTO_TEST_CASE(child) {
    std::shared_ptr<TreeElement<Sudoku>> root = std::make_shared<TreeElement<Sudoku>>(TreeElement<Sudoku>(Sudoku()));
    std::shared_ptr<TreeElement<Sudoku>> child = std::make_shared<TreeElement<Sudoku>>(TreeElement<Sudoku>(Sudoku()));
    root->add_child(child);
    BOOST_CHECK_EQUAL((*(root->child(0))).value() == child->value(), true);
}


BOOST_AUTO_TEST_CASE(backtrackingtree) {
    std::array<uint8_t, 81> field;
    for (size_t i = 0; i < 81; ++i) {
        field[i] = i;
    }
    Sudoku b(field);
    BacktrackingTree<Sudoku> tree(b);
    Sudoku t = tree.root()->value();
    BOOST_CHECK_EQUAL(t == b, true);
}


BOOST_AUTO_TEST_CASE(add) {
    std::array<uint8_t, 81> field;
    for (size_t i = 0; i < 81; ++i) {
        field[i] = i;
    }
    Sudoku b(field);
    BacktrackingTree<Sudoku> tree(b);

    std::array<uint8_t, 81> field2;
    for (size_t i = 0; i < 81; ++i) {
        field2[i] = i;
    }
    Sudoku c(field2);
    tree.add(c, tree.root());
    Sudoku t = tree.root()->child(0)->value();
    BOOST_CHECK_EQUAL(t == c, true);
}

BOOST_AUTO_TEST_SUITE_END()

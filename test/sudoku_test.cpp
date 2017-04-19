#ifdef STAND_ALONE
#   define BOOST_TEST_MODULE sudoku_test
#endif

#include <boost/test/unit_test.hpp>

#include "../src/sudoku/sudoku.h"
#include <array>
#include <stdint.h>
#include <vector>
#include <algorithm>
#include <iostream>

BOOST_AUTO_TEST_SUITE(sudoku_test)

BOOST_AUTO_TEST_CASE(create)
{
    Sudoku u;
    std::array<uint8_t, 81> field;

    for (uint8_t i = 0; i < field.size(); ++i) {
        BOOST_CHECK_EQUAL(u.field(Index(i / 9, i % 9)), 0);
    }
    for (uint8_t i = 0; i < field.size(); ++i) {
        field[i] = i;
    }
    Sudoku b{field};
    for (uint8_t i = 0; i < field.size(); ++i) {
        BOOST_CHECK_EQUAL(field[i], b.field(Index(i / 9, i % 9)));
    }

    for (uint8_t i = 0; i < field.size(); ++i) {
        field[i] = i + 82;
        b.field(Index(i / 9, i % 9), field[i]);
        BOOST_CHECK_EQUAL(field[i], b.field(Index(i / 9, i % 9)));
    }

}


BOOST_AUTO_TEST_CASE(asign) {
    std::array<uint8_t, 81> field;
    Sudoku b;
    for (uint8_t i = 0; i < field.size(); ++i) {
        field[i] = i + 82;
        b.field(Index(i / 9, i % 9), field[i]);
        BOOST_CHECK_EQUAL(field[i], b.field(Index(i / 9, i % 9)));
    }
}

BOOST_AUTO_TEST_CASE(next) {
    Sudoku b;
    Index i = b.next();
    BOOST_CHECK_EQUAL(i.row(), 0);
    BOOST_CHECK_EQUAL(i.column(),0);
    b.field(i, 1);
    i = b.next();
    BOOST_CHECK_EQUAL(i.row(), 0);
    BOOST_CHECK_EQUAL(i.column(), 1);
    for (size_t j = 0; j < 81; ++j) {
        b.field(Index(j / 9, j % 9), j + 1);
    }
    i = b.next();
    BOOST_CHECK_EQUAL(i.row(), -1);
    BOOST_CHECK_EQUAL(i.column(), -1);
}


BOOST_AUTO_TEST_CASE(possibilities) {
    Sudoku b;

    b.field(Index(0, 0), 1);

    const Index i(0, 8);
    std::vector<uint8_t> pos = b.possibilities(i);

    BOOST_CHECK_EQUAL(pos.size(), 8);

    BOOST_CHECK_EQUAL(std::find(pos.begin(), pos.end(), 1) == pos.end(), true);

    for ( uint8_t a = 2; a < 9; ++a) {
        BOOST_CHECK_EQUAL(std::find(pos.begin(), pos.end(), a) != pos.end(), true);
    }

    b.field(Index(0, 1), 2);
    pos = b.possibilities(i);
    BOOST_CHECK_EQUAL(pos.size(), 7);
    BOOST_CHECK_EQUAL(std::find(pos.begin(), pos.end(), 1) == pos.end(), true);
    BOOST_CHECK_EQUAL(std::find(pos.begin(), pos.end(), 2) == pos.end(), true);
    for ( uint8_t a = 3; a < 9; ++a) {
        BOOST_CHECK_EQUAL(std::find(pos.begin(), pos.end(), a) != pos.end(), true);
    }

    b.field(Index(1, 8), 3);
    pos = b.possibilities(i);
    BOOST_CHECK_EQUAL(pos.size(), 6);
    BOOST_CHECK_EQUAL(std::find(pos.begin(), pos.end(), 1) == pos.end(), true);
    BOOST_CHECK_EQUAL(std::find(pos.begin(), pos.end(), 2) ==  pos.end(), true);
    BOOST_CHECK_EQUAL(std::find(pos.begin(), pos.end(), 3) ==  pos.end(), true);
    for ( uint8_t a = 4; a < 9; ++a) {
        BOOST_CHECK_EQUAL(std::find(pos.begin(), pos.end(), a) != pos.end(), true);
    }

    b.field(Index(1, 7), 4);
    pos = b.possibilities(i);
    BOOST_CHECK_EQUAL(pos.size(), 5);
    BOOST_CHECK_EQUAL(std::find(pos.begin(), pos.end(), 1) == pos.end(), true);
    BOOST_CHECK_EQUAL(std::find(pos.begin(), pos.end(), 2) == pos.end(), true);
    BOOST_CHECK_EQUAL(std::find(pos.begin(), pos.end(), 3) == pos.end(), true);
    BOOST_CHECK_EQUAL(std::find(pos.begin(), pos.end(), 4) == pos.end(), true);

    for ( uint8_t a = 5; a < 9; ++a) {
        BOOST_CHECK_EQUAL(std::find(pos.begin(), pos.end(), a) != pos.end(), true);
    }
    for (size_t t = 2; t <= 6; ++t) {
        b.field(Index(0, t), t + 3);
    }
    b.field(Index(0, 3), 6);
    b.field(Index(0, 4), 7);
    b.field(Index(0, 5), 8);
    b.field(Index(0, 6), 9);
    pos = b.possibilities(i);
    BOOST_CHECK_EQUAL(pos.empty(), true);

}

BOOST_AUTO_TEST_SUITE_END()

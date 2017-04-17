#define BOOST_TEST_MAIN
#include <boost/test/included/unit_test.hpp>
#include "../src/sudoku.h"
#include <array>
#include <stdint.h>
#include <vector>
#include <algorithm>
#include <iostream>

BOOST_AUTO_TEST_SUITE(sudoku)

BOOST_AUTO_TEST_CASE(create) {
    Sudoku u;
    std::array<uint8_t, 81> field;
    Index index;
    for (uint8_t i = 0; i < field.size(); ++i) {
        index.row = i / 9;
        index.column = i % 9;
        BOOST_CHECK(0 == u(index));
    }
    for (uint8_t i = 0; i < field.size(); ++i) {
        field[i] = i;
    }
    Sudoku b{field};
    for (uint8_t i = 0; i < field.size(); ++i) {
        index.row = i / 9;
        index.column = i % 9;
        BOOST_CHECK(field[i] == b(index));
    }

    for (uint8_t i = 0; i < field.size(); ++i) {
        field[i] = i + 82;
        index.row = i / 9;
        index.column = i % 9;
        b(index) = field[i];
        BOOST_CHECK(field[i] == b(index));
    }

}

BOOST_AUTO_TEST_CASE(asign) {
    std::array<uint8_t, 81> field;
    Sudoku b;
    Index index;
    for (uint8_t i = 0; i < field.size(); ++i) {
        field[i] = i + 82;
        index.row = i / 9;
        index.column = i % 9;
        b(index) = field[i];
        BOOST_CHECK(field[i] == b(index));
    }
}

BOOST_AUTO_TEST_CASE(next) {
    Sudoku b;
    Index i = b.next();
    BOOST_CHECK(i.row == 0);
    BOOST_CHECK(i.column == 0);
    b(i) = 1;
    i = b.next();
    BOOST_CHECK(i.row == 0);
    BOOST_CHECK(i.column == 1);
    for (size_t j = 0; j < 81; ++j) {
        i.row = j / 9;
        i.column = j % 9;
        b(i) = j + 1;
    }
    i = b.next();
    BOOST_CHECK(i.row == -1);
    BOOST_CHECK(i.column == -1);
}


BOOST_AUTO_TEST_CASE(possibilities) {
    Sudoku b;
    Index index;
    index.row = 0;
    index.column = 0;
    b(index) = 1;
    Index i;
    i.row = 0;
    i.column = 8;
    std::vector<uint8_t> pos = b.possibilities(i);
    BOOST_CHECK(pos.size() == 8);
    BOOST_CHECK(std::find(pos.begin(), pos.end(), 1) == pos.end());
    for ( uint8_t a = 2; a < 9; ++a) {
        BOOST_CHECK(std::find(pos.begin(), pos.end(), a) != pos.end());
    }
    index.column = 1;
    b(index) = 2;
    pos = b.possibilities(i);
    BOOST_CHECK(pos.size() == 7);
    BOOST_CHECK(std::find(pos.begin(), pos.end(), 1) == pos.end());
    BOOST_CHECK(std::find(pos.begin(), pos.end(), 2) == pos.end());
    for ( uint8_t a = 3; a < 9; ++a) {
        BOOST_CHECK(std::find(pos.begin(), pos.end(), a) != pos.end());
    }
    index.row = 1;
    index.column = 8;
    b(index) = 3;
    pos = b.possibilities(i);
    BOOST_CHECK(pos.size() == 6);
    BOOST_CHECK(std::find(pos.begin(), pos.end(), 1) == pos.end());
    BOOST_CHECK(std::find(pos.begin(), pos.end(), 2) == pos.end());
    BOOST_CHECK(std::find(pos.begin(), pos.end(), 3) == pos.end());
    for ( uint8_t a = 4; a < 9; ++a) {
        BOOST_CHECK(std::find(pos.begin(), pos.end(), a) != pos.end());
    }
    index.column = 7;
    b(index) = 4;
    pos = b.possibilities(i);
    BOOST_CHECK(pos.size() == 5);
    BOOST_CHECK(std::find(pos.begin(), pos.end(), 1) == pos.end());
    BOOST_CHECK(std::find(pos.begin(), pos.end(), 2) == pos.end());
    BOOST_CHECK(std::find(pos.begin(), pos.end(), 3) == pos.end());
    BOOST_CHECK(std::find(pos.begin(), pos.end(), 4) == pos.end());

    for ( uint8_t a = 5; a < 9; ++a) {
        BOOST_CHECK(std::find(pos.begin(), pos.end(), a) != pos.end());
    }
    index.column = 2;
    b(index) = 5;
    index.column++;
    b(index) = 6;
    index.column++;
    b(index) = 7;
    index.column++;
    b(index) = 8;
    index.column++;
    b(index) = 9;
    pos = b.possibilities(i);
    BOOST_CHECK(pos.empty());
}

BOOST_AUTO_TEST_SUITE_END()

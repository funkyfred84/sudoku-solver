#include "sudoku.h"
#include <algorithm>
#include <iostream>

Index::Index(const size_t row, const size_t column) : _row(row), _column(column){}

size_t& Index::row() {
    return _row;
}

size_t& Index::column() {
    return _column;
}

Sudoku::Sudoku() {
    for (size_t i = 0; i < _fields.size(); ++i) {
        _fields[i] = 0;
    }
}

Sudoku::Sudoku(std::array<uint8_t, 81> fields) : _fields(fields) {
}

uint8_t& Sudoku::operator()(Index index) {
    return _fields[index.row() * 9 + index.column()];
}

Index Sudoku::next() {
    Index ret;
    for (size_t i = 0; i < _fields.size(); ++i) {
        if (0 == _fields[i]) {
            ret.row() = i / 9;
            ret.column() = i % 9;
            return ret;
        }
    }
    ret.row() = -1;
    ret.column() = -1;
    return ret;
}

std::vector<uint8_t> Sudoku::possibilities(Index index) {
    std::vector<uint8_t> ret{1,2,3,4,5,6,7,8,9};
    for(size_t row = 0; row < index.row; ++row) {

        std::vector<uint8_t>::iterator elem = std::find(ret.begin(), ret.end(), operator ()(row, index.column()));
        if (elem != ret.end()) {
            ret.erase(elem);
        }
    }

    for(size_t row = index.row + 1; row < 9; ++row) {
        std::vector<uint8_t>::iterator elem = std::find(ret.begin(), ret.end(), operator ()(row, index.column()));
        if (elem != ret.end()) {
            ret.erase(elem);
        }
    }

    for(size_t column = 0; column < index.column; ++column) {
        std::vector<uint8_t>::iterator elem = std::find(ret.begin(), ret.end(), operator ()(index.row, column));
        if (elem != ret.end()) {
            ret.erase(elem);
        }
    }

    for(size_t column = index.column + 1; column < 9; ++column) {
        std::vector<uint8_t>::iterator elem = std::find(ret.begin(), ret.end(), operator ()(index.row, column));
        if (elem != ret.end()) {
            ret.erase(elem);
        }
    }


    size_t initial_row = index.row - (index.row % 3);
    size_t initial_column = index.column - (index.column % 3);
    for(size_t row = 0; row < 3; ++row) {
        for(size_t column = 0; column < 3; ++column) {
            if (!((index.row == (initial_row + row)) && (index.column == (initial_column + column)))) {
                std::vector<uint8_t>::iterator elem = std::find(ret.begin(), ret.end(), operator ()(initial_row + row, initial_column + column));
                if (elem != ret.end()) {
                    ret.erase(elem);
                }
            }
        }
    }
    return ret;
}

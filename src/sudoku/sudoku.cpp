#include "sudoku.h"
#include <algorithm>
#include <iostream>

Index::Index(const size_t row, const size_t column) : _row(row), _column(column){}

size_t Index::row() const {
    return _row;
}

size_t Index::column() const {
    return _column;
}

Sudoku::Sudoku() {
    for (size_t i = 0; i < _fields.size(); ++i) {
        _fields[i] = 0;
    }
}

Sudoku::Sudoku(const std::array<uint8_t, 81>& fields) : _fields(fields) {
}

uint8_t Sudoku::field(const Index &index) const {
    return field(index.row(), index.column());
}

uint8_t Sudoku::field(const size_t row, const size_t column) const {
    return _fields[row * 9 + column];
}

void Sudoku::field(const Index &index, const uint8_t value) {
    field(index.row(), index.column(), value);
}

void Sudoku::field(const size_t row, const size_t column, const uint8_t value) {
    _fields[row * 9 + column] = value;
}

Index Sudoku::next() {

    for (size_t i = 0; i < _fields.size(); ++i) {
        if (0 == _fields[i]) {
            return Index(i / 9, i % 9);
        }
    }
    return Index(-1, -1);
}

std::vector<uint8_t> Sudoku::possibilities(const Index& index) const {
    std::vector<uint8_t> ret{1,2,3,4,5,6,7,8,9};
    for(size_t row = 0; row < index.row(); ++row) {

        std::vector<uint8_t>::iterator elem = std::find(ret.begin(), ret.end(), field(row, index.column()));
        if (elem != ret.end()) {
            ret.erase(elem);
        }
    }

    for(size_t row = index.row() + 1; row < 9; ++row) {
        std::vector<uint8_t>::iterator elem = std::find(ret.begin(), ret.end(), field(row, index.column()));
        if (elem != ret.end()) {
            ret.erase(elem);
        }
    }

    for(size_t column = 0; column < index.column(); ++column) {
        std::vector<uint8_t>::iterator elem = std::find(ret.begin(), ret.end(), field(index.row(), column));
        if (elem != ret.end()) {
            ret.erase(elem);
        }
    }

    for(size_t column = index.column() + 1; column < 9; ++column) {
        std::vector<uint8_t>::iterator elem = std::find(ret.begin(), ret.end(), field(index.row(), column));
        if (elem != ret.end()) {
            ret.erase(elem);
        }
    }


    size_t initial_row = index.row() - (index.row() % 3);
    size_t initial_column = index.column() - (index.column() % 3);
    for(size_t row = 0; row < 3; ++row) {
        for(size_t column = 0; column < 3; ++column) {
            if (!((index.row() == (initial_row + row)) && (index.column() == (initial_column + column)))) {
                std::vector<uint8_t>::iterator elem = std::find(ret.begin(), ret.end(), field(initial_row + row, initial_column + column));
                if (elem != ret.end()) {
                    ret.erase(elem);
                }
            }
        }
    }
    return ret;
}


bool Sudoku::operator ==(const Sudoku& val) const {
    for (size_t i = 0; i < _fields.size(); ++i) {
        if (_fields[i] != val.field(i / 9, i % 9)) {
            return false;
        }
    }
    return true;
}

bool Sudoku::operator !=(const Sudoku& val) const {
    return !(*this == val);
}

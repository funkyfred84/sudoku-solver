#ifndef SUDOKU_H
#define SUDOKU_H
#include <array>
#include <stdint.h>
#include <vector>

class Index {
public:
    Index(const size_t row, const size_t column);
    size_t& row(void);
    size_t& column(void);
private:
    size_t _row;
    size_t _column;
};

class Sudoku {
public:
    Sudoku(void);
    Sudoku(std::array<uint8_t, 81> fields);
    uint8_t& operator()(Index index);
    Index next();
    std::vector<uint8_t> possibilities(Index index);
private:
    std::array<uint8_t, 81> _fields;
};

#endif // SUDOKU_H

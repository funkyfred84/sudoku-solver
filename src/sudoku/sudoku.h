#ifndef SUDOKU_H
#define SUDOKU_H
#include <array>
#include <stdint.h>
#include <vector>

class Index {
public:
    Index(const size_t row, const size_t column);
    size_t row(void) const;
    size_t column(void) const;
private:
    size_t _row;
    size_t _column;
};

class Sudoku {
public:
    Sudoku(void);
    Sudoku(const std::array<uint8_t, 81>& fields);
    uint8_t field(const Index& index) const;
    uint8_t field(const size_t row, const size_t column) const;
    void field(const size_t row, const size_t column, const uint8_t value);
    void field(const Index& index, const uint8_t value);
    Index next();
    std::vector<uint8_t> possibilities(const Index& index) const;
    bool operator==(const Sudoku& val) const;
    bool operator !=(const Sudoku& val) const;
private:
    std::array<uint8_t, 81> _fields;
};

#endif // SUDOKU_H

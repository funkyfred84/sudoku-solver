#include "solver.h"
#include <vector>
#include <stdint.h>
#include <memory>
#include <iostream>


Sudoku backtrack(std::vector<Sudoku>& stack) {
      if (stack.empty()) {
          return Sudoku();
      }
      auto element = stack.back();
      stack.pop_back();

      Index free_field = element.next();
      if (free_field.row() == -1 && free_field.column() == -1) {
          //FINISHED GIVE SUDOKU BACK
          return element;
    }
    std::vector<uint8_t> posibilities = element.possibilities(free_field);

    for (auto& val : posibilities) {
        Sudoku tmp = element;
        tmp.field(free_field, val);
        stack.push_back(tmp);
    }
    return backtrack(stack);
}


Sudoku solve(const Sudoku &sudoku) {
    std::vector<Sudoku> stack;
    stack.push_back(sudoku);
    return backtrack(stack);
}

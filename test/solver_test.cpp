#ifdef STAND_ALONE
#   define BOOST_TEST_MODULE sudoku_test
#endif

#include <boost/test/unit_test.hpp>

#include "../src/sudoku/sudoku.h"
#include <array>
#include <stdint.h>
#include "../src/sudoku/solver.h"
#include <iostream>



BOOST_AUTO_TEST_SUITE(sudoku_test)

BOOST_AUTO_TEST_CASE(solve_first)
{
    std::array<uint8_t, 81> field{4, 0, 0, 6, 0, 0, 8, 7, 0,
                                  1, 0, 0, 0, 0, 0, 4, 5, 0,
                                  0, 7, 0, 0, 8, 0, 0, 0, 3,
                                  0, 0, 9, 7, 0, 5, 3, 4, 0,
                                  0, 4, 5, 0, 3, 0, 9, 8, 0,
                                  0, 1, 6, 8, 0, 9, 7, 0, 0,
                                  5, 0, 0, 0, 6, 0, 0, 1, 0,
                                  0, 2, 4, 0, 0, 0, 0, 0, 8,
                                  0, 3, 1, 0, 0, 2, 0, 0, 7};

    Sudoku a{field};
    Sudoku b = solve(a);

    std::array<uint8_t, 81> field2{4, 5, 3, 6, 2, 1, 8, 7, 9,
                                   1, 6, 8, 9, 7, 3, 4, 5, 2,
                                   9, 7, 2, 5, 8, 4, 1, 6, 3,
                                   2, 8, 9, 7, 1, 5, 3, 4, 6,
                                   7, 4, 5, 2, 3, 6, 9, 8, 1,
                                   3, 1, 6, 8, 4, 9, 7, 2, 5,
                                   5, 9, 7, 3, 6, 8, 2, 1, 4,
                                   6, 2, 4, 1, 9, 7, 5, 3, 8,
                                   8, 3, 1, 4, 5, 2, 6, 9, 7};
    Sudoku c{field2};
    std::cout << c << std::endl;

    std::cout << b << std::endl;
    BOOST_CHECK_EQUAL(c == b, true);

}

BOOST_AUTO_TEST_SUITE_END()

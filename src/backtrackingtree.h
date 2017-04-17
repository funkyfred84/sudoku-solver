#ifndef BACKTRACKINGTREE_H
#define BACKTRACKINGTREE_H

#include <vector>
#include <memory>
#include "sudoku.h"

class TreeElement {
public:
    TreeElement(void) = default;
    TreeElement(const TreeElement& original);
    TreeElement(TreeElement&& move);
    TreeElement& operator=(const TreeElement& original);
//    TreeElement& operator=(TreeElement&& move);

//    TreeElement(TreeElement& parent, Sudoku& value);
//    TreeElement(Sudoku& value);

//    Sudoku& value(void);
//    TreeElement* parent();
//    std::vector<TreeElement>& children();

//    void add_child(TreeElement& child);
//    TreeElement* next();

private:
    std::weak_ptr<TreeElement> _parent;
    std::vector<TreeElement> _children;
    Sudoku _value;

};

class BackTrackingTree
{
public:
    BackTrackingTree();
};

#endif // BACKTRACKINGTREE_H

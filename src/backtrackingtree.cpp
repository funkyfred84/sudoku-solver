#include "backtrackingtree.h"
#include <algorithm>
#include <iostream>

TreeElement::TreeElement(const TreeElement &original) : _value(original._value) {
    std::cout << "call " << __func__ << "(const TreeElement &original)\n";
}

TreeElement::TreeElement(TreeElement&& move) {
    std::cout << "call " << __func__ << "(TreeElement &&move)\n";
    if (this != &move) {
        _parent = std::move(move._parent);
        _value = std::move(move._value);
        _children = std::move(move._children);
    }
}

TreeElement& TreeElement::operator=(const TreeElement& original) {
    std::cout << "call " << __func__ << "(const TreeElement& original)\n";
    _value = original._value;
}



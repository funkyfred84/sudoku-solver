#ifndef BACKTRACKINGTREE_H
#define BACKTRACKINGTREE_H

#include<memory>
#include<vector>
#include<iostream>

template<typename T> class TreeElement {
public:
    TreeElement(const T& value);
    T value(void) const;
    void parent(std::shared_ptr<TreeElement<T>> parent);
    std::weak_ptr<TreeElement<T>> parent(void);
    void add_child(std::shared_ptr<TreeElement<T>>& child);
    std::shared_ptr<TreeElement<T>> child(const size_t at);
    size_t count_children(void);
private:
    std::weak_ptr<TreeElement<T>> _parent;
    std::vector<std::shared_ptr<TreeElement<T>>> _children;
    T _value;
};

template<typename T> class BacktrackingTree {
public:
    BacktrackingTree(const T& value);
    void add(const T& value, std::shared_ptr<TreeElement<T>> element);
    std::shared_ptr<TreeElement<T>> root(void);
    std::shared_ptr<TreeElement<T>> next(std::shared_ptr<TreeElement<T>> element);
private:
    std::shared_ptr<TreeElement<T>> _root;
};

template<typename T> TreeElement<T>::TreeElement(const T& value) : _value(value) {}

template<typename T> T TreeElement<T>::value() const {
    return _value;
}

template<typename T> void TreeElement<T>::parent(std::shared_ptr<TreeElement<T>> parent) {
    _parent = parent;
}

template<typename T> std::weak_ptr<TreeElement<T>> TreeElement<T>::parent() {
    return _parent;
}

template<typename T> void TreeElement<T>::add_child(std::shared_ptr<TreeElement<T>>& child) {
    _children.push_back(child);
}

template<typename T> std::shared_ptr<TreeElement<T>> TreeElement<T>::child(const size_t at) {
    return _children[at];
}

template<typename T> size_t TreeElement<T>::count_children() {
    return _children.size();
}

template<typename T> BacktrackingTree<T>::BacktrackingTree(const T& value) : _root(std::make_shared<TreeElement<T>>(TreeElement<T>(value))) {}

template<typename T> void BacktrackingTree<T>::add(const T& value, std::shared_ptr<TreeElement<T>> element) {
    std::shared_ptr<TreeElement<T>> tmp = std::make_shared<TreeElement<T>>(value);
    element->add_child(tmp);
    tmp->parent(element);
}

template<typename T> std::shared_ptr<TreeElement<T>> BacktrackingTree<T>::root() {
    return _root;
}

#endif // BACKTRACKINGTREE_H

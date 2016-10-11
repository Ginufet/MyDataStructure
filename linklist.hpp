/****************************************************************************************************

Copyright(C): JIANG Yizhi

Author: JIANG Yizhi

Data: October 11, 2016

Description: Declearation and implement of class LinkList

Update:
#1 October 12, 2016
    * operator[] return value changed to _last when index out of range
    * member function insert optimized
    * member function erase optimized

****************************************************************************************************/
#pragma once

#include<string>
#include"linklistnode.hpp"

template<typename _Elem>
class LinkList {
public:
    LinkList() {
        _elemNum = 0;
        _first = nullptr;
        _last = nullptr;
    }
    ~LinkList() {
        LinkListNode<_Elem> * cur;
        while (_first != nullptr) {
            cur = _first;
            _first = _first->_next;
            delete cur;
        }
    }

    LinkListNode<_Elem> * first() { return _first; }
    LinkListNode<_Elem> * last() { return _last; }
    int size() { return _elemNum; }
    bool init(int elemNum = 0);
    void link(LinkListNode<_Elem> &elem);
    bool insert(LinkListNode<_Elem> &elem, int pos);
    LinkListNode<_Elem> *find(const LinkListNode<_Elem> &target) const;
    bool erase(LinkListNode<_Elem> * target);

    LinkListNode<_Elem> & operator[](const int pos) const;
private:
    LinkListNode<_Elem> * _first;
    LinkListNode<_Elem> * _last;
    int _elemNum;
};


template<typename _Elem>
bool LinkList<_Elem>::init(int elemNum) {
    if (elemNum < 0) {
        return false;
    }
    _elemNum = 0;
    LinkListNode<_Elem> *cur = nullptr;
    decltype(cur) pre = nullptr;
    for (int i = 0; i < elemNum; ++i) {
        cur = new LinkListNode<_Elem>;
        if (cur != nullptr) {
            if (!_first) {
                _first = cur;
                _first->_previous = nullptr;
            }
            else {
                pre->_next = cur;
                cur->_previous = pre;
            }
            _last = cur;
            cur->_next = nullptr;
            pre = cur;
            ++_elemNum;
        }
        else {
            return false;
        }
    }    
    return true;
}

template<typename _Elem>
inline void LinkList<_Elem>::link(LinkListNode<_Elem>& elem) { //Link elem to the list as the last node
    LinkListNode<_Elem> * tmp = _last;
    _last = &elem;
    tmp->_next = &elem;
    _last->_previous = tmp;
    _last->_next = nullptr;
}

template<typename _Elem>
inline bool LinkList<_Elem>::insert(LinkListNode<_Elem> & elem, int pos) { //inserte elem at position pos
    if (pos <= 0 || pos > _elemNum) {
        return false;
    }
    auto cur = new LinkListNode<_Elem>;
    if (!cur) {
        return false;
    }
    *cur = elem;
    if (pos == 1) {
        cur->_previous = nullptr;
        cur->_next = _first;
        _first->_previous = cur;
        _first = cur;
    }
    else if (pos == _elemNum) {
        cur->_next = nullptr;
        cur->_previous = _last;
        _last->_next = cur;
        _last = cur;
    }
    else {
        cur->_previous = &(*this)[pos - 2];
        cur->_next = cur->_previous->_next;
        cur->_next->_previous = cur->_previous->_next = cur;
    }
    ++_elemNum;
    return true;
}

template<typename _Elem>
LinkListNode<_Elem> * LinkList<_Elem>::find(const LinkListNode<_Elem> & target) const {
    LinkListNode<_Elem> *cur = _first;
    while (cur != nullptr) {
        if (cur->_data == target._data) {
            return cur;
        }
        cur = cur->_next;
    }
    return nullptr;
}

template<typename _Elem>
inline bool LinkList<_Elem>::erase(LinkListNode<_Elem> * target) {
    auto res = find(*target);
    if (res != nullptr) {
        if (target == _first) {
            _first = target->_next;
            _first->_previous = nullptr;
        }
        else if (target = _last) {
            _last = target->_previous;
            _last->_next = nullptr;
        }
        else {
            target->_previous->_next = target->_next;
            target->_next->_previous = target->_previous;
        }
        delete target;
        --_elemNum;
        return true;
    }
    return false;
}

template<typename _Elem>
LinkListNode<_Elem> & LinkList<_Elem>::operator[](int pos) const { // if index > size, the last one will be returned
    if (pos >= _elemNum) {
        return *_last;
    }
    LinkListNode<_Elem> * cur = _first;
    for (int i = 0; i < pos; ++i) {
        cur = cur->_next;
    }
    return *cur;
}
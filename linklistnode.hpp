/****************************************************************************************************

Copyright(C): JIANG Yizhi

Author: JIANG Yizhi

Data: October 11, 2016

Description: Declearation and implement of class LinkListNode<_Elem>

Update:
#1 October 12, 2016
    * new operator= overloaded
    * member data _data changed from private to public
    * some operators' declaration changed from const to non-const
    * operator + ++ -- and - are abandoned
    *member data _next and _previous changed from private to public
****************************************************************************************************/
#pragma once

#include<string>

template<typename _Elem>
class LinkListNode;

template<typename _Elem>
class LinkList;

template<typename _Elem>
class LinkListNode {
    friend LinkList<_Elem>;
public:
    LinkListNode() {}
    ~LinkListNode() {}

    LinkListNode<_Elem> & operator=(const LinkListNode<_Elem> &rhs) { 
        _data = rhs._data; 
        _previous = rhs._previous;
        _next = rhs._next;
        return *this;
    }
    //LinkListNode<_Elem> * operator+(const int rhs) const;
    //LinkListNode<_Elem> * operator-(const int rhs) const;
    //LinkListNode<_Elem> * operator++() { return this + 1; }
    //LinkListNode<_Elem> * operator--() { return this - 1; }
    //LinkListNode<_Elem> * operator++(int) {
    //    linklistnode<_elem> * cur = lhs;
    //    ++lhs;
    //    return cur;
    //};
    //LinkListNode<_Elem> * operator--(int) {
    //    LinkListNode<_Elem> * cur = lhs;
    //    --lhs;
    //    return cur;
    //};

    _Elem _data;
    LinkListNode<_Elem> * _previous;
    LinkListNode<_Elem> * _next;
};


//template<typename _Elem>
//inline LinkListNode<_Elem> * LinkListNode<_Elem>::operator+(const int rhs) const {
//    LinkListNode<_Elem> * end = this;
//    int step = rhs;
//    while (end != nullptr) {
//        if (step < 0) {
//            return end - (-step);
//        }
//        else if (step == 0) {
//            return end;
//        }
//        --step;
//        end = end->next;
//    }
//    return nullptr;
//}
//
//template<typename _Elem>
//inline LinkListNode<_Elem> * LinkListNode<_Elem>::operator-(const int rhs) const {
//    LinkListNode<_Elem> *end = this;
//    int step = rhs;
//    while (end != nullptr) {
//        if (rhs < 0) {
//            return end + (-step);
//        }
//        else if (rhs == 0) {
//            return end;
//        }
//        --step;
//        end = end->previous;
//    }
//    return NULL;
//}
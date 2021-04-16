//
// Created by Shlomi on 16/04/2021.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Iterator is a behavioral DP that allows to traverse elements of a collection (or a Data-Structure such as a list, a
// tree, and so on) without exposing its underlying representation.

template <typename T, typename U>
class Iterator {
private:
    U *data_ptr;
    typename vector<T>::iterator it;
public:
    Iterator(U *data) : data_ptr(data) { it = data_ptr->data_vector.begin(); }
    void getFirst() { it = data_ptr->data_vector.begin(); }
    void getNext() { ++it; }
    bool hasMore() { return (it == data_ptr->data_vector.end()); }
    typename vector<T>::iterator getCurrent() { return it; }
};

template <class T>
class Container {
private:
    vector<T> data_vector;
    friend class Iterator<T, Container>;
public:
    void add(T a) { data_vector.push_back(a); }
    Iterator<T, Container> *CreateIterator() { return new Iterator<T, Container>(this); }
};

class Data {
private:
    int data_vector;
public:
    Data(int a = 0) : data_vector(a) {}
    void setData(int d) { data_vector = d; }
    int getData() { return data_vector; }
};
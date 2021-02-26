//
// Created by kidyme on 2021/2/20.
//

#include "node.h"

#include <utility>

// 初始化静态成员变量
template<class T>
bool Node<T>::hasTeacherWriten = false;

template<class T>
vector<string> Node<T>::keys;
template<class T>
string Node<T>::getType() {
    T t;
    return t.getType();
}

template<class T>
Node<T>::Node() {
    if (hasTeacherWriten) {
        setOwnKeys();
    }
}

template<class T>
Node<T>::~Node() {}

template<class T>
int Node<T>::getSize() {
    return keys.size();
}

template<class T>
int Node<T>::getHasTeacherWriten() {
    return hasTeacherWriten;
}

template<class T>
void Node<T>::addOwnKeys(string key) {
    properties.setKey(key);
}

template<class T>
void Node<T>::write(vector<string> input) {
    properties.setValues(input);
}

template<class T>
void Node<T>::write(int index, string value) {
    properties.setValue(index, value);
}

template<class T>
void Node<T>::read() {
    if (!properties.isCompleted()) {
        cout << "未填完!" << endl;
    }
    properties.show();
}

template<class T>
void Node<T>::update(int keyIndex, string value) {
    properties.setValue(keyIndex, value);
}

template<class T>
void Node<T>::setOwnKeys() {
    properties.setKeys(keys);
}

template<class T>
void Node<T>::setId(int id) {
    this->id = id;
}


template<class T>
void Node<T>::setKey(string key) {
    keys.push_back(key);
}

template<class T>
void Node<T>::setKeys(vector<string> input) {
    keys = input;
    hasTeacherWriten = true;
}

template<class T>
vector<string> Node<T>::getKeys() {
    return keys;
}

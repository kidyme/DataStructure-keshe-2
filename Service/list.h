//
// Created by kidyme on 2021/2/20.
//

#ifndef KESHE_2_CPP_LIST_H
#define KESHE_2_CPP_LIST_H

#include "node.cpp"
#include "node.h"
#include <iostream>
using namespace std;

/*
 * 提供辅导员输入属性的接口
 * 提供学生输入属性值的接口
 * 获取到某一个节点的接口

 * 提供辅导员审核的接口
 * 提供辅导员增加属性的接口
 * 提供直接增加属性的接口
 * 提供辅导员查询所有属性名称的接口
 * 提供辅导员更新属性值的接口
 * 提供辅导员删除属性值接口

 * 提供查询第index个节点的接口
 * 提供查询每个节点信息的接口
 * 提供更新第index个节点的接口
 * 提供删除第index个节点的接口
 */
template<class Data>
class List {
public:
    List();
    ~List();
    Data *getNode(int index);
    int getIndex(string id);
    vector<string> getKeys();

    int getLength();

    void add();
    void add(Data &newNode);
    void read();
    void read(int index);
    void update(int index);
    void update(Data *node);
    void remove(int index);

    void add(vector<string> keys);
    void add(bool isAssistant);
    void read(bool isAssistant);
    void update(bool isAssistant);
    void update(vector<string> keys);
    void remove(bool isAssistant);

    void verify();


private:
    Data *head;// 头指针
};
#endif// KESHE_2_CPP_LIST_H

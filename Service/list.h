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
 * 提供辅导员输入属性、补充属性、学生输入属性值的接口
 * 提供查询第index个节点的接口
 * 提供更新第index个节点、更新属性值的接口
 * 提供删除第index个节点、删除属性值接口
 */
template<class Data>
class List {
public:
    List();
    ~List();
    void add(bool isAssistant);// 待修改：传入true时，还需判断是否辅导员已输入过属性，若输入过则为补充
    void read(int index);
    void update(int index);// 待修改：增加参数isAssistant，传入true时则为对属性的更新
    void remove(int index);// 待修改：增加参数isAssistant，传入true时则为对属性的删除

private:
    Data *head;// 头指针
};
#endif//KESHE_2_CPP_LIST_H

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
 * 提供辅导员输入属性、
 * 提供学生输入属性值的接口

 * 提供查询第index个节点的接口
 * 提供查询每个节点信息的接口
 * 提供更新第index个节点的接口
 * 提供删除第index个节点的接口
 * 提供辅导员增加属性的接口
 * 提供辅导员查询所有属性名称的接口
 * 提供辅导员更新属性值的接口
 * 提供辅导员删除属性值接口
 */
template<class Data>
class List {
public:
    List();
    ~List();
    void add();
    void read();
    void read(int index);
    void update(int index);
    void remove(int index);

    void add(bool isAssistant);
    // 待修改：还需判断是否辅导员已输入过属性，若输入过则为补充
    void read(bool isAssistant);
    void update(bool isAssistant);
    void remove(bool isAssistant);

private:
    Data *head;// 头指针
};
#endif// KESHE_2_CPP_LIST_H

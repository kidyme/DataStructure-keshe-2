//
// Created by kidyme on 2021/1/19.
//

#ifndef KESHE_2_CPP_MAP_H
#define KESHE_2_CPP_MAP_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;
/* 键值对集合
 *
 *      为键的集合赋值
 *      为值的集合赋值
 *      在键的集合中增加一个键
 *      根据键的下标，为对应的值赋值
 *      显示所有键值对
 *      判断是否填完
 */
class Map {
public:
    Map();
    ~Map();
    void setKeys(vector<string> input);
    void setKey(string key);
    void setValues(vector<string> input);
    void setValue(int index, string value);
    void show();
    bool isCompleted();

private:
    vector<string> keys;
    vector<string> values;
};
#endif//KESHE_2_CPP_MAP_H

//    string getValue(string key);
//    void setValue(string key, string value);
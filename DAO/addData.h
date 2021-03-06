//
// Created by kidyme on 2021/2/28.
//

#ifndef KESHE_2_CPP_ADDDATA_H
#define KESHE_2_CPP_ADDDATA_H
#include "../Service/list.h"
#include <fstream>

/*
 * 提供创建文件的接口
 * 增加列名的接口
 * 增加一行数据的接口
 */

template<class DataType, class Data>
class addData {
public:
    addData(DataType *dataType);
    ~addData();

    void create();
    void addColumnTitle();
    void addColumnTitle(vector<string> keys);
    void add(Data *data);

private:
    ofstream file;
    DataType *dataType;
    const string packagePath = "/Users/apple/Documents/数据结构/DataStructure-keshe-2/Data/";
    string filePath;
    const string division = "|";// 一个tab为八个空格
};


#endif//KESHE_2_CPP_ADDDATA_H

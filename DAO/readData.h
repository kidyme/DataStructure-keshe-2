//
// Created by kidyme on 2021/3/5.
//

#ifndef KESHE_2_CPP_READDATA_H
#define KESHE_2_CPP_READDATA_H

#include "../Service/list.h"
#include "../Util/split.h"
#include <fstream>
#include <string>
using namespace std;

template<class DataType, class Data>
class readData {
public:
    readData(DataType *dataType);
    ~readData();

    List<Data> getAll();
    vector<string> getKeys();
    Data getOneById(int index);
    int getLength();

private:
    ifstream file;
    List<Data> *list;

    DataType *dataType;
    const string packagePath = "/Users/apple/Documents/数据结构/DataStructure-keshe-2/Data/";
    string filePath;
    const string division = "|";// 一个tab为八个空格
};


#endif//KESHE_2_CPP_READDATA_H
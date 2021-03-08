//
// Created by kidyme on 2021/3/6.
//

#ifndef KESHE_2_CPP_UPDATEDATA_H
#define KESHE_2_CPP_UPDATEDATA_H

#include "../Service/list.h"
#include "addData.cpp"
#include "addData.h"
#include "readData.cpp"
#include "readData.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<class DataType, class Data>
class updateData {
public:
    updateData(DataType *dataType);
    ~updateData();
    void updateColumnTitle(vector<string> keys);
    void updateRow(Data &data);

private:
    List<Data> list;
    DataType *dataType;
    const string packagePath = "/Users/apple/Documents/数据结构/DataStructure-keshe-2/Data/";
    string filePath;
    readData<DataType, Data> *readData;
    addData<DataType, Data> *addData;
};


#endif//KESHE_2_CPP_UPDATEDATA_H
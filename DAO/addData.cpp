//
// Created by kidyme on 2021/2/28.
//

#include "addData.h"
#include <fstream>

template<class DataType, class Data>
addData<DataType, Data>::addData(DataType *dataType) { this->dataType = dataType; }

template<class DataType, class Data>
addData<DataType, Data>::~addData() {}

template<class DataType, class Data>
void addData<DataType, Data>::create() {
    ofstream file;

    const string filePath = packagePath + dataType->getType() + ".md";

    file.open(filePath, ios::app);

    file << "# " << dataType->getType() << endl;
    file.close();
}

template<class DataType, class Data>
void addData<DataType, Data>::addColumnTitle() {
    ofstream file;

    const string filePath = packagePath + dataType->getType() + ".md";
    const string tab = "        ";// 一个tab为八个空格

    file.open(filePath, ios::app);

    vector<string> keys = Data::getKeys();

    for (int i = 0; i < keys.size(); ++i) {
        file << tab << keys[i];
    }
    file.close();
}


template<class DataType, class Data>
void addData<DataType, Data>::add(DataType *dataType) {
    ofstream file;
    const string tab = "        ";// 一个tab为八个空格
    //        string
    //        file.open("../DataType/")
    //    file.close();
}

//
// Created by kidyme on 2021/3/6.
//

#include "updateData.h"

template<class DataType, class Data>
updateData<DataType, Data>::updateData(DataType *dataType) {
    addData = new ::addData<DataType, Data>((new DataType));
    readData = new ::readData<DataType, Data>((new DataType));
    this->dataType = dataType;
    filePath = packagePath + dataType->getType() + ".md";
    list = readData->getAll();
}

template<class DataType, class Data>
updateData<DataType, Data>::~updateData() {}

template<class DataType, class Data>
void updateData<DataType, Data>::updateColumnTitle(vector<string> keys) {
    remove(filePath.c_str());
    list.update(keys);
    addData->create();
    addData->addColumnTitle(keys);
    for (int i = 0; i < list.getLength(); ++i) {
        addData->add(list.getNode(i + 1));
    }
}

template<class DataType, class Data>
void updateData<DataType, Data>::updateRow(Data &data) {
    remove(filePath.c_str());
    addData->create();
    addData->addColumnTitle();
    list.update(&data);
    for (int i = 0; i < list.getLength(); ++i) {
        addData->add(list.getNode(i + 1));
    }
}
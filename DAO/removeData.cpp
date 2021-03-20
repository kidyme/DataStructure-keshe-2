//
// Created by kidyme on 2021/3/14.
//

#include "removeData.h"

template<class DataType, class Data>
removeData<DataType, Data>::removeData(DataType *dataType) {
    addData = new ::addData<DataType, Data>((new DataType));
    readData = new ::readData<DataType, Data>((new DataType));
    this->dataType = dataType;
    filePath = packagePath + dataType->getType() + ".md";
    list = readData->getAll();
}


template<class DataType, class Data>
removeData<DataType, Data>::~removeData() {}

template<class DataType, class Data>
void removeData<DataType, Data>::removeFile() {
    remove(filePath.c_str());
}

template<class DataType, class Data>
void removeData<DataType, Data>::removeRow(string id) {
    removeFile();
    int index = list.getIndex(id);
    list.remove(index);

    addData->create();
    addData->addColumnTitle(list.getKeys());
    for (int i = 0; i < list.getLength(); ++i) {
        addData->add(list.getNode(i + 1));
    }
}

//
// Created by kidyme on 2021/2/28.
//

#include "addData.h"

template<class DataType, class Data>
addData<DataType, Data>::addData(DataType *dataType) {
    this->dataType = dataType;

    filePath = packagePath + dataType->getType() + ".md";
}

template<class DataType, class Data>
addData<DataType, Data>::~addData() {}

template<class DataType, class Data>
void addData<DataType, Data>::create() {
    file.open(filePath, ios::app);
    file << "# " << dataType->getType() << endl;
    file.close();
}

template<class DataType, class Data>
void addData<DataType, Data>::addColumnTitle() {
    file.open(filePath, ios::app);
    vector<string> keys = Data::getKeys();

    file << division << "Id" << division;
    file << "学生Id" << division;
    file << "姓名" << division;
    for (int i = 0; i < keys.size(); ++i) {
        file << keys[i] << division;
    }
    file << endl;

    file << division << "---" << division;
    file << "---" << division;
    file << "---" << division;
    for (int i = 0; i < keys.size(); ++i) {
        file << "---" << division;
    }
    file.close();
}

template<class DataType, class Data>
void addData<DataType, Data>::addColumnTitle(vector<string> &keys) {
    file.open(filePath, ios::app);

    file << division << "Id" << division;
    file << "学生Id" << division;
    file << "姓名" << division;
    for (int i = 0; i < keys.size(); ++i) {
        file << keys[i] << division;
    }
    file << endl;

    file << division << "---" << division;
    file << "---" << division;
    file << "---" << division;
    for (int i = 0; i < keys.size(); ++i) {
        file << "---" << division;
    }
    file.close();
}


template<class DataType, class Data>
void addData<DataType, Data>::add(Data *data) {
    file.open(filePath, ios::app);
    vector<string> values = data->getValues();
    file << endl
         << division;
    file << data->getDataId() << division;
    file << data->getStudentId() << division;
    file << data->getStudentName() << division;
    for (int i = 0; i < values.size(); ++i) {
        file << values[i] << division;
    }
    file.close();
}

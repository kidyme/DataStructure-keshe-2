//
// Created by kidyme on 2021/3/5.
//

#include "readData.h"

template<class DataType, class Data>
readData<DataType, Data>::readData(DataType *dataType) {
    this->dataType = dataType;
    list = new List<Data>;
    filePath = packagePath + dataType->getType() + ".md";
    file.open(filePath, ios::in);

    string line;
    int rowIndex = 0;
    while (!file.eof()) {
        rowIndex++;
        getline(file, line);

        if (rowIndex == 2) {
            vector<string> keys = split(line, division);
            vector<string>::iterator it = keys.begin();
            keys.erase(it);
            keys.erase(it);
            keys.erase(it);
            list->add(keys);
        }
        if (rowIndex > 3) {
            Data *newData = new Data();
            vector<string> values = split(line, division);
            vector<string>::iterator it = values.begin();
            string dataId = values[0];
            values.erase(it);
            string studentId = values[0];
            values.erase(it);
            string studentName = values[0];
            values.erase(it);
            newData->setDataId(dataId);
            newData->setStudentId(studentId);
            newData->setStudentName(studentName);
            newData->write(values);

            list->add(*newData);
        }
    }
}

template<class DataType, class Data>
readData<DataType, Data>::~readData<DataType, Data>() { file.close(); }

template<class DataType, class Data>
List<Data> readData<DataType, Data>::getAll() {
    return *list;
}

template<class DataType, class Data>
vector<string> readData<DataType, Data>::getKeys() {
    return list->getKeys();
}

template<class DataType, class Data>
Data readData<DataType, Data>::getOneById(int index) {
    return *(list->getNode(index));
}

template<class DataType, class Data>
int readData<DataType, Data>::getLength() {
    return list->getLength();
}
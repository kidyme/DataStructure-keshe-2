//
// Created by kidyme on 2021/2/20.
//
#include "map.h"

Map::Map() {}

Map::~Map() {}

void Map::setKeys(vector<string> input) {
    keys = input;
    for (int i = 0; i < keys.size(); ++i) {
        values.push_back("");
    }
}

void Map::setKey(string key) {
    keys.push_back(key);
    values.push_back("");
}

void Map::setValue(int index, string value) {
    values[index] = value;
}

void Map::setValues(vector<string> input) {
    values = input;
}

void Map::show() {
    for (int i = 0; i < keys.size(); ++i) {
        cout << keys[i] << " : " << values[i] << endl;
    }
}

bool Map::isCompleted() {
    if (values.size() == 0) {
        return false;
    }
    for (int i = 0; i < values.size(); ++i) {
        if (values[i] == "") {
            return false;
        }
    }
    return true;
}

//string Map::getValue(string key) {
//    for (int i = 0; i < keys.size(); ++i) {
//        if (keys[i] == key) {
//            return values[i];
//        }
//    }
//}
//
//
//void Map::setValue(string key, string value) {
//    for (int i = 0; i < keys.size(); ++i) {
//        if (keys[i] == key) {
//            values[i] = value;
//        }
//    }
//}

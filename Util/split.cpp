//
// Created by kidyme on 2021/3/6.
//

#include "split.h"

vector<string> split(string &line, const string &division) {
    vector<string> res;
    if (line.empty()) return res;

    char *target = new char[line.length() + 1];
    char *delimit = new char[division.length() + 1];
    strcpy(target, line.c_str());
    strcpy(delimit, division.c_str());

    char *cell = strtok(target, delimit);
    while (cell) {
        string result = cell;
        res.push_back(result);
        cell = strtok(NULL, delimit);
    }
    return res;
}

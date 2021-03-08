//
// Created by kidyme on 2021/3/1.
//

#include "setId.h"

// 年月日时分秒
string setId() {
    string id = "";
    time_t now = time(nullptr);
    tm *tm_now = localtime(&now);
    id += to_string(tm_now->tm_year + 1900);
    id += to_string(tm_now->tm_mon + 1);
    id += to_string(tm_now->tm_mday);
    id += to_string(tm_now->tm_hour);
    id += to_string(tm_now->tm_min);
    id += to_string(tm_now->tm_sec);

    return id;
}
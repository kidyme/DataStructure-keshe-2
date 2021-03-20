//
// Created by kidyme on 2021/3/15.
//

#ifndef KESHE_2_CPP_MENU_H
#define KESHE_2_CPP_MENU_H

//#include "../DAO/addData.h"
//#include "../DAO/addData.cpp"
//#include "../DAO/readData.h"
//#include "../DAO/readData.cpp"
#include "../DAO/removeData.h"
#include "../DAO/removeData.cpp"
#include "../DAO/updateData.h"
#include "../DAO/updateData.cpp"
#include "../Service/list.cpp"
#include "../Service/list.h"
#include "../Service/nodeType.h"
#include <iostream>
using namespace std;

class menu {
public:
    menu();
    ~menu();

private:
    void showMainMenu();
    int showAssistantMenu();
    int showStudentMenu();

    template<class Datatype>
    int doAssistant();
    template<class Datatype>
    int doStudent();

    template<class DataType>
    void assistantAdd();
    template<class DataType>
    void assistantRead() {}
    template<class DataType>
    void assistantUpdate() {}
    template<class DataType>
    void assistantRemove() {}
    template<class DataType>
    void assistantPass() {}
    template<class DataType>
    void assistantSort() {}

    template<class DataType>
    void studentAdd();
};


#endif//KESHE_2_CPP_MENU_H

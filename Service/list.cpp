//
// Created by kidyme on 2021/2/21.
//
#include "list.h"

template<class Data>
List<Data>::List() {
    head = new Data();//头结点
    head->setNext(NULL);
    head->setPrior(NULL);
}

template<class Data>
List<Data>::~List() {}

template<class Data>
void List<Data>::add() {
    if (head->getHasTeacherWriten()) {
        //        printf("调用\n");
        Data *newNode = new Data();
        string input;
        vector<string> values;

        vector<string> keys = head->getKeys();
        cout << "请输入" << endl;
        for (int i = 0; i < keys.size(); ++i) {
            cout << keys[i] << ": ";
            cin >> input;
            values.push_back(input);
        }
        newNode->write(values);

        if (!head->Next()) {
            newNode->setNext(NULL);
            newNode->setPrior(head);

            head->setNext(newNode);
            head->setPrior(newNode);
        }
        else {
            newNode->setNext(NULL);
            newNode->setPrior(head->Prior());

            Data *last = head->Prior();
            last->setNext(newNode);
            head->setPrior(newNode);
        }
    }
    else {
        cout << "辅导员还未填写属性!" << endl;
    }
}

template<class Data>
void List<Data>::read(int index) {
    Data *tmp = head;
    for (int i = 0; i < index; ++i) {
        tmp = tmp->Next();
    }
    tmp->read();
}

template<class Data>
void List<Data>::read() {
    Data *tmp = head;
    while (tmp->Next()) {
        tmp->Next()->read();
        tmp = tmp->Next();
    }
}

template<class Data>
void List<Data>::update(int index) {
    vector<string> keys = head->getKeys();
    for (int i = 0; i < keys.size(); ++i) {
        cout << i + 1 << ". " << keys[i] << endl;
    }
    cout << "请选择要修改的属性值: ";
    int inputIndex;
    cin >> inputIndex;
    inputIndex--;
    string inputValue;
    cout << "请输入" << endl
         << keys[inputIndex] << ": ";
    cin >> inputValue;

    Data *tmp = head;
    for (int i = 0; i < index; ++i) {
        tmp = tmp->Next();
    }
    tmp->update(inputIndex, inputValue);
}

template<class Data>
void List<Data>::remove(int index) {
    Data *tmp = head;
    for (int i = 0; i < index; ++i) {
        tmp = tmp->Next();
    }

    tmp->Prior()->setNext(tmp->Next());
    tmp->Next()->setPrior(tmp->Prior());
    delete tmp;
}

template<class Data>
void List<Data>::add(bool isAssistant) {
    if (!head->getHasTeacherWriten()) {
        cout << "请输入" << head->getType() << "的属性"
             << "( 输入over停止输入 )" << endl;
        vector<string> keys;
        string input;
        while (true) {
            cin >> input;
            if (input == "over") {
                break;
                break;
            }
            keys.push_back(input);
        }
        if (keys.size()) {
            head->setKeys(keys);
        }
    }
    else {
        cout << "请补充" << head->getType() << "的属性: " << endl;
        string input;
        cin >> input;
        head->addKey(input);
        Data *tmp = head;
        while (tmp->Next()) {
            tmp->Next()->addOwnKey(input);

            tmp = tmp->Next();
        }
    }
}

template<class Data>
void List<Data>::read(bool isAssistant) {
    vector<string> keys = head->getKeys();
    for (int i = 0; i < keys.size(); ++i) {
        cout << i + 1 << ". " << keys[i] << endl;
    }
}

template<class Data>
void List<Data>::update(bool isAssistant) {
    read(true);
    cout << "请选择要修改的属性的序号: ";
    int index;
    cin >> index;
    cout << "将\"" << head->getKeys()[--index] << "\"修改为: ";
    string input;
    cin >> input;
    head->updateKey(index, input);

    Data *tmp = head;
    while (tmp->Next()) {
        tmp->Next()->updateOwnKey(index, input);
        tmp = tmp->Next();
    }
}

template<class Data>
void List<Data>::remove(bool isAssistant) {
    read(true);
    cout << "请选择要删除的属性的序号: ";
    int index;
    cin >> index;

    cout << "确定要将\"" << head->getKeys()[--index]
         << "\"删除? [输入y删除,n取消]: ";
    string input;
    cin >> input;

    if (input == "y") {
        head->removeKey(index);
        Data *tmp = head;
        while (tmp->Next()) {
            tmp->Next()->removeOwnKey(index);
            tmp = tmp->Next();
        }
    }
}

template<class Data>
void List<Data>::verify() {
    Data *tmp = head;
    int i = 1;
    string input;
    cout << "请轮流查看每个学生所填信息并审核" << endl;
    while (tmp->Next()) {
        if (!tmp->Next()->getPassStatus()) {
            read(i);
            cout << "通过输入y, 不通过输入n: ";
            cin >> input;
            if (input == "y") {
                tmp->Next()->pass();
            }
        }
        tmp = tmp->Next();
        i++;
    }
}
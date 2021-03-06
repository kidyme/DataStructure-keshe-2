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
Data *List<Data>::getNode(int index) {
    Data *tmp = head;
    for (int i = 0; i < index; ++i) {
        tmp = tmp->Next();
    }

    return tmp;
}

template<class Data>
int List<Data>::getIndex(string id) {
    Data *tmp = head;
    int index = 1;
    while (tmp->Next()) {
        if (tmp->Next()->getDataId() == id) {
            return index;
        }
        index++;
        tmp = tmp->Next();
    }
    return 0;
}

template<class Data>
vector<string> List<Data>::getKeys() {
    return head->getKeys();
}

template<class Data>
int List<Data>::getLength() {
    int length = 0;
    Data *tmp = head;
    while (tmp->Next()) {
        length++;
        tmp = tmp->Next();
    }
    return length;
}

template<class Data>
void List<Data>::add(Data &newNode) {
    if (!head->Next()) {
        newNode.setNext(NULL);
        newNode.setPrior(head);

        head->setNext(&newNode);
        head->setPrior(&newNode);
    }
    else {
        newNode.setNext(NULL);
        newNode.setPrior(head->Prior());

        Data *last = head->Prior();
        last->setNext(&newNode);
        head->setPrior(&newNode);
    }
}

template<class Data>
void List<Data>::add() {
    if (head->getHasTeacherWriten()) {
        string stuId;
        string stuName;
        cout << "请输入" << endl;
        cout << "学生Id: ";
        cin >> stuId;
        cout << "姓名: ";
        cin >> stuName;

        Data *newNode = new Data();
        string input;
        vector<string> values;

        newNode->setStudentId(stuId);
        newNode->setStudentName(stuName);

        vector<string> keys = head->getKeys();
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
    cout << "1. 学生Id" << endl;
    cout << "2. 姓名" << endl;
    for (int i = 2; i < keys.size() + 2; ++i) {
        cout << i + 1 << ". " << keys[i - 2] << endl;
    }
    cout << "请选择要修改的属性值: ";
    int inputIndex;
    string inputValue;
    cin >> inputIndex;

    if (inputIndex < 1 || inputIndex > keys.size()) {
        cout << "输入错误!" << endl;
        return;
    }

    inputIndex -= 3;

    cout << "请输入" << endl
         << (inputIndex ==
                             (-2)
                     ? "学生Id"
                     : (inputIndex == (-1) ? "姓名" : keys[inputIndex]))
         << ": ";
    cin >> inputValue;

    Data *tmp = head;
    for (int i = 0; i < index; ++i) {
        tmp = tmp->Next();
    }
    if (inputIndex == -2) {
        tmp->setStudentId(inputValue);
    }
    else if (inputIndex == -1) {
        tmp->setStudentName(inputValue);
    }
    else {
        tmp->update(inputIndex, inputValue);
    }
}

template<class Data>
void List<Data>::update(Data *node) {
    Data *tmp = head;
    while (tmp->Next()) {
        if (tmp->Next()->getDataId() == node->getDataId()) {
            Data *find = tmp->Next();
            // 若为最后一个
            if (!tmp->Next()->Next()) {
                find->Prior()->setNext(node);
                node->setPrior(find);
                node->setNext(NULL);
                head->setPrior(node);
                delete find;
                break;
            }
            else {
                find->Prior()->setNext(node);
                find->Next()->setPrior(node);
                node->setPrior(find->Prior());
                node->setNext(find->Next());
                delete find;
                break;
            }
        }
        tmp = tmp->Next();
    }
}

template<class Data>
void List<Data>::remove(int index) {
    Data *tmp = head;
    for (int i = 0; i < index; ++i) {
        tmp = tmp->Next();
    }
    // 最后一个
    if (!tmp->Next()) {
        tmp->Prior()->setNext(NULL);
        head->setPrior(tmp->Prior());
        delete tmp;
        return;
    }
    tmp->Prior()->setNext(tmp->Next());
    tmp->Next()->setPrior(tmp->Prior());
    delete tmp;
}

template<class Data>
void List<Data>::add(vector<string> keys) {
    head->setKeys(keys);
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
        cout << "请补充" << head->getType() << "的属性: (输入over结束)" << endl;
        string input;
        vector<string> keys;
        Data *tmp = head;

        while (true) {
            if (!keys.empty() && keys[keys.size() - 1] == "over") {
                break;
            }
            cin >> input;
            keys.push_back(input);
        }

        for (int i = 0; i < keys.size() - 1; i++) {
            head->addKey(keys[i]);
        }

        while (tmp) {
            for (int i = 0; i < keys.size() - 1; i++) {
                tmp->addOwnKey(keys[i]);
            }
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
void List<Data>::update(vector<string> keys) {
    Data *tmp = head;
    if (head->getSize() > keys.size()) {
        while (tmp->Next()) {
            for (int i = keys.size(); i < head->getSize(); ++i) {
                tmp->Next()->removeOwnKey(i);
            }
            tmp = tmp->Next();
        }
    }

    head->setKeys(keys);
    tmp = head;
    int index = 0;
    while (tmp->Next()) {
        for (int i = 0; i < head->getSize(); ++i) {
            tmp->Next()->updateOwnKey(i, keys[index]);
        }
        tmp = tmp->Next();
        index++;
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
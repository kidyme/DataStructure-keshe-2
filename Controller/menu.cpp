//
// Created by kidyme on 2021/3/15.
//

#include "menu.h"

menu::menu() {
    showMainMenu();
}

menu::~menu() {}

void menu::showMainMenu() {
    int input;
loop:
    cout << "1. 辅导员, 2. 学生" << endl;
    cout << "请输入你的身份: ";
    cin >> input;
    if (input == 1) {
        if (!showAssistantMenu()) {
            system("clear");
            goto loop;
        }
    }
    else if (input == 2) {
        if (!showStudentMenu()) {
            system("clear");
            goto loop;
        }
    }
    else {
        system("clear");
        cout << "输入错误！" << endl;
        goto loop;
    }
}

template<class DataType>
void menu::assistantAdd() {
    ifstream file("/Users/apple/Documents/数据结构/DataStructure-keshe-2/Data/" + (new DataType)->getType() + ".md");
    readData<DataType, Node<DataType>> *readData = new ::readData<DataType, Node<DataType>>(new DataType);
    addData<DataType, Node<DataType>> *addData = new ::addData<DataType, Node<DataType>>(new DataType);
    removeData<DataType, Node<DataType>> *removeData = new ::removeData<DataType, Node<DataType>>(new DataType);
    Node<DataType> *newNode = new Node<DataType>;
    List<Node<DataType>> list = readData->getAll();
    vector<string> keys = newNode->getKeys();

    if (file) {
        cout << (new DataType)->getType() << "现有的属性: " << endl;
        for (int i = 0; i < keys.size(); ++i) {
            if (i) cout << "、";
            cout << keys[i];
        }
    }
    cout << endl;

    vector<string> tmpKeys = Node<DataType>::getKeys();
    list.add(true);

    removeData->removeFile();
    addData->create();

    addData->addColumnTitle();
    for (int i = 0; i < list.getLength(); ++i) {
        addData->add(list.getNode(i + 1));
    }
}

template<class DataType>
void menu::studentAdd() {
    readData<DataType, Node<DataType>> *readData = new ::readData<DataType, Node<DataType>>(new DataType);
    addData<DataType, Node<DataType>> *addData = new ::addData<DataType, Node<DataType>>(new DataType);
    Node<DataType> *newNode = new Node<DataType>;
    List<Node<DataType>> list = readData->getAll();
    vector<string> keys = newNode->getKeys();
    list.add();
    addData->add(list.getNode(list.getLength()));
}

template<class DataType>
int menu::doAssistant() {
    system("clear");
loop:
    cout << "0. 返回" << endl;
    cout << "1. 添加属性" << endl;
    cout << "2. 修改属性" << endl;
    cout << "3. 浏览属性" << endl;
    cout << "4. 删除属性" << endl;
    cout << "5. 审核" << endl;
    cout << "6. 排序" << endl;

    int input;
    cout << "请输入: ";
    cin >> input;

    switch (input) {
        case 0:
            return 0;
        case 1:
            assistantAdd<DataType>();
            break;
        case 2:
            assistantUpdate<DataType>();
            break;
        case 3:
            assistantRead<DataType>();
            break;
        case 4:
            assistantRemove<DataType>();
            break;
        case 5:
            assistantPass<DataType>();
            break;
        case 6:
            assistantSort<DataType>();
            break;
        default:
            system("clear");
            cout << "输入错误" << endl;
            goto loop;
    }
    return 1;
}

template<class DataType>
int menu::doStudent() {
    system("clear");
loop:
    cout << "0. 返回" << endl;
    cout << "1. 填写" << endl;
    cout << "2. 修改" << endl;
    cout << "3. 浏览" << endl;
    cout << "4. 删除" << endl;

    int input;
    cout << "请输入: ";
    cin >> input;

    switch (input) {
        case 0:
            return 0;
        case 1:
            studentAdd<DataType>();
            break;
        case 2:
            //            studentUpdate();
            break;
        case 3:
            //            studentRead();
            break;
        case 4:
            //            studentRemove();
            break;
        default:
            system("clear");
            cout << "输入错误" << endl;
            goto loop;
    }
    return 1;
}

int menu::showAssistantMenu() {
    system("clear");
    int input;
loop:
    cout << "---------------" << endl;
    cout << "| 0. 退回" << endl;
    cout << "| 1. 奖项" << endl;
    cout << "| 2. 论文" << endl;
    cout << "| 3. 发表文章" << endl;
    cout << "| 4. 专利" << endl;
    cout << "| 5. 著作权" << endl;
    cout << "| 6. 校级竞赛" << endl;
    cout << "| 7. 校级以上竞赛" << endl;
    cout << "| 8. 证书" << endl;
    cout << "| 9. 创业项目" << endl;
    cout << "---------------";
    cout << "请选择成果或返回: ";
    cin >> input;
    switch (input) {
        case 0:
            return 0;
        case 1:
            if (!doAssistant<Awards>()) {
                system("clear");
                goto loop;
            }
            break;
        case 2:
            if (!doAssistant<Paper>()) {
                system("clear");
                goto loop;
            }
            break;
        case 3:
            if (!doAssistant<Article>()) {
                system("clear");
                goto loop;
            }
            break;
        case 4:
            if (!doAssistant<Patent>()) {
                system("clear");
                goto loop;
            }
            break;
        case 5:
            if (!doAssistant<Copyright>()) {
                system("clear");
                goto loop;
            }
            break;
        case 6:
            if (!doAssistant<SchoolCompetition>()) {
                system("clear");
                goto loop;
            }
            break;
        case 7:
            if (!doAssistant<SocietyCompetition>()) {
                system("clear");
                goto loop;
            }
            break;
        case 8:
            if (!doAssistant<Certificate>()) {
                system("clear");
                goto loop;
            }
            break;
        case 9:
            if (!doAssistant<Project>()) {
                system("clear");
                goto loop;
            }
            break;
        default:
            system("clear");
            cout << "输入错误" << endl;
            goto loop;
    }
    return 1;
}

int menu::showStudentMenu() {
    system("clear");
    int input;
loop:
    cout << "---------------" << endl;
    cout << "| 0. 退回" << endl;
    cout << "| 1. 奖项" << endl;
    cout << "| 2. 论文" << endl;
    cout << "| 3. 发表文章" << endl;
    cout << "| 4. 专利" << endl;
    cout << "| 5. 著作权" << endl;
    cout << "| 6. 校级竞赛" << endl;
    cout << "| 7. 校级以上竞赛" << endl;
    cout << "| 8. 证书" << endl;
    cout << "| 9. 创业项目" << endl;
    cout << "---------------";
    cout << "请选择成果或返回: ";
    cin >> input;
    switch (input) {
        case 0:
            return 0;
        case 1:
            doStudent<Awards>();
            break;
        case 2:
            doStudent<Paper>();
            break;
        case 3:
            doStudent<Article>();
            break;
        case 4:
            doStudent<Patent>();
            break;
        case 5:
            doStudent<Copyright>();
            break;
        case 6:
            doStudent<SchoolCompetition>();
            break;
        case 7:
            doStudent<SocietyCompetition>();
            break;
        case 8:
            doStudent<Certificate>();
            break;
        case 9:
            doStudent<Project>();
            break;
        default:
            system("clear");
            cout << "输入错误!";
            goto loop;
    }
    return 1;
}
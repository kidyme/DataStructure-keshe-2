//
// Created by kidyme on 2021/2/20.
//

#ifndef KESHE_2_CPP_NODE_H
#define KESHE_2_CPP_NODE_H
#include "../Util/map.h"
#include "../Util/setId.h"

/*
 * 对于类：
 *      填写键  (填完键后，创造对象时可将对象的键的vector赋值)
 *      增加键
 *      更新键
 *      删除键
 *      获取所有键
 *      获取键的个数
 *      判断辅导员是否已经填写过属性
 * 对于对象：
 *      获取所有值
 *      获取当前通过状态
 *      审核通过
 *      获取Node类型
 *      设置id(在Utils中设计算法)
 *      获取id
 *      设置学生id
 *      获取学生id
 *      设置学生姓名
 *      获取学生姓名
 *      填写值
 *      根据键的下标，填写值
 *      查询所有键值对
 *      根据键的下标，修改对应的值
 *      增加键
 *      更新键
 *      删除键
 *      修改next和prior
 *      获取next和prior
 */
template<class T>
class Node {
public:
    Node();
    ~Node();

    void pass();
    bool getPassStatus() { return status; }
    string getType();

    void write(vector<string> input);
    void write(int index, string value);
    void read();
    void update(int keyIndex, string value);
    void addOwnKey(string key);
    void updateOwnKey(int index, string key);
    void removeOwnKey(int index);

    string getDataId() { return dataId; }
    string getStudentId() { return studentId; }
    string getStudentName() { return studentName; }
    void setDataId(string id) { dataId = id; }
    void setStudentId(string id) { studentId = id; }
    void setStudentName(string name) { studentName = name; }
    void setNext(Node *newNext) { next = newNext; }
    void setPrior(Node *newPrior) { prior = newPrior; }
    Node *Next() { return next; }
    Node *Prior() { return prior; }
    vector<string> getValues() { return properties.getValues(); }

    static void setKeys(vector<string> input);
    static void addKey(string key);
    // Service层调用此函数后，必须要遍历List，调用Node的addOwnKey("xxxx")
    static void updateKey(int index, string key);
    // Service层调用此函数后，必须要遍历List，调用Node的updateOwnKey("xxxx")
    static void removeKey(int index);
    // Service层调用此函数后，必须要遍历List，调用Node的removeOwnKey("xxxx")
    static vector<string> getKeys();
    static int getSize();
    static int getHasTeacherWriten();

private:
    void setOwnKeys();           // 若keys已被填写才能在构造函数调用，用于properties变量的赋值
    static bool hasTeacherWriten;// 辅导员是否填写了属性
    static vector<string> keys;
    string dataId;
    string studentId;
    string studentName;
    bool status;// 审核状态
    Map properties;
    Node *next;
    Node *prior;
};

#endif// KESHE_2_CPP_NODE_H

//
// Created by kidyme on 2021/2/20.
//

#ifndef KESHE_2_CPP_NODE_H
#define KESHE_2_CPP_NODE_H
#include "../Util/map.h"


/*
 * 对于类：
 *      填写键  (填完键后，创造对象时可将对象的键的vector赋值)
 *      增加键
 *      获取所有键
 *      获取键的个数
 * 对于对象：
 *      填写值
 *      根据键的下标，填写值
 *      查询所有键值对
 *      根据键的下标，修改对应的值
 *      增加键
 *      修改next和prior
 *      获取next和prior
 */
template<class T>
class Node {
public:
    Node();
    ~Node();
    string getType();
    void write(vector<string> input);
    void write(int index, string value);
    void read();
    void update(int keyIndex, string value);
    void addOwnKeys(string key);

    void setId(int id);
    void setNext(Node *newNext) { next = newNext; }
    void setPrior(Node *newPrior) { prior = newPrior; }
    Node *Next() { return next; }
    Node *Prior() { return prior; }

    static void setKeys(vector<string> input);
    // 在Control层判断用户的写入是否为空或者部分为空，理论上只应调用一次，多次调用后需调用Node的addOwnKeys("xxxx")
    static void setKey(string key);
    // Control层调用此函数后，必须要遍历List，调用Node的addOwnKeys("xxxx")
    static vector<string> getKeys();
    static int getSize();
    static int getHasTeacherWriten();

private:
    void setOwnKeys();// 若keys已被填写才能在构造函数调用，用于properties变量的赋值

    static bool hasTeacherWriten;// 辅导员是否填写了属性
    static vector<string> keys;
    int id;
    Map properties;
    Node *next;
    Node *prior;
};


#endif//KESHE_2_CPP_NODE_H

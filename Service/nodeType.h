//
// Created by kidyme on 2021/2/21.
//

#ifndef KESHE_2_CPP_NODETYPE_H
#define KESHE_2_CPP_NODETYPE_H
#include <string>
using namespace std;

/*
 * 共同的父类Type
 *      提供type属性和getType方法
 *
 * 科研成果
 *      奖项类、论文类、文章类
 *
 * 知识产权
 *      专利类、著作权类
 *
 * 学科与科技竞赛
 *      校级竞赛类，校级以上竞赛类
 *
 * 技能证书
 *      证书类
 *
 * 创业实践
 *      项目类
 */

class Type {
public:
    Type();
    ~Type();
    string getType();

protected:
    string type;
};

//------------------------------------科研成果------------------------------------------------------
class Awards : public Type {
public:
    Awards();
    ~Awards();
};

class Paper : public Type {
public:
    Paper();
    ~Paper();
};

class Article : public Type {
public:
    Article();
    ~Article();
};

//--------------------------------------知识产权---------------------------------------------------
class Patent : public Type {
public:
    Patent();
    ~Patent();
};

class Copyright : public Type {
public:
    Copyright();
    ~Copyright();
};


//-------------------------------------学科科技与竞赛-----------------------------------------------
class SchoolCompetition : public Type {
public:
    SchoolCompetition();
    ~SchoolCompetition();
};

class SocietyCompetition : public Type {
public:
    SocietyCompetition();
    ~SocietyCompetition();
};

//--------------------------------------技能证书---------------------------------------------------
class Certificate : public Type {
public:
    Certificate();
    ~Certificate();
};

//--------------------------------------创业实践---------------------------------------------------
class Project : public Type {
public:
    Project();
    ~Project();
};

#endif//KESHE_2_CPP_NODETYPE_H

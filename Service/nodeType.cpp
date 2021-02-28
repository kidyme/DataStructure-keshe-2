//
// Created by kidyme on 2021/2/21.
//

#include "nodeType.h"

Type::Type() { type = ""; }

Type::~Type() {}

string Type::getType() { return type; }

Awards::Awards() { type = "奖项"; }

Awards::~Awards() {}

Paper::Paper() { type = "论文"; }

Paper::~Paper() {}

Article::Article() { type = "发表文章"; }

Article::~Article() {}

SchoolCompetition::SchoolCompetition() { type = "校级竞赛"; }

SchoolCompetition::~SchoolCompetition() {}

SocietyCompetition::SocietyCompetition() { type = "校级以上竞赛"; }

SocietyCompetition::~SocietyCompetition() {}

Patent::Patent() { type = "专利"; }

Patent::~Patent() {}

Copyright::Copyright() { type = "著作权"; }

Copyright::~Copyright() {}

Certificate::Certificate() { type = "资格证书"; }

Certificate::~Certificate() {}

Project::Project() { type = "创业项目"; }

Project::~Project() {}


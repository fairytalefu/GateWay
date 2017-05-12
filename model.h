#ifndef MODEL_H
#define MODEL_H

#include<QtSql/QSqlDatabase>
#include<QStringList>
#include<QDebug>
#include "svm.h"
class Model
{
public:
    Model();
    void connectTOMySQL();
    void test();
};

#endif // MODEL_H

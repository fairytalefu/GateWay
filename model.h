#ifndef MODEL_H
#define MODEL_H

#include<QtSql/QSqlDatabase>
#include<QStringList>
#include<QDebug>
class Model
{
public:
    Model();
    void connectTOMySQL();
};

#endif // MODEL_H

#include "model.h"

Model::Model()
{

}

void Model::test()
{

}

/**
 * @brief Model::connectTOMySQL
 */
void Model::connectTOMySQL()
{
    //测试是否包含mysql的驱动
    QStringList drivers_l=QSqlDatabase::drivers();
    qDebug() << drivers_l << endl;

    QSqlDatabase    dbconn;
//   // QSqlQuery       query;
    dbconn = QSqlDatabase::addDatabase("QMYSQL");
    dbconn.setHostName("localhost");//主机名字
//    dbconn.setDatabaseName("PVData");//数据库名字
//    dbconn.setPort(3306);//端口
//    dbconn.setUserName("root");//用户名
//    dbconn.setPassword("111");//密码
//    if(dbconn.open())//成功返回1
//        qDebug() << "链接数据库成功" <<endl;
// query = (QSqlQuery)dbconn;
}

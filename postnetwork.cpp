#include "postnetwork.h"

PostToNetwork::PostToNetwork()
{

}
bool PostToNetwork::postToServer()
{
  //QUrl myURL(QString("https://things.ubidots.com/api/v1.6/variables/5901ade07625427cad17e91b/values/?token=wseZ3mpbc7vPzM4tlANdLo5Tqngf48"));
    QUrl myURL(QString("http://127.0.0.1:8888/BaiduMap"));
    QNetworkRequest request(myURL);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QNetworkAccessManager mgr;
    QJsonObject json;
    json.insert("PVStationID", 1);
    json.insert("Voltage", 34);
    json.insert("Current", 34);
    json.insert("Power", 34);
    json.insert("Vmp", 34);
    json.insert("Imp", 34);
    json.insert("Temp", 14);
    json.insert("Irr", 13);
    json.insert("Status", "open1");
    json.insert("Lat", 34);
    json.insert("Lng", 34);
    json.insert("Time", "34");
    QNetworkReply *reply = mgr.post(request, QJsonDocument(json).toJson());

    while(!reply->isFinished())
    {
       qApp->processEvents();
    }
    QByteArray response_data = reply->readAll();
    QJsonDocument response_json = QJsonDocument::fromJson(response_data);
    reply->deleteLater();
    qDebug() << "Success" << response_data << endl;

}

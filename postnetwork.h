#ifndef POSTNETWORK_H
#define POSTNETWORK_H
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QtNetwork>

class PostToNetwork
{
public:
    PostToNetwork();
    bool postToServer();
};

#endif // POSTNETWORK_H

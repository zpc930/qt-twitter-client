#include <QtNetwork/QHttp>
#include <QtCore>
#include <iostream>
#include "http.h"
int main(int argc, char** argv)
{
    if (argc < 3)
    {
        cout<<"http <host> <page>"<<endl;
        return 0;
    }
    QCoreApplication app(argc, argv);
    MyHttp *mh = new MyHttp(argv[1], argv[2]);
    QObject::connect(mh, SIGNAL(finish(QString)),
            &app, SLOT(quit()));
    return app.exec();
}

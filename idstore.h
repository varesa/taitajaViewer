#ifndef IDSTORE_H
#define IDSTORE_H

#include <QString>
#include <QFile>

class IdStore
{
public:
    IdStore();
    static void store(QString id);
    static QString* get();
private:
    static QFile *file;
};

#endif // IDSTORE_H

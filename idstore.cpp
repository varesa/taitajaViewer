#include "idstore.h"

#include <QDir>
#include <QTextStream>

IdStore::IdStore()
{

}

QFile *IdStore::file = 0;

void IdStore::store(QString id) {
    file = new QFile(QDir::homePath() + "/id.txt");
    file->open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream *out = new QTextStream(file);
    *out << id;
    file->close();
}

QString* IdStore::get() {
    file = new QFile(QDir::homePath() + "/id.txt");
    file->open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream *in = new QTextStream(file);

    QString *id = new QString();
    *in >> *id;
    return id;
}

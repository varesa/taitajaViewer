#ifndef CONFIGPARSER_H
#define CONFIGPARSER_H

#include <QString>

class ConfigParser
{
private:
    QString url;
public:
    ConfigParser();

    QString getUrl();
    QString getUrl(QString file);

};

#endif // CONFIGPARSER_H

#include <QtCore/QFile>

#include <QApplication>
#include <QWidget>
#include <QStackedWidget>
#include <QLayout>

#include <QWebView>
#include <QWebFrame>

#include <QDebug>

#include "configparser.h"

#include "containerwidget.h"
#include "webviewerwidget.h"
#include "idchangewidget.h"

#include "vars.h"


int main(int argc, char *argv[])
{
    
    // Initialize app

    QApplication app(argc, argv);
    app.setOverrideCursor(Qt::BlankCursor);

    ConfigParser *parser = new ConfigParser();
    Vars::url = parser->getUrl();

    // Initialize window

    QStackedWidget *window = new ContainerWidget();
    window->showMaximized();

    // Exec...

    return app.exec();
}

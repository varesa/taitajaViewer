#ifndef CONTAINERWIDGET_H
#define CONTAINERWIDGET_H

#include <QWidget>
#include <QStackedWidget>

#include "webviewerwidget.h"
#include "idchangewidget.h"

class ContainerWidget : public QStackedWidget
{
    Q_OBJECT
public:
    explicit ContainerWidget(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *e);
    WebviewerWidget *webwidget;
    IdChangeWidget *idwidget;

private:
    void showWebview();
    void showIdChange();
signals:
    void openWebview();
    void openIdChange();
    void reloadPage();
public slots:
};

#endif // CONTAINERWIDGET_H

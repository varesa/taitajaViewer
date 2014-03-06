#include <QDebug>
#include <QKeyEvent>
#include <QStackedWidget>
#include <QFile>
#include <QDir>

#include "containerwidget.h"
#include "webviewerwidget.h"
#include "idchangewidget.h"
#include "idstore.h"

ContainerWidget::ContainerWidget(QWidget *parent) :
    QStackedWidget(parent)
{
    setCursor(Qt::BlankCursor);

    webwidget = new WebviewerWidget();
    idwidget = new IdChangeWidget();

    connect(this, SIGNAL(reloadPage()), webwidget, SLOT(refresh()) );

    addWidget(webwidget);
    addWidget(idwidget);
}

void ContainerWidget::keyPressEvent(QKeyEvent *e) {
    if(e->key() == Qt::Key_F1) {
        showWebview();
    } else if(e->key() == Qt::Key_F2) {
        showIdChange();
    } else if(e->key() == Qt::Key_F5) {
        qDebug() << "Reload page";
        emit reloadPage();
    }
}

void ContainerWidget::showWebview() {
    QLineEdit *line = idwidget->lineedit;
    IdStore::store(line->text());

    this->widget(1)->hide();
    this->widget(0)->show();
}

void ContainerWidget::showIdChange() {
    this->widget(0)->hide();
    this->widget(1)->show();

}

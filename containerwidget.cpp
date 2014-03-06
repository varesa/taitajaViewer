#include <QDebug>
#include <QKeyEvent>
#include <QStackedWidget>
#include <QFile>
#include <QDir>

#include "containerwidget.h"
#include "webviewerwidget.h"
#include "idchangewidget.h"

ContainerWidget::ContainerWidget(QWidget *parent) :
    QStackedWidget(parent)
{
    setCursor(Qt::BlankCursor);

    addWidget(new WebviewerWidget());
    addWidget(new IdChangeWidget());
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
    IdChangeWidget *idwidget = (IdChangeWidget*)this->widget(1);
    QLineEdit *line = (QLineEdit*) idwidget->children()[1];

    QFile idfile(QDir::homePath() + "/id.txt");
    idfile.open(QIODevice::WriteOnly | QIODevice::Text);
    qDebug() << idfile.fileName();
    QTextStream out(&idfile);
    out << line->text();
    idfile.close();

    this->widget(1)->hide();
    this->widget(0)->show();
}

void ContainerWidget::showIdChange() {
    this->widget(0)->hide();
    this->widget(1)->show();

}

#include "idchangewidget.h"
#include <QVBoxLayout>
#include <QLineEdit>
#include <QDebug>

IdChangeWidget::IdChangeWidget(QWidget *parent) :
    QWidget(parent)
{
    lineedit = new QLineEdit();
    lineedit->setMaximumSize(QSize(500, 100));
    lineedit->setMinimumHeight(64);
    QFont font = QFont();
    font.setPixelSize(60);
    lineedit->setFont(font);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->setAlignment(Qt::AlignCenter);
    layout->addWidget(lineedit);

    this->setLayout(layout);
    lineedit->setFocus();
}

void IdChangeWidget::showEvent() {
    qDebug() << "show";
    this->lineedit->setFocus();
}

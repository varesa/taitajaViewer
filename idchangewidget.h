#ifndef IDCHANGEWIDGET_H
#define IDCHANGEWIDGET_H

#include <QWidget>
#include <QLineEdit>

class IdChangeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit IdChangeWidget(QWidget *parent = 0);
    void showEvent();
    QLineEdit *lineedit;

private:

signals:

public slots:

};

#endif // IDCHANGEWIDGET_H

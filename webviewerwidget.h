#ifndef WEBVIEWERWIDGET_H
#define WEBVIEWERWIDGET_H

#include <QWidget>
#include <QWebView>

class WebviewerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WebviewerWidget(QWidget *parent = 0);

private:
    QWebView *webview;

signals:

public slots:
    void reload(void);

};

#endif // WEBVIEWERWIDGET_H

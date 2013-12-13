#include <QWebView>
#include <QWebFrame>
#include <QBoxLayout>

#include "webviewerwidget.h"

WebviewerWidget::WebviewerWidget(QWidget *parent) :
    QWidget(parent)
{
    /*
     * Setup webview
     */

    QWebView *webview = new QWebView();
    //webview->setUrl(QUrl(url));
    webview->setUrl(QUrl("http://taitaja.finbit.dy.fi/"));
    webview->page()->mainFrame()->setScrollBarPolicy(Qt::Horizontal, Qt::ScrollBarAlwaysOff);
    webview->page()->mainFrame()->setScrollBarPolicy(Qt::Vertical, Qt::ScrollBarAlwaysOff);

    //QObject::connect(window, SIGNAL(reloadPage()), webview, SLOT(reload()));


    /*
     * Widget layout
     */

    QBoxLayout::Direction dir = QBoxLayout::TopToBottom;
    QBoxLayout *layout = new QBoxLayout(dir);
    layout->setSpacing(0);
    layout->setContentsMargins(0,0,0,0);

    this->setLayout(layout);
    layout->addWidget(webview);
    webview->show();
}

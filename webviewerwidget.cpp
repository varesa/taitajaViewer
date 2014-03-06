#include <QWebView>
#include <QWebFrame>
#include <QBoxLayout>

#include "webviewerwidget.h"
#include "idstore.h"

WebviewerWidget::WebviewerWidget(QWidget *parent) :
    QWidget(parent)
{
    /*
     * Setup webview
     */

    webview = new QWebView();
    //webview->setUrl(QUrl("http://taitaja.finbit.dy.fi/"));

    /*
     * Widget layout
     */

    QBoxLayout::Direction dir = QBoxLayout::TopToBottom;
    QBoxLayout *layout = new QBoxLayout(dir);
    layout->setSpacing(0);
    layout->setContentsMargins(0,0,0,0);

    this->setLayout(layout);
    layout->addWidget(webview);

    reload();

    webview->show();
}

void WebviewerWidget::reload(void) {
    QString *id = IdStore::get();
    QUrl url("http://taitaja.finbit.dy.fi/?id=" + *id);
    qDebug() << url;

    webview->load(QUrl("http://taitaja.finbit.dy.fi/?id=" + *id));

    webview->page()->mainFrame()->setScrollBarPolicy(Qt::Horizontal, Qt::ScrollBarAlwaysOff);
    webview->page()->mainFrame()->setScrollBarPolicy(Qt::Vertical, Qt::ScrollBarAlwaysOff);
}

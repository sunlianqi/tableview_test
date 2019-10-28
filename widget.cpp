#include "widget.h"
#include "ui_widget.h"
#include <QtDebug>
#include "tabledelegate.h"
#include <QAbstractItemModel>
#include <QToolTip>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    tableModel = new TableModel();  // Model
    ui->tableView->setModel(tableModel);    // View
    ui->tableView->setItemDelegate(new TableDelegate);  // Delegate
    ui->tableView->verticalHeader()->setDefaultSectionSize(20);
    ui->tableView->horizontalHeader()->setDefaultSectionSize(20);
    //connect(ui->tableView,SIGNAL(clicked(QModelIndex)),this,SLOT(choseItem(QModelIndex)));
    tableModel->addElement();
    ui->tableView->viewport()->installEventFilter(this);//安装事件过滤器
    ui->tableView->viewport()->setMouseTracking(true);//true鼠标移动触发 false按下触发
}

Widget::~Widget()
{
    delete ui;
}

bool Widget::eventFilter(QObject *obj, QEvent *e)
{
    if(obj == ui->tableView->viewport())
    {
        if(e->type() == QEvent::MouseMove)
        {
            choseItem(ui->tableView->indexAt(ui->tableView->mapFromGlobal(QCursor::pos())));
        }
    }
    return QWidget::eventFilter(obj,e);
}

void Widget::choseItem(QModelIndex index)
{
    if(!index.isValid())
    return;
    QString text = QString("(%1,%2) %3").arg(QString::number(index.row()),QString::number(index.column()),index.data().toString());
    if(text.isEmpty())
    return;
    QToolTip::showText(QCursor::pos(),text);
}

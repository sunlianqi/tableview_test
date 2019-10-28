#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QList>
#include <QPair>
#include "tablemodel.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
    bool eventFilter(QObject *target, QEvent *event);

private slots:
    void choseItem(QModelIndex index);

private:
    Ui::Widget *ui;
private:
    TableModel *tableModel;
};

#endif // WIDGET_H

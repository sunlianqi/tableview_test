#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>

#define COUNT 50


class TableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    enum Columns { Element = 0, Value, Count = Value + 1 };

    explicit TableModel(QObject *parent = nullptr);

    Qt::ItemFlags flags(const QModelIndex &index) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    //QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    //bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::DisplayRole);

    void addElement();

private:
    int m_element[COUNT][COUNT];
};

#endif // TABLEMODEL_H

#include "tablemodel.h"
#include <QTime>

TableModel::TableModel(QObject *parent) : QAbstractTableModel(parent)
{

}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    if (index.column() == Element)
    {
        return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
    }
    else if (index.column() == Value)
    {
        return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
    }

    return QAbstractTableModel::flags(index);
}

int TableModel::rowCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : COUNT;
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : COUNT;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() < 0 || index.row() > COUNT)
    {
        return QVariant();
    }

    switch (role)
    {
    case Qt::DisplayRole:
        return m_element[index.row()][index.column()];
    case Qt::EditRole:
        return m_element[index.row()][index.column()];
    }

    return QVariant();
}

//QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
//{
//    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
//    {
//        switch (section)
//        {
//        case Element:
//            return "Element";
//        case Value:
//            return "Value";
//        }
//    }

//    return QAbstractTableModel::headerData(section, orientation, role);
//}

//bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
//{
//    if (!index.isValid() || index.row() < 0 || index.row() >= mElements.count())
//    {
//        return false;
//    }

//    switch (role)
//    {
//    case Qt::DisplayRole:
//    case Qt::EditRole:
//        if (index.column() == Element)
//        {
//            mElements[index.row()].first = value.toString();
//        }
//        else if (index.column() == Value)
//        {
//            mElements[index.row()].second = value.toInt();
//        }
//        emit dataChanged(index, index);
//        return true;
//    }

//    return false;
//}

void TableModel::addElement()
{
    beginInsertRows(QModelIndex(), 0, 0);
    for(int i =0; i < COUNT; i++)
    {
        for(int j =0; j < COUNT; j++)
        {
            m_element[i][j] = 200;
        }
    }
    endInsertRows();
}

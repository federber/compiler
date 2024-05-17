#include "AST.h"
#include <QDebug>
#include <QAbstractItemModel>
#include <iostream>

ObjectTreeModel::ObjectTreeModel(QObject *parent)
    : QAbstractItemModel(parent)
{
    _rootItem = new QObject(this);
    qDebug() << "root" << _rootItem;

}

void ObjectTreeModel::setColumns(QStringList cols)
{
    _columns = cols;
}

void ObjectTreeModel::appendItemToParent(QObject *item, int row, const QModelIndex &parentIdx)
{
    qDebug() << "appendItemToParent(): parent " << item << parentIdx;
std::cout << "0" << std::endl;
beginResetModel();
//    beginInsertRows(parentIdx, row, row);
    std::cout << "1" << std::endl;
    auto par_obj = (!parentIdx.isValid()) ? _rootItem : parentObjOfIndex(parentIdx)->children().at(parentIdx.row());
    std::cout << "1" << std::endl;
    item->setParent(par_obj);
    std::cout << "1" << std::endl;
//    endInsertRows();
    endResetModel();
}

QObject *ObjectTreeModel::parentObjOfIndex(const QModelIndex &index) const
{
    if (!index.isValid())
        throw std::logic_error("askked parent of root!");
    return static_cast<QObject*>(index.internalPointer());
}

QModelIndex ObjectTreeModel::index(int row, int column, const QModelIndex &parent) const
{
    qDebug() << "index(): parent " << parent;
//    if(!hasIndex(row, column, parent))
//        return QModelIndex();
//    QObject* parentObj = objByIndex(parent);
    auto par_obj = (!parent.isValid()) ? _rootItem : parentObjOfIndex(parent)->children().at(parent.row());
    qDebug() << "index(): par_obj " << par_obj;
    return createIndex(row, column, par_obj);

}

QModelIndex ObjectTreeModel::parent(const QModelIndex &child) const
{
//    QObject* childObj = objByIndex(child);
    qDebug() << "parent(): child " << child;
    QObject* parentObj = parentObjOfIndex(child);
    if (parentObj == _rootItem)
        return QModelIndex();
    QObject* grandParentObj = parentObj->parent();
    int row = grandParentObj->children().indexOf(parentObj);
    return createIndex(row, 0, grandParentObj);
}

int ObjectTreeModel::rowCount(const QModelIndex &parent) const
{
    qDebug() << "rowC(): parent" << parent;
    auto par_obj = (!parent.isValid()) ? _rootItem : parentObjOfIndex(parent)->children().at(parent.row());
    qDebug() << par_obj->children().count();
    return par_obj->children().count();
}

int ObjectTreeModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return _columns.count();
}

QVariant ObjectTreeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (role == Qt::DisplayRole) {
        return parentObjOfIndex(index)->children().at(index.row())->property(_columns.at(index.column()).toUtf8());
    }
    return QVariant();
}




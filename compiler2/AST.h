#ifndef AST_H
#define AST_H

#include <QAbstractItemModel>
#include <QObject>

class ObjectTreeModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    ObjectTreeModel(QObject* parent = nullptr);
    void setColumns(QStringList cols);
    void appendItemToParent(QObject* item, int row, const QModelIndex &parentIdx);


protected:
    QStringList _columns;
    QObject* _rootItem;

    QObject* parentObjOfIndex(const QModelIndex &index) const;
  // QAbstractItemModel interface
public:
    virtual QModelIndex index(int row, int column, const QModelIndex &parent) const override;
    virtual QModelIndex parent (const QModelIndex &child) const override;
    virtual int rowCount(const QModelIndex &parent) const override;
    virtual int columnCount(const QModelIndex &parent) const override;
    virtual QVariant data (const QModelIndex &index, int role) const override;

};

#endif // AST_H

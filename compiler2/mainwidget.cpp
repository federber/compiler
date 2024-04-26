#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "AST.h"
#include <QAbstractItemModel>
#include <QObject>
#include <QTreeView>
MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    ObjectTreeModel *model = new ObjectTreeModel(this);

    QStringList cols;
    cols << "objectName";

    model->setColumns(cols);

    QObject* item1 = new QObject();
    item1->setObjectName("+");

    QObject* item2 = new QObject(item1);
    item2->setProperty("objectName", "3");

    QObject* item3 = new QObject(item1);
    item3->setProperty("objectName", "*");

    QObject* item4 = new QObject(item3);
    item4->setProperty("objectName", "2");

    QObject* item5 = new QObject(item3);
    item5->setProperty("objectName", "7");

    model->addItem(item1, QModelIndex());

    QTreeView *tree = new QTreeView(this);
    tree->setModel(model);

}

MainWidget::~MainWidget()
{
    delete ui;
}

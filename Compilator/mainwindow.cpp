#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _model = new ObjectTreeModel(this);
    QStringList cols;
    cols << "objectName";
    _model->setColumns(cols);

    QObject* item1 = new QObject();
    item1->setObjectName("+");

    QObject* item2 = new QObject(item1);
    item2->setProperty("objectName", "1");

    _model->addItem(item1, QModelIndex());

    ui->treeView.setModel(_model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnAdd_clicked()
{
    QObject* newItem = new QObject();
    newItem->setObjectName(ui->edtName->text());
    _model->addItem(newItem, ui->treeView->currentIndex());
}


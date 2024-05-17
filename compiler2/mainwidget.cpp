#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "AST.h"
#include <QAbstractItemModel>
#include <QObject>
#include <QTreeView>
#include <QFileDialog>
#include <QTextEdit>
#include <QTextStream>
#include "ast_str.h"

const std::vector<std::string> type ({"NT_NUM", "NT_COMPARE", "NT_IDENT", "NT_DATA_TYPE",
                                     "NT_ADD", "NT_SUB", "NT_MUL", "NT_DIV",
                                     "NT_ABS", "NT_NEG", "NT_ASSIGN", "NT_INIT_LIST",
                                     "NT_VARDECL", "NT_IFELSE", "NT_COND", "NT_FNDECL",
                                     "NT_TYPED_VAR", "NT_IL_conc", "NT_FN_CALL", "NT_NOT",
                                     "NT_LOOP", "NT_NULL"});
std::string get_nodetype(int num_type){
    return type[num_type];
}

/*
void draw_AST(AST_node* start_node, QObject* item, ObjectTreeModel *model){
    if (item != nullptr){
        if (start_node->next == nullptr){
            for (int i = 0; i < (start_node->subtrees).size(); ++i){
                if (((start_node->subtrees)[i])->nodetype < NodeT_CONSTANT){
                    QObject* item1 = new QObject(item);
                    item1->setProperty("objectName", ((AST_leaf*)((start_node->subtrees)[i]))->value);
                }
                else {
                    QObject* item2 = new QObject(item);
                    std::string nt = get_nodetype(((AST_node*)((start_node->subtrees)[i]))->nodetype);
                    item2->setProperty("objectName", QString::fromStdString(nt) );
                    draw_AST((AST_node*)((start_node->subtrees)[i]), item2, model);
                }
            }
        model->addItem(item, QModelIndex());
        }
         else {
            std::string nt = get_nodetype((start_node->next)->nodetype);
            QObject* item3 = new QObject();
            item3->setObjectName(QString::fromStdString(nt));
            draw_AST((AST_node*)(start_node->next), item3, model);
        }
   }
   else {
        std::string nt = get_nodetype(start_node->nodetype);
        QObject* item = new QObject();
        item->setObjectName(QString::fromStdString(nt));
        //model->addItem(item, QModelIndex());
        draw_AST(start_node, item, model);
    }
}
*/

/* Первоначальная версия
 *
void draw_AST(AST_node* start_node, ObjectTreeModel *model, QModelIndex index = QModelIndex()){
    int i = 0;
    for (start_node; start_node!=nullptr; start_node = (AST_node*)(start_node->next)){


        if (start_node != nullptr){
            QObject* item = new QObject();
            //std::cout << "parent item = " << parent_item << std::endl;
            std::string nt = get_nodetype(start_node->nodetype);
            std::cout << "nt = " << nt << std::endl;
            item->setProperty("objectName", QString::fromStdString(nt));
            //model->addItem(item, QModelIndex());
            std::cout << "item = " << item << std::endl;
            std::cout << "created node" << std::endl;

//            if (start_node->next != nullptr){
//                std::cout << "created the same level item" << std::endl;
//                draw_AST(((AST_node*)(start_node->next)), parent_item, model);


//            }

            model->appendItemToParent(item, i, index);
 std::cout << "appanded " << std::endl;


            int j =0;
            for (auto& subtree : start_node->subtrees){
                //int j =0;
                if (subtree->nodetype < NodeT_CONSTANT){
                    auto middle_index = model->index(i,0,index);
                    QObject* item1 = new QObject();
                    item1->setProperty("objectName", ((AST_leaf*)subtree)->value);
                    std::cout << "create leafs" << std::endl;
                    std::cout << "parent item = " << item << std::endl;
                    model->appendItemToParent(item1, j , middle_index );
                    j++;
                }
                else {

                    std::cout << "find any node" << std::endl;
                    std::cout << "parent item = " << item << std::endl;
                    //draw_AST(((AST_node*)subtree), model, model->index(j,0,index));
                    draw_AST(((AST_node*)subtree), model, model->index(0,j,index));
                    //model->addItem(item, QModelIndex());
                }
            }
            i ++;

        }
    }
        //model->addItem(parent_item, QModelIndex());
}
*/

// РАБОЧАЯ ВЕРСИЯ????
void draw_AST(AST_node* start_node, ObjectTreeModel *model, QModelIndex index = QModelIndex()) {

    int i = 0;

    for (; start_node != nullptr; start_node = static_cast<AST_node*>(start_node->next)) {
        QObject* item = new QObject();
        std::string nt = get_nodetype(start_node->nodetype);
        item->setProperty("objectName", QString::fromStdString(nt));

        model->appendItemToParent(item, i, index);
        std::cout << "appended" << std::endl;


        int j = 0;
        for (auto& subtree : start_node->subtrees) {
            if (subtree->nodetype < NodeT_CONSTANT) {

                auto middle_index = model->index(i, 0, index);
                QObject* item1 = new QObject();
                item1->setProperty("objectName", ((AST_leaf*)subtree)->value);
                model->appendItemToParent(item1, j, middle_index);
                j++;
            }
            else {
                draw_AST(static_cast<AST_node*>(subtree), model, model->index(i, 0, index));
            }
        }
        i++;
    }
}







/*
void draw_AST(AST_node* start_node, QObject* parent_item, ObjectTreeModel *model){
    if (start_node != nullptr){
        QObject* item = new QObject(parent_item);
        std::string nt = get_nodetype(start_node->nodetype);
        item->setProperty("objectName", QString::fromStdString(nt));

        // Обрабатываем поддеревья текущего узла AST
        for (auto& subtree : start_node->subtrees){
            if (subtree->nodetype < NodeT_CONSTANT){
                QObject* leafItem = new QObject(item);
                leafItem->setProperty("objectName", ((AST_leaf*)subtree)->value);
            }
            else {
                draw_AST((AST_node*)subtree, item, model);
            }
        }
        model->addItem(item, QModelIndex());
        // Обрабатываем следующий узел в текущем уровне AST
        if (start_node->next != nullptr){
            draw_AST((AST_node*)(start_node->next), parent_item, model);
        }
        //model->addItem(item, QModelIndex());
        //Добавляем элемент в модель, если он не имеет родителя
        if (parent_item == nullptr) {
           model->addItem(item, QModelIndex());
        }
    }
}
*/


MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);


    /*ObjectTreeModel *model = new ObjectTreeModel(this);

    QStringList cols;
    cols << "objectName";

    model->setColumns(cols);

    std::string example = "let r = 9; let z = 5;";
    //std::string example = "let r=9; if a==e {a=ss; let r=p;} else {let a=c;}";
    AST_node* start_node = get_AST(example);


    //std::string nt = get_nodetype(start_node->nodetype);
    //QObject* item = new QObject();
    //item->setObjectName(QString::fromStdString(nt));
    //QObject* pitem = new QObject();
    //pitem->setObjectName("AST_TREE");

    draw_AST(start_node, model);
    //model->addItem(pitem, QModelIndex());*/
/*
    QObject* item1 = new QObject();
    item1->setObjectName("var_decl");

    QObject* item2 = new QObject(item1);
    item2->setProperty("objectName", "var assign");

    QObject* item3 = new QObject(item2);
    item3->setProperty("objectName", "r");

    QObject* item4 = new QObject(item2);
    item4->setProperty("objectName", "9");

    model->addItem(item1, QModelIndex());



    QObject* item5 = new QObject();
    item5->setObjectName("var_decl");

    QObject* item6 = new QObject(item5);
    item6->setProperty("objectName", "var assign");

    QObject* item7 = new QObject(item6);
    item7->setProperty("objectName", "r");

    QObject* item8 = new QObject(item6);
    item8->setProperty("objectName", "9");

    model->addItem(item5, QModelIndex());
*/
    //QTreeView *tree = new QTreeView(this);

    //ui->treeView->setModel(model);




}

MainWidget::~MainWidget()
{
    delete ui;
}




void MainWidget::on_fileButton_clicked()
{
    QString fileName=QFileDialog::getSaveFileName(this, tr("Save Filename"),
                                                  ui->setLine->text(),
                                                  tr("Text Files(*.txt)"));
    if (!fileName.isEmpty())
        ui->setLine->setText(fileName);

        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly))
                return;
        QString file_content = file.readLine();
        file.close();
        ui->codeEdit->setText(file_content);

        std::string example = file_content.toStdString();
        AST_node* start_node = get_AST(example);

        ObjectTreeModel *model = new ObjectTreeModel(this);

        QStringList cols;
        cols << "objectName";

        model->setColumns(cols);

        draw_AST(start_node, model);
        ui->treeView->setModel(model);

}



void MainWidget::on_pushButton_clicked()
{
    QString file_content = ui->codeEdit->toPlainText();

    std::string example = file_content.toStdString();
    AST_node* start_node = get_AST(example);

    ObjectTreeModel *model = new ObjectTreeModel(this);

    QStringList cols;
    cols << "objectName";

    model->setColumns(cols);

    draw_AST(start_node, model);
    ui->treeView->setModel(model);
}

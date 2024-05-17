#include "mainwidget.h"
#include "ast_str.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;
    printf(">>> ");
    //std::string example;
    //example = "let r=9; if a==e {a=ss; let r=p;} else {let a=c;}";
    //example = "let r = 9;";
    //std::cout << *get_AST(example);
    //AST_node* start_node = get_AST(example);
    //print_tree(start_node);
    //std::cout << *(((AST_leaf*)((start_node->subtrees)[1]))->value) << std::endl;
    //char* aa = ((AST_leaf*)(((AST_node*)((start_node->subtrees)[0]))->subtrees[0]))->value;
    //std::cout << aa << std::endl;
    //std::cout << (((AST_node*)((start_node->subtrees)[0]))->subtrees).size() << std::endl;
    //std::cout << (start_node->next ==  nullptr)  << std::endl;
    //std::cout << NodeT::NT_ABS <<std::endl;
    //std::cout << (start_node->subtrees).size() << std::endl;
    //std::cout << ((start_node->subtrees)[0]) -> nodetype << std::endl;
    w.show();
    return a.exec();
}

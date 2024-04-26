#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "ast_str.h"
#include<vector>
#include<iostream>
int yyparse(void);

/* is the operator to create a subtree */
std::ostream& operator<<(std::ostream& ost, const AST_leaf& nd)
{
    ost << "\tLEAF, nodetype: " << nd.nodetype << ";   value: " << nd.value << ";" << std::endl;
    return ost;
}

std::ostream& operator<<(std::ostream& ost, const AST_node& nd)
{
    ost << "NODE, nodetype: " << nd.nodetype << std::endl;
    ost << "SUBTREES: " << std::endl;
    for(auto el : nd.subtrees){
        if(el->nodetype == NT_NUM or el->nodetype == NT_IDENT)
            ost << *(AST_leaf*)el;
        else {
            ost << *(AST_node*)el;
            ost << std::endl << "-----------------------------------------------------------" << std::endl;
        }

    }
    return ost;
}

AST_node *newast(int nodetype, std::vector<AST_base*> vec) {
    AST_node* nd1 = new AST_node;
    nd1->subtrees = vec;
    nd1->nodetype = nodetype;
    return nd1;
}

AST_leaf *newleaf(int nodetype, char* chr) {
  AST_leaf* lf = new AST_leaf;
  lf->nodetype = nodetype;
  lf->value = chr;
  return lf;
}



void yyerror(char *s, ...) {
  va_list ap;
  va_start(ap, s);
  fprintf(stderr, "%d: error: ", yylineno);
  vfprintf(stderr, s, ap);
  fprintf(stderr, "\n");
}

int main() {
  printf(">>> ");
  return yyparse();
}

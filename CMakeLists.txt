project(flex_bison_comp)
include_directories(include)

find_package(BISON)
find_package(FLEX)

BISON_TARGET(create_ast_parc create_ast.y src/create_ast.tab.cpp
             DEFINES_FILE include/create_ast.tab.h)
add_executable(Comp ../src/ast_str.cpp ../src/create_ast.tab.cpp)
FLEX_TARGET(create_ast_lex lexer_ast.l src/lex.yy.cpp)
add_executable(Comp ../src/lex.yy.cpp)


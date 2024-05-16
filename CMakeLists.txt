project(flex_bison_comp)
include_directories(include)

find_package(BISON)
find_package(FLEX)



BISON_TARGET(MyParser create_ast.y ${CMAKE_CURRENT_BINARY_DIR}/create_ast.tab.cpp
			DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/create_ast.tab.h)
FLEX_TARGET(MyScanner lexer_ast.l  ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.cpp)
ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)
include_directories(${CMAKE_CURRENT_BINARY_DIR})
 add_executable(Foo
    ./src/ast_str.cpp
    ./src/ast_test.cpp
    ${BISON_MyParser_OUTPUTS}
    ${FLEX_MyScanner_OUTPUTS}
 )
 target_link_libraries(Foo ${FLEX_LIBRARIES})

list(
    APPEND
    graphviz_list
    "${CMAKE_CURRENT_SOURCE_DIR}/WhileStatement.gv"
)

add_graphviz_target(${graphviz_list})

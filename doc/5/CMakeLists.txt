list(
    APPEND
    graphviz_list
    "${CMAKE_CURRENT_SOURCE_DIR}/DoWhileStatement.gv"
    "${CMAKE_CURRENT_SOURCE_DIR}/ForStatement.gv"
    "${CMAKE_CURRENT_SOURCE_DIR}/SwitchStatement.gv"
)

add_multiple_graphviz_targets(${graphviz_list})

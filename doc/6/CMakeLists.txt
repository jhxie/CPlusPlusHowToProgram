list(
    APPEND
    graphviz_list
    "${CMAKE_CURRENT_SOURCE_DIR}/FactorialConclusion.gv"
    "${CMAKE_CURRENT_SOURCE_DIR}/FactorialProcession.gv"
    "${CMAKE_CURRENT_SOURCE_DIR}/FibonacciProgression.gv"
)

add_multiple_graphviz_targets(${graphviz_list})

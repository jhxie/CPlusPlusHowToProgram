# Try to find 'GraphViz'.
#
# This will define the following variables:
#
# GRAPHVIZ_FOUND
# True if all the layout engines
# ("dot", "neato", "twopi", "circo", "fdp", "patchwork") are
# available.

set(_graphviz_found TRUE)
foreach(layout_engine "dot;neato;twopi;circo;fdp;patchwork")
    find_program(GRAPHVIZ NAMES ${layout_engine})
    if(${GRAPHVIZ} STREQUAL "GRAPHVIZ-NOTFOUND")
        set(_graphviz_found FALSE)
        break()
    endif()
endforeach()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(GraphViz
    FOUND_VAR
        GraphViz_FOUND
    REQUIRED_VARS
       _graphviz_found
)

unset(_graphviz_found)

include(FeatureSummary)
set_package_properties(GraphViz PROPERTIES
    URL "https://graphviz.org/"
    DESCRIPTION "Graphviz is open source graph visualization software."
)

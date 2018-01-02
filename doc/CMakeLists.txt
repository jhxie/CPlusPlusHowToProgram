# aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} PROJECT_SRCS)

find_package(GraphViz)

if(GraphViz_FOUND)
    foreach(sub_dir RANGE 4 22)
        add_subdirectory("${sub_dir}")
    endforeach()
endif()

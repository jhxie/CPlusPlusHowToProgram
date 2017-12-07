# aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} PROJECT_SRCS)

foreach(subdir RANGE 2 22)
    add_subdirectory("${subdir}")
endforeach()

# aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} PROJECT_SRCS)

# To turn-on static linking feature, uncomment the following 3 lines.
# SET(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
# SET(BUILD_SHARED_LIBRARIES OFF)
# SET(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")

list(APPEND
    executable_list
    "ArrayBraceInitialization.cpp"
    "ArrayConstantSize.cpp"
    "ArrayDieRolling.cpp"
    "ArrayGradeBarChart.cpp"
    "ArrayInitializationComparison.cpp"
    "ArrayLoopInitialization.cpp"
    "ArrayLoopRange.cpp"
    "ArrayMultidimensional.cpp"
    "ArraySortAndSearch.cpp"
    "ArraySum.cpp"
    "ArraySurveySummary.cpp"
    "VectorDemonstration.cpp"
)

add_multiple_executable_list(${executable_list})


list(APPEND
    gradebook_single_array_list
    "GradeBookSingleArrayTest.cpp"
    "GradeBookSingleArray.cpp"
)

add_executable_list(${gradebook_single_array_list})

list(APPEND
    gradebook_2d_array_list
    "GradeBook2DArrayTest.cpp"
    "GradeBook2DArray.cpp"
)

add_executable_list(${gradebook_2d_array_list})
add_subdirectory("exercises")

# target_link_libraries(main ${CMAKE_THREAD_LIBS_INIT})
# install(TARGETS main
# RUNTIME DESTINATION /usr/bin      COMPONENT Runtime)
# LIBRARY DESTINATION lib      COMPONENT Runtime
# ARCHIVE DESTINATION lib/main COMPONENT Development)

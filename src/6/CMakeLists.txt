# aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} PROJECT_SRCS)

# To turn-on static linking feature, uncomment the following 3 lines.
# SET(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
# SET(BUILD_SHARED_LIBRARIES OFF)
# SET(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")

list(APPEND
    executable_list
    "ArgumentDefault.cpp"
    "ArgumentPassing.cpp"
    "CubeVolumeInline.cpp"
    "DiceCraps.cpp"
    "DieFrequency.cpp"
    "DieNaive.cpp"
    "DieSimplePRNG.cpp"
    "DieStatisticalPRNG.cpp"
    "FactorialIterative.cpp"
    "FactorialRecursive.cpp"
    "FibonacciRecursive.cpp"
    "FunctionOverloading.cpp"
    "MaximumTest.cpp"
    "MaximumValue.cpp"
    "ScopeOperatorUnary.cpp"
    "ScopingRules.cpp"
)

# Switch off the warning for shadowing outer scope identifiers as it is
# intentional in this specific file.
# Reference:
# stackoverflow.com/questions/13638408/override-compile-flags-for-single-files
set_source_files_properties(
    "ScopeOperatorUnary.cpp"
    "ScopingRules.cpp"
    PROPERTIES
    COMPILE_FLAGS
    "-Wno-shadow"
)

add_multiple_executable_list(${executable_list})
# target_link_libraries(main ${CMAKE_THREAD_LIBS_INIT})
# install(TARGETS main
# RUNTIME DESTINATION /usr/bin      COMPONENT Runtime)
# LIBRARY DESTINATION lib      COMPONENT Runtime
# ARCHIVE DESTINATION lib/main COMPONENT Development)

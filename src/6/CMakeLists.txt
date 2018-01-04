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
if(UNIX)
    set(_no_shadow_flag_a "-Wno-shadow")
    set(_no_shadow_flag_b "")
endif()

# Does something similar but this is for Visual C++.
# Reference:
# docs.microsoft.com/en-us/cpp/build/reference/compiler-option-warning-level
# docs.microsoft.com/en-us/visualstudio/code-quality/c6244
# docs.microsoft.com/en-us/visualstudio/code-quality/c6246
if(WIN32)
    set(_no_shadow_flag_a "/wd6244")
    set(_no_shadow_flag_b "/wd6246")
endif()

set_source_files_properties(
    "ScopeOperatorUnary.cpp"
    "ScopingRules.cpp"
    PROPERTIES
    COMPILE_FLAGS
    ${_no_shadow_flag_a}
    ${_no_shadow_flag_b}
)

unset(_no_shadow_flag_a)
unset(_no_shadow_flag_b)

add_multiple_executable_list(${executable_list})
add_subdirectory("exercises")
# target_link_libraries(main ${CMAKE_THREAD_LIBS_INIT})
# install(TARGETS main
# RUNTIME DESTINATION /usr/bin      COMPONENT Runtime)
# LIBRARY DESTINATION lib      COMPONENT Runtime
# ARCHIVE DESTINATION lib/main COMPONENT Development)

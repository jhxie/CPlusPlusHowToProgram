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

list(APPEND
    no_shadow_warning_target_list
    "DieSimplePRNG"
    "ScopeOperatorUnary"
    "ScopingRules"
)

add_multiple_executable_list(${executable_list})

# Switch off the warning for shadowing outer scope identifiers as it is
# intentional in this specific file.
# Reference:
# stackoverflow.com/questions/13638408/override-compile-flags-for-single-files
if(UNIX)
    set(_no_shadow_flag_a "-Wno-shadow")
endif()

# Does something similar but this is for Visual C++.
# The last two only becomes effective under warning level 4.
# Reference:
# docs.microsoft.com/en-us/cpp/build/reference/compiler-option-warning-level
# docs.microsoft.com/en-us/visualstudio/code-quality/c6244
# docs.microsoft.com/en-us/visualstudio/code-quality/c6246
# /en-us/cpp/error-messages/compiler-warnings/compiler-warning-level-4-c4456
# /en-us/cpp/error-messages/compiler-warnings/compiler-warning-level-4-c4459
if(WIN32)
    set(_no_shadow_flag_a "/wd6244")
    set(_no_shadow_flag_b "/wd6246")
    set(_no_shadow_flag_c "/wd4456")
    set(_no_shadow_flag_d "/wd4459")
endif()

foreach(no_shadow_target ${no_shadow_warning_target_list})
    target_compile_options(
        ${no_shadow_target}
        PUBLIC
        ${_no_shadow_flag_a}
    )
    if(WIN32)
        target_compile_options(
            ${no_shadow_target}
            PUBLIC
            ${_no_shadow_flag_b}
            PUBLIC
            ${_no_shadow_flag_c}
            PUBLIC
            ${_no_shadow_flag_d}
        )
    endif()
endforeach()

unset(_no_shadow_flag_a)
if(WIN32)
    unset(_no_shadow_flag_b)
    unset(_no_shadow_flag_c)
    unset(_no_shadow_flag_d)
endif()

add_subdirectory("exercises")
# target_link_libraries(main ${CMAKE_THREAD_LIBS_INIT})
# install(TARGETS main
# RUNTIME DESTINATION /usr/bin      COMPONENT Runtime)
# LIBRARY DESTINATION lib      COMPONENT Runtime
# ARCHIVE DESTINATION lib/main COMPONENT Development)

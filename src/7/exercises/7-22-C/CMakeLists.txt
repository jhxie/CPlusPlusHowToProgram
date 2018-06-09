# aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} PROJECT_SRCS)

# To turn-on static linking feature, uncomment the following 3 lines.
# SET(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
# SET(BUILD_SHARED_LIBRARIES OFF)
# SET(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")

list(APPEND
    exercise_7_22_c_list
    "7-22-C.cpp"
    "EventLoop.cpp"
    "HeuristicBoard.cpp"
    "KnightBoard.cpp"
)

if(UNIX)
    set(_macro_prefix "-D")
endif()

if(WIN32)
    set(_macro_prefix "/D")
endif()

set_source_files_properties(
    ${exercise_7_22_c_list}

    PROPERTIES
    COMPILE_FLAGS
    "${_macro_prefix}PRINT_DEBUG_INFO"
)
unset(_macro_prefix)

add_executable_list(${exercise_7_22_c_list})

# target_link_libraries(main ${CMAKE_THREAD_LIBS_INIT})
# install(TARGETS main
# RUNTIME DESTINATION /usr/bin      COMPONENT Runtime)
# LIBRARY DESTINATION lib      COMPONENT Runtime
# ARCHIVE DESTINATION lib/main COMPONENT Development)

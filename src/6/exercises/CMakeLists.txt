# aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} PROJECT_SRCS)

# To turn-on static linking feature, uncomment the following 3 lines.
# SET(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
# SET(BUILD_SHARED_LIBRARIES OFF)
# SET(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")

list(APPEND
    exercises_executable_list
    "6-11.cpp"
    "6-12.cpp"
    "6-13.cpp"
    "6-14.cpp"
    "6-17.cpp"
    "6-23.cpp"
    "6-28.cpp"
    "6-29.cpp"
    "6-30.cpp"
    "6-36.cpp"
    "6-38.cpp"
)

add_multiple_executable_list(${exercises_executable_list})

# target_link_libraries(main ${CMAKE_THREAD_LIBS_INIT})
# install(TARGETS main
# RUNTIME DESTINATION /usr/bin      COMPONENT Runtime)
# LIBRARY DESTINATION lib      COMPONENT Runtime
# ARCHIVE DESTINATION lib/main COMPONENT Development)

# Compile a single executable with base name specified in the first element of
# the list given; the rest of the elements are treated as different translation
# units associated with the final output.
function(add_executable_list)

    if(${ARGC} EQUAL "0")
        message(WARNING "No Argument Passed to 'add_executable_list'")
        return()
    endif()

    list(GET ARGV 0 exec_name)

    get_filename_component(exe_target ${exec_name} NAME_WE)
    add_executable(${exe_target} ${ARGV})
    if(CMAKE_BUILD_TYPE MATCHES "Debug")
        target_compile_definitions(
            ${exe_target}
            PRIVATE
            PRINT_DEBUG_INFO=1
        )
    endif()
    # target_link_libraries(${exe_target} "m")
endfunction()

# Compile all the source files with base name set as the output target name;
# i.e. each executable corresponds to one file in 'ARGV'.
# For example; a list argument of "a.cpp", "b.cpp", "c.cpp" would be considered
# three separate targets named "a", "b", and "c", respectively.
function(add_multiple_executable_list)
    foreach(exec_single_source_file ${ARGV})
        add_executable_list(${exec_single_source_file})
    endforeach()
endfunction()

# Invoke 'Graphviz' drawing software to draw the graph specified in the first
# element of input (prefixed by absolute path).
# The rest of the arguments are optional.
#
# NOTE:
# A custom target with the same base name as ARGV[0] would be created.
# For example, the invocation
# 'add_graphviz_target("/home/user/projects/graphviz_experiment/test.gv")'
# would create a target named 'test.gv'; this also implies that there cannnot
# be another file with the exact same name in a project regardless of which
# subdirectory it resides.
#
# ARGV[1] - layout engine
# If given, use the layout engine specified rather than the default 'dot'.
# Available options are ('man 7 graphviz' on Debian for further information):
# dot       filter for hierarchical layouts of graphs
# neato     filter for symmetric layouts of graphs
# twopi     filter for radial layouts of graphs
# circo     filter for circular layout of graphs
# fdp       filter for symmetric layouts of graphs
# patchwork filter for drawing clustered graphs as treemaps
#
# ARGV[2] - output format
# If given, use the specified output format rather than the default 'png'.
#
# ARGV[3..] - extra command line flags
# If given, these flags are passed directly to the layout engine.
function(add_graphviz_target)
    if(${ARGC} EQUAL "0")
        message(WARNING "No Argument Passed to 'add_graphviz_target'")
        return()
    endif()

    list(GET ARGV 0 gv_input_file)
    list(
        APPEND
        gv_layout_engine_list
        "dot"
        "neato"
        "twopi"
        "circo"
        "fdp"
        "patchwork"
    )

    foreach(layout_engine ${gv_layout_engine_list})
        find_program(GRAPHVIZ NAMES ${layout_engine})
        if(${GRAPHVIZ} STREQUAL "GRAPHVIZ-NOTFOUND")
            message(WARNING "Layout engine '${layout_engine}' is not found")
            return()
        endif()
    endforeach()

    get_filename_component(gv_output_file_base ${gv_input_file} NAME_WE)
    get_filename_component(gv_input_file_format ${gv_input_file} EXT)
    set(gv_output_file_path "${CMAKE_CURRENT_BINARY_DIR}")
    # get_filename_component(gv_output_file_path ${gv_input_file} DIRECTORY)

    if(${ARGC} GREATER "1")
        list(GET ARGV 1 gv_layout_engine)
        if (NOT ${gv_layout_engine} IN_LIST gv_layout_engine_list)
            message(
                WARNING
                "${gv_layout_engine} is not a valid layout engine, "
                "reset to 'dot'")
        endif()
    else()
        set(gv_layout_engine "dot")
    endif()

    if(${ARGC} GREATER "2")
        list(GET ARGV 2 gv_output_format)
    else()
        set(gv_output_format "png")
    endif()

    # The built-in '-O' flag would attach an extra file extension besides
    # the original; so '-o' is used instead.
    set(
        gv_output_file
        "${gv_output_file_path}/${gv_output_file_base}.${gv_output_format}"
    )

    # Handle Extra command line options.
    if(${ARGC} GREATER "3")
        # Remove the first three elements - range is [0, 2].
        foreach(counter RANGE 2)
            list(REMOVE_AT ARGV 0)
        endforeach()
    else()
        set(ARGV "")
    endif()

    add_custom_command(
        OUTPUT
        ${gv_output_file}
        COMMAND
        ${gv_layout_engine}
        "-T${gv_output_format}"
        "${gv_input_file}"
        "-o"
        "${gv_output_file}"
        "${ARGV}"
        DEPENDS
        ${gv_input_file}
    )
    add_custom_target(
        "${gv_output_file_base}${gv_input_file_format}"
        # The following conflicts with the output file itself; thus it cannot
        # be used as a target.
        # The 'Ninja' build system reports this error.
        #"${gv_output_file_base}.${gv_output_format}"
        ALL
        DEPENDS
        ${gv_output_file}
    )
endfunction()

# Invoke 'Graphviz' drawing software to draw all the graph(s) specified
# (prefixed by absolute path(s)).
function(add_multiple_graphviz_targets)
    foreach(graphviz_target ${ARGV})
        add_graphviz_target(${graphviz_target})
    endforeach()
endfunction()

project(tools)

include_directories(include)

aux_source_directory(src TOOLS_SRC)

add_library(tools ${TOOLS_SRC})
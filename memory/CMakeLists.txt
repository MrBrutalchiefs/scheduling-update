project(memory)

include_directories(include)

aux_source_directory(src MEMORY_SRC)

add_library(memory ${MEMORY_SRC})
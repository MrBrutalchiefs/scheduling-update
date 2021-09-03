project(erasure)

include_directories(include)

aux_source_directory(src ERASURE_SRC)

add_library(erasure ${ERASURE_SRC})
target_link_libraries(erasure tools)
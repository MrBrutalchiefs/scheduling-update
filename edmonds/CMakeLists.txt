project(edmonds)

include_directories(include)

aux_source_directory(src EDMONDS_SRC)

add_library(edmonds ${EDMONDS_SRC})
target_link_libraries(edmonds tools)
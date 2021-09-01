project(tabu)

include_directories(include)

aux_source_directory(src TABU_SRC)

add_library(tabu ${TABU_SRC})
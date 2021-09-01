project(algorithm)

include_directories(include)

aux_source_directory(src ALGORITHM_SRC)

add_library(algorithm ${ALGORITHM_SRC})
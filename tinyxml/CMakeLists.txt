project(tinyxml)

include_directories(include)

aux_source_directory(src TINYXML_SRC)

add_library(tinyxml ${TINYXML_SRC})
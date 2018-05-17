file(GLOB DATA_STRUCTURE_SOURCES container/*.c utils.c)
file(GLOB ALGORITHM_SOURCES algorithm/*.c)
add_library(generic ${DATA_STRUCTURE_SOURCES} ${ALGORITHM_SOURCES})

file(GLOB DATA_STRUCTURE_SOURCES data_structure/*.c utils.c)
file(GLOB ALGORITHM_SOURCES algorithm/*.c)
add_library(generic ${DATA_STRUCTURE_SOURCES} ${ALGORITHM_SOURCES})

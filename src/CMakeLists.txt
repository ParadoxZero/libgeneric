<<<<<<< HEAD

add_library(st_data_structure data_structure/data_stucture.c)


add_library(st_list data_structure/list.c)
target_link_libraries(st_list st_data_structure)

add_library(st_stack data_structure/stack.c)
target_link_libraries(st_stack st_list st_data_structure)

add_library(st_utils utils.c)
=======
file(GLOB DATA_STRUCTURE_SOURCES data_structure/*.c utils.c)
add_library(generic ${DATA_STRUCTURE_SOURCES})
>>>>>>> 2196f83... Organize code into one library

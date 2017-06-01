
add_library(st_data_structure data_structure/st_data_stucture.c)


add_library(st_list data_structure/st_list.c)
target_link_libraries(st_list st_data_structure)

add_library(st_stack data_structure/stack.c)
target_link_libraries(st_stack st_list st_data_structure)


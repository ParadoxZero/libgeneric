
add_library(st_list data_structure/st_list.c)

add_library(st_stack data_structure/stack.c)
target_link_libraries(st_stack st_list)
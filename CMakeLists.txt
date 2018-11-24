cmake_minimum_required(VERSION 2.8)
project(training_algorithm)

#group
add_executable(group_path_compression_by_having group/path-compression-by-having.cpp)
add_executable(group_quick_find_algorithm group/quick-find_algorithm.cpp)
add_executable(group_quick_union_algorithm group/quick-union_algorithm.cpp)
#list
add_executable(list-josephus list/Josephus.cpp)
#prime
add_executable(prime_eratoth prime/Eratoth.cpp)
#sort
add_executable(sort_bubble sort/bubble_sort.cpp)
add_executable(sort_comb sort/comb_sort.cpp)
add_executable(sort_heap sort/heap_sort.cpp)
add_executable(sort_insertion sort/insertion_sort.cpp)
add_executable(sort_merge sort/merge_sort.cpp)
add_executable(sort_quick sort/quick_sort.cpp)
add_executable(sort_radix sort/radix_sort.cpp)
add_executable(sort_selection sort/selection_sort.cpp)
#stack
add_executable(stack_make_ten stack/Make-Ten.cpp)
add_executable(stack_reverse stack/Reverse-Polish-Notion.cpp)
#tree
add_executable(tree_minimum tree/minimum_tree.cpp)

#other
add_executable(Euclidean_method other/Euclidean-method-of-mutual-division.cpp)
add_executable(fibonacci other/Fibonacci-number.cpp)
add_executable(gaussuru other/gausssuru.cpp)


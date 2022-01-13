//
// Created by Gianluca Cognigni on 07/12/21.
//

#ifndef LABORATORIO_ALGORITMI_2020_2021_GIANLUCA_COGNIGNI_MERGE_BINARY_INSERTION_SORT_H
#define LABORATORIO_ALGORITMI_2020_2021_GIANLUCA_COGNIGNI_MERGE_BINARY_INSERTION_SORT_H

void merge_binary_insertion_sort(void **array, int left_bound, int right_bound, int k, int (*compare)(void *, void *));

void binary_insertion_sort(void **array, int left_bound, int right_bound, int (*compare)(void*, void*));

void merge_binary_insertion_sort_entry(void **array,int array_size,int k,int (*compare)(void*,void*));


#endif //LABORATORIO_ALGORITMI_2020_2021_GIANLUCA_COGNIGNI_MERGE_BINARY_INSERTION_SORT_H

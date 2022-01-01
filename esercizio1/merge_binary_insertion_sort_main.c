#include "merge_binary_insertion_sort.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

#define BUFFER_SIZE  1024
#define STRING_SIZE  16
#define FILEDATASIZE  20000000

typedef struct _Record {

    int id;
    char* first_field;
    int second_field;
    float third_field;

}Record;


int load_array (Record** record,char* filename){
    char read_line[BUFFER_SIZE];

    int new_id;
    char new_field1[STRING_SIZE];
    int new_field2;
    float new_field3;

    Record* new_record;
    int pos_loaded = 0;

    if (filename == NULL){
        fprintf(stderr,"File name is null");
    }

    FILE * fp = fopen(filename,"r");
    if (fp == NULL){
        fprintf(stderr,"Unable to open file %s",filename);
    }

    while (fgets(read_line,BUFFER_SIZE,fp) != NULL){
        new_id = atoi(strtok(read_line,","));
        strcpy(new_field1,strtok(NULL,","));
        new_field2 = atoi(strtok(NULL,","));
        new_field3 = atof(strtok(NULL,","));

        new_record = (Record*) malloc(sizeof(Record));

        if (new_record == NULL){
            fprintf(stderr,"Unable to allocate memory for next record");
        }

        new_record->id = new_id;
        new_record->first_field = (char*)malloc(sizeof(char) * (strlen(new_field1) + 1));
        strcpy(new_record->first_field,new_field1);
        new_record->second_field = new_field2;
        new_record->third_field = new_field3;

        record[pos_loaded++] = new_record;

    }

    return pos_loaded;
}

int create_array(Record*** array, char* filename){
    *array = (Record**) malloc(sizeof(Record*) * FILEDATASIZE);

    if (*array == NULL){
        fprintf(stderr,"Unable to allocate memory");
    }

    return load_array(*array,filename);

}


int precedes_record_string_first_field(void* one_record, void* another_record) {

    if(one_record == NULL) {
        printf("first record in comparison is null");
        exit(0);
    }

    if(another_record == NULL) {
        printf("second record in comparison is null");
        exit(0);
    }

    Record* to_compare_record1 = (Record*) one_record;
    Record* to_compare_record2 = (Record*) another_record;

    if((strcmp(to_compare_record1->first_field, to_compare_record2->first_field)<0))
        return (1);
    return (0);

}


int precedes_record_int_second_field(void* one_record, void* another_record) {

    if(one_record == NULL) {
        printf("first record in comparison is null");
        exit(0);
    }

    if(another_record == NULL) {
        printf("second record in comparison is null");
        exit(0);
    }

    Record* to_compare_record1 = (Record*) one_record;
    Record* to_compare_record2 = (Record*) another_record;

    if(to_compare_record1->second_field < to_compare_record2->second_field)
        return (1);
    else if(to_compare_record1->second_field > to_compare_record2->second_field)
        return (-1);
    else
        return (0);

}






int precedes_record_float_third_field(void* one_record, void* another_record) {

    if(one_record == NULL) {
        printf("first record in comparison is null");
        exit(0);
    }

    if(another_record == NULL) {
        printf("second record in comparison is null");
        exit(0);
    }

    Record* to_compare_record1 = (Record*) one_record;
    Record* to_compare_record2 = (Record*) another_record;

    if(to_compare_record1->third_field < to_compare_record2->third_field)
        return (1);
    return (0);

}















void free_array_first_field(Record** array, int size){
    int i;
    for (i = 0; i < size ; i++){
        free(array[i]->first_field);
    }
}


void free_array(Record** array, int size){
    int i;
    for (i = 0; i < size ; i++){
        free(array[i]);
    }
    free(array);
}






void sort_array(Record** array, int size, int k){
    long msec0 = 0;
    long msec1 = 0;
    long msec2 = 0;



    clock_t first_clock_start = clock();
    merge_binary_insertion_sort_entry((void**)array,size,k, &precedes_record_string_first_field);
    msec0 = (clock()-first_clock_start) *1000 / CLOCKS_PER_SEC;
    printf("Sorting of first_field completed after %ld ms\n",msec0);

    //free_array_first_field(array,size);

    clock_t second_clock_start = clock();
    merge_binary_insertion_sort_entry((void**)array,size,k,&precedes_record_int_second_field);
    msec1 = (clock()-second_clock_start) *1000 / CLOCKS_PER_SEC;
    printf("Sorting of second_field completed after %ld ms\n",msec1);

    //free_array_second_field(array,size);


    clock_t third_clock_start = clock();
    merge_binary_insertion_sort_entry((void**)array,size,k, &precedes_record_float_third_field);
    msec2 = (clock()-third_clock_start) *1000 / CLOCKS_PER_SEC;
    printf("Sorting of third_field completed after %ld ms\n",msec2);


    //free_array(array, size);

}





int main(){
    Record **array;
    int array_size;
    char filename[STRING_SIZE];
    int k;

    printf("Insert the name of the file containing all records to sort: \n");
    scanf("%s", filename);

    printf("Insert the value of k: \n");
    scanf("%d", &k);

    array_size = create_array(&array,filename);

    sort_array(array,array_size,k);

    //print_array(array,array_size);

    //free(array);
    //free_array(array,array_size);

    exit(0);
}

//read file
//load each data point into a Record
//create array
//load each datapoint onto the array
//WTF IS WRONG !!!EIOWNDANLDNADIANSKDABSND





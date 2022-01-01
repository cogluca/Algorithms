#include "merge_binary_insertion_sort.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

#define BUFFER_SIZE  1024
#define STRING_SIZE  16
#define FILEDATASIZE  20000000
#define FILENAMESIZE 300

typedef struct _Record {

    int id;
    char* first_field;
    int second_field;
    float third_field;

}Record;



/**
 * Opens file through path given in input, incapsulates the data in a Record struct and feeds it into an array
 * @param record array
 * @param filename file path
 * @return returns size of array - 1
 */
int load_array (Record** record,char* filename){
    char read_line[BUFFER_SIZE];

    Record* new_record;

    int data_position = 0;

    int new_id;
    char new_field_one[STRING_SIZE];
    int new_field_two;
    float new_field_three;


    if (filename == NULL){
        fprintf(stderr,"Filename is null - during array loading");
    }

    FILE * fp = fopen(filename,"r");
    if (fp == NULL){
        fprintf(stderr,"Unable to open file %s during array loading",filename);
    }

    while (fgets(read_line,BUFFER_SIZE,fp) != NULL){


        new_id = atoi(strtok(read_line,","));
        strcpy(new_field_one, strtok(NULL, ","));
        new_field_two = atoi(strtok(NULL, ","));
        new_field_three = atof(strtok(NULL, ","));

        new_record = (Record*) malloc(sizeof(Record));

        if (new_record == NULL){
            fprintf(stderr,"Unable to allocate memory for next record during array loading");
        }

        new_record->id = new_id;
        new_record->first_field = (char*)malloc(sizeof(char) * (strlen(new_field_one) + 1));
        strcpy(new_record->first_field, new_field_one);
        new_record->second_field = new_field_two;
        new_record->third_field = new_field_three;

        record[data_position++] = new_record;

    }

    return data_position;
}

/**
 * Wrapper method that allocates necessary memory to array and feeds array into load method for data filling
 * @param array pristine array, still to allocate memory
 * @param filename file path necessary to feed data onto array
 * @return returns size of array - 1
 */
int create_array(Record*** array, char* filename){
    *array = (Record**) malloc(sizeof(Record*) * FILEDATASIZE);

    if (*array == NULL){
        fprintf(stderr,"Unable to allocate memory");
    }

    return load_array(*array,filename);

}

// Comparator function for strings, makes use of string library methods
int precedes_record_string_first_field(void* one_record, void* another_record) {

    if(one_record == NULL) {
        printf("first record  has null value during comparison");
        exit(0);
    }

    if(another_record == NULL) {
        printf("second record  has null value during comparison");
        exit(0);
    }

    Record* to_compare_record1 = (Record*) one_record;
    Record* to_compare_record2 = (Record*) another_record;

    if((strcmp(to_compare_record1->first_field, to_compare_record2->first_field)<0))
        return (1);
    if((strcmp(to_compare_record1->first_field, to_compare_record2->first_field)>0))
        return(-1);
    return (0);

}

//Comparator method for integers

int precedes_record_int_second_field(void* one_record, void* another_record) {

    if(one_record == NULL) {
        printf("first record  has null value during comparison");
        exit(0);
    }

    if(another_record == NULL) {
        printf("second record has  null value during comparison");
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



//Comparator function for float types


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
    if(to_compare_record1->third_field > to_compare_record2->third_field)
        return (-1);
    return (0);

}















void free_array_first_field(Record** array, int size){
    int i;
    for (i = 0; i < size ; i++){
        free(array[i]->first_field);
    }
}

//Frees array memory

void free_array(Record** array, int size){
    int i;
    for (i = 0; i < size ; i++){
        free(array[i]);
    }
    free(array);
}




/**
 * Sorting wrapper, executes 3 sortings one for each type of data (string, int, float) and registers execution time extremely dependent on k value
 * @param array actual array to be sorted
 * @param size size of array, necessary for boundary calculations
 * @param k internal sorting mechanism parameter, decides size of subarray onto which apply binary insertion sort
 */

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



/**
 * Main method
 * @return
 */

int main(){
    Record **array;
    int array_size;
    char filename[FILENAMESIZE];
    int k;

    printf("Insert datasheet name: \n");
    scanf("%s", filename);

    printf("Insert value of k: \n");
    scanf("%d", &k);

    array_size = create_array(&array,filename);

    sort_array(array,array_size,k);

    free_array(array,array_size);

    return 0;
}

//read file
//load each data point into a Record
//create array
//load each datapoint onto the array
//WTF IS WRONG !!!EIOWNDANLDNADIANSKDABSND





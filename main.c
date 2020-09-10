#include "readerwriter.h"

int main(int argc, char *argv[]) {
    if (argc != 3){
    	printf("Incorrect number of arguments: ./rwmain #readloops #writeloops\n");
    	exit(1);
    }  

    //initialize lock with struct
    rwlock_init(&mutex);

    FILE* ptr = fopen("scenarios.txt", "r");
    char* ptr1;

    if(ptr == NULL)
        return NULL;

    ptr1 = malloc(1000);

    int check, num;
    do{  
        ptr1[num++] = check;        
    }while((check = fgetc(ptr)) != EOF);

    pthread_t my_thread[num];

    int total_read_threads = 0;
    int total_write_threads = 0;

    for(int i = 0; i < num; i++){
             if(ptr1[i] == 'r'){
                 pthread_create(&my_thread[i], NULL, reader, &mutex);
                 total_read_threads++;
             }else{
                 pthread_create(&my_thread[i], NULL, writer, &mutex);
                 total_write_threads++;
             }
    }//end for

    for(int i = 0; i < num; i++){
            pthread_join(my_thread[i], NULL);
    }

    printf("Total Read threads: %d\n", total_read_threads);
    printf("Total Write threads: %d\n", total_read_threads);
    printf("all done\n");
    return 0;
}

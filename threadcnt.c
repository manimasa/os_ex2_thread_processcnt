#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_THREADS 9

void* pthread_cnt(void* thread_id)
{
    int *id = (int *) thread_id;
    
    printf("[thread] nr %d starting\n", *id);
    int i;
    for( i = 0; i < 100000000; i++){
        /* CPU workout */
    }
    
    printf("[thread] nr %d finished\n", *id);
    
    return NULL;
}


int main(int argc, char* argv)
{
    void* pthread_cnt(void* thread_id);
    pthread_t thread[NUM_THREADS];
    int thread_id[NUM_THREADS];
    
    int id;
    for(id = 0; id < NUM_THREADS; id++){
        if(pthread_create(&thread[id], NULL, pthread_cnt, &id)){
            fprintf(stderr, "Error creating thread");
            return 1;
        }
    }
    
    
    printf("[thread] nr %d starting\n", id+1);
    int i;
    for( i = 0; i < 100000000; i++){
        /* CPU workout */
    }
    printf("[thread] nr %d finished\n", id+1);
    
    int b;
    for( b = 0; b < NUM_THREADS; b++){
        if(pthread_join(thread[b], NULL)){
            fprintf(stderr, "Error joining thread");
            return 2;
        }
    }
}
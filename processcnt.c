#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>


#define SIZE 400

void cnt(int id)
{
    char buf[SIZE];
    sprintf(buf, "[process] nr %d starting\n", id+1);
    write(1, buf, strlen(buf));
    int i;
    for( i = 0; i < 100000000; i++){
        /* CPU workout */
    }
    sprintf(buf, "[process] nr %d finished\n", id+1);
    write(1, buf, strlen(buf));
}


int main(int argv, char* argc[])
{
    pid_t pid;
    int i;
    
    
    for( i = 0; i < 9; i++){
        pid = fork();
        if(pid == 0){
            cnt(i);
            exit(0);
        } 
    }
    cnt(i);
    int status;
    for( status = 0; status < 9; status++){
        pid = wait(&status);
    }
}
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>     /* sleep */
#include <string.h>     

// compile: g++ -D _REENTRANT pthread_demo.cpp -lpthread

/* intptr_t
https://stackoverflow.com/questions/19527965/cast-to-pointer-from-integer-of-different-size-pthread-code
*/

#define NUMBER_OF_THREADS 5

void * thread_func1(void *tid)
{
    /* This function prints the thread’s identifier and then exits. */
    printf("Greetings from thread %d\n", (int) (intptr_t) tid);
    
    sleep(1);

    // To not return anything: pthread_exit(NULL)
    pthread_exit((void *) "Finished");
}


int main(int argc, char *argv[])
{
    /* The main program creates 5 threads and then exits. */
    pthread_t threads[NUMBER_OF_THREADS];
    int status, i;
    for(i=0; i < NUMBER_OF_THREADS; i++) {
        printf("Creating thread %d\n", i);

        // If we wanted to pass char pointer as argument in pthread_create: just (char *)
        status = pthread_create(&threads[i], NULL, thread_func1, (void *) (intptr_t) i);
        if (status != 0) {
            printf("Pthread_create returned error code %d\n", status);
            exit(EXIT_FAILURE);
        }
    }

    for(i=0; i < NUMBER_OF_THREADS; i++) {
        void *thread_result;
        status = pthread_join(threads[i], &thread_result);

        if (status != 0) {
            perror("Thread join failed");
            exit(EXIT_FAILURE);
        }
        printf("Thread joined, it returned %s\n", (char *)thread_result);
    }    
    exit(EXIT_SUCCESS);
}
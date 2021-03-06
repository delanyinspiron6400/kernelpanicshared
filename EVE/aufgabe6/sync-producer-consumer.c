/*****************************************************************************
 **
 **
 ** Expected Behaviour:
 ** This is a classical producer-consumer problem!
 ** No Consumer should consume a product, before it has been produced by
 ** a Producer! :D
 **
 **
 ****************************************************************************/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>


#define BUFF_SIZE   5           /* total number of slots */
#define NP          1           /* total number of producers */
#define NC          1           /* total number of consumers */
#define NITERS      10           /* number of items produced/consumed */

typedef struct
{
    int buf[BUFF_SIZE];   /* shared var */
    int in;               /* buf[in%BUFF_SIZE] is the first empty slot */
    int out;              /* buf[out%BUFF_SIZE] is the first full slot */    
} sbuf_t;

sbuf_t shared;


sem_t spaces;           /* keep track of the number of available spaces in buffer */
sem_t items;          	/* keep track of the number of items */
pthread_mutex_t mutex;  /* enforce mutual exclusion to shared data */


void *Producer(void *arg)
{
    int i, item, index;

    index = (int)arg;
    for (i=0; i < NITERS; i++)
    {
        item = i;                                   // Produce an item

        sem_wait(&spaces);                          // Decrement the number of free spaces
        pthread_mutex_lock(&mutex);                 // Get access to shared data

        shared.buf[shared.in] = item;
        shared.in = (shared.in+1)%BUFF_SIZE;
        printf("[P%d] Producing %d ...\n", index, item);

        pthread_mutex_unlock(&mutex);               // Release mutual exclusion to shared data
        sem_post(&items);                           // increment Number of items
        sleep(1);
    }
    return NULL;
}

void *Consumer(void *arg)
{
    int i, item, index;

    index = (int)arg;
    for (i=NITERS; i > 0; i--) {
        sem_wait(&items);                           // Wait for an item
        pthread_mutex_lock(&mutex);                 // Get access to shared data

        item=i;
        item=shared.buf[shared.out];
        shared.out = (shared.out+1)%BUFF_SIZE;
        printf("[C%d] Consuming %d ...\n", index, item);

       
        pthread_mutex_unlock(&mutex);               // Release mutual exlusion to shared data
        sem_post(&spaces);                          // increment Number of free spaces

        sleep(1);
    }
    return NULL;
}

int main()
{
    pthread_t idP, idC;
    int index;

    sem_init(&items, 0, 0);
    sem_init(&spaces, 0, BUFF_SIZE);
    pthread_mutex_init(&mutex, NULL);

    printf("\nSync-Producer-Consumer.sweb\n\n");
    printf("A possible solution to the producer-consumer problem using semaphores and mutexes.\n");

    for (index = 0; index < NP; index++)
    {
        /* Create a new producer */
        pthread_create(&idP, NULL, Producer, (void*)index);
    }

    for(index=0; index<NC; index++)
    {
      /*create a new Consumer*/
      pthread_create(&idC, NULL, Consumer, (void*)index);
    }

    for (index = 0; index < NP; index++)
      pthread_join(idP, NULL);

    for(index=0; index<NC; index++)
      pthread_join(idC,NULL);

    return 0;
}

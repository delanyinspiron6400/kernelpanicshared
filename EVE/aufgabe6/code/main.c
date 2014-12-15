#define BUFF_SIZE   5   /* total number of slots */
#define NP          1   /* total number of producers */
#define NC          1   /* total number of consumers */
#define NITERS      10  /* number of items produced/consumed */
sem_t spaces;           /* number of available spaces in buffer */
sem_t items;            /* number of items */
pthread_mutex_t mutex;  /* mutual exclusion to shared data */

int main()
{
    pthread_t idP, idC;
    int index;

    sem_init(&items, 0, 0);
    sem_init(&spaces, 0, BUFF_SIZE);
    pthread_mutex_init(&mutex, NULL);
    
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
    // Join on all threads in the end!
    return 0;
}
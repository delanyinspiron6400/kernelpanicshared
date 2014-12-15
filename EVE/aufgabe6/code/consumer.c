void *Consumer(void *arg)
{
    int i, item, index;

    index = (int)arg;
    for (i = NITERS; i > 0; i--) {
        sem_wait(&items);                 // Wait for an item
        pthread_mutex_lock(&mutex);       // Get access to shared data

        item = i;
        item = shared.buf[shared.out];
        shared.out = (shared.out+1)%BUFF_SIZE;
        printf("[C%d] Consuming %d ...\n", index, item);

       
        pthread_mutex_unlock(&mutex);      // Release mutex to shared data
        sem_post(&spaces);                 // increment Number of free spaces

        sleep(1);
    }
    return NULL;
}
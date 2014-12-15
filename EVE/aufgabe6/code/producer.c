void *Producer(void *arg)
{
    int i, item, index;

    index = (int)arg;
    for (i=0; i < NITERS; i++)
    {
        item = i;                     // Produce an item

        sem_wait(&spaces);            // Decrement the number of free spaces
        pthread_mutex_lock(&mutex);   // Get access to shared data

        shared.buf[shared.in] = item;
        shared.in = (shared.in+1)%BUFF_SIZE;
        printf("[P%d] Producing %d ...\n", index, item);

        pthread_mutex_unlock(&mutex);  // Release mutex to shared data
        sem_post(&items);              // increment Number of items
        sleep(1);
    }
    return NULL;
}
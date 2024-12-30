#include <pthread.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>

pthread_mutex_t count_mutex;
bool stop = false;

void *increment_routine(void *arg)
{
    int *count = (int *)arg;

    while (1)
    {
        pthread_mutex_lock(&count_mutex);

        usleep(50000);

        if (stop || *count > 10)
        {
            stop = true;
            pthread_mutex_unlock(&count_mutex);
            break;
        };

        (*count)++;
        pthread_mutex_unlock(&count_mutex);

        printf("inc, count:%d\n", *count);
    };

    return 0;
}

void *decrement_routine(void *arg)
{
    int *count = (int *)arg;

    while (1)
    {
        pthread_mutex_lock(&count_mutex);

        usleep(50000);

        if (stop || *count < -10)
        {
            stop = true;
            pthread_mutex_unlock(&count_mutex);
            break;
        };

        (*count)--;
        pthread_mutex_unlock(&count_mutex);

        printf("dec, count:%d\n", *count);
    };

    return 0;
}

int main(int argc, char *argv[])
{
    pthread_t increment_thread;
    pthread_t decrement_thread;

    pthread_mutex_init(&count_mutex, NULL);

    int count = 0;

    pthread_create(&increment_thread, NULL, increment_routine, (void *)&count);
    pthread_create(&decrement_thread, NULL, decrement_routine, (void *)&count);

    pthread_join(increment_thread, NULL);
    pthread_join(decrement_thread, NULL);

    pthread_mutex_destroy(&count_mutex);

    char action[10];

    if (count > 0)
    {
        strcpy(action, "increment");
    }
    else
    {
        strcpy(action, "decrement");
    }

    printf("Winner action: %s\n", action);

    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:18:30 by hachahbo          #+#    #+#             */
/*   Updated: 2023/05/13 15:11:17 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include <unistd.h>
#include "../philosophers.h"

// int main()
// {
// 	int i;

// 	i = 0;
// 	printf("sleeping for 1 second : \n");
// 	while(i <= 10)
// 	{
// 		printf("%d\n", i);
// 		usleep(1000000);
// 		i++;
// 	}
// 	return (0);
// }

// int main()
// {
// 	struct timeval tv;

// 	gettimeofday(&tv, NULL);
// 	printf("with qsecond : %ld || with micro_second : %d \n", tv.tv_sec, tv.tv_usec);
// 	return (0);	
// }
// int primes[10] = {2 , 3, 5, 7, 11, 13, 17, 19, 3, 29}
// //pthread_mutex_t mutex;

// void *routine(void* av)
// {
	
// 	printf("%d", primes)
// 	// while(i < 100000)
// 	// {
// 	// 	pthread_mutex_lock(&mutex);
// 	// 	x++;
// 	// 	i++;
// 	// 	pthread_mutex_unlock(&mutex);
// 	// }
// 	// printf("teste from threads\n");
// 	// sleep(3);
// 	// printf("ending threads\n");
// }

// int main(int ac ,char **av)
// {
// 	pthread_t th[8];
// 	int i = 0;

// 	pthread_mutex_init(&mutex, NULL);
// 	while(i < 8)
// 	{
// 		if(pthread_create(th + i, NULL, &routine, NULL) != 0)
// 			return 1;
// 		printf("philospher number [%d] is eating \n",i+1);
// 		i++;
// 	}
// 	i = 0;
// 	while(i < 8)
// 	{
// 		if(pthread_join(th[i], NULL)!= 0)
// 			return 3;
// 		printf("philosopher number [%d] is  sleeping\n",i+1);
// 		i++;
// 	}
// 	pthread_mutex_destroy(&mutex);
// 	printf(" number of mails : %d\n", x);
// 	return(0);
// }

#include <stdio.h>
#include <pthread.h>

typedef struct {
    int arg1;
    char arg2;
} ThreadArgs;

void *myThread(void *arg) {
    ThreadArgs *threadArgs = (ThreadArgs*) arg;
    printf("Thread argument 1: %d\n", threadArgs->arg1);
    printf("Thread argument 2: %c\n", threadArgs->arg2);
    return NULL;
}

int main() {
    pthread_t thread;
    ThreadArgs args = { 123, 'a' };
    pthread_create(&thread, NULL, myThread, &args);
    pthread_join(thread, NULL);
    return 0;
}
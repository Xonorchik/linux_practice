#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

long long divisors(long long n) {
	long long count = 0;
	for(long long i = 1; i <= n; ++i) {
		if(n % i == 0) {
			++count;
		}
	}
	return count;
}

enum{SIZE = 20};

typedef struct {
	long long* data;
	long long* result;
	unsigned int start_index;
	unsigned int end_index;
}Params;

void * func(void* args){
	Params* pr = (Params*) args;
	for(int i = pr->start_index; i<pr->end_index; ++i){
		pr->result[i]  = divisors(pr->data[i]);
	}
	return NULL;
}

int main(int argc, char* argv[]) {
	long long args[20];
	long long res[20];
	long long tmp;
	short int one = 0, two = 5, three = 10, four = 15; //indexes
	for(int i = 0; i < SIZE; ++i) {
		if(sscanf(argv[i+1], "%lli", &tmp) != 1) {
			return 1;
		}
		if(i % 4 == 0) {
			args[one] = tmp;
			++one;
		}
		else if(i % 4 == 1) {
			args[two] = tmp;
			++two;
		}
		else if(i % 4 == 2) {
			args[three] = tmp;
			++three;
		}
		else if(i % 4 == 3) {
			args[four] = tmp;
			++four;
		}
	}
	pthread_t t[4];
	Params pr[4];
	for(int i = 0;i<4;++i){
		pr[i].start_index = i*5;
		pr[i].end_index = (i+1)*5;
		pr[i].result = res;
		pr[i].data = args;
        	pthread_create(&t[i], NULL, func, &pr[i]);
	}
	for(int i = 0;i<4;++i){
		pthread_join(t[i], NULL);
	}
	for(int i = 0; i < SIZE; ++i) {
		printf("Count of divisors %d is: %d\n", args[i], res[i]);
	}
	return 0;
}

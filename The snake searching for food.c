#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void nuw(char *food){
	srand(time ());
	food[0]=(char) (rand()%40+1);
	food[1]=(char) (rand()%30+1); 
}

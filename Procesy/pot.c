#include <stdio.h> 
//#include <process.h> 
#include <unistd.h> 
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

void main(int argc, char* argv[]) { 
  int i,j; 
  for(j=i;j <= atoi(argv[i+2]);++j){
	   printf("Potomny = %d , krok: %d \n",i+1, j);
	   sleep(1);        
 	}
        exit(i); //Zakonczenie procesu
} 

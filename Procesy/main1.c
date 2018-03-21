// Działanie funkcji fork()
#include <stdio.h> 
//#include <process.h> 
#include <unistd.h> 
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

void main(int argc, char* argv[]){ 
  int pid,status,i,j;		//Deklaracja zmiennych
  for(i=0;i<argc-1 ;i++){ 
    if((pid = fork()) == 0) { 	//Proces potomny pot -------
        printf("Potomny PID = %d \n",getpid()); 
	for(j=i;j <= atoi(argv[i+2]);++j){
	   printf("Potomny = %d , krok: %d \n",i+1, j);
	   sleep(1);        
 	}
        exit(i); //Zakonczenie procesu
    }   

  }
  // Proces macierzysty ----------------
  for(j=0;j<atoi(argv[1]);++j){
 	 printf("Macierzysty, krok: %d \n",j);
         sleep(1); 
  }  
  for(i=0;i<argc-1 ;++i){
	pid = wait(&status);	//Czekanie na zakonczenie procesu
	printf("Proces %d zakończony status: %d\n",pid,WEXITSTATUS(status)); 
  }
 
 
} 

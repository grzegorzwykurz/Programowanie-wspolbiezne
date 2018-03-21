//Grzegorz Wykurz - 218571
//Program do kopiowania danych z plik1.txt to plik2.txt

#include <stdio.h> 					//standardowa biblioteka C
#include <errno.h> 					//mechanizm zgłaszania błędów
#include <fcntl.h>					//funkcja dostepu do flag pliku
#include <unistd.h> 					//udostepnia rozne makra
#define BSIZE 512					//zdefiniowanie wielkosci bufora

int main(void) 
{
	int fd, rd, wr1, wr2; 				//zadeklarowanie zmiennych
	char buf[BSIZE];				//utworzenie bufora
	fd = open("plik1.txt",O_RDONLY);		//otworzenie plik1.txt, tylko odczyt
	wr1 = open("plik2.txt",O_WRONLY);		//otworzenie plik2.txt, tylko zapis
	
	if (wr1<0)
	{
		perror("write");			//wypisanie komunikatu o bledzie przy zapisie
		return 0;
	}
	
	if (fd<0)
	{
		perror("open");				//wypisanie komunikatu o bledzie przy otwieraniu
		return 0;
	}

	do
	{
		rd = read(fd,buf,BSIZE);		//odczytywanie bajtow z plik1.txt
		if(rd<0)
		{
			perror("read");			//wypisanie komunikatu o bledzie przy odczytywaniu
			return 0;
		}
		printf("Odczytano %d bajtów\n",rd);
		wr2 = write(wr1,buf,rd);		//zapisywanie bajtow w plik2.txt
		printf("Zapisano %d bajtów\n",wr2);
	}
	while (rd==BSIZE);				//zamkniecie w momencie konca buforu
	close(fd);
	close(wr1);
	return 0;
}	
	

	




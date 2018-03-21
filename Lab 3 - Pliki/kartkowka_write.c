int main(void) {
	int fd, znak=x;
	char buf[80];
	fd = open("nowy.txt",O_RDWR| O_CREAT, 0600);
	if(fd < 0) {
		perror("open");
		return 0;
	}
	do {
		wd = write(fd,&znak,80);
		if(wd < 0) {
			perror("write");
			return 0;
		}
		printf("Zapisano %d bajtow \n" wd);
	} while(wd > 0);
	close(fd);
	return 0;
}
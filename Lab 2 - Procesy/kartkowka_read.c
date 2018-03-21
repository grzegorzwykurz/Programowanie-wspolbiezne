int main(void) {
    int fd;
    char buf[80];
    fd = open("nowy.txt",O_RDWR| O_CREAT, 0600);
    if(fd < 0) {
        perror("open");
        return 0;
    }
    do {
        rd = read(fd,buf,8);
        if(rd < 0) {
            perror("read");
            return 0;
        }
        printf("Odczytano %d bajtow \n" rd);
    } while(rd > 0);
    close(fd);
    return 0;
}
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>

#include <err.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "my_socket.h"
#include "readn.h"

#define HEADER_BUF_SIZE 12
#define LENGTH_POS       4
#define DATA_BUF_SIZE   1024*1024

int get_data_length(unsigned char *header_buf)
{
    unsigned int *len;
    int rv;
    len = (unsigned int *)&header_buf[LENGTH_POS];
    rv = ntohl(*len);

    return rv;
}

int main(int argc, char *argv[])
{
    unsigned char header_buf[HEADER_BUF_SIZE];
    unsigned char data_buf[DATA_BUF_SIZE];
    
    char tc_board_ip_address[] = "192.168.10.16";
    int  tc_board_port         = 24;

    int sockfd = tcp_socket();
    if (sockfd < 0) {
        errx(1, "tcp_socket");
    }

    if (connect_tcp(sockfd, tc_board_ip_address, tc_board_port) < 0) {
        errx(1, "connect_tcp");
    }

    for ( ; ; ) {
        int n;
        n = readn(sockfd, header_buf, HEADER_BUF_SIZE);
        if (n != HEADER_BUF_SIZE) {
            errx(1, "read for header");
        }

        int data_length = get_data_length(header_buf);
        fprintf(stderr, "data_length: %d\n", data_length);

        n = readn(sockfd, data_buf, data_length);
        if (n != data_length) {
            errx(1, "read for data");
        }
        
        fwrite(header_buf, 1, HEADER_BUF_SIZE, stdout);
        fwrite(data_buf,   1, data_length,     stdout);
        fflush(stdout);
    }

    return 0;
}

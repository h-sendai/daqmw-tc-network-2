#include <arpa/inet.h> // for ntohl()

#include <err.h>
#include <stdio.h>
#include <stdlib.h>

#include <cstdio>
#include <fstream>
#include <iostream>

#include "RawDataReader.h"

extern int get_data_length(unsigned char *, int);
extern int decode_data(unsigned char *, int);

int usage(void);

int usage()
{
    std::cerr << "Usage: decode filename" << std::endl;

    return 0;
}

int main(int argc, char *argv[])
{
    FILE *fp;
    char *filename;
    int n;
    unsigned char data_buf[MAX_BUF_FIZE];

    if (argc != 2) {
        usage();
        exit(1);
    }

    filename = argv[1];
    fp = fopen(filename, "r");
    if (fp == NULL) {
        err(1, "fopen for %s", filename);
    }

    for ( ; ; ) {
        // Try to read header part only
        n = fread(data_buf, 1, HEADER_SIZE, fp);
        if (n == 0) {
            if (feof(fp)) {
                break;
            }
            else if (ferror(fp)) {
                err(1, "fread");
            }
        }
        if (n != HEADER_SIZE) {
            errx(1, "partial read: %d bytes.  Should be %d bytes",
                n, HEADER_SIZE);
        }
        int data_length = get_data_length(data_buf, n);

        // then try to read data part
        n = fread(&data_buf[HEADER_SIZE], 1, data_length, fp);
        if (n == 0) {
            if (feof(fp)) {
                break;
            }
            else if (ferror(fp)) {
                err(1, "fread");
            }
        }
        if (n != data_length) {
            errx(1, "partial read: %d bytes.  Should be %d bytes",
                n, data_length);
        }
        decode_data(data_buf, HEADER_SIZE + data_length);
    }

    return 0;
}

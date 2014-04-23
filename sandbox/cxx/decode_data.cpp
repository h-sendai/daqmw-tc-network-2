#include <arpa/inet.h> // for ntohl()

#include <err.h>
#include <stdio.h>
#include <stdlib.h>

#include <cstdio>
#include <fstream>
#include <iostream>

#include "RawDataReader.h"


int get_data_length(unsigned char *buf, int buflen)
{
    unsigned int *len;
    
    len = (unsigned int *)&buf[LENGTH_POS];
    return ntohl(*len);
}

int decode_header(struct raw_data_header *header, unsigned char *buf, int buflen)
{
    header->type = (buf[0] & 0xf0) >> 4;
    header->one_event_data_size = buf[0] & 0x0f;
    header->n_ch = buf[1];

    int *len;
    len = (int *)&buf[LENGTH_POS];
    header->data_length = ntohl(*len);
    
    int *trig;
    trig = (int *)&buf[TRIGGER_POS];
    header->trigger_count = ntohl(*trig);

    return 0;
}

int decode_data_part_by_ch(unsigned char *buf, int buflen, int ch, struct raw_data_header *header,  int window_size, unsigned short *data)
{
    for (int w = 0; w < window_size; w ++) {
        int one_window_byte_size = (header->one_event_data_size)*(header->n_ch);
        unsigned short *v;
        int offset = HEADER_SIZE + one_window_byte_size*w + (header->one_event_data_size)*ch;
        v = (unsigned short *)&buf[offset];
        data[w] = ntohs(*v) & 0x0fff;
    }

    return 0;
}

int decode_data(unsigned char *buf, int buflen)
{
    // Fill this routine
    struct raw_data_header header;

    decode_header(&header, buf, buflen);
    int window_size = header.data_length / header.one_event_data_size / header.n_ch;

    unsigned short adc_data[header.n_ch][window_size];

    for (int ch = 0; ch < header.n_ch; ch ++) {
        decode_data_part_by_ch(buf, buflen, ch, &header, window_size, adc_data[ch]);
    }

    for (int w = 0; w < window_size; w++) {
        for (int ch = 0; ch < header.n_ch; ch ++) {
            printf("ch: %d w: %d data: %d\n", ch, w, adc_data[ch][w]);
        }
    }
    return 0;
}

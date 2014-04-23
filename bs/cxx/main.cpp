#include <cstdio>
#include <fstream>
#include <iostream>

#include "RawData.h"

int usage()
{
    std::cerr << "Usage: ./sample datafile" << std::endl;
    return 0;
}

int main(int argc, char *argv[])

{
    if (argc != 2) {
        usage();
        exit(1);
    }

    std::string filename = argv[1];

    RawData r;
    r.fill_raw_data(filename);
    r.decode_data();

    int n_ch        = r.get_n_ch();
    int window_size = r.get_window_size();

    for (int ch = 0; ch < n_ch; ch++) {
        for (int w = 0; w < window_size; w++) {
            unsigned short data = get_data_at(ch, w);
        }
    }
        
    return 0;
}

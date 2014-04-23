#include <string.h>

#include <cstdio>
#include <fstream>
#include <iostream>

#include "RawDataPacket.h"

int usage()
{
    std::cerr << "Usage: ./sample datafile" << std::endl;
    return 0;
}

using namespace std;
int main(int argc, char *argv[])
{
    RawDataPacket r;
    unsigned char my_buf[1024];

    r.set_buf(my_buf, sizeof(my_buf));
    memset(my_buf, 0, sizeof(my_buf));

    my_buf[0] = 0xf2;
    my_buf[1] = 16;
    my_buf[2] = 0;
    my_buf[3] = 0;
    my_buf[4] = 0;
    my_buf[5] = 0;
    my_buf[6] = 0;
    my_buf[7] = 100;
    my_buf[8] = 0;
    my_buf[9] = 0;
    my_buf[10] = 0;
    my_buf[11] = 101;
    
    int length = r.get_data_length();
    int trigger_count = r.get_trigger_count();
    
    cout << length << endl;
    cout << trigger_count << endl;

	if (r.is_raw_data_packet()) {
		cout << "ok. raw data packet" << endl;
	}
	else {
		cout << "not raw data packet" << endl;
	}
		
	int word_size = r.get_word_size();
	cout << word_size << endl;

    return 0;
}

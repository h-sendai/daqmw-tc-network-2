#include "RawDataPacket.h"

RawDataPacket::RawDataPacket(): m_buf(NULL), m_buf_len(-1)
{

}

RawDataPacket::~RawDataPacket()
{

}

int RawDataPacket::set_buf(const unsigned char *buf, const int buf_len)
{
    m_buf = buf;
    m_buf_len = buf_len;

    return 0;
}

bool RawDataPacket::is_valid_magic()
{
    // write this method
}

bool RawDataPacket::is_valid_footer()
{
    // write this method
}

int RawDataPacket::get_word_size()
{
    return 2;
}

int RawDataPacket::get_data_length()
{
    // write this method
}

int RawDataPacket::get_trigger_count()
{
    // write this method
}

int RawDataPacket::get_num_of_ch()
{
    return 4;
}

unsigned int RawDataPacket::get_data_at(int ch, int window)
{
    // write this method
}

int RawDataPacket::get_window_size()
{
    int word_size = 2;
    int n_ch      = 4;
    int data_length = get_data_length();

    int window_size = data_length / (word_size*n_ch);

    return window_size;
}

int RawDataPacket::reset_buf()
{
    m_buf = NULL;
    m_buf_len = -1;
    
    return 0;
}

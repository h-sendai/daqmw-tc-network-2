//
// Data Format
// 31                              0
// +--------------------------------+
// |  (*)  | n_ch | unused | unused |
// +--------------------------------+
// |     Data  Length (data only)   |
// +--------------------------------+
// |          Trigger Count         |
// +--------------------------------+  <-- Window # 0
// |   ADC ch # 0   |  ADC ch # 1   |
// +--------------------------------+
// |   ADC ch # 2   |  ADC ch # 3   |
// +--------------------------------+
// |   ADC ch # 4   |  ADC ch # 5   |
// +--------------------------------+
// |   ADC ch # 6   |  ADC ch # 7   |
// +--------------------------------+  <-- Window # 1
// |   ADC ch # 0   |  ADC ch # 1   |
// +--------------------------------+
// |   ADC ch # 2   |  ADC ch # 3   |
// +--------------------------------+
// |   ADC ch # 4   |  ADC ch # 5   |
// +--------------------------------+
// |   ADC ch # 6   |  ADC ch # 7   |
// +--------------------------------+
//
// (*) Bit 7 - 4: type: (0xf)
//     Bit 3 - 0: one event data byte size (2 bytes)
// ADC Data: Bit 15 - 12: channel number
//           Bit 11 -  0: Data

#ifndef _RAWDATAPACKET
#define _RAWDATAPACKET

#include <arpa/inet.h> // for ntohs(), ntohl()
#include <iostream>

class RawDataPacket
{
public:
    RawDataPacket();
    virtual ~RawDataPacket();
    int set_buf(unsigned char * const buf, int buf_len);
    bool is_raw_data_packet();
	int  get_word_size();
    int  get_num_of_ch();
    int  get_data_length();
	int  get_window_size();
    int  get_trigger_count();
    int  get_buf_pos();
    int  get_buf_len();
	unsigned int get_data_at(int ch, int window);
	int  reset_buf();
	const static int HEADER_SIZE = 12;
    const static int FORMAT_POS  = 0;
    const static int N_CH_POS    = 1;
    const static int LENGTH_POS  = 4;
    const static int TRIGGER_POS = 8;

private:
    unsigned char *m_buf;
    int m_buf_len;

};

RawDataPacket::RawDataPacket(): m_buf(NULL), m_buf_len(-1)
{

}

RawDataPacket::~RawDataPacket()
{

}

int RawDataPacket::set_buf(unsigned char* const buf, int buf_len)
{
    m_buf = buf;
    m_buf_len = buf_len;

    return 0;
}

bool RawDataPacket::is_raw_data_packet()
{
    unsigned char format = m_buf[FORMAT_POS];
    format = (format & 0xf0);
    if (format == 0xf0) {
        return true;
    }
    else {
        return false;
    }
}

int RawDataPacket::get_word_size()
{
	unsigned char word_size = m_buf[FORMAT_POS];
	word_size = (word_size & 0x0f);

	return word_size;
}

int RawDataPacket::get_data_length()
{
    unsigned int *len;
    int rv;
    len = (unsigned int *)&m_buf[LENGTH_POS];
    rv = ntohl(*len);

    return rv;
}

int RawDataPacket::get_trigger_count()
{
    unsigned int *trig;
    int rv;
    trig = (unsigned int *)&m_buf[TRIGGER_POS];
    rv = ntohl(*trig);

    return rv;
}

int RawDataPacket::get_num_of_ch()
{
    unsigned char n_ch;
    n_ch = m_buf[N_CH_POS];
    return n_ch;
}

unsigned int RawDataPacket::get_data_at(int ch, int window)
{
	// XXX: Assume the word size is 16 bit
	unsigned short *data;

	int word_size = get_word_size();
	int n_ch      = get_num_of_ch();
	
	int offset = HEADER_SIZE + n_ch*word_size*window + ch*word_size;
	data = (unsigned short *)&m_buf[offset];
	unsigned short rv = ntohs(*data);
	rv = (rv & 0x0fff);
	return rv;
}

int RawDataPacket::get_window_size()
{
	int word_size = get_word_size();
	int n_ch      = get_num_of_ch();
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

#endif

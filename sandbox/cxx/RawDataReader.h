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

#ifndef _RAWDATAREADER
#define _RAWDATAREADER 1

const static int MAX_BUF_FIZE = 1024*1024;
const static int HEADER_SIZE  = 12;
const static int LENGTH_POS   = 4;
const static int TRIGGER_POS  = 8;

struct raw_data_header {
    int type;
    int one_event_data_size;
    int n_ch;
    int data_length;
    int trigger_count;
};

#endif

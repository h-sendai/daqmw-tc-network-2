(テーマ) ネットワークバイトオーダー 
===================================

整数0x12345678を

    union my_num {
        int num;
        unsigned char buf[4];
    };
    my_num x.num = 0x12345678;

とunionを使って定義し、バイトオーダを確認するプログラムを書く。

サンプルコードはbs/byte_orderにある。

htonl()を使うにはman htonlするとわかるように

    #include <apra/inet.h>

が必要。

unionは上のように定義したときにx.numとするとintとしてアクセスできる。
これとおなじ内容でunsigned charとしてアクセスするときには
x.buf[0], x.buf[1], x.buf[2], x.buf[3]を使う。


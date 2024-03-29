(テーマ) バイナリファイルの読みだし
===================================

バイナリファイルを読む。

実習内容
--------

バイナリファイルを読むプログラムを書く。
バイナリファイルは``../../bs/sample.dat``にあるものを使う(これは
実習に使うボードから読んだデータ)。

方針
----

- 読んだデータをいれるバッファを1024バイト、charの配列で確保する。
- fopen()でファイルを開く。
- fread()でファイルを読む。読むサイズはバッファ分(いまの場合は1024バイト)。
- エラー処理もいれておく。
- 1024バイト読めなかった場合は読めなかった旨表示する。

サンプル例は
[../../bs/fread](../../bs/fread) にあるのでわからない場合はこれを見て
学習する。

ファイルのオープン
------------------

バイナリファイルはテキストファイルと違って行の概念がないので
どこまで読めばよいのか自動できめることができない。読むバイト数を指定する必要がある。

ファイルを読む前にfopen()する必要がある(テキストファイルと同様)。

    #include <stdio.h>
    
    FILE *fp = fopen("filename", "r");
    if (fp == NULL) {
        // エラー処理
    }

エラー処理の方法はいろいろあるだろうが、ここではerr()関数を使う。

    err(1, "fopen");

とすると

    progname: fopen: 失敗した理由

が標準エラー出力に出力され、終了ステータス1で終了する。

読みだし
--------

openできたらfread()関数を使って読む。

    char buf[1024];
    int n = fread(buf, 1 /* bytes */, 128, fp);

とすると、「1バイトのオブジェクト」を「128個」読むのを試みる。
戻り値はよみとった「オブジェクト数」。
128バイト読むには、他に

    fread(buf, 8, 16, fp); // 8バイトを16個読む
    fread(buf, 16, 8, fp); // 16バイトを8個読む

というのも考えられる。戻り値がそれぞれ違う(一番下の例では128バイト
読めたときに16を返す)。通常何バイト読めたか知りたいことが多いと思うので
第2引数は1を指定するのがよいかと思う。
(オブジェクトバイト数，読みだし回数)の組合せがいろいろある場合もあるが、
効率よく読めるという組合せは特にないので、自分が欲しい戻り値で決めれば
よい。

ファイル終端などリクエストしたバイト数未満しか読めない場合はエラーとはならず
読み取ったオブジェクト数を返す。指定したバイト数未満しか読めないのは
異常を示していると思う場合にはそれなりにエラーメッセージを出した
ほうがよい。

fread()の戻り値として0が返ってきた場合の状態は

* エラー
* ファイル終端まで達した(EOF)

のふたつがあり、戻り値だけでは区別がつかない。man freadでRETRUN VALUEの
ところを読むこと。エラー、EOFの判定にはferror()、feof()関数を使えと
書いてある。

---

[ex06](../ex06)

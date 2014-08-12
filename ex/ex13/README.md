(テーマ) DAQ-Middlewareでモニターコンポーネントを開発する
=========================================================

ボードからデータを読んで保存できるようになったので、保存ではなくて
オンラインでグラフを書くモニターコンポーネントを開発する。
ex09で行ったncコマンドで読んでパイプ経由でグラフを書いたシステムの
DAQ-Middleware化を行う。

作業の順番としては

1. RawDataReader - RawDataLoggerコンポーネントを作ったディレクトリに
   RawDataMonitorを置く場所を作る
2. RawDataMonitorコンポーネントの作成
3. コンフィギュレーションファイルの作成
4. システム起動、ラン
5. trigger.pyでボードにトリガーを送りグラフが更新されていることを確認する
6. trigger停止

となる。

1. RawDataMonitorコンポーネントの場所の確保
-------------------------------------------

通常、一からRawDataMonitorコンポーネントを書くのではなくて
すでにあるSampleMonitorをコピーして、データフォーマットを変更、
自分の用途にあうように改良していく。

SampleMonitorコンポーネントはDAQ-Middlewareをセットすると
/usr/share/daqmw/examples/SampleMonitorに入っているのでまず
これをコピーする:

    % cd ~/DaqData
    % cp -r /usr/share/daqmw/examples/SampleMonitor .
    % cd SampleMonitor
    % make (正常にコピーされたかどうか確認する)

最後のmakeコマンドは正常に終了しSampleReaderCompができているはずである。
できていたらOKなので、生成されたオブジェクト、実行ファイルを消して
前回同様コンポーネント名をRawDataMonitorに変更する作業を行う。

    % make clean
    % cp ~/daqmw-tc/daqmw/utils/change-SampleMonitor-name.sh .
    % sh change-SampleMonitor-name.sh
    % cd ..
    % mv SampleMonitor RawDataMonitor
    % make (名前を変えただけなので正常にコンパイルできるはず)

最後のmakeでエラーが出ないことを確認する。

このままではロジックはSampleMonitorのままなのでRawDataフォーマット
にあわせる、描画するものを変更するなどの作業が必要になる。

デコードルーチンは [ex05](../ex05) で書いたものを使うので
RawDataPacket.hおよびRawDataPacket.cppをコピーし、さらに
Makefileで

    SRCS += RawDataPacket.cpp

の行を追加する。これでコードを書く準備ができた。あとはロジックを
書き直せばよい。

2. RawDataMonitorコンポーネントの作成
------------------------------------

以下変更を要する点のポイントを書いておく。

RawDataMonitor.hでの変更点

- SampleMonitorではヒストグラムを書いていたのでTH1.hをインクルードし、
  HT1F *m_histとしてヒストグラムへのポインタを宣言していたが、RawDataMonitorでは書くものはグラフなのでTGraph.hをインクルードし、変数名、型もそれにあわせて変更する必要がある。
- SampleMonitorでは上流からくるデータをいれるバッファとして

        unsigned char m_recv_data[4096];
を使っている。これはSampleMonitorの上流コンポーネントから送られてくるデータ長が4096バイトの固定長だからである。
RawDataMonitorではフォーマット上はデータ長は固定長ではないので、
大きめにバッファを確保する必要がある。たとえば

        const static unsigned int DATA_BUF_SIZE = 1024*1024; // 1MB
        unsigned char m_recv_data[DATA_BUF_SIZE];
とする。

ほとんどのシステムではデータをファイルに保存するDAQコンポーネントは
DAQ-Middlewareに例題として付属しているSampleLoggerコンポーネントを
使うことができる。SampleLoggerコンポーネントは

- データをコンフィギュレーションファイルのdirNameパラメータで指定したディレクトリに保存する
- ファイルがmaxFileSizeInMegaByteパラメータで指定するバイト数を越えたら次のファイルに書く
  (イベント途中で次のファイルに移ることはない。Readerコンポーネントが1回に送ったデータを途中
  で分断することはしない)。
- 保存するファイル名はYYYYMMDDTHHMMSS_RRRRR_BBB.dat (RRRRRはrun番号、BBBは000から始まる連番)。
  例:20110202T143748_000000_000.dat
- パラメータのisLoggingがyesになっている場合に実際にデータを保存する。
  noになっている場合はデータは保存しない(テストに使ったりする)

と動作する。

コピーしてそのままの名前で使ってもよいが、少し改造する場合もある
(たとえば「イベントデータのなかに時刻情報が入っていないのでLoggerコンポーネントが
動いているPCから時刻情報を取得して時刻情報を追加して書くようにするなど)。
その場合は動作仕様が変わってくるので名前をSampleLoggerから変更したほうがよい。
ここでSample*コンポーネントの名前を変更する方法を学ぶ。SampleLoggerからRawDataLoggerに
名前を変更することにする。

コード上では大文字小文字を以下のように使い分けている。かならずこのように
しなければならないわけではないが、習慣上そうなっているので引継が生じるなどの場面を
考えると守っておいたほうがよい。

- samplelogger (全部小文字) InPort、OutPortの名前
- SampleLogger (大文字小文字ミックス。最初の文字、および単語の切れ目は大文字) ファイル名、コンポーネント名
- SAMPLELOGGER (全部大文字) インクルードガード

SampleLoggerコンポーネントは /usr/share/daqmw/example/SampleLogger/ ディレクトリに
ある。これをコピーして、手で修正してもよいが間違いが生じる可能性が大きいので
sedコマンドを使ったスクリプトを用意したのでこれを使う(現在のDAQ-Middlewareにはまだないが今後
追加する予定になっている)。

    % cd ~/RawData
    % cp -r /usr/share/daqmw/examples/SampleLogger .
    % mv SampleLogger RawDataLogger (ディレクトリ名の書き換え)
    % cd RawDataLogger
    % cp ~/daqmw-tc/daqmw/utils/change-SampleLogger-name.sh .
    % chmod +x change-SampleLogger-name.sh
    (change-SampleLogger-name.shのなかみを見てみる)
    (RawDataLoggerではない名前に変更する場合はnew_name_camel_caseを変更する)
    % ./change-SampleLogger-name.sh
    % grep -i sample * などしてSample, sampleの文字が残っていないかどうか確認
    % make

これでRawDataLoggerCompという実行ファイルができる。

3. コンフィギュレーションファイルの作成
---------------------------------------

コンフィギュレーションファイルを作る。ほぼ完成された雛型を
~/daqmw-tc/daqmw/reader-logger.xmlに用意してあるのでそれを編集して使う。

    % cd ~/RawData
    % cp ~/daqmw-tc/daqmw/reader-logger.xml .
    % reader-logger.xmlのexecPathを自分の環境にあわせて編集

4. システム起動、ラン
---------------------

    % run.py -cl reader-logger.xml

でシステムを起動し、0, 1とキーを押してシステムを動かす。

5. trigger.pyでボードにトリガーを送る
-------------------------------------

    % ~/daqmw-tc/trigger/trigger.py

としてstartボタンを押しトリガーを送る。読みだしシステムのイベントバイト数が
増えるのを確認する。

6. trigger停止、システム停止
--------------

trigger GUIのstopボタンを押しトリガーを送るのを停止する。
2を押してシステムを止める。


7. データがセーブされていることを確認
-------------------------------------

/tmp/ディレクトリにデータが保存されているのを確認する。
hexdumpコマンド、あるいは以前作ったファイルを読んでデコードするプログラムで
正当性を確認する。
    



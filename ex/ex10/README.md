(テーマ) ncコマンドでデータを読みグラフを画面に表示する
=======================================================

実習内容
--------

ncコマンドでデータを読んでグラフを画面に表示する。

方針
----

前の例題とおなじく、ファイルを読んでグラフを書くプログラムを
改造するとncコマンドでデータを読んでグラフを画面に表示できるようになる。

ファイルから読むかわりに標準入力からデータを読むように変更する。
標準入力から読むには

    fp = stdin;

とすればよい。

解答例は
[../../bs/read_nc_decode_graph](../../bs/read_nc_decode_graph) にある。

以下のコマンドを投入すると一直線のグラフが順次上にあがっていく
様子が表示される。

    % nc 127.0.0.1 1234 | ./read_nc_decode_graph
    
またteeコマンドを使って入力をファイルに分流するとデータのセーブと
モニターの両方ができるシステムができる。

    % nc 127.0.0.1 1234 | tee data | ./graph_command

この簡易システムの問題点は

- パイプ中のバッファサイズを自分で決めることができないので
  データ速度が大きいと対応がむずかしい
- ストップにControl-cを使うのでデータが途中で切れてしまうことがある

などである。

エミュレータからサインカーブのデータを送る
------------------------------------------

daqmw-tc-serverはデフォルトではグラフを書いたときに
一直線のグラフができるデータを送ってくるが
以下のように -t sin を付けるとサインカーブのデータを
送ってくる。


    pkill daqmw-tc-server (すでに起動しているサーバを停止させる)
    daqmw-tc-server -t sin -D

これで

    % nc 127.0.0.1 1234 | ./read_nc_decode_graph

とするとサインカーブのグラフが現れる。

以上でDAQ-Middlewareを使わないでデータをグラフ化するプロジェクトは終了です。

DAQMW-TC
========

Source code for DAQMW Training Course

2014年9月開催のDAQ-Middlewareトレーニングコース実習用ファイルです。
トレーニングコース内で実習に入るまえに何をどういう手順で行うのかを説明します。

![実習システムの様子](http://daqmw.kek.jp/seminar/2014/spartan_and_mac-small.png)

ファイルの取得
--------------

ここにあるファイルをダウンロードするにはターミナルを開いて次のコマンドを実行します。

    % cd
    % git clone https://github.com/h-sendai/daqmw-tc.git

パーセント記号(%)はコマンドラインのプロンプトで入力する必要は
ありません。最初のcdコマンドはホームディレクトリに移動するために
行っています。

ダウンロードするとホームディレクトリにdaqmw-tcというディレクトリができます。
この文書ではこのディレクトリを ~/daqmw-tcと書きます。
その中には以下のディレクトリ(複数)ができます。

[daqmw](daqmw/)
---------------

実習で使うDAQコンポーネントが入っています。
実習途中でにっちもさっちもいかなくなったらこれを見て学習するのも
DAQ-Middleware習得手段のひとつだと思っていれてあります。

* RawDataReader
* RawDataMonitor
* RawDataLogger
* Dispatcher

[trigger](trigger/)
-------------------

実習で使うSpartan 3Eにトリガー信号を送るプログラムが入っています。

[bs](bs/)
---------

実習の解答例があります。

[doc](doc/)
-----------

実習で使うSpartan 3Eが送ってくるデータのデータフォーマットが入っています。

[ex](ex/)
---------

実習で行う項目、コードなどが入っています。

[sandbox](sandbox/)
-------------------

受講者のかたがたは必要ならこのディレクトリにファイルをコピーするなどして
実習してください。

DAQMW-TC
========

Source code for DAQMW Training Course

2014年9月開催のDAQ-Middlewareトレーニングコース実習用ファイルです。

ファイルをダウンロードするにはターミナルを開いて次のコマンドを実行します。

    % cd
    % git clone https://github.com/h-sendai/DAQMW-TC.git

パーセント記号(%)はコマンドラインのプロンプトで入力する必要は
ありません。最初のcdコマンドはホームディレクトリに移動するために
行っています。

ダウンロードするとホームディレクトリにDAQMW-TCというディレクトリができます。
この文書ではこのディレクトリを ~/DAQMW-TCと書きます。
その中には以下のディレクトリ(複数)ができます。

daqmw
-----

実習で使うDAQコンポーネントが入っています。

* RawDataReader
* RawDataMonitor
* RawDataLogger
* Dispatcher

trigger
-------

実習で使うSpartan 3Eにトリガー信号を送るプログラムが入っています。

bs
--

実習の解答例があります。

doc
---

実習で使うSpartan 3Eが送ってくるデータのデータフォーマットが入っています。

ex
--

実習で行う項目、コードなどが入っています。

sandbox
-------

受講者のかたがたは必要ならこのディレクトリにファイルをコピーするなどして
実習してください。

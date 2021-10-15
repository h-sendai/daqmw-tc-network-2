# DAQMW-TC

[DAQ-Middlewareトレーニングコース時間割など](http://daqmw.kek.jp/seminar/2021/)

2021年9月21日開催のDAQ-Middlewareトレーニングコースの
第1日目 ネットワークプログラミングに関する実習用ファイルです。
トレーニングコース内で実習に入るまえに何をどういう手順で行うのかを説明します。

受講者のかたがたは以下のものを用意してください。

- パソコン(Windows 7/10あるいはMacOS X)

パソコンにはVirtualBoxをインストールして、仮想CentOS 7で実習を行います。
VirtualBoxのセットアップ方法は
[説明ページ](https://daqmw.kek.jp/virtualbox-centos7/)をご覧ください。

## ファイルの取得

ここにあるファイルをダウンロードするにはターミナルを開いて次のコマンドを実行します:

    % cd
    % git clone https://github.com/h-sendai/daqmw-tc-network-2.git

パーセント記号(%)はコマンドラインのプロンプトで入力する必要は
ありません。最初のcdコマンドはホームディレクトリに移動するために
行っています。

次のように"Resolving deltas: 100% (NNN/NNN), done." (NNNには数値が入る)
とでたら正常に取得できています。

    Cloning into 'daqmw-tc-network-2'...
    remote: Enumerating objects: 1112, done.
    remote: Counting objects: 100% (1112/1112), done.
    remote: Compressing objects: 100% (422/422), done.
    remote: Total 1112 (delta 616), reused 1110 (delta 614), pack-reused 0
    Receiving objects: 100% (1112/1112), 1.43 MiB | 1.59 MiB/s, done.
    Resolving deltas: 100% (616/616), done.

ダウンロードするとホームディレクトリにdaqmw-tc-network-2というディレクトリができます。
この文書ではこのディレクトリを ~/daqmw-tc-network-2と書きます。
その中には以下のディレクトリ(複数)ができます。

一度git cloneコマンドを実行したあと、修正があったとアナウンスがあったら
次のようにgit pullコマンドを実行し、修正を反映させます:

    % cd daqmw-tc-network-2
    % git pull

## [ex](ex/)

実習で行う項目の解説、一部のコードなどが入っています。

## [sandbox](sandbox/)

受講者のかたがたは必要ならこのディレクトリにファイルをコピーするなどして
実習してください。

## [doc](doc/)

実習で使うエミュレータが送ってくるデータのデータフォーマットが入っています。
当初はこのファイルにあるようにハードウェアを使う予定でしたが、今回は
オンラインで講義、実習を行うのでソフトウェアエミュレータを使うことにしました。
ソフトウェアエミュレータは下のemulatorディレクトリにあります。

## [emulator](emulator/)

ソフトウェアエミュレータが入っています。使いかたは上のリンクを
クリックするとでてきます。

## [Spartan-3E](Spartan-3E/)

以前のSpartan-3E評価ボードを使っていたときのコードです。
今回のトレーニングコースでは使いません。

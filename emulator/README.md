# ソフトウェアエミュレータ

## ソースコード、コンパイル方法など

ソースコードは
https://github.com/h-sendai/daqmw-tc-server
にあります。
今回のトレーニングコースでは時間の都合で解説はしませんが
データフォーマットを改造して使うなどのときはこちらを
利用してください。

    % git clone https://github.com/h-sendai/daqmw-tc-server.git
    % cd daqmw-tc-server
    % make
    % mkdir ~/bin
    % cp daqmw-tc-server ~/bin

これで/home/daq/bin/daqmw-tc-server
としてインストールされています。

bashのPATH環境変数には/home/daq/binが入っていますのでコマンドラインから
パスを指定することなしに起動することができます:

    % daqmw-tc-server
    
ポートを指定する場合は-pオプションを使います:

    % daqmw-tc-server -p 1235

-pオプションを指定しない場合はポート1234が使われます。

終了するにはControl-Cを押します。

上記のように起動するとdaqmw-tc-serverコマンドが終了しないので
終了までひとつの端末を占有することになります。-Dオプションを付けると
バックグラウンドで起動するので、コマンドラインから次のコマンドを
入力することができるようになります:

    % daqmw-tc-server -D
    % (すぐに次のプロンプトがでる)。
    % (ポートを起動するには-pオプションを使います)
    % daqmw-tc-server -D -p 1235

## やってくるデータ

全チャンネル共通で
trigger 0のとき全部0、trigger 1のとき全部128、trigger 2のとき全部256、
となり以下4096-128でいったあとまた0に戻ります。

-t sinでサインカーブのデータがきます:

    % daqmw-tc-server -t sin

位相がだんだんずれていきます。全チャンネル同じデータです。


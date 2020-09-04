(テーマ) semaphoreを使った同期
====================================

実習内容
--------

semaphoreを使った同期を試します。
ここではsem_post(), sem_wait()の動作を確認します。

ファイルをsandbox以下にコピーしてmakeを実行し、実行ファイルを作成します。

    % cd ~/daqmw-tc-network-2/sandbox
    % cp -r ../ex/supplement-ex02 . (最後にカレントディレクトリを示すドット(.)があることに注意)
    % cd supplement-ex02
    % make
    % ./sem-sample

確認
----

実行するとreaderスレッドとwriterスレッドが起動します。

readerスレッドは「10秒スリープ、sem_post()を実行する」の動作を5回繰り返します。

writerスレッドはsem_wait()を実行し、readerスレッドがsem_post()を行うのを待ちます。
postされるまでwriterスレッドはスリープ状態になります。ポストされたらsem_wait()が
終了し、次のプログラム行を実行します。


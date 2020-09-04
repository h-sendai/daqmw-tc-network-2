(テーマ) threadの生成と終了
====================================

実習内容
--------

pthread_create(), pthread_join()でthreadの生成、終了を実習します。

ファイルをsandbox以下にコピーしてmakeを実行し、実行ファイルを作成します。

    % cd ~/daqmw-tc-network-2/sandbox
    % cp -r ../ex/supplement-ex01 . (最後にカレントディレクトリを示すドット(.)があることに注意)
    % cd supplement-ex01
    % make
    % ./thread

確認
----

実行して、threadが2個起動し、それぞれプロセスID (PID)、スレッドID (TID)を
表示することを確認します。

- PIDは同一ですが、TIDは違ったものになります。


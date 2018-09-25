(テーマ) semaphoreを使った同期
====================================

実習内容
--------

semaphoreを使った同期を試します。

ファイルをsandbox以下にコピーしてmakeを実行し、実行ファイルを作成します。

    % cd ~/daqmw-tc-network/sandbox
    % cp -r ../ex/supplement-ex02 . (最後にカレントディレクトリを示すドット(.)があることに注意)
    % cd supplement-ex02
    % make
    % ./sem

確認
----

実行して、writerとreaderというthreadが起動します。
bufという有限バッファを共有しています。
writerはバッファに数値を入れてきます。いれる数値は、
配列のインデックス(0, 1, 2, ... , MAX_BUF)
です。
readerは配列のインデックスの数値が入っているか確認し、確認後-1を入れます。

semaphore変数としてstoredとemptyというふたつの変数を使います。
初期値はstoredは0、emptyはMAX_BUFです。
初期値の設定はsem_init()を使います。

sem_wait(&sem_var)では

- sem_varが0なら1以上になるのを待つ。
- sem_varが1以上ならsem_varを1減らして次の行に移る

という動作をします。

sem_post(&sem_var)ではsem_varの値をひとつ増やします。

これらによりwriterでは

- emptyが1以上ならバッファに空きがあるので数値を書き込み、storedを1増やします
- emptyが0なら1以上になるのを待つ

ことでデータの上書きをしないようになります。

readerのほうは

- storedが0なら1以上になるのを待ちます
- storedが1以上なら処理して、emptyを1増やします。



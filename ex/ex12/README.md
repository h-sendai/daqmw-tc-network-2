(テーマ) Webモードでシステムを動かす
====================================

DAQ-Middlewareを稼働させる方法にはコンソールモードと
Webモードがある。コンソールモードで動かす方法はすでに
試したので、次にWebモードで動かすのを試してみる。

Webモードで起動するにはrun.pyを-cなしで起動する。

    % run.py -l sample.xml

なにも表示されなければ正常に起動できている。
Webブラウザを使って
http://localhost/daqmw/scripts/OperatorPanel/OperatorPanel0.html
にアクセスするとWeb UIが起動する。

configure, begin, end, unconfigureのボタンがあるので適当にボタンを
押す。状態により押しても無意味なボタンはグレーアウトしている。

ラン番号は自動で1づつ増えていくようになっている。

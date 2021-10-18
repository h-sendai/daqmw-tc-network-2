(テーマ) ROOTを使ってグラフを書く
=================================

実習内容
--------

この実習では、ボードから読んだデータはヒストグラムではなくてグラフを
書くことでモニターコンポーネントを作成する。
そのためにここで適当なデータからROOTでグラフを書けるようにする。

方針
----

素粒子原子核分野ではROOT https://root.cern/ を使ってヒストグラム、
グラフを書くことが多い。
ヒストグラムを書く方法は周知と思うがグラフはヒストグラムよりは書かれる
機会がないと思うのでここで取り上げる。

[../../bs/draw_graph](../../bs/draw_graph) に放物線上の点を指定して書くプログラムを
おいてある。コピー、コンパイルして
動かし、コードを読みグラフの書きかたを習得すること。

ROOTではC++プログラムをコンパイルするのに必要なインクルードファイル、
ライブラリファイルの指定を簡略化するためにroot-configというコマンドを
用意している。Makefile中で以下のように指定しているので見ておく。

    CPPFLAGS += -I$(shell ${ROOTSYS}/bin/root-config --incdir)
    LDLIBS   += $(shell ${ROOTSYS}/bin/root-config --glibs)

コード解説
----------

[C++の一般的インクルードファイル](https://github.com/h-sendai/daqmw-tc-network-2/blob/cdf5ab0eb28fc9d7ec14f9bab2d86c4d7ad22ce0/bs/draw_graph/draw_graph.cpp#L1-L4) 

[ROOTのインクルードファイル](https://github.com/h-sendai/daqmw-tc-network-2/blob/cdf5ab0eb28fc9d7ec14f9bab2d86c4d7ad22ce0/bs/draw_graph/draw_graph.cpp#L6-L13)

[名前空間std](https://github.com/h-sendai/daqmw-tc-network-2/blob/cdf5ab0eb28fc9d7ec14f9bab2d86c4d7ad22ce0/bs/draw_graph/draw_graph.cpp#L15) std::coutをcoutのようにstdなしに書けるようにusing namespaceを使っている。

[usage()](https://github.com/h-sendai/daqmw-tc-network-2/blob/cdf5ab0eb28fc9d7ec14f9bab2d86c4d7ad22ce0/bs/draw_graph/draw_graph.cpp#L16-L21) ここでは使っていないが引数が複雑なプログラムでは引数解説などをプリントする関数を用意して、必要な引数が指定されなかった場合などに画面出力するようにする。

[データの代入](https://github.com/h-sendai/daqmw-tc-network-2/blob/cdf5ab0eb28fc9d7ec14f9bab2d86c4d7ad22ce0/bs/draw_graph/draw_graph.cpp#L31-L35)

[ROOT TApplication](https://github.com/h-sendai/daqmw-tc-network-2/blob/cdf5ab0eb28fc9d7ec14f9bab2d86c4d7ad22ce0/bs/draw_graph/draw_graph.cpp#L37) ROOTではTApplicationオブジェクトを生成することで内部データの初期化などを行っている(ようである)。

[ROOT TCanvas](https://github.com/h-sendai/daqmw-tc-network-2/blob/cdf5ab0eb28fc9d7ec14f9bab2d86c4d7ad22ce0/bs/draw_graph/draw_graph.cpp#L38) グラフはTCanvas上に行われる。

[ROOT Graph](https://github.com/h-sendai/daqmw-tc-network-2/blob/cdf5ab0eb28fc9d7ec14f9bab2d86c4d7ad22ce0/bs/draw_graph/draw_graph.cpp#L39) グラフオブジェクトの生成。

[ROOT TText](https://github.com/h-sendai/daqmw-tc-network-2/blob/cdf5ab0eb28fc9d7ec14f9bab2d86c4d7ad22ce0/bs/draw_graph/draw_graph.cpp#L40-L43) グラフに表示される文字の大きさ、色、位置などを設定している。

[ROOT SetPoint](https://github.com/h-sendai/daqmw-tc-network-2/blob/cdf5ab0eb28fc9d7ec14f9bab2d86c4d7ad22ce0/bs/draw_graph/draw_graph.cpp#L45-L47) データ点の定義。

[タイトル、Y軸最大値、最小値の設定](https://github.com/h-sendai/daqmw-tc-network-2/blob/cdf5ab0eb28fc9d7ec14f9bab2d86c4d7ad22ce0/bs/draw_graph/draw_graph.cpp#L48-L50) Form()でprintf()の括弧内と同じフォーマットを指定することで文字列を作ることができる。

[ROOT draw()](https://github.com/h-sendai/daqmw-tc-network-2/blob/cdf5ab0eb28fc9d7ec14f9bab2d86c4d7ad22ce0/bs/draw_graph/draw_graph.cpp#L52-L54) Draw()でグラフを書く。Draw()引数の"a": 軸を書く。"l": 線を書く。"*": 各点に"*"をプロットする。
TCanvas.Update()を実行することでグラフが更新される。

[TGraphPainter Class Reference](https://root.cern.ch/doc/master/classTGraphPainter.html)を見てください。

[ROOT TApplication.Run()](https://github.com/h-sendai/daqmw-tc-network-2/blob/cdf5ab0eb28fc9d7ec14f9bab2d86c4d7ad22ce0/bs/draw_graph/draw_graph.cpp#L57) ROOTアプリケーションイベントループ。メニューバーなどを表示し、マウス入力などを待つ。

TApplication.Run()についての注意
--------------------------------

DAQ-MiddlewareのDAQコンポーネントはTApplication.Run()と同様にアプリケーションイベントループが
必要となっている。イベントループ待ちはひとつのプログラムでひとつしか持てないので
ROOTをDAQ-Middlewareで使う場合はTApplication.Run()を使ってはいけない。

VirtualBoxでの注
----------------

PC上でnativeにLinuxを動かした場合、TApplication.Run()を走らせなくてもTCanvas.Update()で
グラフが表示できる。ただしVirtualBoxでTApplication.Run()なしにUpdate()させると
最初のグラフのみ表示されないという不具合があることがわかっている(2回目以降は
表示される)。

グラフのクラス化
----------------

グラフオブジェクトの部分をクラス化したものを
~/daqmw-tc-network-2/bs/draw_graph_class においてある。
グラフデータのx, y座標値をvectorで保持するように変更してある。
ついでにROOT Canvasを4つに分割し、そのうちの2つにグラフを
書くようにした。

複雑なデータを扱うときには適切にclass化をはかったほうがよいと
思うがトレーニングコースで扱うデータではどちらを使ってもよいと
思う(わかりやすい方を使えばよい)。

---

[ex08](../ex08/)

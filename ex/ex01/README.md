(テーマ) Makefile
====================================

インクルードファイルの指定の< ... > と " ... "の違い
----------------------------------------------------

sample.cppの

```C++
#include <iostream>
#include "world.h"
```

の \<> (angle bracket)と "" (double quote)についての説明。
\<> はC++コンパイラが探すディレクトリを知っているインクルードファイルを
指定するのに使う。デフォルトでは/usr/includeの下を探す。
コンパイラのコマンドラインで `-I path` を付けることで探す場所を追加可能。
"" ならソースがあるところのディレクトリ(からの相対パス)。

- \<> はOS付属、自分以外が書いたライブラリ
- "" は自分で書いたインクルードファイル

であることが多い。

Makefileとは
------------

ファイルタイムスタンプを使って変更されていないソースコードは再コンパイル
しないようにするコマンド``make``の設定ファイル。

実習内容
--------

ファイルをsandbox以下にコピーしてmakeを実行し、実行ファイルを作成します。

    % cd ~/daqmw-tc-network-2/sandbox
    % cp -r ../ex/ex01 . (最後にカレントディレクトリを示すドット(.)があることに注意)
    % cd ex01

中に basic と simplify というふたつのディレクトリがあります。
ふたつともソースファイルは以下のとおりでmain()はsample.cppの中にある
(world.h, world.cppはサブルーチンあるいはライブラリ的ファイル)。

- sample.cpp
- world.cpp
- world.h

basicディレクトリのMakefile
---------------------------

\<TAB>のところには実際にはタブが入ります。スペースではないので注意。

タブかどうかは``cat -t Makefile``するとわかる（タブは^Iと表示される）。
viでは``:set list``でわかる。もとに戻すには``:set nolist``。
emacsでは``M-x whitespace-mode``でタブが``>>``と表示される。もとに戻すには
再び``M-x whitespace-mode``を実行する。

    CC = g++
    all: sample

    sample: sample.o world.o
    <TAB>$(CC) -o sample sample.o world.o

    sample.o: sample.cpp
    <TAB>$(CC) -c sample.cpp

    world.o: world.cpp world.h
    <TAB>$(CC) -c world.cpp

    clean:
    <TAB>rm -f sample *.o

- CC = g++
    - マクロ。以降の行で$(CC)として使える
- all: sample
    - 最終生成物をallターゲットとして指定。make allとするとここで指定したものを作るように動作する
- sample: sample.o world.o
    - sampleという実行ファイルはsample.o、world.oに依存する。sample.oあるいはworld.oがsampleより新しければ次の行に書いたコマンドを実行しsampleを作る
- sample.o: sample.cpp
    - sample.oはsample.cppに依存する。sample.cppがsample.oより新しければ次の行を実行してsample.oを作る
- world.o: world.cpp world.h
    - sample.oと同様。c++ではあworld.hのような.hファイルに実装をいれることがあるのでここではworld.hにも依存すると指定してある

ファイルタイムスタンプでの動作の確認
------------------------------------

- basicディレクトリでmakeを実行してsampleというファイルができることを確認する。
- touch sample.cpp、makeの順に実行してworld.cppのコンパイルは必要ないので実行されないことを確認する。
- touch world.h、makeの順に実行してコマンド結果を考える。

簡略化したMakefileの書きかた
----------------------------

- makeは.c, .h, .cppなどよく使われる拡張子についてはどう扱えばいいのかしっているので、g++コマンドを全部書く必要はない。
- マクロは += で追加することができる。

次のように書いておくと、(worldのような)ライブラリ的ファイルが増えてもOBJS += の行に追加するだけでよいので機械的に作業できるようになる。

    CC = g++
    PROG = sample
    CXXFLAGS = -g -O2 -Wall

    all: $(PROG)
    OBJS += $(PROG).o
    OBJS += world.o
    $(PROG): $(OBJS)

    clean:
        rm -f *.o $(PROG)

- CCでコンパイラを指定している。
- CXXFLAGSにはコンパイラ(いまの場合はg++)で使うオプションを指定する。
ここでは次のように指定している。
    - -g: デバッグ情報を埋め込む
    - -O2: レベル2で最適化する。最適化しない場合は-O0を指定する
    - -Wall: コンパイル時に全ての警告を表示する
- 実行ファイル(ここではsample)を作るのに外部ライブラリが必要ならLDLIBSで指定する。
- 単にmakeとするとallターゲットを実行する。
- make cleanで生成されたファイルを消すようにしている。rmコマンドで消すのと同じだが
誤ってソースファイルまで消さないようにmake cleanで消すようにMakefileを書いておくのが
安全。

---

[ex02](../ex02/)

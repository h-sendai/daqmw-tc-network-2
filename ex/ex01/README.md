(テーマ) Makefile
====================================

インクルードファイル
--------------------

Makefileの前にsample.cppの

```C++
#include <iostream>
#include "world.h"
```

の \<> (angle bracket)と "" (double quote)についての説明。
\<> はC++コンパイラ、ライブラリ付属のインクルードファイルでコンパイラが
探す場所をしっているところ(`/usr/includeの下)。""ならソースがあるところの
ディレクトリ(からの相対パス)。
コンパイラのコマンドラインで `-I path` を付けることで探す場所を追加可能。

- \<> はOS付属、自分以外が書いたライブラリ
- "" は自分で書いたインクルードファイル

であることが多い。

Makefileとは
------------

ファイルタイムスタンプを使って変更されていないソースコードは再コンパイル
しないようにするコマンド。

実習内容
--------

ファイルをsandbox以下にコピーしてmakeを実行し、実行ファイルを作成します。

    % cd ~/daqmw-tc-network/sandbox
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


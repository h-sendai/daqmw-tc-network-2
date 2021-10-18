(テーマ) C++の復習
==================
クラスファイルを作りそれを利用するプログラムを作る

ファイル
--------

* MyClass.h   (クラス宣言)
* MyClass.cpp (実装)
* main.cpp    (MyClassを使うプログラム)

C++プログラムはmain()関数からスタートする。main()関数は
main.cppに書いてある(かならずmain.cppというファイル名で
なければいけないわけではない)。

実習内容
--------

ファイルをコピーしてmakeで実行ファイルを作る:

    % cd ~/daqmw-tc-network-2/sandbox
    % cp -r ../ex/ex02 .
    % cd ex02
    % make

実行前にコードを見て結果を予想する。次に
実行ファイル main を実行してみる:

    % ./main

またMakefileの中身を見てみる。Makefileについては以下を参照。

    % make clean

で*.oファイル、および実行ファイル(今の場合はmain)が消されることも
確認しておく。

コードの変更
------------

- MyClass.h、MyClass.cppにメンバー変数m_zを追加し、set_z()メソッド、
  get_z()メソッドを追加する。
- main.cppを変更し、set_z()、get_z()を使って値をセット、ゲットする
  プログラムを書く。

オブジェクトの生成
------------------

```
MyClass a; // デフォルトコンストラクタ
MyClass b(1, 2) // 整数引数2個のコンストラクタ

MyClass c(a); // MyClassオブジェクトcを作成。aと同じ値に設定
              // MyClass c = a; と同じ。
MyClass d;    // デフォルトコンストラクタ
d = a;        // aの値を代入

MyClass array[5]; // MyClassオブジェクト5個の配列。デフォルトコンストラクタが呼ばれる。
```

```
MyClass(const MyClass &rhs); // Copy Constructor
MyClass& operator =(const MyClass& a);
```
コピーコンストラクタ、代入演算子は書かれていなければコンパイラが自動で作る。

---

[ex03](../ex03/)

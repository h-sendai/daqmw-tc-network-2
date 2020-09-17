#include <cstdio>
#include <fstream>
#include <iostream>

#include "MyClass.h"
using namespace std;

void my_function(MyClass x)
{
    return;
}

int main(int argc, char *argv[])
{
    // デフォルトコンストラクタ
    cerr << "---> MyClass a" << endl;
    MyClass a;
    cerr << "<--- MyClass a" << endl;

    // 引数付きコンストラクタ
    cerr << "---> MyClass b(1, 2)" << endl;
    MyClass b(1, 2);
    cerr << "<--- MyClass b(1, 2)" << endl;
    
    // set_x()テスト
    cerr << "---> b.set_x(100)" << endl;
    b.set_x(100);
    cerr << "<--- b.set_x(100)" << endl;

    // get_x()テスト
    cerr << "---> b.get_x()" << endl;
    cerr << b.get_x() << endl;
    cerr << "<--- b.get_x()" << endl;

    // 新規にオブジェクトを生成。すでにあるオブジェクトで新オブジェクトを初期化
    cerr << "---> use copy ctor" << endl;
    MyClass c(a);
    // 同様なことは = をつかっても行える(代入ではない）
    MyClass d = a;
    cerr << "<--- use copy ctor" << endl;

    // 代入
    cerr << "---> use assignment operator" << endl;
    MyClass e;
    e = a;
    cerr << "<--- use assignment operator" << endl;

    // 配列。デフォルトコンストラクタが使われる
    cerr << "---> array" << endl;
    MyClass my_array[5];
    cerr << "<---array" << endl;

    // 関数呼び出し。
    cerr << "---> function call" << endl;
    my_function(a);
    cerr << "<--- function call" << endl;

    cerr << "program end" << endl;
    return 0;
}

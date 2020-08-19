(テーマ)コンパイル環境確認プログラム
====================================

実習内容
--------

ファイルをsandbox以下にコピーしてmakeを実行し、実行ファイルを作成します。

    % cd ~/daqmw-tc-network/sandbox
    % cp -r ../ex/ex00 . (最後にカレントディレクトリを示すドット(.)があることに注意)
    % cd ex00
    % make

確認
----

- コンパイルでエラーがでないことを確認します。
- sample という実行ファイルができていることを確認します。

実行方法
--------

    % ./sample

とするとhello, worldと画面に表示されるので試してみる。

Makefile
--------

Makefileの中身を見ておく。

Cコンパイラの動作
----------------

- cc (gcc)コマンドは他のコマンドを呼び出すコマンド
- cpp (プリプロセス)
- cc1 (コンパイラ。プリプロセスされたコードをアセンブリコードに変換)
- as  (アセンブラ)
- リンカ (ライブラリをリンクして実行形式へ変換)

以下のコマンドで実際に実行されるコマンドが表示される:

    % g++ -v sample.cpp

以下の出力例では先頭に行番号を追加している。

     1	Using built-in specs.
     2	COLLECT_GCC=g++
     3	COLLECT_LTO_WRAPPER=/usr/libexec/gcc/x86_64-redhat-linux/4.8.5/lto-wrapper
     4	Target: x86_64-redhat-linux
     5	Configured with: ../configure --prefix=/usr --mandir=/usr/share/man --infodir=/usr/share/info --with-bugurl=http://bugzilla.redhat.com/bugzilla --enable-bootstrap --enable-shared --enable-threads=posix --enable-checking=release --with-system-zlib --enable-__cxa_atexit --disable-libunwind-exceptions --enable-gnu-unique-object --enable-linker-build-id --with-linker-hash-style=gnu --enable-languages=c,c++,objc,obj-c++,java,fortran,ada,go,lto --enable-plugin --enable-initfini-array --disable-libgcj --with-isl=/builddir/build/BUILD/gcc-4.8.5-20150702/obj-x86_64-redhat-linux/isl-install --with-cloog=/builddir/build/BUILD/gcc-4.8.5-20150702/obj-x86_64-redhat-linux/cloog-install --enable-gnu-indirect-function --with-tune=generic --with-arch_32=x86-64 --build=x86_64-redhat-linux
     6	Thread model: posix
     7	gcc version 4.8.5 20150623 (Red Hat 4.8.5-28) (GCC)
     8	COLLECT_GCC_OPTIONS='-v' '-shared-libgcc' '-mtune=generic' '-march=x86-64'
     9	 /usr/libexec/gcc/x86_64-redhat-linux/4.8.5/cc1plus -quiet -v -D_GNU_SOURCE sample.cpp -quiet -dumpbase sample.cpp -mtune=generic -march=x86-64 -auxbase sample -version -o /tmp/ccNuDEqA.s
    10	GNU C++ (GCC) version 4.8.5 20150623 (Red Hat 4.8.5-28) (x86_64-redhat-linux)
    11	        compiled by GNU C version 4.8.5 20150623 (Red Hat 4.8.5-28), GMP version 6.0.0, MPFR version 3.1.1, MPC version 1.0.1
    12	GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
    13	ignoring nonexistent directory "/usr/lib/gcc/x86_64-redhat-linux/4.8.5/include-fixed"
    14	ignoring nonexistent directory "/usr/lib/gcc/x86_64-redhat-linux/4.8.5/../../../../x86_64-redhat-linux/include"
    15	#include "..." search starts here:
    16	#include <...> search starts here:
    17	 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/../../../../include/c++/4.8.5
    18	 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/../../../../include/c++/4.8.5/x86_64-redhat-linux
    19	 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/../../../../include/c++/4.8.5/backward
    20	 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include
    21	 /usr/local/include
    22	 /usr/include
    23	End of search list.
    24	GNU C++ (GCC) version 4.8.5 20150623 (Red Hat 4.8.5-28) (x86_64-redhat-linux)
    25	        compiled by GNU C version 4.8.5 20150623 (Red Hat 4.8.5-28), GMP version 6.0.0, MPFR version 3.1.1, MPC version 1.0.1
    26	GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
    27	Compiler executable checksum: 7fb95bf168a3a77dff787b6ebe09443a
    28	COLLECT_GCC_OPTIONS='-v' '-shared-libgcc' '-mtune=generic' '-march=x86-64'
    29	 as -v --64 -o /tmp/cca9OUDM.o /tmp/ccNuDEqA.s
    30	GNU assembler version 2.27 (x86_64-redhat-linux) using BFD version version 2.27-28.base.el7_5.1
    31	COMPILER_PATH=/usr/libexec/gcc/x86_64-redhat-linux/4.8.5/:/usr/libexec/gcc/x86_64-redhat-linux/4.8.5/:/usr/libexec/gcc/x86_64-redhat-linux/:/usr/lib/gcc/x86_64-redhat-linux/4.8.5/:/usr/lib/gcc/x86_64-redhat-linux/
    32	LIBRARY_PATH=/usr/lib/gcc/x86_64-redhat-linux/4.8.5/:/usr/lib/gcc/x86_64-redhat-linux/4.8.5/../../../../lib64/:/lib/../lib64/:/usr/lib/../lib64/:/usr/lib/gcc/x86_64-redhat-linux/4.8.5/../../../:/lib/:/usr/lib/
    33	COLLECT_GCC_OPTIONS='-v' '-shared-libgcc' '-mtune=generic' '-march=x86-64'
    34	 /usr/libexec/gcc/x86_64-redhat-linux/4.8.5/collect2 --build-id --no-add-needed --eh-frame-hdr --hash-style=gnu -m elf_x86_64 -dynamic-linker /lib64/ld-linux-x86-64.so.2 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/../../../../lib64/crt1.o /usr/lib/gcc/x86_64-redhat-linux/4.8.5/../../../../lib64/crti.o /usr/lib/gcc/x86_64-redhat-linux/4.8.5/crtbegin.o -L/usr/lib/gcc/x86_64-redhat-linux/4.8.5 -L/usr/lib/gcc/x86_64-redhat-linux/4.8.5/../../../../lib64 -L/lib/../lib64 -L/usr/lib/../lib64 -L/usr/lib/gcc/x86_64-redhat-linux/4.8.5/../../.. /tmp/cca9OUDM.o -lstdc++ -lm -lgcc_s -lgcc -lc -lgcc_s -lgcc /usr/lib/gcc/x86_64-redhat-linux/4.8.5/crtend.o /usr/lib/gcc/x86_64-redhat-linux/4.8.5/../../../../lib64/crtn.o

15行目から22行目にかけてインクルードファイルを探しているディレクトリが
表示される。「インクルードファイルが無い」というエラーの場合はこの方法で
どこを探しているのかわかる。

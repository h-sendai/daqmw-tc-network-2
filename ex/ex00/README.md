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

Cコンパイラの動作
----------------

- cc (gcc)コマンドは他のコマンドを呼び出すコマンド
- cpp (プリプロセス)
- cc1 (コンパイラ。プリプロセスされたコードをアセンブリコードに変換)
- as  (アセンブラ)
- リンカ (ライブラリをリンクして実行形式へ変換)

以下のコマンドで実際に実行されるコマンドが表示される:

    % g++ -v sample.cpp

    Using built-in specs.
    COLLECT_GCC=g++
    COLLECT_LTO_WRAPPER=/usr/libexec/gcc/x86_64-redhat-linux/4.8.5/lto-wrapper
    Target: x86_64-redhat-linux
    Configured with: ../configure --prefix=/usr --mandir=/usr/share/man --infodir=/usr/share/info --with-bugurl=http://bugzilla.redhat.com/bugzilla --enable-bootstrap --enable-shared --enable-threads=posix --enable-checking=release --with-system-zlib --enable-__cxa_atexit --disable-libunwind-exceptions --enable-gnu-unique-object --enable-linker-build-id --with-linker-hash-style=gnu --enable-languages=c,c++,objc,obj-c++,java,fortran,ada,go,lto --enable-plugin --enable-initfini-array --disable-libgcj --with-isl=/builddir/build/BUILD/gcc-4.8.5-20150702/obj-x86_64-redhat-linux/isl-install --with-cloog=/builddir/build/BUILD/gcc-4.8.5-20150702/obj-x86_64-redhat-linux/cloog-install --enable-gnu-indirect-function --with-tune=generic --with-arch_32=x86-64 --build=x86_64-redhat-linux
    Thread model: posix
    gcc version 4.8.5 20150623 (Red Hat 4.8.5-28) (GCC)
    COLLECT_GCC_OPTIONS='-v' '-shared-libgcc' '-mtune=generic' '-march=x86-64'
     /usr/libexec/gcc/x86_64-redhat-linux/4.8.5/cc1plus -quiet -v -D_GNU_SOURCE sample.cpp -quiet -dumpbase sample.cpp -mtune=generic -march=x86-64 -auxbase sample -version -o /tmp/ccNuDEqA.s
    GNU C++ (GCC) version 4.8.5 20150623 (Red Hat 4.8.5-28) (x86_64-redhat-linux)
            compiled by GNU C version 4.8.5 20150623 (Red Hat 4.8.5-28), GMP version 6.0.0, MPFR version 3.1.1, MPC version 1.0.1
    GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
    ignoring nonexistent directory "/usr/lib/gcc/x86_64-redhat-linux/4.8.5/include-fixed"
    ignoring nonexistent directory "/usr/lib/gcc/x86_64-redhat-linux/4.8.5/../../../../x86_64-redhat-linux/include"
    #include "..." search starts here:
    #include <...> search starts here:
     /usr/lib/gcc/x86_64-redhat-linux/4.8.5/../../../../include/c++/4.8.5
     /usr/lib/gcc/x86_64-redhat-linux/4.8.5/../../../../include/c++/4.8.5/x86_64-redhat-linux
     /usr/lib/gcc/x86_64-redhat-linux/4.8.5/../../../../include/c++/4.8.5/backward
     /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include
     /usr/local/include
     /usr/include
    End of search list.
    GNU C++ (GCC) version 4.8.5 20150623 (Red Hat 4.8.5-28) (x86_64-redhat-linux)
            compiled by GNU C version 4.8.5 20150623 (Red Hat 4.8.5-28), GMP version 6.0.0, MPFR version 3.1.1, MPC version 1.0.1
    GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
    Compiler executable checksum: 7fb95bf168a3a77dff787b6ebe09443a
    COLLECT_GCC_OPTIONS='-v' '-shared-libgcc' '-mtune=generic' '-march=x86-64'
     as -v --64 -o /tmp/cca9OUDM.o /tmp/ccNuDEqA.s
    GNU assembler version 2.27 (x86_64-redhat-linux) using BFD version version 2.27-28.base.el7_5.1
    COMPILER_PATH=/usr/libexec/gcc/x86_64-redhat-linux/4.8.5/:/usr/libexec/gcc/x86_64-redhat-linux/4.8.5/:/usr/libexec/gcc/x86_64-redhat-linux/:/usr/lib/gcc/x86_64-redhat-linux/4.8.5/:/usr/lib/gcc/x86_64-redhat-linux/
    LIBRARY_PATH=/usr/lib/gcc/x86_64-redhat-linux/4.8.5/:/usr/lib/gcc/x86_64-redhat-linux/4.8.5/../../../../lib64/:/lib/../lib64/:/usr/lib/../lib64/:/usr/lib/gcc/x86_64-redhat-linux/4.8.5/../../../:/lib/:/usr/lib/
    COLLECT_GCC_OPTIONS='-v' '-shared-libgcc' '-mtune=generic' '-march=x86-64'
     /usr/libexec/gcc/x86_64-redhat-linux/4.8.5/collect2 --build-id --no-add-needed --eh-frame-hdr --hash-style=gnu -m elf_x86_64 -dynamic-linker /lib64/ld-linux-x86-64.so.2 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/../../../../lib64/crt1.o /usr/lib/gcc/x86_64-redhat-linux/4.8.5/../../../../lib64/crti.o /usr/lib/gcc/x86_64-redhat-linux/4.8.5/crtbegin.o -L/usr/lib/gcc/x86_64-redhat-linux/4.8.5 -L/usr/lib/gcc/x86_64-redhat-linux/4.8.5/../../../../lib64 -L/lib/../lib64 -L/usr/lib/../lib64 -L/usr/lib/gcc/x86_64-redhat-linux/4.8.5/../../.. /tmp/cca9OUDM.o -lstdc++ -lm -lgcc_s -lgcc -lc -lgcc_s -lgcc /usr/lib/gcc/x86_64-redhat-linux/4.8.5/crtend.o /usr/lib/gcc/x86_64-redhat-linux/4.8.5/../../../../lib64/crtn.o

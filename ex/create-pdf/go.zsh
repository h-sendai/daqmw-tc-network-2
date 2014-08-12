#!/bin/zsh

setopt extendedglob
setopt nonomatch

export PATH=/usr/local/texlive/2013/bin/x86_64-linux:$PATH

rm -f ex??.tex
rm -f ex.tex
rm -f *.aux
rm -f *.dvi
rm -fr *.log

pandoc -t latex ../README.md -o ex.tex

for i in {01..13}; do
    pandoc -t latex ../ex${i}/README.md -o ex${i}.tex
done

for i in {01..13}; do
    pandoc -t latex ../ex${i}/README.md -o ex${i}.tex
done

platex frame
dvipdfmx frame

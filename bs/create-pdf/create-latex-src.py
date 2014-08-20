#!/usr/bin/env python

import os
import sys
import time # for sleep

def get_latex_head():
    src = r"""\documentclass[10pt]{jsarticle}
\usepackage{graphicx}
\usepackage{hyperref}
\usepackage{enumerate}
\usepackage{fancyvrb}
\fvset{
    tabsize=4,
    baselinestretch=0.55,
    numbers=left,
    frame=single,
    framesep=5pt,
    numbersep=5pt,
    fontsize=\small,
    % fontfamily=courier,
    % frame=topline,
    % frame=bottomline,
    % frame=lines,
    % frame=single,
    % firstnumber=100,
    % firstnumber=last,
    % comment
}

\begin{document}
"""
    return src

def get_latex_tail():
    src = r'\end{document}'
    return src

def main():
    if len(sys.argv) == 1:
        sys.exit('Usage: create-latex-src filename.tex dir0 dir1 ...')
    
    output = sys.argv[1]

    try:
        fh = open(output, 'w')
    except IOError, e:
        sys.exit(e)

    #print get_latex_head()
    fh.writelines(get_latex_head())

    for d in sys.argv[2:]:
        #for (root, dirs, files) in os.walk('../examples/Skeleton'):
        for (root, dirs, files) in os.walk(d):
            #print '--->', root
            files.sort(key=lambda f: os.path.splitext(f)[1], reverse=True)
            for f in files:
                ext = os.path.splitext(f)[1]
                if f == 'Makefile' or ext == '.cpp' or ext == '.h':
                    file_path = os.path.join(root, f)
                    #section_line = file_path.replace('_', '\_')
                    section_line = file_path.replace('_', '\_').replace('../', '')
                    section_line = os.path.join('bs', section_line)
                    fh.writelines(['\subsection*{%s}' % (section_line), '\n'])
                    fh.writelines([r'\begingroup', '\n'])
                    fh.writelines([r'\catcode`\_=12\relax', '\n'])
                    fh.writelines([r'\VerbatimInput{%s}' % (file_path), '\n'])
                    fh.writelines([r'\endgroup', '\n'])
                    fh.writelines(['\n', r'\clearpage', '\n'])

    fh.writelines(get_latex_tail())

if __name__ == '__main__':
    main()

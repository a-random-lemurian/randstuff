[![CodeQL](https://github.com/a-random-lemurian/randstuff/actions/workflows/codeql-analysis.yml/badge.svg)](https://github.com/a-random-lemurian/randstuff/actions/workflows/codeql-analysis.yml)
```
===< Random Stuff >===============================
A set of apps written in C that output random stuff. At the
moment, only random hex is available.

This project abides by C17 (-std=c17 is one of the compiler
flags used).

===< Compile >===================================
At the moment, this project is source-only, meaning that you must
compile the tools yourself. Simply type 'make' in your terminal,
in the root project directory. Check the bin folder, and then cp
those files to a directory on your $PATH.

Path                   Root user required
/usr/local/bin         yes
~/.local/bin           no

===< OS Support >=================================
Linux
  - Ubuntu 20.04       YES
  - Debian 11          UNTESTED
  - Debian 10          UNTESTED
  - Arch Linux         YES

macOS
  - 11.4 "Big Sur"     UNTESTED

Windows
  - Windows 10         NO [ 1 ]

[ 1 ] Default filename in ./src/randquote.c is `-`, which
      is the Unix identifier for STDIN.

===< Compiler Support >===========================
GCC 9.3.0              YES
GCC 11.1.0             YES
Clang 13.0.0           YES
```

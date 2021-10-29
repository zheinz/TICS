#!/bin/bash

clang++ getTime.cpp -o test

>host.txt
>qemu.txt
>data.txt

./test >> host.txt
qemu-x86_64 test >> qemu.txt

python3 analyse.py >> data.txt

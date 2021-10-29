#!/bin/bash

clang++ getTime.cpp -o test

>data.txt
>finalData.txt

for i in {1..1000}
do
	>host.txt
	>qemu.txt

	./test >> host.txt
	qemu-x86_64 test >> qemu.txt
	python3 analyse.py >> data.txt
done

python3 analyse2.py >>finalData.txt
while getopts "i:" opt
do
	case $opt in 
		i) input=${OPTARG};;
	esac
done

python3 ../annotate.py $input

clang++ annotatedFile.cpp -o a.out
./a.out > output.txt

python3 ../analyse.py output.txt > Host.txt

qemu-x86_64 ./a.out > output.txt

python3 ../analyse.py output.txt > Qemu.txt

python3 ../display.py Host.txt Qemu.txt

rm output.txt
rm annotatedFile.cpp
rm a.out
rm Host.txt
rm Qemu.txt

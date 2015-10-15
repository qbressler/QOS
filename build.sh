#!/bin/sh


build=build
opt="-m32 -Wall -O -fstrength-reduce -fomit-frame-pointer -nostdinc -fno-builtin -I./kernel/include -c -fno-strict-aliasing -fno-common -fno-stack-protector"


echo "======================="
echo "Building Quinix(QOS)"
echo "======================="

# Build C files

#gcc -m32 -Wall -O -fstrength-reduce -fomit-frame-pointer -nostdinc -fno-builtin -I./kernel/include -c -o $build/main.o ./kernel/main.c -fno-strict-aliasing -fno-common -fno-stack-protector
gcc $opt -o $build/main.o ./kernel/main.c 
gcc $opt -o $build/console.o ./kernel/console.c 

# Build ASM files
nasm -f elf ./kernel/loader.asm -o $build/loader.o

# Link 
ld -m elf_i386 -T linker.ld $build/*.o

# Put on floppy image
sudo cp Boot/myos.img myos.img
sudo mkdir /media/floppy1
sudo mount -o loop myos.img /media/floppy1
sudo cp kernel.bin /media/floppy1/
sudo umount /media/floppy1
sudo rm -r /media/floppy1

all: SOX PROJET EXECUTION

menu.o: menu.c
		gcc -c menu.c 

prog.o: prog.c
		gcc -c prog.c

texte.o: texte.c
		gcc -c texte.c 

main.o: main.c header.h
		gcc -c main.c 


PROJET: prog.o menu.o texte.o main.o
		gcc -o PROJET prog.o menu.o texte.o main.o -Wall

SOX:
	sudo apt-get update -y	
	sudo apt-get install sox libsox-fmt-all

EXECUTION:
			./PROJET

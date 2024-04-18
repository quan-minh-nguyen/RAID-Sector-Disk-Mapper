raid: raid.o
	cc raid.o -o raid

raid.o: raid.c
	cc -c raid.c -o raid.o

raid.c:
	echo > raid.c
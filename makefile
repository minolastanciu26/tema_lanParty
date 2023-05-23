build:
	gcc -g -o lanParty main.c liste.c cozi.c stive.c arbori.c

run:
	./lanParty

clean:
	rm lanParty
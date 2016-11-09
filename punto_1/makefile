placas.pdf : grafica.py datos.dat
	python grafica.py
datos.dat : placas.x
	./placas.x > datos.dat
placas.x : placas.c
	gcc placas.c -lm -o placas.x
clean :
	rm -f datos.dat placas.pdf placas.x

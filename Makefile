game:
	g++ -o bin/game *.cpp -Wall `sdl2-config --cflags --libs`

clean:
	rm bin/game


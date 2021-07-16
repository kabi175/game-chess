game:
	g++ -o bin/game *.cpp -Wall `sdl2-config --cflags --libs` -lSDL2_image -lm

clean:
	rm bin/game


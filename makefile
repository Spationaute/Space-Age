SDL = `pkg-config --cflags --libs sdl SDL_image SDL_gfx`
LIBS= -ltar -lboost_regex -lm
GCC = g++
NAME= SpaceAge


all:
	$(GCC) *.cpp -o $(NAME) $(SDL) $(LIBS);

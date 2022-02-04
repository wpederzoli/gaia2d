build:
	g++ -std=c++14 -g -Iheaders/ \
	./src/*.cpp \
	-lSDL2 -lSDL2_image -lSDL2_mixer \
	-o engine
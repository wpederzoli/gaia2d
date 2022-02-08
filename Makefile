build:
	g++ -std=c++14 -Iheaders/ \
	./src/*.cpp \
	-lSDL2 -lSDL2_image -lSDL2_mixer \
	-o engine
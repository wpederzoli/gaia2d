build:
	g++ -std=c++14 -g -Iheaders/ \
	./src/*.cpp \
	-lSDL2  \
	-o engine
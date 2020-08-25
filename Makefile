target = main.cpp
libs = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
cxxargs = -O3 -Wall
all: ${target}
	${CXX} ${target} ${cxxargs} ${libs} -o warframebattleroyael

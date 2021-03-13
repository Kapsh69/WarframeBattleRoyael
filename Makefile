SOURCES = main.cpp
OBJECTS = ${SOURCES:.cpp=.o}

TARGET = warframebattleroyael
CXXFLAGS = -O2 -Wall -pipe
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

.PHONY: all clean

all: ${OBJECTS}
	${CXX} ${OBJECTS} ${CXXFLAGS} ${LDFLAGS} -o ${TARGET}

clean:
	-${RM} ${OBJECTS}

$(filter %.o, ${OBJECTS}): %.o: %.cpp
	${CXX} $< ${CXXFLAGS} -c -o $@

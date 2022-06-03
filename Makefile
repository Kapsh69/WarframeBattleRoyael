ifeq ($(shell echo "check_quotes"),"check_quotes")
# Windows
SOURCES := $(shell dir /s /B *.cxx)
TARGETEXT := .exe
RUN := start 
else
# UNIX
SOURCES := $(shell find . -name "*.cxx")
TARGETEXT := .out
RUN := ./
endif

OBJECTS = ${SOURCES:.cxx=.o}

TARGET = wbr${TARGETEXT}
TARGETDIR = bin

CXXFLAGS = -O2 -pipe -Wall -Isrc
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio


.PHONY: all clean run

all: ${OBJECTS}
	${CXX} ${OBJECTS} ${CXXFLAGS} ${LDFLAGS} -o ${TARGETDIR}/${TARGET}

run: ${TARGETDIR}/${TARGET}
	cd ${TARGETDIR} && ${RUN}${TARGET}

clean:
	${RM} ${OBJECTS}

$(filter %.o, $(OBJECTS)): %.o: %.cxx
	${CXX} $< ${CXXFLAGS} -c -o $@

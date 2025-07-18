INCLUDEDIR := /usr/include
TARGET := wow.h
SRC := wow.h

all: install

install:
	cp $(SRC) $(INCLUDEDIR)/$(TARGET)

uninstall:
	rm $(INCLUDEDIR)/$(TARGET)

.PHONY: all install uninstall


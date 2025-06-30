INCLUDEDIR := /usr/include
TARGET := wow.h
SRC := wow.h

all: install

check-root:
	@if [ "$$(id -u)" -ne 0 ]; then \
		echo "Error: This command must be run as root (use sudo)."; \
		exit 1; \
	fi

install: check-root
	@if [ ! -f $(SRC) ]; then \
		echo "Error: $(SRC) not found!"; \
		exit 1; \
	fi
	@echo "Installing $(SRC) to $(INCLUDEDIR)/$(TARGET)..."
	cp $(SRC) $(INCLUDEDIR)/$(TARGET)
	@echo "Installed."

uninstall: check-root
	@if [ ! -f $(INCLUDEDIR)/$(TARGET) ]; then \
		echo "Warning: $(INCLUDEDIR)/$(TARGET) not found, nothing to remove."; \
		exit 0; \
	fi
	@echo "Removing $(INCLUDEDIR)/$(TARGET)..."
	rm $(INCLUDEDIR)/$(TARGET)
	@echo "Removed."

clean:
	@echo "Nothing to clean."

.PHONY: all install uninstall clean check-root


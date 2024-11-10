# Variables
MCU = atmega328p
F_CPU = 16000000UL
BAUD = 115200
PORT ?= COM5# Set the COM port manually or override with `make PORT=COMx`
PROGRAMMER = arduino
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
SRC = $(SRC_DIR)/example.c
OBJ = $(BUILD_DIR)/example.elf
HEX = $(BUILD_DIR)/example.hex

# Compiler and flags
CC = avr-gcc
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Wall -Os -I$(INCLUDE_DIR)
OBJCOPY = avr-objcopy
AVRDUDE = avrdude

# Default target: Compile, upload and clean
all: compile upload clean

# Compile to ELF and HEX
compile: $(SRC)
	$(CC) $(CFLAGS) -o $(OBJ) $(SRC)
	$(OBJCOPY) -O ihex -R .eeprom $(OBJ) $(HEX)
	@echo "Compilation complete. HEX file created: $(HEX)"

# Upload using avrdude
upload: $(HEX)
	$(AVRDUDE) -v -p$(MCU) -c$(PROGRAMMER) -P$(PORT) -b$(BAUD) -D -Uflash:w:$(HEX):i
	@echo "Upload complete."

# Clean up generated files
clean:
	rm -f $(OBJ) $(HEX)
	@echo "Cleaned up."

# Phony targets
.PHONY: all compile upload clean
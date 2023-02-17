PORT = -p COM3
BAUD = -b 115200
ARGS = ${PORT} ${BAUD}
COMMAND = idf.py

all: build flash monitor

build:
	${COMMAND} build

flash:
	${COMMAND} ${ARGS} flash

monitor:
	${COMMAND} ${ARGS} monitor

.PHONY: all build flash monitor

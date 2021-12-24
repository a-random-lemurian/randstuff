COMPILE_FLAGS=-O3 -Wpedantic -Wall -Werror -fstack-protector
main:
	gcc "./src/randhex.c" -o "./bin/randhex" ${COMPILE_FLAGS}
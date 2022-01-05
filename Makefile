CC=gcc
COMPILE_FLAGS=-std=c17 -O3 -Wpedantic -Wall -Werror -fstack-protector
main:
	mkdir -p "bin" "build"
	$(CC) "src/randascii.c" -o "bin/randascii" ${COMPILE_FLAGS}
	$(CC) "src/randhex.c" -o "bin/randhex" ${COMPILE_FLAGS}
	$(CC) "src/randfromargs.c" -o "bin/randfromargs" ${COMPILE_FLAGS}
	$(CC) "src/randquote.c" -o "bin/randquote" ${COMPILE_FLAGS} -lm

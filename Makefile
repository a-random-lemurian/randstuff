COMPILE_FLAGS=-std=c17 -O3 -Wpedantic -Wall -Werror -fstack-protector -v -save-temps
main:
	mkdir -p "bin" "build"
	gcc "./src/randascii.c" -o "./bin/randascii" ${COMPILE_FLAGS}
	gcc "./src/randhex.c" -o "./bin/randhex" ${COMPILE_FLAGS}
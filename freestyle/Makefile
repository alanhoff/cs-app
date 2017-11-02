all: bin-to-hex hex-to-bin is-power-of-two

bin-to-hex:
	gcc -ansi shared.c bin-to-hex.c -o bin-to-hex

hex-to-bin:
	gcc -ansi shared.c hex-to-bin.c -o hex-to-bin

is-power-of-two:
	gcc -ansi shared.c is-power-of-two.c -o is-power-of-two

clean:
	rm -rf bin-to-hex hex-to-bin is-power-of-two

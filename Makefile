generator: main.c dictionary.c
	gcc -g -o $@ $^

clean:
	rm -rf generator generator.exe

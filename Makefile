generator: main.c
	gcc -g -o $@ $<

clean:
	rm -rf generator generator.exe

all:
	gcc main.c -o xcows -lX11 -lXpm
clean:
	rm xcows
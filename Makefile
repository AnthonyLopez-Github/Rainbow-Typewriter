all: raintype

raintype: raintype.c
	gcc raintype.c -o raintype

clean:
	rm -f raintype

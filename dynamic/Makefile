CC := gcc

PACKAGES := \
	drmollineda.so \
	danrdominguez.so

%.so: proc_%.c
	$(CC) -shared -fpic -o $@ $^

all: ${PACKAGES}

clean:
	rm -rf *.o *.so

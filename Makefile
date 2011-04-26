
# -L/usr/X11R6/lib
LDFLAGS=-lX11


BINS=xkb-reset


all: $(BINS)
#xkb-reset:
#	cc -L /usr/X11R6/lib   -lX11 xkb-reset.c -o xkb-reset


bindir=$(DESTDIR)/usr/bin/

install: xkb-reset
	install --directory $(bindir)
	install -D xkb-reset $(bindir)/xkb-reset

xkb-reset:xkb-reset.c
	$(CC) $^ -o $@ -lX11

clean:
	rm -f $(BINS)


.PHONY:	clean all install

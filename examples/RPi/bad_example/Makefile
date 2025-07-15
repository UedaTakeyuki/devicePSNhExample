ALL     = main
all: $(ALL)

%: %.c
	gcc $^ -o $@ `pkg-config --cflags --libs glib-2.0`

clean:
	rm -f $(ALL)

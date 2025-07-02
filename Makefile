SRCS    = main.c \
          devicePSNh.a
HDRS    = *.h 
ALL     = $(SRCS) $(HDRS) 

devicePSNh: $(ALL)
	# $@ target name
	# $< the first name of dependency
	# $^ all dependencies of the target
	# https://tex2e.github.io/blog/makefile/automatic-variables
	gcc $(SRCS) -g `pkg-config --cflags --libs openssl json-glib-1.0 glib-2.0 libcurl` -D __linux__ -o $@

clean:
	rm -f devicePSNh

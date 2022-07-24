CC = clang++
CFLAGS = -std=c++20 -O2 -Wall -Werror
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

.PHONY: all
all:
	$(CC) $(CFLAGS) -o pixel_engine src/main.cc $(LDFLAGS)

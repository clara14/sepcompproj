#
# Makefile for asteroids game
#
# Enter one of the following
#
# make
# make all
# make asteroids
# make clean
#
CFLAGS = -I ./include
#LFLAGS = -lrt -lX11 -lGLU -lGL -pthread -lm
LFLAGS = -lrt -lX11 -lGL

all: zombies

zombies: zombies.cpp log.cpp timers.cpp Global.o Bullet.o Ship.o \
	 Game.o functions.o physics.o render.o
	g++ $(CFLAGS) zombies.cpp log.cpp timers.cpp X11_wrapper.o Global.o Bullet.o \
	Ship.o Game.o functions.o physics.o render.o libggfonts.a -Wall $(LFLAGS) -o zombies

clean:
	rm -f zombies
	rm -f *.o

Global.o: Global.h Global.cpp
	g++ $(CFLAGS) -Wall -c Global.cpp

X11_wrapper.o: X11_wrapper.h X11_wrapper.cpp
	g++ $(CFLAGS) -Wall -c X11_wrapper.cpp

Bullet.o: Bullet.h Bullet.cpp
	g++ $(CFLAGS) -Wall -c Bullet.cpp

Ship.o: Ship.h Global.h Global.cpp Ship.cpp
	g++ $(CFLAGS) -Wall -c Ship.cpp 

Game.o: Game.h Game.cpp
	g++ $(CFLAGS) -Wall -c Game.cpp

functions.o: functions.h functions.cpp
	g++ $(CFLAGS) -Wall -c functions.cpp

physics.o: physics.h physics.cpp
	g++ $(CFLAGS) -Wall -c physics.cpp

render.o: render.h render.cpp
	g++ $(CFLAGS) -Wall -c render.cpp


# --------------------------------------

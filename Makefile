CXXFLAGS = -std=c++11
LDFLAGS = -L/usr/local/lib -lfltk -lXext -lX11 -lm -lfltk_images

all: main

debug: CXXFLAGS += -g
debug: main

rebuild: clean main

main: robbie_robot_shop_gui.cpp
	$(CXX) $(CXXFLAGS) $(fltk-config --use-images --cxxflags) robbie_robot_shop_gui.cpp $(LDFLAGS)

clean:
	-rm -f *.o *~ a.out

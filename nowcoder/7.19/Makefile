.PHONY:clean all
CXXFLAGS = -g -std=c++11 -O0 -Wall -Wextra 
BIN=bracket a game
all:$(BIN)
%.o:%.cpp
	g++ $(CXXFLAGS)  -c $< -o $@
clean:
	rm -f *.o $(BIN)

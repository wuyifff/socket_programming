
src = $(wildcard *.cpp)

obj=$(patsubst %.cpp, %.exe, $(src))

all : $(obj)
%.exe:%.cpp
	g++ $< -o $@ -Wall

.PHONY:clean
clean:
	-rm  -f $(obj)


cc=g++
flags=-lsfml-graphics -lsfml-window -lsfml-system -Wall
inc=include
src=src
obj=obj
deps=$(foreach var,$(wildcard $(src)/*.cpp),$(subst cpp,o,$(subst $(src),$(obj),$(var)))) main.cpp

$(obj):
	mkdir $(obj)

$(obj)/%.o: $(src)/%.cpp $(obj)
	$(cc) -c -o $@ $< $(flags)

install: $(deps)
	$(cc) -o test $^ $(flags)

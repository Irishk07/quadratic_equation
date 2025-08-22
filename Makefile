CXX = g++

CPPFLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

CPPSRC = main.cpp solver.cpp in_out_put.cpp cat.cpp

CPPOBJ = build/main.o build/solver.o build/in_out_put.o build/cat.o

HEADER_DEPENDS = $(CPPOBJ:%.o=%.d)

.PHONY: all
all: prog.exe

$(CPPOBJ): build/%.o: %.cpp
	$(CXX) $(CPPFLAGS) -MP -MMD -c $< -o $@

prog.exe: $(CPPOBJ) 
	$(CXX) $^ -o $@ $(CPPFLAGS)

-include $(HEADER_DEPENDS)
 
.PHONY: doxygen
doxygen:
	doxygen docs/Doxyfile

.PHONY: clean
clean:
	del build\*.o /a /s
	del build\*.d /a /s

CXX = g++

CPPFLAGS = -D _DEBUG -ggdb3 -std=c++17 -O0 -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations -Wc++14-compat \
-Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy \
-Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op \
-Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow \
-Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn \
-Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef \
-Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers \
-Wno-narrowing -Wno-old-style-cast -Wno-varargs -fcheck-new -fsized-deallocation -fstack-protector \
-fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer -Wlarger-than=8192 -Wstack-usage=8192 -pie -fPIE -Werror=vla \
-fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,$\
null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr

#override CPPFLAGS += -DPRINT_CAT_FROM_FILE
#override CPPFLAGS += -DNDEBUG

CPPSRC = main.cpp solver.cpp in_out_put.cpp cat.cpp test.cpp pass_arg.cpp

CPPOBJ = $(CPPSRC:%.cpp=build/%.o)

HEADER_DEPENDS = $(CPPOBJ:%.o=%.d)

PHONY: all #run
all: prog

# run: all
# 	./prog.exe 

# .PHONY: all test
# all: prog.exe

# test: all
# 	./prog.exe test.txt

$(CPPOBJ): build/%.o: %.cpp
	$(CXX) $(CPPFLAGS) -MP -MMD -c $< -o $@

prog: $(CPPOBJ) 
	$(CXX) $^ -o $@ $(CPPFLAGS)

-include $(HEADER_DEPENDS)
 
.PHONY: doxygen
doxygen:
	doxygen docs/Doxyfile

.PHONY: clean
clean:
	rm -f build/*.o
	rm -f build/*.d

OBJ = obj
LIB = ../lib
LIBOBJ = $(LIB)/obj

CXXFLAGS = -g -Wextra -Wall --pedantic-errors -Wno-sign-compare -std=c++98
CXXFLAGS_TEST = -g -Wextra -Wall --pedantic-errors -Wno-sign-compare -std=c++11 -lgtest
INCLUDE = -I$(LIB)

ARGS = $(CXXFLAGS) $(INCLUDE)

8_0_median: $(OBJ)/8_0_median.o $(LIBOBJ)/median.o
	g++ $^ -o $@


8_0_binsearch: $(OBJ)/8_0_binsearch.o
	g++ $^ -o $@

8_0_stream_iterators: $(OBJ)/8_0_stream_iterators.o
	g++ $^ -o $@

8_0_split: $(OBJ)/8_0_split.o $(LIBOBJ)/string_utils.o
	g++ $^ -o $@

8_1: $(OBJ)/8_1.o $(LIBOBJ)/compare_schemes.o $(LIBOBJ)/Student_info.o \
			 $(LIBOBJ)/grade.o $(LIBOBJ)/median.o $(LIBOBJ)/average.o
	g++ $^ -o $@

8_2: 8_2.cpp
	g++ $(CXXFLAGS_TEST) $(INCLUDE) $^ -o $@

8_4: $(OBJ)/8_4.o
	g++ $^ -o $@

8_5: $(OBJ)/8_5.o $(LIBOBJ)/strvect_utils.o $(LIBOBJ)/grammar.o \
			$(LIBOBJ)/random.o $(LIBOBJ)/string_utils.o
	g++ $^ -o $@

$(OBJ)/%.o: %.cpp
	g++ -c $(ARGS) $^ -o $@

$(LIBOBJ)/%.o: $(LIB)/%.cpp
	g++ -c $(ARGS) $^ -o $@

clean:
	rm -f $(OBJ)/*
	rm -f $(LIBOBJ)/*
	rm -f 8_0_median
	rm -f 8_0_binsearch
	rm -f 8_0_stream_iterators

.PHONY: clean
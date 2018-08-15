OBJ = obj
LIB = ../lib
LIBOBJ = $(LIB)/obj

CXXFLAGS = -g -Wextra -Wall --pedantic-errors -Wno-sign-compare -std=c++98
INCLUDE = -I$(LIB)

ARGS = $(CXXFLAGS) $(INCLUDE)

7_0_words: $(OBJ)/7_0_words.o
	g++ $^ -o $@

7_0_xref: $(OBJ)/7_0_xref.o $(LIBOBJ)/xref.o $(LIBOBJ)/string_utils.o
	g++ $^ -o $@

7_0_grammar: $(OBJ)/7_0_grammar.o $(LIBOBJ)/strvect_utils.o $(LIBOBJ)/grammar.o \
			$(LIBOBJ)/random.o $(LIBOBJ)/string_utils.o
	g++ $^ -o $@

7_1: $(OBJ)/7_1.o $(LIBOBJ)/strvect_utils.o
	g++ $^ -o $@

7_2: $(OBJ)/7_2.o $(LIBOBJ)/grade.o $(LIBOBJ)/average.o $(LIBOBJ)/median.o \
	$(LIBOBJ)/Student_info.o
	g++ $^ -o $@

$(OBJ)/%.o: %.cpp
	g++ -c $(ARGS) $^ -o $@

$(LIBOBJ)/%.o: $(LIB)/%.cpp
	g++ -c $(ARGS) $^ -o $@

clean:
	rm -f $(OBJ)/*
	rm -f $(LIBOBJ)/*
	rm -f 7_0_words
	rm -f 7_0_xref

.PHONY: clean
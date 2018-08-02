CXXFLAGS = -g -Wextra -Wall --pedantic-errors -Wno-sign-compare -std=c++98
INCLUDE = -I$(LIB)

OBJ = obj
LIB = ../lib
LIBOBJ = obj

6_0_strings: $(OBJ)/6_0_strings.o $(LIB)/$(LIBOBJ)/string_utils.o $(LIB)/$(LIBOBJ)/strvect_utils.o
	g++ $^ -o $@

$(OBJ)/6_0_strings.o: 6_0_strings.cpp
	g++ -c $(INCLUDE) $(CXXFLAGS) $^ -o $@

$(LIB)/$(LIBOBJ)/string_utils.o: $(LIB)/string_utils.cpp
	g++ -c $(INCLUDE) $(CXXFLAGS) $^ -o $@

$(LIB)/$(LIBOBJ)/strvect_utils.o: $(LIB)/strvect_utils.cpp
	g++ -c $(INCLUDE) $(CXXFLAGS) $^ -o $@

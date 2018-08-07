CXXFLAGS = -g -Wextra -Wall --pedantic-errors -Wno-sign-compare -std=c++98
INCLUDE = -I$(LIB)

OBJ = obj
LIB = ../lib
LIBOBJ = $(LIB)/obj

6_0_strings: $(OBJ)/6_0_strings.o $(LIBOBJ)/string_utils.o $(LIBOBJ)/strvect_utils.o
	g++ $^ -o $@

6_0_grading: $(OBJ)/6_0_grading.o $(LIBOBJ)/compare_schemes.o $(LIBOBJ)/Student_info.o \
			 $(LIBOBJ)/grade.o $(LIBOBJ)/median.o $(LIBOBJ)/average.o
	g++ $^ -o $@

6_0_extractfails: $(OBJ)/6_0_extractfails.o $(LIBOBJ)/Student_info.o  $(LIBOBJ)/fails.o \
				  $(LIBOBJ)/grade.o $(LIBOBJ)/median.o $(LIBOBJ)/average.o
	g++ $^ -o $@

6_3: $(OBJ)/6_3.o
	g++ $^ -o $@

6_4: $(OBJ)/6_4.o
	g++ $^ -o $@

#$(OBJ)/6_0_strings.o: 6_0_strings.cpp
#	g++ -c $(INCLUDE) $(CXXFLAGS) $^ -o $@

$(OBJ)/%.o: %.cpp
	g++ -c $(INCLUDE) $(CXXFLAGS) $^ -o $@

$(LIBOBJ)/%.o: $(LIB)/%.cpp
	g++ -c $(INCLUDE) $(CXXFLAGS) $^ -o $@

#$(LIBOBJ)/string_utils.o: $(LIB)/string_utils.cpp
#	g++ -c $(INCLUDE) $(CXXFLAGS) $^ -o $@

#$(LIBOBJ)/strvect_utils.o: $(LIB)/strvect_utils.cpp
#	g++ -c $(INCLUDE) $(CXXFLAGS) $^ -o $@

clean:
	rm $(OBJ)/*
	rm $(LIBOBJ)/*
	rm 6_0_grading
	rm 6_0_strings

.PHONY: clean
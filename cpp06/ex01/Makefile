# Compiler and flags
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

# Directories
OBJDIR = build

# Source and output
SRC = main.cpp Serializer.cpp
OBJ = $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRC))
NAME = serial

# Default rule
all: $(NAME)

# Link
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

# Compile: put .o files into $(OBJDIR)
$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -rf $(OBJDIR)

# Clean objects + binary + shrubbery files
fclean: clean
	rm -f $(NAME)

# Rebuild
re: fclean all

.PHONY: all clean fclean re

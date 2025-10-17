# Compiler and flags
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

# Directories
OBJDIR = build

# Source and output
SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp
OBJ = $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRC))
NAME = forms

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
	# Remove any files ending with _shrubbery in the working directory
	rm -f *_shrubbery

# Rebuild
re: fclean all

.PHONY: all clean fclean re

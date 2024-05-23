CXX=		c++
CXXFLAGS=	-Wall -Wextra -Werror -std=c++98 -g
NAME=		main

FILES=		main Base A B C funcs
SRCS=		$(addsuffix .cpp, $(FILES))
OBJ_DIR=	objs
OBJS=		$(addprefix ./$(OBJ_DIR)/, $(SRCS:.cpp=.o))

HD_FILES=	Base A B C funcs
HEADER=		$(addsuffix .hpp, $(HD_FILES))

RM=			rm -rf

.PHONY: all clean fclean re

all:	$(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(HEADER)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

objs/%.o:	%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir objs

clean:
	$(RM) objs

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

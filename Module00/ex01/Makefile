CXX=		c++
CXXFLAGS=	-Wall -Wextra -Werror -std=c++98
NAME=		PhoneBook

FILES=		PhoneBook Contact
SRCS=		$(addsuffix .cpp, $(FILES))
OBJ_DIR=	objs
OBJS=		$(addprefix ./$(OBJ_DIR)/, $(SRCS:.cpp=.o))

HD_FILES=	PhoneBook Contact
HEADER=		$(addsuffix .hpp, $(HD_FILES))

RM=			rm -rf

.PHONY: all bonus clean fclean re

all:	$(NAME)

$(NAME): $(OBJS) #$(HEADER)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

objs/%.o:	%.cpp $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir objs

clean:
	$(RM) objs
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

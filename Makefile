NAME		=	ft_scop

# Config
# ==============================================================================
CC			=	c++

CPPFLAGS	=	-Wall -Wextra -std=c++17 -MMD $(DBGFLAGS) $(INCLUDE)

ifeq ($(MAKECMDGOALS), debug)
	DBGFLAGS = -g3 -fsanitize=address
endif

INCLUDE 	=	-I/usr/local/include -I/opt/local/include -I/opt/homebrew/include \
			 	-Ivendor/imgui -Ivendor/glm -Ivendor/glad -Ivendor/stb

LIBS 		=	-framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo \
			 	-L/usr/local/lib -L/opt/homebrew/lib -lglfw

RM			=	rm -rf

# Files
# ==============================================================================
DIR_SRCS		=	srcs/
DIR_OBJ			=	objs/

SRCS_CORE		=	main.cpp core.cpp core_imgui.cpp renderer.cpp shader.cpp \
					texture.cpp

DIR_ASSET		=	asset/
SRCS_ASSET		=	mesh.cpp parser.cpp model.cpp

DIR_COMPONENTS	=	components/
SRCS_COMPONENTS	=	camera.cpp

IMGUI_DIR		=	vendor/imgui/
SRCS_IMGUI		=	imgui.cpp imgui_draw.cpp imgui_tables.cpp imgui_widgets.cpp \
					imgui_impl_glfw.cpp imgui_impl_opengl3.cpp imgui_stdlib.cpp

GLM_DIR			=	vendor/glm/detail/
SRCS_GLM		=	glm.cpp

GLAD_DIR		=	vendor/glad/glad/
SRCS_GLAD		=	glad.cpp

SRCS		=	$(addprefix $(DIR_SRCS), $(SRCS_CORE)) \
				$(addprefix $(IMGUI_DIR), $(SRCS_IMGUI)) \
				$(addprefix $(GLM_DIR), $(SRCS_GLM)) \
				$(addprefix $(GLAD_DIR), $(SRCS_GLAD)) \
				$(addprefix $(DIR_COMPONENTS)$(DIR_SRCS), $(SRCS_COMPONENTS)) \
				$(addprefix $(DIR_ASSET)$(DIR_SRCS), $(SRCS_ASSET))

OBJS 		=	$(addprefix $(DIR_OBJ), $(notdir $(SRCS:.cpp=.o)))

DEPS		=	$(OBJS:.o=.d)

# Rules
# ==============================================================================
all: $(NAME)

$(DIR_OBJ)%.o: $(DIR_SRCS)/*/%.cpp | $(DIR_OBJ)
	$(CC) $(CPPFLAGS) -c $< -o $@

$(DIR_OBJ)%.o: $(DIR_SRCS)%.cpp | $(DIR_OBJ)
	$(CC) $(CPPFLAGS) -c $< -o $@

$(DIR_OBJ)%.o: $(IMGUI_DIR)/%.cpp | $(DIR_OBJ)
	$(CC) $(CPPFLAGS) -c $< -o $@

$(DIR_OBJ)%.o: $(GLAD_DIR)/%.cpp | $(DIR_OBJ)
	$(CC) $(CPPFLAGS) -c $< -o $@

$(DIR_OBJ)%.o: $(GLM_DIR)/%.cpp | $(DIR_OBJ)
	$(CC) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) $(LIBS) -o $(NAME)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME)

debug: all

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

print-%:	; @echo $* = $($*)

.PHONY: all clean fclean re run debug print-

# Dependencies
# ==============================================================================
-include $(DEPS)

# Extra
# ==============================================================================
header:
	@printf "\n"
	@printf "$(_ORANGE)\t \n$(_END)"
	@printf "$(_ORANGE)\t \n$(_END)"
	@printf "$(_ORANGE)\t \n$(_END)"
	@printf "$(_ORANGE)\t \n$(_END)"
	@printf "$(_ORANGE)\t \n$(_END)"
	@printf "$(_ORANGE)\t \n$(_END)"
	@printf "\n"

.PHONY: header

# Colors
# ==============================================================================
_GREY	= \033[30m
_RED	= \033[31m
_ORANGE	= \033[38;5;209m
_GREEN	= \033[32m
_YELLOW	= \033[33m
_BLUE	= \033[34m
_PURPLE	= \033[35m
_CYAN	= \033[36m
_WHITE	= \033[37m
_END	= \033[0m

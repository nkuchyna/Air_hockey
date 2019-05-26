NAME = aero_hockey
CLANG = clang++ -std=c++14
FLAGS = -Wall -Wextra -Werror
SRC_NAME = main.cpp ErrorException.cpp Vector.cpp SPlayerSDL.cpp\
			view/SDLRender.cpp view/View.cpp view/SDLTextureFabric.cpp view/Animation.cpp\
			model/Menu.cpp model/Particle.cpp model/Puck.cpp model/Paddle.cpp model/ParticleManager.cpp model/Level.cpp\
			controller/Game.cpp controller/Controller.cpp controller/Physics.cpp

INC_GEN	 =  ErrorException.h  Aero_hockey.h Vector.h ISPlayer.h SPlayerSDL.h
INC_VIEW =  view/SDLRender.h view/IRender.h view/View.h\
			view/SDLTextureFabric.h view/ITexturefabric.h view/Animation.h
INC_MODEL = model/Menu.h model/Particle.h model/Puck.h model/Paddle.h\
			model/ParticleManager.h model/Level.h
INC_CONTR = controller/Game.h controller/Controller.h controller/Physics.h

OBJ_NAME = $(SRC_NAME:.cpp=.o)
SRC_PATH = ./src/

INC_PATH = ./inc/
INC_VIEW = ./inc/view
INC_MODEL = ./inc/model
INC_CONTR = ./inc/controller

OBJ_PATH = ./obj/
OBJ_VIEW = ./obj/view
OBJ_MODEL = ./obj/model
OBJ_CONTR = ./OBJ/controller

FRM = -F ./SDL/ -framework SDL2 -framework SDL2_image -framework SDL2_TTF -framework SDL2_mixer
FRM_INC_NAME = ./SDL/SDL2.framework/Headers ./SDL/SDL2_ttf.framework/Headers\
				./SDL/SDL2_image.framework/Headers ./SDL/SDL2_mixer.framework/Headers
FRM_INC = $(addprefix -I, $(FRM_INC_NAME))

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
INC = -I $(INC_PATH) -I $(INC_VIEW) -I $(INC_MODEL) -I $(INC_CONTR)
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

all: $(NAME)

$(NAME) : $(OBJ)
	$(CLANG) -o $(NAME) $(OBJ) $(FLAGS) $(FRM_INC) $(FRM) 

$(OBJ):		| $(OBJ_PATH)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH) $(OBJ_VIEW) $(OBJ_MODEL) $(OBJ_CONTR)


$(OBJ_PATH)%.o : $(SRC_PATH)%.cpp
	$(CLANG) -c $< -o $@ $(INC) $(FRM_INC)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

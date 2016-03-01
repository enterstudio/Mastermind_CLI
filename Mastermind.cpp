#include "Mastermind.h"

int main()
{
	int decision = 0;
	Mastermind game;
	AsciiImage img = game.getMastermindImage();
	game.printAsciiImage(img);
	game_code codegen = game.Generate_Code();
	
	decision = game.game_begin(codegen);

	if(decision == 1)
	{
		printf("You won\n");
	}
	else if(decision == -1)
	{
		printf("You Lost\n");
	}
	else if(decision == -2)
	{
		printf("OOPS you entered the wrong number please try again using (make run)\n");
	}
	else
	{
		printf("There is a bug, please contact:- prashantrar@gmail.com");
	}

	printf("Generated code is %d %d %d %d\n",codegen.pos1,codegen.pos2,codegen.pos3,codegen.pos4);

	return 0;


}


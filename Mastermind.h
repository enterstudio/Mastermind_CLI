#include<iostream>
#include<stdio.h>
#include<math.h>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef struct game_code
{
	int pos1;
	int pos2;
	int pos3;
	int pos4;
}game_code;

typedef struct game_row
{
	int pos1;
	int pos2;
	int pos3;
	int pos4;
	int pos5;
	char *str[4];
}game_row;

typedef struct AsciiImageStruct {
	char **data;
	int rows;
}AsciiImage;

class Mastermind
{
	public:
		game_row rows[8];
		Mastermind();
		AsciiImage getMastermindImage();
		void printAsciiImage(AsciiImage img);
		game_code Generate_Code();
		int game_begin(game_code codegen);
		void print_rows();

};

Mastermind::Mastermind() {
	int i;
	for(i=0;i<8;i++)
	{
		rows[i].pos1 = 0;
		rows[i].pos2 = 0;
		rows[i].pos3 = 0;
		rows[i].pos4 = 0;
		rows[i].str[0] = " ";
		rows[i].str[1] = " ";
		rows[i].str[2] = " ";
		rows[i].str[3] = " ";
	}
}

AsciiImage Mastermind::getMastermindImage() {
	static char *lines[] = {
		"*	::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::	*\t",
		"*	::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::	*\t",
		"*	o     o                 o                 o     o  o            8	*\t",
		"*	8b   d8                 8                 8b   d8               8	*\t", 
		"*	8`b d'8 .oPYo. .oPYo.  o8P .oPYo. oPYo.   8`b d'8 o8 odYo. .oPYo8	*\t", 
		"*	8 `o' 8 .oooo8 Yb..     8  8oooo8 8  `'   8 `o' 8  8 8' `8 8    8	*\t", 
		"*	8     8 8    8   'Yb.   8  8.     8       8     8  8 8   8 8    8	*\t", 
		"*	8     8 `YooP8 `YooP'   8  `Yooo' 8       8     8  8 8   8 `YooP'	*\t", 
		"*	..::::..:.....::.....:::..::.....:..::::::..::::..:....::..:.....:	*\t",
		"*	:::::::::::::::::::::::by :- Prashant Ravi::::::::::::::::::::::::	*\t",
		"*	::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::	*\t",
		"*	::: This is a modified mastermind game using numbers(1-8)      :::	*\t",
		"*	::: A code is generated with 4 numbers(1-8) you have 8 tries   :::	*\t",
		"*	::: The code has 4 numbers between 1-8 without repetition      :::	*\t",
		"*	::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::	*\t",
		"*	::: In each try you can guess the code by keying in 4 numbers  :::	*\t",
		"*	::: In a successful try the numbers entered and their position :::	*\t",
		"*	::: will match with that of the generated code and you win     :::	*\t",
		"*	::: If you fail to guess the code in 8 trials, you loose       :::	*\t",
		"*	::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::	*\t",
		"*	::: After each try, you get feedback on the code you keyed in  :::	*\t",
		"*	::: The feedback column will be displayed along with the input :::	*\t",
		"*	::: You must use the feedback to guess the code correctly      :::	*\t",
		"*	::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::	*\t",
		"*	::: ░:- the number is correct but not in the right position    :::	*\t",
		"*	::: █:- the number is correct and in the right position        :::	*\t",
		"*	::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::	*\t",
	};
	return (AsciiImage){ lines, sizeof(lines)/sizeof(char*) };
}


void Mastermind::printAsciiImage(AsciiImage img){
	int i;
	for(i=0; i<img.rows; i++) {
		printf("%s\n", img.data[i]);
	}
	printf("\n");
}

game_code Mastermind::Generate_Code() {
	srand ( time(NULL) );
	int arr[4] ={0,0,0,0};
	int i = 0;
	int temp = 0;
	arr[0] = 1 + (rand() % 8);
	game_code retval;
	for(i=1;i<4;i++)
	{
		temp = 1 + (rand() % 8);
		while(temp == arr[0] | temp == arr[1] | temp == arr[2] | temp == arr[3])
		{
			temp = 1 + (rand() % 8);
		}
		arr[i] = temp;
	}
	retval.pos1 = arr[0];
	retval.pos2 = arr[1];
	retval.pos3 = arr[2];
	retval.pos4 = arr[3];

	return retval;

}

int Mastermind::game_begin(game_code codegen) {
	int i = 0;
	for(i=0;i<8;i++)
	{	
		int a,b,c,d,match_inc,str_inc;
		int match[4] = {0,0,0,0};
		a=b=c=d=match_inc=str_inc=0;
		printf("*	::::::::::::::::::╔╦╗┌─┐┌─┐┌┬┐┌─┐┬─┐╔╦╗┬┌┐┌┌┬┐::::::::::::::::::::	*\n"
			   "*	::::::::::::::::::║║║├─┤└─┐ │ ├┤ ├┬┘║║║││││ ││::::::::::::::::::::	*\n"
			   "*	::::::::::::::::::╩ ╩┴ ┴└─┘ ┴ └─┘┴└─╩ ╩┴┘└┘─┴┘::::::::::::::::::::	*\n"
			   "*	::: Enter 4 nos with space after each number eg:- 1 2 3 4      :::	*\n");
		scanf("%d %d %d %d",&a,&b,&c,&d);

		if((a<1|a>8) && (b<1|b>8) && (c<1|c>8) && (d<1|d>8))
			return -2;
		//Checking for position 1
		if(a==codegen.pos1)
		{
			match[0] = 1;
		}
		else if(a==codegen.pos2 | a==codegen.pos3 | a==codegen.pos4)
		{
			match[0] = 0;
		}
		else
		{
			match[0] = -1;
		}
		//checking for position 2
		if(b==codegen.pos2)
		{
			match[1] = 1;
		}
		else if(b==codegen.pos1 | b==codegen.pos3 | b==codegen.pos4)
		{
			match[1] = 0;
		}
		else
		{
			match[1] = -1;
		}
		//checking for position 3
		if(c==codegen.pos3)
		{
			match[2] = 1;
		}
		else if(c==codegen.pos1 | c==codegen.pos2 | c==codegen.pos4)
		{
			match[2] = 0;
		}
		else
		{
			match[2] = -1;
		}
		//checking for position 4
		if(d==codegen.pos4)
		{
			match[3] = 1;
		}
		else if(d==codegen.pos1 | d==codegen.pos2 | d==codegen.pos3)
		{
			match[3] = 0;
		}
		else
		{
			match[3] = -1;
		}

		rows[i].pos1 = a;
		rows[i].pos2 = b;
		rows[i].pos3 = c;
		rows[i].pos4 = d;
		while(match_inc<4)
		{
			if(match[match_inc] != -1)
			{
				if(match[match_inc]==1)
				{
					rows[i].str[str_inc] = "█";
				}
				else
				{
					rows[i].str[str_inc] = "░";
				}
				
				str_inc++;
			}
		match_inc++;
		}
		print_rows();
		if(a==codegen.pos1 && b==codegen.pos2 && c==codegen.pos3 && d==codegen.pos4)
			return 1;
	}
	return -1;
}

void Mastermind::print_rows() {
	int i = 0;
	printf(" +-+-+-+-+---+-+-+-+-+ \n"
 	       " |No.'s  |   |Feedback|\n"
 	       " +-+-+-+-+---+-+-+-+-+ \n");
	for(i=0;i<8;i++)
	{
		printf(" +-+-+-+-+---+-+-+-+-+ \n"
 	       	   " |%d|%d|%d|%d|   |%s|%s|%s|%s| \n"
 	           " +-+-+-+-+---+-+-+-+-+ \n",rows[7-i].pos1,rows[7-i].pos2,rows[7-i].pos3,rows[7-i].pos4,
 	           							   rows[7-i].str[0],rows[7-i].str[1],rows[7-i].str[2],rows[7-i].str[3]);
	}
}

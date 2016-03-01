# Mastermind_CLI
This Repository contains the code for playing the Mastermind Game via CLI.
The game is inspired from the android version of the game:-https://play.google.com/store/apps/details?id=com.cphcloud.mastermind&hl=en

The rules of the game are slightly tweaked, please refer to the [rules section](#H2R).

## <a name="H2R"></a> 1) How to Run
  >make
  >make run
  
## <a name="H2R"></a> 2)Cleaning game files
  >make clean
  
## <a name="H2R"></a> 3)Rules
* There are numbers used instead of colours, numbers 1-8
* The Codemaker here is the computer and decides a unique combination of 4 numbers from 1-8 as the code, the numbers in the code are not repeated.
* You the code breaker has a total of 8 trials to crack the code, you must guess both the number as well as the right position in which it is located in the generated code.
* After each trial, the entries you made will be shown along with some feedback boxes.
* The feedback boxes give you some info regarding the selection you have made.
    * the "█" symbol indicates that you have a number that is part of the code at the right position. 
    * the "░" symbol indicates that you have a number that is part of the code but in the wrong position.
    * if all the feedback boxes are blank, it means that none of your entries are part of the code.
    * The position of the feedback boxes has no relation to the position of your entry i.e. if the 1st feedback box is █ it does not mean that the 1st number in your trial is correct and in the right position it just indicates that a number in your code is correct and in the right position.
* In each trial you must enter only 4 numbers separated by spaces and all numbers must be between 1-8(both numbers included).
* If you succeed in guessing the code in any of the 8 trials, you win and the program exits.
* If you cannot guess the right code even in the 8th trial, you loose.
* There are no points in this game, its either win or loose(Binary scoring system).

## <a name="H2R"></a> 3)Software Design
The software is designed using Objected oriented C++ and the source is available in this repo. As of now the software may not be using the best space and time complexity but for a 4 number code it does just fine. Future commits may be added for more game features and an even better CLI.

## <a name="H2R"></a> 3)Hardware Tested on



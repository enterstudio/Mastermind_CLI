

mastermind:Mastermind.cpp Mastermind.h
	g++ -o Mastermind Mastermind.cpp -Wno-write-strings

run:
	g++ -o Mastermind Mastermind.cpp -Wno-write-strings
	./Mastermind

clean:
	rm -rf Mastermind *~

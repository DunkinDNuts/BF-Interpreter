#include <iostream>
#include "BF_Interpreter.h"

int main(int argc, char *argv[]) {
	if (argc == 1) {
		std::string program(argv[1]);
		BrainFuck interpreter;
		try {
			interpreter.Evaluate(program);
		} catch (const char* e) {
			std::cout << "Error: " << e << std::endl;
			return 1;
		}
	} else {
		std::cout << "Error: incorrect number of arguments. \n"
		"Please pass the brainfuck code as the only argument.\n"
		"Example Usage: \n"
		"./interpret \"++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.\""
		<< std::endl;
	}
	return 0;
}
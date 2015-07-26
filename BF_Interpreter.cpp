#include "BF_Interpreter.h"
#include <iostream>

BrainFuck::BrainFuck() {
	pointer = 0;
	memory.resize(1,0);
}

void BrainFuck::Evaluate(const std::string program) {
	std::string result;
	for (size_t command = 0; command < program.length(); ++command) {
		switch (program[command]) {
			case INCREMENT_PTR:
				++pointer;
				if (memory.size() < pointer + 1)
					memory.push_back(0);
				break;

			case DECREMENT_PTR:
				if (!pointer)
					throw "Segmentation Fault";
				--pointer;
				break;

			case INCREMENT_DATA:
				++memory[pointer];
				break;

			case DECREMENT_DATA:
				--memory[pointer];
				break;

			case BEGIN_LOOP:
				if (memory[pointer]) {
					loop_stack.push(command);	
					break;
				}
				for (size_t open = 1; open > 0;) {
					++command;
					if (program[command] == BEGIN_LOOP)
						++open;
					else if (program[command] == END_LOOP)
						--open;
					else if (command == program.length() - 1)
						throw "Found \'[\', missing matching \']\'";
				}
				break;

			case END_LOOP:
				if (!loop_stack.empty()) {
					command = loop_stack.top() - 1;
					loop_stack.pop();
				} else {
					throw "Found \']\', missing matching \'[\'";
				}
				break;

			case PRINT:
				result += memory[pointer];
				break;

			case READ:
				std::cin >> memory[pointer];
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				break;
		}
	}
	if (!loop_stack.empty())
		throw "Found \'[\', missing matching \']\'";
	std::cout << result << std::endl;	
}
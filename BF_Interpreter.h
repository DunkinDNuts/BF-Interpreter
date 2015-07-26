#ifndef BF_INTERPRETER
#define BF_INTERPRETER

#include <string>
#include <vector>
#include <stack>
#include <cstdint>

class BrainFuck {
private:
	enum {
		INCREMENT_PTR  = '>',
		DECREMENT_PTR  = '<',
		INCREMENT_DATA = '+',
		DECREMENT_DATA = '-',
		BEGIN_LOOP     = '[',
		END_LOOP       = ']',
		PRINT          = '.',
		READ           = ','
	};
	size_t pointer;
	std::vector<uint8_t> memory;	
	std::stack<size_t> loop_stack;

public:
	BrainFuck();
	void Evaluate(const std::string program);
};

#endif

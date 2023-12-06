/*
Розгляньте приклад. Допишіть в ньому за зразком усі потрібні обробки винятків.

#include <iostream>
using namespace std;
class stack_size_error : public length_error {
public:
	explicit stack_size_error(const std::string &msg);
};
class stack_bad_alloc : public std::bad_alloc {
public:
	explicit stack_bad_alloc(void);
};
class stack_overflow : public std::logic_error {
public:
	explicit stack_overflow(const std::string &msg);
};
class stack_empty : public std::logic_error {
public:
	explicit stack_empty(const std::string &msg);
};

stack_size_error::stack_size_error(const std::string &msg) : std::length_error(msg) {};
stack_bad_alloc::stack_bad_alloc(void) : std::bad_alloc() {};
stack_overflow::stack_overflow(const std::string &msg) : std::logic_error(msg) {};
stack_empty::stack_empty(const std::string &msg) : std::logic_error(msg) {};

class Stack {
	private:
	int *stackstore;
	int stacksize;
	int SP;
	public:
	Stack(int size = 100);
	~Stack();
	void push(int value);
	int pop(void);
};

Stack::Stack(int size) {
	if(size <= 0)
		throw stack_size_error("Розмір має бути додатним!");
	try {
		stackstore = new int[size];
	} catch(std::bad_alloc ba) {
		throw stack_bad_alloc();
	}
	stacksize = size;
	SP = 0;
}

Stack::~Stack(void) {
	delete [] stackstore;
}

void Stack::push(int value){
	if(SP == stacksize)
		throw stack_overflow("Переповнення стоса!");
	stackstore[SP++] = value;
}

int Stack::pop(void){
	if(SP == 0)
		throw stack_empty("Стос порожній!");
	return stackstore[--SP];
}

int main() {
	Stack stk;
  try{
	for(int i=0; i < 100; i++){
	  stk.push(i);
	}
	stk.push(8);

  }
  catch(stack_overflow &exc)
	{
	cout << "Переповнення стека: елемент не доданий." << endl;
	}
  cout << stk.pop() << endl;
	return 0;
}
*/

#include <iostream>
using namespace std;
class stack_size_error : public length_error {
public:
	explicit stack_size_error(const std::string& msg);
};
class stack_bad_alloc : public std::bad_alloc {
public:
	explicit stack_bad_alloc(void);
};
class stack_overflow : public std::logic_error {
public:
	explicit stack_overflow(const std::string& msg);
};
class stack_empty : public std::logic_error {
public:
	explicit stack_empty(const std::string& msg);
};

stack_size_error::stack_size_error(const std::string& msg) : std::length_error(msg) {};
stack_bad_alloc::stack_bad_alloc(void) : std::bad_alloc() {};
stack_overflow::stack_overflow(const std::string& msg) : std::logic_error(msg) {};
stack_empty::stack_empty(const std::string& msg) : std::logic_error(msg) {};

class Stack {
private:
	int* stackstore;
	int stacksize;
	int SP;
public:
	Stack(int size = 100);
	~Stack();
	void push(int value);
	int pop(void);
};

Stack::Stack(int size) {
	if (size <= 0)
		throw stack_size_error("Розмір має бути додатним!");
	try {
		stackstore = new int[size];
	}
	catch (std::bad_alloc ba) {
		throw stack_bad_alloc();
	}
	stacksize = size;
	SP = 0;
}

Stack::~Stack(void) {
	delete[] stackstore;
}

void Stack::push(int value) {
	if (SP == stacksize)
		throw stack_overflow("Переповнення стоса!");
	stackstore[SP++] = value;
}

int Stack::pop(void) {
	if (SP == 0)
		throw stack_empty("Стос порожній!");
	return stackstore[--SP];
}

int main() {
	Stack stk;
	try {
		for (int i = 0; i < 100; i++) {
			stk.push(i);
		}
		stk.push(8);

	}
	catch (stack_overflow& exc)
	{
		cout << "Переповнення стека: елемент не доданий." << endl;
	}
	catch (stack_bad_alloc& ba_exc)
	{
		cout << "Помилка виділення пам'яті для стека." << endl;
	}
	catch (stack_size_error& se_exc)
	{
		cout << "Помилка розміру стека." << endl;
	}
	catch (stack_empty& empty_exc)
	{
		cout << "Стек порожній." << endl;
	}
	cout << stk.pop() << endl;
	return 0;
}

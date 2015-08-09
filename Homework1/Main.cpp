#include <iostream>"
#include "Stack.h"
#include <string>
#include "Operation.h"
#include <fstream>
int priority(char ch, Operation* op, size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		if (op[i].name == ch)
		{
			return op[i].priority;
		}
	}
	return -1;
}
bool operationCheck(Operation* op, char ch, size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		if (op[i].name == ch)
		{
			return true;
		}
	}
	return false;
}
void translate(char* s, char* ns, Operation* op,size_t size)
{
	Stack<char> st;
	st.push('(');
	char x;
	int i = -1, j = -1, n =  strlen(s);
	while (i < n)
	{
		i++;
		
		if (s[i] >= '0' && s[i] <= '9')
		{

			j++;
			if (s[i - 1] == '-')
			{
				ns[j] = '-';
				j++;
			}
			ns[j] = s[i];
			while (s[i + 1] >= '0' && s[i + 1] <= '9')
			{
				i++;
				j++;
				ns[j] = s[i];
			}
			j++;
			ns[j] = ' ';
		}
		else
		if (s[i] == '(') st.push(s[i]);
		else
		if (s[i] == ')')
		{
			x = st.peek();
			st.pop();
			while (x != '(')
			{
				j++;
				ns[j] = x;
				x = st.peek();
				st.pop();
			}
		}
		else
		if (operationCheck(op,s[i],size))
		{
			x=st.peek();
			st.pop();
			while (x != '(' && priority(x, op, size) >= priority(s[i], op, size))
			{
				j++;
				ns[j] = x;
				x = st.peek();
				st.pop();
			}
			st.push(x);
			st.push(s[i]);
		}
	}
	x = st.peek();
	st.pop();
	while (x != '(')
	{
		j++; ns[j] = x;
		x = st.peek();
		st.pop();
	}
	j++;
	ns[j] = 0;
}
size_t counter(std::string str)
{
	std::ifstream file;
	file.open(str, std::ios::in);
	size_t i = 0;
	char name;
	char operation;
	int priority;
	int associativity;
	while (!file.eof())
	{
		file >> name >> std::ws;
		file >> operation >> std::ws;
		file >> priority >> std::ws;
		file >>associativity >> std::ws;
		++i;
	}
	file.close();
	return i;
}

void init(Operation* op, std::string str)
{
	std::ifstream file;
	file.open(str, std::ios::in);
	size_t i = 0;
	while (!file.eof())
	{
		file >> op[i].name>>std::ws;
		file >> op[i].operation >> std::ws;
		file >> op[i].priority >> std::ws;
		file >> op[i].associativity >> std::ws;
		++i;
	}
	file.close();
}

void print(Operation* op,size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << op[i].name << "  " << op[i].operation << " " << op[i].priority << "  " << op[i].associativity<<std::endl;
	}
}

int search(char ch , Operation* op, size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		if (op[i].name == ch)
		{
			return i;
		}
	}

}
int value(char *s, Operation* op , size_t size)
{
	Stack<int> st;
	int x=0, y=0, z=0;
	size_t i = 0, n = strlen(s);
	while (i < n)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			bool isNegative = false;
			if (s[i-1] == '-')
			{
				isNegative = true;
			}
			int number = (int)s[i] - (int)'0';
			while (s[i + 1] >= '0' && s[i + 1] <= '9')
			{
				i++;
				number = number * 10 + (int)s[i] - (int)'0';
			}

			if (isNegative)
			{
				number = number*(-1);
			}
			st.push(number);
		}
		else
		if (operationCheck(op,s[i],size))
		{
			y = st.peek();
			st.pop();
			x = st.peek();
			st.pop();
			int index = search(s[i], op, size);
			switch (op[index].operation)
			{
			case '+':
				z = x + y; break;
			case '-':
				if (op[index].priority == 0)
				{
					z = x - y;
					
				}else
					{
						z = y - x;
						
					}
				break;
			case '*': z = x*y; break;
			case '/':
				if (op[index].priority == 0)
				{
					z = x / y;
					break;
				}else
					{
						z = y / x;
						break;
					}
			}
			st.push(z);
		}
		i++;
	}
	z = st.peek();
	st.pop();
	return z;
}
void validate(char* str)
{
	size_t i = 0;
	size_t size = strlen(str);
	if (!(str[i] <= '9' && str[i] >= '0'))
	{
		std::cout << "Invalid expression1!!!"<<std::endl;
		throw "Invalid expression!!!";
	}

	size_t counter = 0;
	while (i <size)
	{
		if (str[i] == '(')
		{
			++counter;
		}
		if (str[i] == ')')
		{
			--counter;
		}
		if (counter < 0)
		{
			std::cout << "Invalid expression3!!!" << std::endl;
			throw "Invalid expression!!!";
		}
		++i;
	}
	if (counter>0)
	{
		std::cout << "Invalid expression3!!!" << std::endl;
		throw "Invalid expression!!!";
	}
	if (!((str[i-1] <= '9' && str[i-1] >= '0') || (str[i-1] == ')')))
	{
		std::cout << "Invalid expression2!!!" << std::endl;
		throw "Invalid expression!!!";
	}
	i = 0;
	/*
	size_t counterOp = 0;
	size_t counterNum = 0;
	for (; i < size; ++i)
	{
		if ((str[i] <= '9' && str[i] >= '0'&& str[i+1]==' '))
		{ 
			
			++counterNum;
		}
		if ((str[i] <= '9' && str[i] >= '0'&& !str[i + 1] == ' '))
		{

			++i;
		}
		if (str[i] <= 'z' && str[i] >= 'a' )
		{
			++counterOp;
		}
	}
	if (counterNum - counterOp != 1)
	{
		std::cout << "Invalid expression4!!!" << std::endl;
		throw "Invalid expression!!!";
	}*/
}
int main()
{
	char str1[120];
	char str2[120];
	std::cin.getline(str1, 100);
	validate(str1);
	std::string str;
	std::cin >> str;
	size_t size = counter(str);
	Operation* op = new Operation[size]; 
	init(op,str);
	print(op, size);
	translate(str1, str2,op,size);
	std::cout << str2;
	std::cout << std::endl;
	std::cout << value(str2, op, size);
	system("pause");
	return 0;
}
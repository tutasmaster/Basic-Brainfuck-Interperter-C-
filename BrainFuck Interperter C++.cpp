// BrainFuck Interperter C++.cpp : Defines the entry point for the console application.
//

#include "stdlib.h"
#include "stdafx.h"
#include <string>
#include <stdio.h>
#include <iostream>

bool end = true;

unsigned char tape[sizeof(char)];

std::string code = "++++[>++++[>++++ ++++ ++++.<-]<-]";

unsigned int pos;
unsigned int loop;
int i;

void getChar()
{
	unsigned char ch;
	std::cin >> ch;
	tape[pos] = ch;
}

void drawChar()
{
	std::cout << tape[pos];
}

void addValue(int value)
{
	int newVal = tape[pos] + value;
	if (newVal < 0) {
		tape[pos] = 255 + newVal;
	}
	else if (newVal > 255) {
		tape[pos] = newVal - 255;
	}
	else 
	{
		tape[pos] = newVal;
	}
}

void skipPos(int skipSize)
{
	int skipPos = pos + skipSize;
	if (skipPos >= 0 && skipPos <= 255) {
		pos = skipPos;
	}
}

void checkChar(char ch)
{
	if (ch == '>') {
		skipPos(1);
	}
	else if (ch == '<') {
		skipPos(-1);
	}
	else if (ch == '+') {
		addValue(1);
	}
	else if (ch == '-') {
		addValue(-1);
	}
	else if (ch == '.') {
		drawChar();
	}
	else if (ch == ',') {
		getChar();
	}
	else if (ch == '[') {
		return;
	}
	else if (ch == ']') {
		loop = 1;
		while (loop != 0 && tape[pos] != 0) 
		{
			char ch = code.at(--i);
			if (ch == '[') {
				loop--;
			}
			else if (ch == ']') {
				loop++;
			}
		}
	}
}

void interpert(std::string code) 
{
	pos = 0;
	loop = 0;
	for (i = 0; i < code.length(); i++) 
	{
		char curChar = code.at(i);
		checkChar(curChar);
	}
}

int main()
{
	interpert(code);
	return 0;
}


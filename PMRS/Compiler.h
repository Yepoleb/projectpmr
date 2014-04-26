#pragma once

#include <fstream>
#include <streambuf>
#include "Preprocessor.h"
#include "Commands.h"

class Compiler
{
public:
	Compiler(ostream& out, const char* filename);
	~Compiler();

	void Compile();

private:
	vector<Line> lines;
};
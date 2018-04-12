#pragma once

#include <string>

class FunCompiler
{
public:
	FunCompiler();
	~FunCompiler();


	bool Compile(std::string code, std::string fileOutput);
	bool CompileFile(std::string filePath, std::string fileOutput);


private:

};
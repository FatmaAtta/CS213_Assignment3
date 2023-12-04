#include "header.h"

LabelGenerator::LabelGenerator(string p, int i){
	this->prefix = p;
	this->index = i;
}
string LabelGenerator::nextLabel(){
	string output = "";
	output += this->prefix;
	output += to_string(this->index);

	this->index += 1;

	return output;
}

FileLabelGenerator::FileLabelGenerator(string p, int i, string fileName): LabelGenerator(p, i){
	this->fileName = fileName;
	string line = "";
	ifstream f(fileName);

	if (f.is_open()){
		while (getline(f, line))
			this->lines.push_back(line);
	}
}

string FileLabelGenerator::nextLabel(){	
	string output = "";
	output += prefix;
	output += to_string(index);

	if (lineIndex < lines.size())
		output += " " + lines[lineIndex];

	lineIndex += 1;
	index += 1;

	return output;
}

// File name: main.cpp
// Purpose: Label Generator
// Author(s): Iyad Mahdy Mahrous
// ID(s): 20220075
// Section: S9
// Date: December 5 2023
// Version: 1
#include <bits/stdc++.h>
#include <fstream>
#include <vector>
using namespace std;

class LabelGenerator{
	protected:
		string prefix;
		int index;
	public:
		LabelGenerator(string p, int i);
		virtual string nextLabel();
};


class FileLabelGenerator: public LabelGenerator{
	private:
		string fileName;
		vector<string> lines;
		int lineIndex = 0;
	public:
		FileLabelGenerator(string p, int i, string fileName);
		string nextLabel();
};

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
	string output = LabelGenerator::nextLabel();

	if (lineIndex < lines.size())
		output += " " + lines[lineIndex];

	lineIndex += 1;
	return output;
}

int main()
{
	LabelGenerator figureNumbers("Figure ", 1);
	LabelGenerator pointNumbers("P", 0);
	FileLabelGenerator fileLabel("Line ", 1, "input.txt");
	LabelGenerator *ptr;

	// Change the variable that ptr points to to choose what type of label use
	ptr = &fileLabel;
	for (int i = 0; i < 5; i++)
		cout << ptr->nextLabel() << endl;

	return EXIT_SUCCESS;
}

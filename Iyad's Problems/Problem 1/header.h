#ifndef problem1_h
#define problem1_h

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

#endif

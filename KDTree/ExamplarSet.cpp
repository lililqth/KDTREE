#include "Examplar.h"
#include "ExamplarSet.h"
#include <fstream>
#include <iostream>
using namespace std;
ExamplarSet::ExamplarSet()
{
	
}

ExamplarSet::~ExamplarSet()
{
}

int ExamplarSet::readData(std::string strFilePath){
	ifstream in(strFilePath);
	assert(in.is_open());
	string buffer;
	int totalNum = 0;
	while (getline(in, buffer))
	{
		vector<double> temp;
		for (int i = 0;;){
			int pos = buffer.find(' ', i);
			double num = atof(buffer.substr(i, pos).c_str());
			temp.push_back(num);
			if (pos == -1){
				break;
			}
			i = pos + 1;
		}
		_Examplar exam;
		exam.dom_dims = temp.size();
		exam.dom_elt = temp;
		this->_ex_set.push_back(exam);
		totalNum++;
	}
	return totalNum;
}

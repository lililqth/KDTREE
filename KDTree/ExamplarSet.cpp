#include "Examplar.h"
#include "ExamplarSet.h"
#include <fstream>
#include <iostream>
#include <algorithm>


using namespace std;
ExamplarSet::ExamplarSet()
{
	
}

ExamplarSet::~ExamplarSet()
{
}
bool lessmark(dimVariance* Item1, dimVariance* Item2)
{
	return Item1->variance > Item2->variance;
}

void ExamplarSet::sortByVariance(){
	int dim = this->getDims();
	this->varianceVec.clear();
	for (int i = 0; i < dim; i++){
		// cal average
		double average = 0;
		for (int j = 0; j < this->getSize(); j++){
			average += this->_ex_set[j][i];
		}
		average = average / this->getSize();
		double vari = 0.0;
		for (int j = 0; j < this->getSize(); j++){
			vari += (this->_ex_set[j][i] - average)*(this->_ex_set[j][i] - average);
		}
		dimVariance* temp = new dimVariance(vari, i);
		this->varianceVec.push_back(temp);
	}
	sort(this->varianceVec.begin(), this->varianceVec.end(), lessmark);
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
		this->_dims = exam.dom_dims;
		totalNum++;
	}
	return totalNum;
}

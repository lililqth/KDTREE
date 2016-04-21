#ifndef _EXAMPLAR_SET
#define _EXAMPLAR_SET
#include "Examplar.h"
#include <string>
class dimVariance{
public:
	double variance;
	int dim;
	dimVariance(double var, int di){
		variance = var;
		dim = di;
	}
};
class ExamplarSet
{
public:
	ExamplarSet();
	~ExamplarSet();
	bool remove(int idx);
	void sortByVariance();     //按某个方向维的排序函数
	int readData(std::string strFilePath);  //从文件读取数据集
	ExamplarSet(std::vector<_Examplar> ex_set, int size, int dims);
	ExamplarSet(int size, int dims);
	ExamplarSet(const ExamplarSet& rhs);
	ExamplarSet& operator=(const ExamplarSet& rhs);
	_Examplar& examplarAt(int idx);
	_Examplar& operator[](int idx);
	const _Examplar& examplarAt(int idx) const;
	void create(int size, int dims);
	int getDims() const { return _dims; }
	int getSize() const { return _ex_set.size(); }
	std::vector<dimVariance*> varianceVec;

public:
	int _dims;   // dimensiionality of the data
	std::vector<_Examplar> _ex_set; // the set of data
	void releaseExamplarSetMem(){
		_ex_set.clear();
		_dims = 0;
	}
};
#endif
#ifndef _EXAMPLAR_H
#define _EXAMPLAR_H
#include <vector>
#include <assert.h>
class _Examplar
{
public:
	int dom_dims; 
	std::vector<double> dom_elt;
	_Examplar();
	_Examplar(const std::vector<double> elt, int dims);
	_Examplar(const _Examplar& rhs) ;
	~_Examplar();
	double& dataAt(int dim);
	double& operator[] (int dim);
	const double& dataAt(int dim) const;
	const double& operator[](int dim) const ;
	_Examplar& operator= (const _Examplar& rhs);
	void create(int dims);
	int getDomDims() const ;
	void setTo(double val) ;
private:
	void releaseExamplarMem();
};
#endif // !_EXAMPLAR_H

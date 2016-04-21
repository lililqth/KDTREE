#include <vector>
#include <assert.h>
#include "Examplar.h"
_Examplar::_Examplar() :dom_dims(0){};
_Examplar::_Examplar(const std::vector<double> elt, int dims)
{
	if (dims > 0){
		dom_elt = elt;
		dom_dims = dims;
	}
	else{
		dom_dims = 0;
	}
}
_Examplar::_Examplar(const _Examplar& rhs)
{
	if (rhs.dom_dims > 0){
		dom_elt = rhs.dom_elt;
		dom_dims = rhs.dom_dims;
	}
	else{
		dom_dims = 0;
	}
}

_Examplar::~_Examplar(){
}

double& _Examplar::dataAt(int dim){
	assert(dim < dom_dims);
	return dom_elt[dim];
}
double& _Examplar::operator[] (int dim){// []���������
	return dataAt(dim);
}
const double& _Examplar::dataAt(int dim) const{// ֻ��
	assert(dim < dom_dims);
	return dom_elt[dim];
}
const double& _Examplar::operator[](int dim) const    //����"[]"�������ʵ���±�ֻ������
{
	return dataAt(dim);
}

_Examplar& _Examplar:: operator= (const _Examplar& rhs){  // ����=�����
	if (this == &rhs){
		return *this;
	}
	releaseExamplarMem();
	if (rhs.dom_dims > 0){
		dom_elt = rhs.dom_elt;
		dom_dims = rhs.dom_dims;
	}
	return *this;
}
void _Examplar::create(int dims)    //������������
{
	releaseExamplarMem();
	if (dims > 0)
	{
		dom_elt.resize(dims);    //������������ά��
		dom_dims = dims;
	}
}
int _Examplar::getDomDims() const     //�����������ά����Ϣ
{
	return dom_dims;
}
void _Examplar::setTo(double val)    //����������ʼ������
{
	if (dom_dims > 0)
	{
		for (int i = 0; i < dom_dims; i++)
		{
			dom_elt[i] = val;
		}
	}
}
void _Examplar::releaseExamplarMem(){
	dom_elt.clear();
	dom_dims = 0;
}
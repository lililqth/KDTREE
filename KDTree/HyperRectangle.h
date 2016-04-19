#include "Examplar.h"
class _HyperRectangle    //定义表示数据范围的超矩形结构
{
	_Examplar min;        //统计数据集中所有数据向量每个维度上最小值组成的一个数据向量
	_Examplar max;        //统计数据集中所有数据向量每个维度上最大值组成的一个数据向量


	_HyperRectangle() {}
	_HyperRectangle(_Examplar mx, _Examplar mn)
	{
		assert(mx.getDomDims() == mn.getDomDims());
		min = mn;
		max = mx;
	}
	_HyperRectangle(const _HyperRectangle& rhs)
	{
		min = rhs.min;
		max = rhs.max;
	}
	_HyperRectangle& operator= (const _HyperRectangle& rhs)
	{
		if (this == &rhs)
			return *this;
		min = rhs.min;
		max = rhs.max;
		return *this;
	}
	void create(_Examplar mx, _Examplar mn)
	{
		assert(mx.getDomDims() == mn.getDomDims());
		min = mn;
		max = mx;
	}
};
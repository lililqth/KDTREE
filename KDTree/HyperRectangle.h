#include "Examplar.h"
class _HyperRectangle    //�����ʾ���ݷ�Χ�ĳ����νṹ
{
	_Examplar min;        //ͳ�����ݼ���������������ÿ��ά������Сֵ��ɵ�һ����������
	_Examplar max;        //ͳ�����ݼ���������������ÿ��ά�������ֵ��ɵ�һ����������


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
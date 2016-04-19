//k-d tree�ڵ�ṹ����
#include "Examplar.h"
#include "HyperRectangle.h"
class KDTreeNode
{
private:
	int _split_dim;                //�ýڵ��������ֶȷ���ά
	_Examplar _dom_elt;            //�ýڵ����������
	_HyperRectangle _range_hr;     //��ʾ���ݷ�Χ�ĳ����νṹ
public:
	KDTreeNode *_left_child, *_right_child, *_parent;        //�ýڵ�����������͸��ڵ�


public:
	KDTreeNode(const KDTreeNode &rhs);
	KDTreeNode& operator=(const KDTreeNode &rhs);
	_Examplar& getDomElt() { return _dom_elt; }
	_HyperRectangle& getHyperRectangle(){ return _range_hr; }
	int& splitDim(){ return _split_dim; }
	void create(KDTreeNode *left_child, KDTreeNode *right_child,
		KDTreeNode *parent, int split_dim, _Examplar dom_elt, _HyperRectangle range_hr);
};
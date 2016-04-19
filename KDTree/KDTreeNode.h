//k-d tree节点结构定义
#include "Examplar.h"
#include "HyperRectangle.h"
class KDTreeNode
{
private:
	int _split_dim;                //该节点的最大区分度方向维
	_Examplar _dom_elt;            //该节点的数据向量
	_HyperRectangle _range_hr;     //表示数据范围的超矩形结构
public:
	KDTreeNode *_left_child, *_right_child, *_parent;        //该节点的左右子树和父节点


public:
	KDTreeNode(const KDTreeNode &rhs);
	KDTreeNode& operator=(const KDTreeNode &rhs);
	_Examplar& getDomElt() { return _dom_elt; }
	_HyperRectangle& getHyperRectangle(){ return _range_hr; }
	int& splitDim(){ return _split_dim; }
	void create(KDTreeNode *left_child, KDTreeNode *right_child,
		KDTreeNode *parent, int split_dim, _Examplar dom_elt, _HyperRectangle range_hr);
};
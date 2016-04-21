#ifndef _KDTREENODE_H

#define _KDTREENODE_H
//k-d tree节点结构定义
#include "Examplar.h"

class KDTreeNode
{
public:
	int split_dim;                //该节点的最大区分度方向维
	_Examplar* nodeData;            //该节点的数据向量
	ExamplarSet* dataSet;	      //该节点的超空间数据集
	KDTreeNode(){};
	KDTreeNode(ExamplarSet* set, KDTreeNode* father)
	{
		this->dataSet = set;
		this->father = father;
	}
	~KDTreeNode(){}
	KDTreeNode* father;
	KDTreeNode* right;
	KDTreeNode* left;
	bool visited;
};
#endif // !_KDTREENODE_H
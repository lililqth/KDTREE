#ifndef _KDTREENODE_H

#define _KDTREENODE_H
//k-d tree�ڵ�ṹ����
#include "Examplar.h"

class KDTreeNode
{
public:
	int split_dim;                //�ýڵ��������ֶȷ���ά
	_Examplar* nodeData;            //�ýڵ����������
	ExamplarSet* dataSet;	      //�ýڵ�ĳ��ռ����ݼ�
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
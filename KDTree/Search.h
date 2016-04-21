#ifndef _SEARCH_H
#define _SEARCH_H
#include "Examplar.h"
#include "KDTreeNode.h"
class Search{
public:
	_Examplar target;
	double maxDistance;
	int currentDim;
	int totalDim;
	_Examplar* searchResult;
	void setTarget(_Examplar Exp){
		target = Exp;
	}
	void setTotalDim(int dim){
		totalDim = dim;
	}
	KDTreeNode* searchDown(KDTreeNode* root){
		root->visited = true;
		if (root->left == NULL && root->right == NULL){// 如果到达了叶子节点
			return root;
		}
		currentDim = root->split_dim;
		double nodeData = root->nodeData->dom_elt[currentDim];
		double targetData = target.dom_elt[currentDim];
		if (targetData <= nodeData){
			return searchDown(root->left);
		}
		else{
			return searchDown(root->right);
		}
	}
	double distance(KDTreeNode* node, _Examplar exp){
		double dis = 0.0;
		for (int i = 0; i < totalDim; i++){
			double x1 = node->nodeData->dom_elt[i];
			double x2 = exp.dom_elt.at(i);
			dis += (x1 - x2)*(x1 - x2);
		}
		return dis;
	}
	double distance(_Examplar exp1, _Examplar exp2){
		double dis = 0.0;
		for (int i = 0; i < totalDim; i++){
			double x1 = exp1.dom_elt[i];
			double x2 = exp2.dom_elt[i];
			dis += (x1 - x2)*(x1 - x2);
		}
		return dis;
	}
	double spaceDistance(KDTreeNode* node, _Examplar exp){
		return abs(node->nodeData->dom_elt[node->split_dim] - exp.dom_elt[node->split_dim]);
	}
	_Examplar* searchUp(KDTreeNode* root){
		while (root->father != NULL){
			root = root->father;
			if (distance(root, target) < maxDistance){
				maxDistance = distance(root, target);
				searchResult = root->nodeData;
			}
			if (root->left->visited == false){
				for (int i = 0; i < root->left->dataSet->getSize(); i++){
					if (distance(root->left->dataSet->_ex_set[i], target) < maxDistance){
						maxDistance = distance(root->left->dataSet->_ex_set[i], target);
						searchResult = &root->left->dataSet->_ex_set[i];
					}
				}
			}
			else if (root->right->visited == false){
				for (int i = 0; i < root->right->dataSet->getSize(); i++){
					if (distance(root->right->dataSet->_ex_set[i], target) < maxDistance){
						maxDistance = distance(root->right->dataSet->_ex_set[i], target);
						searchResult = &root->right->dataSet->_ex_set[i];
					}
				}
			}
		}
		return searchResult;
	}
	_Examplar* Find(KDTreeNode* root){
		KDTreeNode* leaf = searchDown(root);
		searchResult = leaf->nodeData;
		maxDistance = distance(leaf, target);
		_Examplar* ans = searchUp(leaf);
		return ans;
	}
};
#endif

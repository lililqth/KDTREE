#include <iostream>
#include <algorithm>
#include "Examplar.h"
#include "ExamplarSet.h"
#include "KDTree.h"
using namespace std;
ExamplarSet* expSet;

double findMid(vector<double>* data){
	sort(data->begin(), data->end());
	return data->at(data->size() / 2);
}

void devide(KDTreeNode* father , KDTreeNode* root, ExamplarSet* dataSet, int index, int totalDim){
	if (dataSet->getSize() == 0){
		return;
	}
	if (dataSet->getSize() == 1){
		root->nodeData = &dataSet->_ex_set[0];
		return;
	}
	index = index % totalDim;
	ExamplarSet *leftSet = new ExamplarSet();
	ExamplarSet *rightSet = new ExamplarSet();
	int currentDim = expSet->varianceVec[index]->dim;
	root->split_dim = currentDim;

	// 查找中位数
	vector<double>* temp = new vector<double>();
	for (int i = 0; i < dataSet->getSize(); i++){
		double data = dataSet->_ex_set[i][currentDim];
		temp->push_back(data);
	}
	double middle = findMid(temp);
	for (int i = 0; i < dataSet->getSize(); i++){
		if (dataSet->_ex_set[i][currentDim] < middle){
			leftSet->_ex_set.push_back(dataSet->_ex_set[i]);
		}
		else if (dataSet->_ex_set[i][currentDim] == middle){
			root->nodeData= &dataSet->_ex_set[i];
		}
		else{
			rightSet->_ex_set.push_back(dataSet->_ex_set[i]);
		}
	}
	KDTreeNode *leftNode = new KDTreeNode(leftSet, root);
	root->left = leftNode;
	devide(root, leftNode, leftSet, index + 1, totalDim);
	KDTreeNode *rightNode = new KDTreeNode(rightSet, root);
	root->right = rightNode;
	devide(root, rightNode, rightSet, index + 1, totalDim);
}

int main(){
	expSet = new ExamplarSet();
	int num = expSet->readData("data.txt");
	expSet->sortByVariance();
	KDTreeNode *root = new KDTreeNode(expSet, NULL);
	devide(NULL, root, expSet, 0, expSet->getSize());
	system("pause");
	return 0;
}

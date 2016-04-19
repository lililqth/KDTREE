#include <iostream>
#include "Examplar.h"
#include "ExamplarSet.h"
#include "KDTree.h"
using namespace std;
int main(){
	ExamplarSet* expSet = new ExamplarSet();
	int num = expSet->readData("data.txt");
	system("pause");
	return 0;
}
void calVariance(){

}
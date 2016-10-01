/*
 * main.c
 *
 *  Created on: Oct 1, 2016
 *      Author: 
 */

#include <stdlib.h>
#include <stdio.h>

#include "adtlist.h"

void NodePrintUserFunc(Node node) {
	if (NULL != node) printf("%d\n", *GetValue(node));
}

int main() {
	int SampleNumbers[] = {23, 54, 76, 33, 99};
	List MyList = CreateList(0);

	for (int i = 0; i < 5; ++i) {
		Node NewNode = CreateNode();
		SetValue(NewNode, &SampleNumbers[i]);
		AddHead(MyList, NewNode);
	}

	PrintList(MyList, NodePrintUserFunc);

	FreeList(MyList);
	free(MyList);

	system("pause");
	return 0;
}

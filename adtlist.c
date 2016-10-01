/*
 * adtlist.c
 *
 *  Created on: Oct 1, 2016
 *      Author: 
 */

#include <stdlib.h>

#include "adtlist.h"

struct List {
	Node head;
	unsigned int count;
};

struct Node {
	ValueType value;
	Node next;
};

/*
 * <Comment>
 */
List CreateList(unsigned int count) {
	List rv = (List)malloc(1*sizeof(struct List));
	if (NULL == rv) return rv;

	rv->count = 0;
	rv->head = NULL;
	for (int i = 0; i < count; ++i)
		AddHead(rv, CreateNode());

	return rv;
}

/*
 * <Comment>
 */
Node CreateNode(void) {
	return (Node)malloc(1*sizeof(struct Node));
}

/*
 * <Comment>
 */
void AddHead(List list, Node node) {
	if (NULL == list || NULL == node) return;

	++list->count;
	node->next = list->head;
	list->head = node;
}

/*
 * <Comment>
 */
void SetValue(Node node, ValueType value) {
	if (NULL == node || NULL == value)
		return;	//	i'm obviously assuming ValueType is a reference (just for the example)
	else
		node->value = value;
}

/*
 * <Comment>
 */
ValueType GetValue(Node node) {
	if (NULL != node)
		return node->value;
	else
		return NULL;
}

/*
 * <Comment>
 */
Node GetHead(List list) {
	if (NULL == list)
		return NULL;
	else
		return list->head;
}

/*
 * <Comment>
 */
List FreeList(List list) {
	Node ToFree = NULL;
	if (NULL == list)
		return list;
	else
		ToFree = list->head;

	for (int i = 0; i < list->count; ++i, ToFree = list->head) {	//	or NULL != list->head
		list->head = list->head->next;
		free(ToFree);
	}

	list->count = 0;
	return list;
}

/*
 * <Comment>
 */
void PrintList(List list, void (print)(Node)) {
	Node current = NULL;
	if (NULL == list)
		return;
	else
		current = list->head;

	for (int i = 0; i < list->count; ++i, current = current->next) print(current);
}

/*
 * adtlist.h
 *
 *  Created on: Oct 1, 2016
 *      Author: 
 */

#ifndef ADTLIST_H_
#define ADTLIST_H_


typedef struct List* List;
typedef struct Node* Node;
typedef int* ValueType;

/*
 * <Comment>
 */
List CreateList(unsigned int);

/*
 * <Comment>
 */
Node CreateNode(void);

/*
 * <Comment>
 */
void AddHead(List, Node);

/*
 * <Comment>
 */
void SetValue(Node, ValueType);

/*
 * <Comment>
 */
ValueType GetValue(Node);

/*
 * <Comment>
 */
Node GetHead(List);

/*
 * <Comment>
 */
List FreeList(List);

/*
 * <Comment>
 */
void PrintList(List, void (print)(Node));


#endif /* ADTLIST_H_ */

#include <stdint.h>
#ifndef SLIST_H_INCLUDED
#define SLIST_H_INCLUDED

typedef struct _node_ Node;

struct _node_{
    int32_t     data;   //to store the data
    Node        *next;  //to store the address
};

typedef struct _slist_ Slist;                                                                 //defining and renaming another structure wityh the name Slist
struct _slist_{
    Node        *head;                                                                        //to store the head address
    Node        *tail;                                                                        //to store the address of last node
    uint32_t    length;                                                                       //to count the length of the list
};

Slist       slist_new();                                                                      //to initialize the value of the list to 0
uint8_t     slist_lookup(const  Slist *list,int32_t  key);                                    //to search an element in the list (output will be true or false)
uint32_t    slist_length(const  Slist *list);                                                 // to count the number of element in the list
Slist*      slist_addnode_head(Slist *list,int32_t   val);                                    //to add a value in the head node
Slist*      slist_addnode_tail(Slist *list,int32_t   val);                                    //to add the value to the tail node
Slist*      slist_delnode_head(Slist *list);                                                  //to delete the first node
Slist*      slist_delnode_tail(Slist *list);                                                  //to delete the last node
int32_t     Slist_max_element(Slist *list);                                                   //to find the max element in the list
int32_t     Slist_min_element(Slist *list);                                                   //to find the min element in the list
Slist*      slist_add_specified_ele(Slist *list, int32_t element,int32_t spec_ele);           //to add specified element into the list
Slist*      slist_del_specified_ele(Slist *list, int32_t spec_ele);                           //to delete specified element from the list
Slist*      rev_ele_list(Slist *list);                                                        //to reverse element in the list
uint32_t    compare_list(Slist *list_1,Slist *list_2);                                        //to check if the two list are same
Slist*      union_two_list(Slist *union_list,Slist *list1,Slist *list2);                      //to create union of two lists
Slist*      intersection_two_list(Slist *inter_list,Slist *list1,Slist *list2);               //to create union of two lists
Slist*      unique_list(Slist* list,uint32_t element);                                        //to get the unique list



Slist* union_twolist(Slist *union_list,Slist *list1,Slist *list2);
#endif // SLIST_H_INCLUDED

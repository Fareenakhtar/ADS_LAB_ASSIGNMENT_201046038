#include <stdlib.h>                                                                 //to dynamically allocate the memory
#include <assert.h>
#include <stdio.h>
#include    "slist.h"


Slist       slist_new(){
    Slist   s1 = {NULL, NULL, 0};
    return  s1;
}

uint32_t    slist_length(const  Slist   *list){
    assert (list!=NULL);                                                              //if this isnt given thn the program will crash if the list is null
    return  list->length;
}

/*helper function which is not visible outside*/

static Node*    _get_new_node_(int32_t  val){
    Node*   newnode = (Node*)malloc(sizeof(Node));
    newnode-> data = val;
    newnode->next=NULL;

    return newnode;
}

Slist*      slist_addnode_head(Slist *list,int32_t   val){
    assert (list!=NULL);
    Node    *new_node = _get_new_node_(val);

    new_node->next=list->head;
    list->head=new_node;  //storing the address of the first node to the head
    if(list->tail == NULL){
        list->tail=new_node;
    }
    ++list->length;
    assert((list->length==1 && list->head == list->tail) ||
            (list->length >1 && list->head !=list->tail));
    return list;
}

Slist*      slist_addnode_tail(Slist *list,int32_t   val){
    assert (list!=NULL);
    Node    *new_node =_get_new_node_(val);

    if(list->tail != NULL){
        list->tail->next=new_node;
        list->tail=new_node;
    }else{
        list->head=list->tail=new_node;     //when you add node for the first time
    }
    ++list->length;
    assert((list->length==1 && list->head == list->tail) ||
            (list->length>1 && list->head !=list->tail));

    return list;
}

uint8_t     slist_lookup(const  Slist *list,int32_t key){
    assert (list!=NULL);
    Node *cur = list->head;

    for (cur = list->head; cur !=NULL; cur = cur ->next){
        if (cur->data == key){
            break;
        }
    }
    return (cur != NULL); //if cur is NULL, return 0. if cur is not NULL, return 1

}

Slist*      slist_delnode_head(Slist *list){
    assert  (list !=NULL);
    Node *temp;
    if (list ->head !=NULL){
        temp=list->head;
        list->head = list->head->next;
        if (list->head== NULL){
            list->tail=NULL;
        }
        --list->length;
        free(temp);
    }
    return list;
}

Slist*      slist_delnode_tail(Slist *list){
    assert (list!=NULL);
    Node *last, *cur;

    if (list->tail!=NULL){
        last = list->tail;
        if (list->head == list->tail){
            list->head=list->tail = NULL;
        }else{
        for (cur = list->head; cur->next !=last; cur=cur->next);
        list->tail = cur;
        cur->next = NULL;
        }
        --list->length;
        free(last);
    }
    return list;
}

int32_t      Slist_max_element(Slist *list){
    assert(list !=NULL);
    Node *cur=list->head;
    int32_t max=0;
    while (cur!=NULL){
        if(cur->data>max){
            max=cur->data;
        }
        cur=cur->next;
    }
    return max;
}

int32_t      Slist_min_element(Slist *list){
    assert(list!=NULL);
    Node *cur=list->head;
    int32_t min=list->head;
    while(cur!=NULL){
        if((cur->data)< min){
            min=cur->data;
        }
        cur=cur->next;
    }
    return min;
}

Slist*      slist_add_specified_ele(Slist *list, int32_t val,int32_t spec_ele){
    assert(list!=NULL);
    Node *new_node=_get_new_node_(val);
    Node *cur;
    for(cur=list->head;cur!=NULL;cur=cur->next)
    {
        if(cur->data==spec_ele)
        {
            new_node->next=cur->next;
            cur->next=new_node;
            if(cur->next==NULL)
            {
                assert(cur->next==NULL);
                list->tail=new_node;
            }
        }

    }
    ++list->length;
    return list;
}

Slist*      slist_del_specified_ele(Slist *list, int32_t spec_ele){
     assert(list != NULL);
    Node *temp,*prev;
    prev->next = NULL;
    temp=list->head;
    if(list->length == 1){
        list->head=NULL;
        list->tail=NULL;
        list->length = 0;
    }
    else if (temp != NULL && temp->data == spec_ele)
    {
        list->head= temp->next;
	--list->length;
        return list;
    }
    else{
    for(temp=list->head;temp!=NULL;temp=temp->next){


        if(temp->data == spec_ele)
        {
            prev->next=temp->next;
        }
        prev = temp;
    }
    free(temp);
--list->length;
   }

    return list;
}

Slist*      rev_ele_list(Slist *list){
    assert(list!=NULL);
    Node *prev=NULL,*nxt=NULL,*cur,*cur1;
    cur=list->head;
    cur1= cur;
    while(cur!=NULL)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    list->tail = cur1;
    list->head = prev;
    return list;
}

uint32_t    compare_list(Slist *list1,Slist *list2){
    assert(list1!=NULL);
    assert(list2!=NULL);
    Node *cur1,*cur2;
    cur1=list1->head;
    cur2=list2->head;
    while(cur1!=NULL && cur2!=NULL)
    {
        if(cur1->data == cur2->data)
        {
            return 1;
        }
        else{
            return 0;
        }
        cur1=cur1->next;
        cur2=cur2->next;
    }
    return (list1 == NULL && list2==NULL);
}

Slist*      union_two_list(Slist *union_list,Slist *list1,Slist *list2){
    assert(list1!=NULL);
    assert(list2!=NULL);

    Node *cur1,*cur2;
    cur1=list1->head;
    cur2=list2->head;

    while(cur1!=NULL)
    {
	if(!(slist_lookup(union_list, cur1->data)))
        {
            union_list = slist_addnode_tail(union_list,cur1->data);
        }

        cur1=cur1->next;
    }
    while(cur2!=NULL)
    {
        if(!(slist_lookup(list1, cur2->data)))
        {
            union_list = slist_addnode_tail(union_list,cur2->data);
        }
        cur2=cur2->next;
    }
    return union_list;
}

Slist*      intersection_two_list(Slist *inter_list,Slist *list1,Slist *list2){
    assert(list1!=NULL);
    assert(list2!=NULL);


    Node *cur1,*cur2;
    cur1=list1->head;
    cur2=list2->head;
    while(cur1!=NULL)
    {
        if(slist_lookup(list2, cur1->data))
        {
            inter_list = slist_addnode_tail(inter_list,cur1->data);
        }
        cur1=cur1->next;
    }
return inter_list;
}

Slist*      unique_of_slist(Slist* list,uint32_t val){
    assert(list!=NULL);
    Node *cur;
    cur=list->head;

    while(cur!=NULL)
	{
	    if(!(slist_lookup(list,val)))
        {
            list = slist_addnode_tail(list,val);
        }
cur= cur->next;
}


return list;
}





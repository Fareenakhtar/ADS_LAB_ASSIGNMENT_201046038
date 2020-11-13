#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "slist.h"

void    test_empty_list(){
    Slist   s1 = slist_new();           //calling the function
    Slist   *list = &s1;                //variable list is pointing to s1
    assert (slist_length(list)== 0);    //check the length of the empty list and return 0
}

void test_add_at_tail(){
    Slist s1= slist_new();
    Slist *list = &s1;
    assert(slist_length(list)==0);
    list = slist_addnode_tail(list, 10);
    assert (slist_length(list)==1);
    list = slist_addnode_tail(list,20);
    list = slist_addnode_tail(list,30);
    assert (slist_length(list)==3);
}

void test_add_at_head(){
    Slist s1= slist_new();
    Slist *list = &s1;
    assert(slist_length(list)==0);
    list = slist_addnode_head(list, 10);
    assert (slist_length(list)==1);
    list = slist_addnode_head(list,20);
    list = slist_addnode_head(list,30);
    assert (slist_length(list)==3);
}

void test_delete_head(){
    Slist s1= slist_new();
    Slist *list = &s1;

    list = slist_addnode_head(list, 10);

    list = slist_addnode_head(list,20);
    list = slist_addnode_head(list,30);

    list= slist_delnode_head(list);

    assert (slist_length(list)==2);
    assert (slist_lookup(list,30)==0);
    assert (slist_lookup(list,20)==1);
    list = slist_addnode_head(list,40);
    list=slist_addnode_head(list,50);
    assert (slist_length(list)==4);
}

void test_delete_tail(){
    Slist s1= slist_new();
    Slist *list = &s1;

    list = slist_addnode_tail(list,10);
    list = slist_addnode_tail(list,20);
    list = slist_addnode_tail(list,30);

    list= slist_delnode_tail(list);

    assert (slist_length(list)==2);
    assert (slist_lookup(list,30)==0);
    assert (slist_lookup(list,20)==1);

    list= slist_delnode_tail(list);
    list= slist_delnode_tail(list);


    assert (slist_length(list)==0);
}

void max_element_in_list(){
    Slist s1= slist_new();
    Slist *list = &s1;
    Slist_max_element(list);

    list = slist_addnode_tail(list,10);
    list = slist_addnode_tail(list,20);
    list = slist_addnode_tail(list,30);

    list= slist_delnode_tail(list);

    assert (slist_length(list)==2);
    assert (slist_lookup(list,30)==0);
    assert (slist_lookup(list,20)==1);

    list= slist_addnode_tail(list,40);
    list= slist_addnode_tail(list,50);

    assert (slist_length(list)==4);
    assert (slist_lookup(list,40)==1);
    assert (slist_lookup(list,50)==1);

    assert(Slist_max_element(list)==50);
}

void min_element_in_list(){
    Slist s1= slist_new();
    Slist *list = &s1;
    Slist_max_element(list);

    list = slist_addnode_tail(list,10);
    list = slist_addnode_tail(list,20);
    list = slist_addnode_tail(list,30);

    list= slist_delnode_tail(list);

    assert (slist_length(list)==2);
    assert (slist_lookup(list,30)==0);
    assert (slist_lookup(list,20)==1);

    list= slist_addnode_tail(list,40);
    list= slist_addnode_tail(list,50);

    assert (slist_length(list)==4);
    assert (slist_lookup(list,40)==1);
    assert (slist_lookup(list,50)==1);

    assert(Slist_min_element(list)==10);
}

void add_new_ele_specified_in_list(){
    Slist s1= slist_new();
    Slist *list = &s1;
    Slist_max_element(list);

    list = slist_addnode_tail(list,10);
    list = slist_addnode_tail(list,20);
    list = slist_addnode_tail(list,30);

    list= slist_delnode_tail(list);

    assert (slist_length(list)==2);
    assert (slist_lookup(list,30)==0);
    assert (slist_lookup(list,20)==1);

    list= slist_addnode_tail(list,40);
    list= slist_addnode_tail(list,50);

    assert (slist_length(list)==4);
    assert (slist_lookup(list,40)==1);
    assert (slist_lookup(list,50)==1);

    list= slist_add_specified_ele(list,100,40);

	  assert (slist_length(list) == 6);
}

void del_specific_ele_from_list(){
    Slist s1= slist_new();
    Slist *list = &s1;
    Slist_max_element(list);

    list = slist_addnode_tail(list,10);
    list = slist_addnode_tail(list,20);
    list = slist_addnode_tail(list,30);

    list= slist_delnode_tail(list);

    assert (slist_length(list)==2);
    assert (slist_lookup(list,30)==0);
    assert (slist_lookup(list,20)==1);

    list= slist_del_specified_ele(list,10);

	  assert (slist_length(list) == 1);
    assert (slist_lookup(list,10)==0);
    assert (slist_lookup(list,20)==1);
}

void rev_list(){
    Slist s1= slist_new();
    Slist *list = &s1;
    Slist_max_element(list);

    list = slist_addnode_tail(list,10);
    list = slist_addnode_tail(list,20);
    list = slist_addnode_tail(list,30);

    list= slist_delnode_tail(list);

    assert (slist_length(list)==2);
    assert (slist_lookup(list,30)==0);
    assert (slist_lookup(list,20)==1);

    list= slist_del_specified_ele(list,10);

	  assert (slist_length(list) == 1);
    assert (slist_lookup(list,10)==0);
    assert (slist_lookup(list,20)==1);

    rev_ele_list(list);
}

void compare_two_lists(){
    Slist s1 = slist_new();
    Slist s2 = slist_new();
	  Slist *list1 = &s1;
	  Slist *list2 = &s2;

	  list1 = slist_addnode_head(list1, 100);
	  list1 = slist_addnode_head(list1, 10);

    list2 = slist_addnode_head(list2, 100);
	  list2 = slist_addnode_head(list2, 10);

    assert(compare_list(list1,list2)==1);
}

void union_of_two_list(){

    Slist s1 = slist_new();
    Slist s2 = slist_new();
	  Slist *list1 = &s1;
	  Slist *list2 = &s2;
	  Slist s3 = slist_new();
	  Slist *union_list = &s3;

	  list1 = slist_addnode_head(list1, 100);
	  list1 = slist_addnode_head(list1, 10);

    list2 = slist_addnode_head(list2, 30);
	  list2 = slist_addnode_head(list2, 40);


    union_list=union_two_list(union_list,list1,list2);
	  assert (slist_length(union_list) == 4);

}

void intersection_of_two_list(){
    Slist s1= slist_new();
    Slist s2= slist_new();
    Slist s3= slist_new();
    Slist *list1= &s1;
    Slist *list2= &s2;
    Slist *inter_list = &s3;

    list1 = slist_addnode_head(list1, 100);
	  list1 = slist_addnode_head(list1, 10);
    list1 = slist_addnode_head(list1, 20);

    list2 = slist_addnode_head(list2, 100);
	  list2 = slist_addnode_head(list2, 10);
    list2 = slist_addnode_head(list2, 40);
    inter_list=intersection_two_list(inter_list,list1,list2);
    assert (slist_length(inter_list)==2);

}

void unique_slist(){
    Slist s1= slist_new();
    Slist *list1= &s1;


    list1 = slist_addnode_head(list1, 100);
	  list1 = slist_addnode_head(list1, 10);
    list1 = slist_addnode_head(list1, 20);

    list1=unique_of_slist(list1,40);
    assert (slist_length(list1)==4);

}


int main()
{
    printf("Hello world!\n");
    test_empty_list();
    test_add_at_tail();
    test_add_at_head();
    test_delete_head();
    test_delete_tail();
    max_element_in_list();
    min_element_in_list();
    add_new_ele_specified_in_list();
    del_specific_ele_from_list();
    rev_list();
    compare_two_lists();
    union_of_two_list();
    intersection_of_two_list();
    unique_slist();
    return 0;
}

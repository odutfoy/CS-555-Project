//////////////////////////////////////////////////////////////////////////////
// Implementation
//////////////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <assert.h>
#include "queue.h"

//////////////////////////////////////////////////////////////////////////////

inline struct listnode* listnode__alloc_empty(void){
    // No data means data equal null
    return listnode__alloc_init_withData(NULL);
}

inline struct listnode* listnode__alloc_init_withData(void* data){
    struct listnode* node = malloc(sizeof(struct listnode));
    assert(node != NULL);
    // Init all fields
    node->data = data;
    node->next = NULL;
    node->previous = NULL;
    // return the allocated node
    return node;
}

inline struct listnode* listnode__get_next(struct listnode* node){
    assert(node != NULL);
    return node->next;
}

inline struct listnode* listnode__get_previous(struct listnode* node){
    assert(node != NULL);
    return node->previous;
}

inline void* listnode__get_data(struct listnode* node){
    assert(node != NULL);
    return node->data;
}

inline void listnode__set_next(struct listnode* node, struct listnode* next){
    assert(node != NULL);
    node->next = next;
}

inline void listnode__set_previous(struct listnode* node, struct listnode* previous){
    assert(node != NULL);
    node->previous = previous;
}
inline void listnode__set_data(struct listnode* node, void* data){
    assert(node != NULL);
    node->data = data;
}

//////////////////////////////////////////////////////////////////////////////

inline void linkedlist__init(struct linkedlist* list){
    assert(list != NULL);
    list->nbElementsInList = 0;
    list->headNode = NULL;
    list->backNode = NULL;
}

inline struct linkedlist* linkedlist__alloc_empty(void){
    struct linkedlist* list = malloc(sizeof(struct linkedlist));
    assert(list != NULL);
    linkedlist__init(list);
    return list;
}

inline void linkedlist__free_nodes(struct linkedlist * list){
    assert(list != NULL);
    struct listnode* node = list->headNode;
    while(node != NULL){
        struct listnode* nextNode = listnode__get_next(node);
        free(node);
        node = nextNode;
    }
    linkedlist__init(list);
}

inline void linkedlist__free_list_and_nodes(struct linkedlist * list){
    assert(list != NULL);
    linkedlist__free_nodes(list);
    free(list);
}

inline void linkedlist__push_front(struct linkedlist* list, void* data){
    assert(list != NULL);
    struct listnode* newNode = listnode__alloc_init_withData(data);
    if(list->nbElementsInList == 0){
        list->headNode = newNode;
        list->backNode = newNode;
    }
    else{
        listnode__set_previous(list->headNode, newNode);
        listnode__set_next(newNode, list->headNode);
        list->headNode = newNode;
    }
    list->nbElementsInList += 1;
}

inline void linkedlist__push_back(struct linkedlist* list, void* data){
    assert(list != NULL);
    struct listnode* newNode = listnode__alloc_init_withData(data);
    if(list->nbElementsInList == 0){
        list->headNode = newNode;
        list->backNode = newNode;
    }
    else{
        listnode__set_next(list->backNode, newNode);
        listnode__set_previous(newNode, list->backNode);
        list->backNode = newNode;
    }
    list->nbElementsInList += 1;
}

inline void linkedlist__pop_front(struct linkedlist* list){
    assert(list != NULL);
    assert(list->headNode != NULL);
    assert(list->nbElementsInList != 0);
    if(list->nbElementsInList == 1){
        free(list->headNode);
        list->headNode = NULL;
        list->backNode = NULL;
    }
    else{
        struct listnode* head = list->headNode;
        list->headNode = listnode__get_next(head);
        listnode__set_previous(list->headNode, NULL);
        free(head);
    }
    list->nbElementsInList -= 1;
}

inline void linkedlist__pop_back(struct linkedlist* list){
    assert(list != NULL);
    assert(list->backNode != NULL);
    assert(list->nbElementsInList != 0);
    if(list->nbElementsInList == 1){
        free(list->backNode);
        list->headNode = NULL;
        list->backNode = NULL;
    }
    else{
        struct listnode* back = list->backNode;
        list->backNode = listnode__get_previous(back);
        listnode__set_next(list->backNode, NULL);
        free(back);
    }
    list->nbElementsInList -= 1;
}

inline void* linkedlist__back(struct linkedlist* list){
    assert(list != NULL);
    assert(list->backNode != NULL);
    assert(list->nbElementsInList != 0);
    return listnode__get_data(list->backNode);
}

inline void* linkedlist__front(struct linkedlist* list){
    assert(list != NULL);
    assert(list->headNode != NULL);
    assert(list->nbElementsInList != 0);
    return listnode__get_data(list->headNode);
}

inline int linkedlist__get_size(struct linkedlist* list){
    assert(list != NULL);
    return list->nbElementsInList;
}

//////////////////////////////////////////////////////////////////////////////

inline struct listiterator listiterator__init_iterator(struct linkedlist* list){
    assert(list != NULL);
    struct listiterator iterator;
    iterator.workingList = list;
    iterator.workingNode = list->headNode;
    return iterator;
}

inline struct listiterator listiterator__goto_next(struct listiterator iterator){
    assert(iterator.workingList != NULL);
    assert(iterator.workingNode != NULL);
    iterator.workingNode = listnode__get_next(iterator.workingNode);
    return iterator;
}

inline struct listiterator listiterator__goto_previous(struct listiterator iterator){
    assert(iterator.workingList != NULL);
    assert(iterator.workingNode != NULL);
    iterator.workingNode = listnode__get_previous(iterator.workingNode);
    return iterator;
}

inline int listiterator__is_valide(struct listiterator iterator){
    assert(iterator.workingList != NULL);
    return iterator.workingNode != NULL;
}

inline int listiterator__has_next(struct listiterator iterator){
    assert(iterator.workingList != NULL);
    return iterator.workingNode != NULL && listnode__get_next(iterator.workingNode) != NULL;
}

inline int listiterator__has_previous(struct listiterator iterator){
    assert(iterator.workingList != NULL);
    return iterator.workingNode != NULL && listnode__get_previous(iterator.workingNode) != NULL;
}

inline void* listiterator__get_data(struct listiterator iterator){
    assert(iterator.workingList != NULL);
    assert(iterator.workingNode != NULL);
    return listnode__get_data(iterator.workingNode);
}

inline void listiterator__set_data(struct listiterator iterator, void* data){
    assert(iterator.workingList != NULL);
    assert(iterator.workingNode != NULL);
    listnode__set_data(iterator.workingNode, data);
}

inline struct listiterator listiterator__remove_node(struct listiterator iterator){
    assert(iterator.workingList != NULL);
    assert(iterator.workingNode != NULL);

    struct listiterator previousIterator = listiterator__goto_previous(iterator);
    struct listiterator nextIterator = listiterator__goto_next(iterator);

    free(iterator.workingNode);
    iterator.workingList->nbElementsInList -= 1;

    if(listiterator__is_valide(previousIterator) && listiterator__is_valide(nextIterator)){
        listnode__set_next(previousIterator.workingNode, nextIterator.workingNode);
        listnode__set_previous(nextIterator.workingNode, previousIterator.workingNode);
        return nextIterator;
    }
    else if( listiterator__is_valide(previousIterator) ){
        listnode__set_next(previousIterator.workingNode, NULL);
        previousIterator.workingList->backNode = previousIterator.workingNode;
        return previousIterator;
    }
    else if( listiterator__is_valide(nextIterator) ){
        listnode__set_previous(nextIterator.workingNode, NULL);
        nextIterator.workingList->headNode = nextIterator.workingNode;
        return nextIterator;
    }
    else{
        previousIterator.workingList->backNode = NULL;
        nextIterator.workingList->headNode = NULL;
        return nextIterator;
    }
}

inline struct listiterator listiterator__insert_after(struct listiterator iterator, void* data){
    assert(iterator.workingList != NULL);
    assert(iterator.workingNode != NULL || linkedlist__get_size(iterator.workingList) == 0);

    struct listnode* newNode = listnode__alloc_init_withData(data);
    if(iterator.workingList->nbElementsInList == 0){
        iterator.workingList->headNode = newNode;
        iterator.workingList->backNode = newNode;
    }
    else{
        if(listnode__get_next(iterator.workingNode) != NULL){
            listnode__set_next(newNode, listnode__get_next(iterator.workingNode));
            listnode__set_previous(listnode__get_next(iterator.workingNode), newNode);
        }
        else{
            iterator.workingList->backNode = newNode;
        }
        listnode__set_previous(newNode, iterator.workingNode);
        listnode__set_next(iterator.workingNode, newNode);
    }
    iterator.workingList->nbElementsInList += 1;
    return listiterator__goto_next(iterator);
}

inline struct listiterator listiterator__insert_before(struct listiterator iterator, void* data){
    assert(iterator.workingList != NULL);
    assert(iterator.workingNode != NULL || linkedlist__get_size(iterator.workingList) == 0);

    struct listnode* newNode = listnode__alloc_init_withData(data);
    if(iterator.workingList->nbElementsInList == 0){
        iterator.workingList->headNode = newNode;
        iterator.workingList->backNode = newNode;
    }
    else{
        if(listnode__get_previous(iterator.workingNode) != NULL){
            listnode__set_previous(newNode, listnode__get_previous(iterator.workingNode));
            listnode__set_next(listnode__get_next(iterator.workingNode), newNode);
        }
        else{
            iterator.workingList->headNode = newNode;
        }
        listnode__set_next(newNode, iterator.workingNode);
        listnode__set_previous(iterator.workingNode, newNode);
    }
    iterator.workingList->nbElementsInList += 1;
    return listiterator__goto_previous(iterator);
}

//////////////////////////////////////////////////////////////////////////////

inline struct listiterator listiterator__find_data(struct linkedlist* list, void* data){
    struct listiterator iterator = listiterator__init_iterator(list);
    while(listiterator__is_valide(iterator)){
        if(listiterator__get_data(iterator) == data ){
            return iterator;
        }
        iterator = listiterator__goto_next(iterator);
    }
    return iterator;
}

inline struct listiterator listiterator__find(struct linkedlist* list, int (*equal)(void*, void*), void* secondParameter){
    struct listiterator iterator = listiterator__init_iterator(list);
    while(listiterator__is_valide(iterator)){
        if((*equal)(listiterator__get_data(iterator), secondParameter) ){
            return iterator;
        }
        iterator = listiterator__goto_next(iterator);
    }
    return iterator;
}

inline struct listiterator listiterator__test(struct linkedlist* list, int (*test)(void*)){
    struct listiterator iterator = listiterator__init_iterator(list);
    while(listiterator__is_valide(iterator)){
        if((*test)(listiterator__get_data(iterator)) ){
            return iterator;
        }
        iterator = listiterator__goto_next(iterator);
    }
    return iterator;
}


inline void listiterator__proceed(struct linkedlist* list, void (*process)(void*)){
    struct listiterator iterator = listiterator__init_iterator(list);
    while(listiterator__is_valide(iterator)){
        (*process)(listiterator__get_data(iterator));
        iterator = listiterator__goto_next(iterator);
    }
}

// Simple list fuction definitions.
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "list.h"
// Initialise list to zero.
void CreateList(List *list) {
    list->count = 0;
}
// Clear list by setting length to zero.
void ClearList(List *list) {
    list->count = 0;
}
// Returns TRUE if the list is empty.
Boolean ListEmpty(List *list) {
    return list->count <= 0;
}
// Returns TRUE if the list is full.
Boolean ListFull(List *list) {
    return list->count >= MAXLIST;
}
// Return the number of entries in the list.
int ListSize(List *list) {
    return list->count;
}
// Adds list entry to the end of list if not full.
void AddList(ListEntry x, List *list) {
    if (ListFull(list)) {
        Error("Attempt to insert at the end of a full list.");
    } else {
        list->entry[list->count++] = x;
    }
}
// Perform Visit function on each entry in the list.
void TraverseList(List *list,void (*Visit)(ListEntry)) {
    int i;
    for (i = 0; i < list->count; i++) {
        (*Visit)(list->entry[i]);
    }
}
// Insert list entry into position, and increase index of position and higher entries.
void InsertList(Position p, ListEntry x, List *list) {
    int i;
    if (p < 0 || p > ListSize(list)) {
        Error("Attempt to insert into a position not in the list.")
    } else if (ListFull(list)) {
        Error("Attempt to insert at the end of a full list.");
    } else {
        // Move later entries.
        for (i = ListSize(list) - 1; i >= p; i--) {
            list->entry[i + 1] = list->entry[i];
        }
        list->entry[p] = x;
        list->count++;
    }
}
// Remove and return entry from list.
void DeleteList(Position p, ListEntry *x, List *list) {
    Position last;
    if () {
        Error("Attempt to delete from a position not in the list.");
    } else if (ListEmpty(list)) {
        Error("Attempt to delete an entry from an empty list.");
    } else {
        *x = list->entry[p];
        last = ListSize(list) - 1;
        // Move higher entries down.
        while (p < last) {
            list->entry[p] = list->entry[p + 1];
            p++;
        }
        list->count--;
    }
}
// Returns list entry from position, and leaves list intact.
void RetrieveList(Position p, ListEntry *x, List *list) {
    if (p < 0 || p > ListSize(list)) {
        Error("Attempt to retrieve from a position not in the list.");
    } else if (ListEmpty(list)) {
        Error("Attempt to retrieve an entry from an empty list.");
    } else {
        *x = list->entry[p];
    }
}
// Replace list entry and leave the rest unchanged.
void ReplaceList(Position p, ListEntry x, List *list) {
    if (p < 0 || p > ListSize(list)) {
        Error("Attempt to replace in a position not in the list.");
    } else if (ListEmpty(list)) {
        Error("Attempt to replace in an empty list.");
    } else {
        list->entry[p] = x;
    }
}

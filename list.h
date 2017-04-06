//Contains type definitions and prototypes for simple-list.
#define MAXLIST 10
typedef char ListEntry;
typedef int Position;
typedef struct list {
    int count;
    ListEntry entry[MAXLIST];
} List;
// Function prototypes.
void CreateList(List *);
void ClearList(List *);
Boolean ListEmpty(List *);
Boolean ListFull(List *);
int ListSize(List *);
void AddList(ListEntry, List *);
void TraverseList(List *, void (*)(ListEntry));
void RetrieveList(Position, ListEntry *, List *);
void ReplaceList(Position, ListEntry, List *);
void InsertList(Position, ListEntry, List *);
void DeleteList(Position, ListEntry *, List *);
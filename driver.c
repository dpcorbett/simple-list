// Simple list driver, for testing list.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // Contains functions for case conversions.
#include "common.h"
#include "list.h"
#include "driver.h"
// Entry point for program to test simple lists.
int main(void) {
    List list;
    CreateList(&list);
    // An endless loop, DoCommand() will call exit() to end the program.
    while (TRUE) {
        DoCommand(GetCommand(), &list);
    }
    // This statement should never get executed.
    return 1; 
}
// Print program help to screen.
void Help(void) {
    printf("\nThis program allows one command to be entered on each line.\n"
            "For example, if the command I is entered at the command line\n"
            "then the program will ask for a string of characters and\n"
            "insert them one at a time into the simple list.\n");
    printf("Valid commands are:\n"
            "\tI - Insert values into the simple list\n"
            "\tP - Print the simple list\n"
            "\tT - Traverse the simple list (same as print)\n"
            "\tS - The current size of the simple list\n"
            "\tD - Delete the simple list\n"
            "\tC - Clear the simple list (same as delete)\n"
            "\tH - This help screen\n"
            "\tQ - Quit\n"
            "Press <Enter> to continue.");
    while (getchar() != '\n') {
        ;
    }
}
// Returns valid command from terminal.
char GetCommand(void) {
    char command;
    printf("\n\t[I]nsert entry\t[P]rint list\t[S]ize of list\n"
            "\t[Delete list\t[C]lear list\t[H]elp\n"
            "\t[T]raverse the list\t\t[Q]uit.\n"
            "Select command and press <Enter>:");
    while (TRUE) {
        while ((command = getchar()) == '\n') {
            ;
        }
        // Change case if necessary.
        command = tolower(command);
        if (command == 'i' || command == 'p' || command == 't' ||
            command == 's' || command == 'd' || command == 'c' ||
            command == 'h' || command == 'q') {
                while (getchar() != '\n') {
                    ;
                }
                return command;
        }
        printf("Please enter a valid command or H for help:");
    }
}
// Perform command on simple list.
void DoCommand(char command, List *list) {
    ListEntry x;
    switch (command) {
        // Insert new entry.
        case 'i': {
            if (ListFull(list)) {
                Warning("Sorry, list is full.");
            } else {
                printf("Enter new key(s) to insert");
                while ((x = getchar()) != '\n' && !ListFull(list)) {
                    AddList(x, list);
                }
                if (x != '\n') {
                    Warning("The list is full, cannot insert any more entries.");
                    while ((x = getchar()) != '\n') {
                        ;
                    }
                }
            }
            break;
        }
        // Delete entry.
        case 'd':
        // Clear list.
        case 'c': {
            ClearList(list);
            printf("List is cleared.\n");
            break;
        }
        // Print list.
        case 'p':
        // Traverse list printing entries.
        case 't': {
            if (ListEmpty(list)) {
                printf("List is empty.\n")
            } else {
                printf("\nTraversing the list; it contains:\n");
                TraverseList(list, Print);
            }
            break;
        }
        // Display number of entries in list.
        case 's': {
            printf("The size of the list is %d\n", ListSize(list));
            break;
        }
        // Display help menu.
        case 'h': {
            Help();
            break;
        }
        // Exit program.
        case 'q': {
            printf("Simple list demonstration finished.\n");
            exit(0);
        }
    }
}
// Display list entry.
void Print(ListEntry x) {
    printf("   %c", x);
}
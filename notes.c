#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void) {
    char input_buffer[100];
    char nano[100];
    char note_name[100];
    printf("NEW NOTE: 1\n");
    printf("OPEN NOTE: 2\n");
    printf("DELETE NOTE: 3\n");
    printf("Enter A Number: ");
    if (fgets(input_buffer, sizeof(input_buffer), stdin) != NULL) {
        int menu_input = atoi(input_buffer);
        switch (menu_input) {
            case 1:
                printf("What do you want to call the note: ");
                if (fgets(note_name, 100, stdin) != NULL) {
                    note_name[strcspn(note_name, "\n")] = '\0';
                }
                sprintf(nano, "nano %s", note_name);
                system(nano);
                break;
            case 2:
                printf("What note would you like to open: ");
                if (fgets(note_name, 100, stdin) != NULL) {
                    note_name[strcspn(note_name, "\n")] = '\0';
                }
                if (access(note_name, F_OK) != 0) {
                    printf("File does not exist!\n");
                } else {
                    snprintf(nano, sizeof(nano), "nano %s", note_name);
                    system(nano);
                }
                break;
            case 3:
                printf("What note would you like to delete: ");
                if (fgets(note_name, 100, stdin) != NULL) {
                    note_name[strcspn(note_name, "\n")] = '\0';
                }
                if (access(note_name, F_OK) != 0) {
                    printf("This file does not exist!\n"); 
                } else {
                    remove(note_name);
                }
                break;
            default:
                return EXIT_FAILURE;
                break;
        }
    }
    return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void) {
    char buffer[1024];
    char nano[1024];
    char noteName[1024];

    puts("NEW NOTE 1\n" "OPEN NOTE: 2\n" "DELETE NOTE: 3");
    printf("Enter A Number: ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        switch (atoi(buffer)) {
            case 1:
                printf("What do you want to call the note: ");
                if (fgets(noteName, 100, stdin) != NULL) {
                    noteName[strcspn(noteName, "\n")] = '\0';
                }
                snprintf(nano, sizeof(nano), "nano %s", noteName);
                system(nano);
                break;
            case 2:
                printf("What note would you like to open: ");
                if (fgets(noteName, 100, stdin) != NULL) {
                    noteName[strcspn(noteName, "\n")] = '\0';
                }
                snprintf(nano, sizeof(nano), "%s", noteName);
                if (access(noteName, F_OK) != 0) {
                    fputs("This file does not exist!", stderr);
                } else {
                    snprintf(nano, sizeof(nano), "nano %s", noteName);
                    system(nano);
                }
                break;
            case 3:
                printf("What note would you like to delete:");
                if (fgets(noteName, 100, stdin) != NULL) {
                    noteName[strcspn(noteName, "\n")] = '\0';
                }
                if (access(noteName, F_OK) != 0) {
                    fputs("This file does not exist!\n", stderr); 
                } else {
                    remove(noteName);
                }
                break;
            default:
                fputs("Invalid number!", stderr);
                return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}
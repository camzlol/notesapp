#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE* file;
    int menu_input;
    char *note_name = malloc(100 * sizeof(char));
    printf("NEW NOTE: 1\n");
    printf("OPEN NOTE: 2\n");
    printf("DELETE NOTE: 3\n");
    printf("Enter A Number: ");
    scanf("%d", &menu_input);
    while (getchar() != '\n');
    switch (menu_input) {
        case 1:
            printf("What do you want to call the note? \n");
            if (fgets(note_name, 100, stdin) != NULL) {
                note_name[strcspn(note_name, "\n")] = '\0';
            }
            file = fopen(note_name, "w");
            free(note_name);
            break;
        default:
            return EXIT_FAILURE;
            break;
    }
    return EXIT_SUCCESS;
}
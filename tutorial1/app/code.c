// INCLUDES
#include <stdio.h>
#include "code.h"

// GLOBALS


//FUNCTIONS
// welcome message
void welcome_message()
{
    printf("Welcome!\n");
}
// get group name
void get_name(char* name)
{
    printf("Enter group name : ");
    gets(name);
}

// 1. Function to create a folder using the name variable as its name
void create_folder(char* name)
{
mkdir(name,0777)
}

// 2. Function to create a file in the folder <folder_name> called group.txt where you insert the <group_name> as text
void create_file(char* folder_name, char* group_name)
{
char filename[100];
snprintf(filename, sizeof(filename), "%s/%s.txt", folder_name, group_name);
    FILE* file = fopen(filename, "w");
    if (file != NULL) {
        fprintf(file, "Group: %s\n", group_name);
        fclose(file);
    }
}

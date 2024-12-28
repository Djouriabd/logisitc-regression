#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 400

int main() {
    FILE *file;
    char line[100]; 
    char *p;
    int i = 0;
    
    file = fopen("C:/Users/Dell/Desktop/Game/survey_lung_cancer (4).csv", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    
    while (fgets(line, sizeof(line), file) && i < MAX_LINES) {
        i++; 
        printf("Row %d: ", i);

        
        p = strtok(line, ",");
        while (p != NULL) {
            
            printf("%s ", p);
            p = strtok(NULL, ",");
        }
        printf("\n"); 
    }

    
    fclose(file);

    return 0;
}

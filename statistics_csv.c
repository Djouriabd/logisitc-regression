#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define MAX_LINES 5   
#define MAX_LINE_LENGTH 1024  
#define MAX_COLUMNS 100

void display_info(const char *filename) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *p;
    int num_columns = 0;
    int num_rows = 0;

    
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }
    if (fgets(line, sizeof(line), file)) {
        printf("Columns: ");
        p = strtok(line, ",");
        while (p != NULL) {
            printf("%s ", p);
            num_columns++;
            p = strtok(NULL, ",");
        }
        printf("\n");
    }
    while (fgets(line, sizeof(line), file)) {
        num_rows++;
    }

    fclose(file);
    printf("Number of columns: %d\n", num_columns);
    printf("Number of rows: %d\n", num_rows);
}

void display_rows(const char *filename, int max_lines) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *p;
    int i = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }
    fgets(line, sizeof(line), file);
    while (fgets(line, sizeof(line), file) && i < max_lines) {
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
}
    void check_missing_values(const char *filename) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *p;
    int column_missing[MAX_COLUMNS] = {0};
    int num_columns = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }
    if (fgets(line, sizeof(line), file)) {
        p = strtok(line, ",");
        while (p != NULL) {
            num_columns++;
            p = strtok(NULL, ",");
        }
    }
    while (fgets(line, sizeof(line), file)) {
        int column_index = 0;
        p = strtok(line, ",");
        while (p != NULL) {
            if (strcmp(p, "") == 0 || strcmp(p, "\n") == 0 || p[0] == '\0') {
                column_missing[column_index]++;
            }
            column_index++;
            p = strtok(NULL, ",");
        }
    }

    fclose(file);
    printf("\nMissing values per column:\n");
    for (int i = 0; i < num_columns; i++) {
        printf("Column %d: %d missing values\n", i + 1, column_missing[i]);
    }
}
    void calculate_statistics(const char *filename) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *p;
    double data[MAX_COLUMNS][MAX_LINES] = {0};
    int num_columns = 0, num_rows = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }
    if (fgets(line, sizeof(line), file)) {
        p = strtok(line, ",");
        while (p != NULL) {
            num_columns++;
            p = strtok(NULL, ",");
        }
    }
    while (fgets(line, sizeof(line), file) && num_rows < MAX_LINES) {
        int column_index = 0;
        p = strtok(line, ",");
        while (p != NULL) {
            if (column_index < MAX_COLUMNS) {
                data[column_index][num_rows] = atof(p);
            }
            column_index++;
            p = strtok(NULL, ",");
        }
        num_rows++;
    }

    fclose(file);

    
    printf("\nStatistics per column:\n");
    for (int i = 0; i < num_columns; i++) {
        double sum = 0, min = data[i][0], max = data[i][0], mean, stddev = 0;

        for (int j = 0; j < num_rows; j++) {
            sum += data[i][j];
            if (data[i][j] < min) min = data[i][j];
            if (data[i][j] > max) max = data[i][j];
        }

        mean = sum / num_rows;

        for (int j = 0; j < num_rows; j++) {
            stddev += pow(data[i][j] - mean, 2);
        }

        stddev = sqrt(stddev / num_rows);

        printf("Column %d: mean = %.2f, min = %.2f, max = %.2f, stddev = %.2f\n",
                i + 1, mean, min, max, stddev);
    }
}

int main() {
    const char *filename = "C:/Users/Dell/Desktop/Game/survey_lung_cancer (4).csv";
    display_info(filename);
    display_rows(filename, MAX_LINES);
    check_missing_values(filename);
    calculate_statistics(filename);
    return 0;
}

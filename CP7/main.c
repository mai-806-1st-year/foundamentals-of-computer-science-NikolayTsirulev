#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
	
void incorrectFilename() {
    puts("The filename is incorrect");
}

void menu() {
    puts("1. Read matrix.");
    puts("2. Print matrix.");
    puts("3. Print inner data of matrix");
    puts("4. Transpose matrix.");
    puts("5. Transpose by side-diagonal matrix.");
    puts("6. Check the whether the matrix is skew-matrix.");
    puts("7. Quit.");
}

int main() {
    int choice = 0;
    printf("Print name of file: ");
    char* filename = (char*)calloc(40, sizeof(char));
    scanf("%s", filename);
    Matrix *m = init();
    while (choice < 7) {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enter(m, filename);
                printf("The matrix was successfully read\n\n");
                break;
            case 2:
                print(m);
                break;
            case 3:
                print_inner(m);
                break;
            case 4:
                m = transpose(m);
                break;
            case 5:
                m = transpose_by_side_diagonal(m);
                break;
            case 6:
                if(skew_symmetric(m)) {
                    puts("Matrix is skew-symmetric.");
                }else {
                    puts("Matrix is not skew-symmetric.");
                }
                break;
            default:
                menu();
                break;
        }
    }
    free_matrix(m);
    free(filename);
    printf("The program is closed\n");

}

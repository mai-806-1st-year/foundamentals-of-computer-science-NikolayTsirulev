#include "person.h"

int main(int argc, char* argv[]){
    if (argc != 3){
        fprintf(stderr, "Wrong number of args!\n");
        return 2;
    }
    FILE* in = fopen(argv[1], "r");
    FILE* out = fopen(argv[2], "wb");
    if (in == NULL){
        fprintf(stderr, "Can't open in file!\n");
        return 1;
    }
    if (out == NULL){
        fprintf(stderr, "Can't create out file!\n");
        return 3;
    }
    person p;
    int c = 0;
    fseek(out, sizeof(int), SEEK_SET);
    while(fscanf(in, "%[^ ] %[^ ] %c %d %c %u %u %u %c\n", p.surname, p.initials, &p.gender, &p.school_number, &p.medal, &p.math, &p.physics, &p.computer_science, &p.essay) == 9){
        if (fwrite(&p, sizeof(p), 1, out) != 1){
            fprintf(stderr, "Write error!\n");
            return 1;
        }
        c++;
    }
    fseek(out, 0, SEEK_SET);
    if (fwrite(&c, sizeof(int), 1, out) != 1) {
        fprintf(stderr, "Write error!\n");
        return 1;
    }
	printf("%d lines are written\n", c);
    fclose(in);
    fclose(out);
    return 0;
}

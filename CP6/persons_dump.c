#include "person.h"

bool ReadData (person* p, FILE* in) {
    int essay, gender, medal;
    int res = fscanf(in, "%[^ ] %[^ ] %d %d %d %u %u %u %d\n", p->surname, p->initials, &gender, &p->school_number, &medal, &p->math, &p->physics, &p->computer_science, &essay);
    p->essay = (bool)essay;
    p->gender = (bool)gender;
    p->medal = (bool)medal;
    return res == 9;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Wrong number of args!\n");
        return 2;
    }
    FILE* in = fopen(argv[1], "r");
    FILE* out = fopen(argv[2], "w");
    if (in == NULL) {
        fprintf(stderr, "Can't open in file!\n");
        return 1;
    }
    if (out == NULL) {
        fprintf(stderr, "Can't create out file!\n");
        return 3;
    }
    person p;
    while(ReadData(&p, in)) {
    	fwrite(&p, sizeof(person), 1, out);
    }
    fclose(in);
    fclose(out);
    return 0;
}

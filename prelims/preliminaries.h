#ifndef __PRELIMINARIES_H__
#define __PRELIMINARIES_H__

int sample_func(float param_1, int* param_2); // Function declaration

enum data_types {chr=0,intg=1,flt=2,dbl=3};

typedef enum ctype {cse=0,csd=1,ece=2,ecd=3,cld=4,chd=5} course_type;

typedef struct record_type_1 rec_1;

struct record_type_1 {
    char *name;
    int roll;    
    course_type ctyp;
};

typedef struct _addr addr;
struct _addr {    
    const char* pincode;
};

typedef struct record_type_2 rec_2;

struct record_type_2 {
    rec_1 acad;
    addr  add;
};

#endif
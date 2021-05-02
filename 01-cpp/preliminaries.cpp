#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <new> // bad_alloc
#include <iostream> // cout, endl
#include "preliminaries.h"

/*
void print_choices()
{
    printf("\n===========\n");
    printf(" 1 : Built-in data types and their storage sizes\n");
    printf(" 2 : Type modifier example \n");
    printf(" 3 : Pointers\n");
    printf(" 4 : Arrays\n");
    printf(" 5 : 2D Arrays\n");
    printf(" 6 : Functions\n");
    printf(" 7 : Structures\n");

    printf("\n\nSelect a number. Press 0 to exit:");
}
*/

void print_choices()
{
    std::cout << std::endl << "===========" << std::endl;    
    std::cout << " 1 : Arrays" << std::endl;
    std::cout << " 2 : 2D Arrays" << std::endl;    

    std::cout << std::endl << std::endl << "Select a number. Press 0 to exit:" << std::endl;
}

void pause()
{
    std::cout << std::endl << "Press any key to continue ..." << std::endl;

    char ch; 
    std::cin >> ch;
    
    std::cin.seekg(0,std::ios::end);
    std::cin.clear();
    
}

void arrays()
{
    
    int num_elems = 10;
    
    int *p = NULL;
    // code block below is similar to assert
    try {
         p = new int[num_elems];
    } catch (std::bad_alloc&) {
        std::cout << "Not enough memory to allocate for array." << std::endl;
        throw;
    }
    
    delete[] p;  // NOTE: not delete p since p is pointer to an array of elements

    char *ch = new char;
    delete ch;
    
}

void arrays_2d()
{
    int nRows = 6;
    int nCols = 7;
    
    // Dynamic allocation
    int **matrixPtr = NULL; // pointer to pointer to int
    matrixPtr = new int*[nRows];
    for(int i = 0 ; i < nRows ; i++) {
        matrixPtr[i] = new int[nCols];
    }
    
    // Free up memory
    for(int i = 0 ; i < nRows ; i++) 
    	delete[] matrixPtr[i];
    delete[] matrixPtr;

}
/*
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

void structures()
{
    
    rec_1 r1,r2;
    printf("Size of structure r1 (after initialization) = %d bytes\n",sizeof(r1));
    pause();

    // INITIALIZE STRUCT ENTRIES
    // r1
    r1.roll = 1;
    char *name_1 = "Ravi Kiran";
    r1.name = strdup(name_1);
    assert(r1.name != NULL);
    r1.ctyp = course_type::csd;
    // r2
    r2.roll = 2;
    char *name_2 = "Suresh Purini";
    r2.name = strdup(name_2);
    assert(r2.name != NULL);
    r2.ctyp = course_type::cse;

    // DE-ALLOCATE STRUCT ENTRIES
    free(r1.name);
    free(r2.name);
    
    // Array of structures    
    int nRecords = 2;
    const char *name_list[nRecords];
    name_list[0] = "PJN";
    name_list[1] = "Vineet";         
    const course_type ctypArr[] = {course_type::cse,course_type::csd};
       
    // ITERATE THROUGH STRUCT ARRAY 
    rec_1 acad_records[nRecords];
    for(int i = 0 ; i < nRecords ;i++) {
        acad_records[i].roll = i+1;
        acad_records[i].name = strdup(name_list[i]);
        acad_records[i].ctyp = ctypArr[i];
    }

    // Nested structures
    rec_2 *soc_record;

    soc_record = (rec_2 *)malloc(sizeof(rec_2));
    assert(soc_record != NULL);
    soc_record->acad = acad_records[0];
    soc_record->acad.name = strdup(acad_records[0].name);
    soc_record->add.pincode = "500084";

    // DESTROY STRUCTURE ELEMENTS
    for(int i  = 0 ; i < nRecords ; i++)
        free(acad_records[i].name);

    free(soc_record->acad.name);
               
}

*/

int main()
{

    bool flag = false;
    flag = true;

    int ch;
    while(1)
    {
        print_choices();

        std::cin >> ch; // getchar()

        std::cin.seekg(0,std::ios::end);
        std::cin.clear();

        switch (ch)
        {            
            case 1:
                arrays();
                break;
            case 2:
                arrays_2d();
                break;         
            case 0:            
                goto endofprog;
        }                 
    }
    
    endofprog: ;
    
    return 0;
}

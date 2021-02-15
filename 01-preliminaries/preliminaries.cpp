#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "preliminaries.h"

// An ugly, but generic way of printing an array of in-built data types
void print_array(void *x,int nElems,enum data_types dt)
{
    printf("\n");
    for(int i = 0 ; i < nElems ; i++)
    {        
        switch(dt)
        {
            case chr :
            {
                    char *c = (char *)x;                    
                    printf("%c ",c[i]);
                    break;
            }
            case intg :
            {
                    int *g = (int *)x;                    
                    printf("%d ",g[i]);
                    break;
            }
            case flt :
            {
                    float *f = (float *)x;                    
                    printf("%f ",f[i]);
                    break;
            }
            case dbl:
            {
                    double *d = (double *)x;                    
                    printf("%lf ",d[i]);
                    break;
            }
        }
    }
    printf("\n");
}

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

void pause()
{
    printf("\nPress any key to continue ...\n");
    char ch; scanf("%c",&ch);    
    fseek(stdin,0,SEEK_END); // flush input buffer
}

void data_types()
{
    printf("Built-in data types and their storage sizes\n");    
    
    printf("[Signed]\n");
    printf("char:   %d bytes\n",sizeof(char));
    printf("short:  %d bytes\n",sizeof(short));
    printf("int:    %d bytes\n",sizeof(int));
    printf("float:  %d bytes\n",sizeof(float));
    printf("double: %d bytes\n",sizeof(double));

    printf("\n[TYPE MODIFIER Unsigned - for storing nonnegative values]\n");
    printf("uchar:   %d bytes\n",sizeof(unsigned char));
    printf("ushort:  %d bytes\n",sizeof(unsigned short));
    printf("uint:    %d bytes\n",sizeof(unsigned int));
    //Code below will throw an error ! unsigned float, unsigned 
    // double aren't supported at hardware level. Feel free to 
    // find out why :)
    //printf("ufloat:  %d bytes\n",sizeof(unsigned float));
    //printf("udouble: %d bytes\n",sizeof(unsigned double));

    // Minimum and maximum value
    printf("\nFor minimum and maximum values of data types, look at limits.h and float.h\n");
    
}

void type_qualifier()
{
    // TYPE QUALIFIER const
    const int x = 0; // variable is read-only
    //x = 3; // Error!    
}

void pointers()
{
    printf("[Signed]\n");
    printf("char pointer:   %d bytes\n",sizeof(char*));
    printf("short pointer:  %d bytes\n",sizeof(short*));
    printf("int pointer:    %d bytes\n",sizeof(int*));
    printf("float pointer:  %d bytes\n",sizeof(float*));
    printf("double pointer: %d bytes\n",sizeof(double*));
    
    pause();

    char* p; // A pointer variable - Stores address of an associated data type variable
    char ch = 'a';
    p = &ch;
    // &ch = p; This will throw an error. Why ?
    printf("\nch:%c, ch:%c (via pointer dereferencing)\n",ch,*p);

    p = NULL; // Special address : Logically equivalent to 0
    if( !p )
        printf("\nA null pointer is logically equivalent to 0\n");

    void* v; // Can store address of ANY data type
    int x=10;
    v = &x; // OK - stores address of variable x    
    v = &ch; // OK - now stores address of variable ch  
    
    p = &ch;
    ch = x; // OK (but a bit weird and buggy!) 
    //p = &x;  // Error - x is integer pointer, p is char pointer

    p = &ch;  // OK - p stores address of char variable ch 
    char ch2 = 'm';
    p = &ch2; // OK - p now stores address of char variable ch2
    printf("\nBefore: %c ",*p);
    *p = 'm'; // OK - Changing value stored in ch2 via pointer dereferencing
    printf("After: %c \n",*p);
    printf("Address stored in variable p = %p\n",p);
    printf("Address of variable p = %p\n",&p);
    pause();

    const char* ptr2const = NULL;
    ptr2const = &ch;
    //*ptr2const = 'd'; // ERROR : ptr2const cannot be used to modify content it points to
    ptr2const = "DSA"; // OK - points to a non-modifiable content

    //char* const constPtr; // ERROR : Constant pointer has to be initialized during declaration
    char* const constPtr = &ch;
    //constPtr = &ch2; // ERROR : Constant pointer cannot be assigned a location after initialization
    *constPtr = 'r'; // OK

    // Q: How to have a pointer which points to a fixed location
    // and cannot be used to change the value at that location ?
    // (Hint: Combine the two const ideas above)
    
}

void arrays()
{
    // An array is a fixed-size collection of elements 
    // arranged sequentially in memory

    // version 1: static allocation - size known at compile time
    int counts[100]; // initializes to 0 (C++)
    int counts2[10] = {6,1,8}; // partial initialization
    //counts2 = {1,2,3,4,5,6,7,8,9,10}; // ERROR - assignment is not supported for arrays
    
    int num_elems = 10;
    int counts3[num_elems]; 
    for(int i = 0 ; i < num_elems ; i++)
        printf("i=%d, counts:%d counts2:%d counts3:%d\n",i,counts[i],counts2[i],counts3[i]);
    printf("\n");
    pause();

    // size determined implicitly from initialization list
    int entries[] = {6,1,8,9,23};
    char course_name[] = "DSA2021";
    printf("Number of elements in array [entries] = %d\n",sizeof(entries)/sizeof(entries[0]));
    printf("Number of characters in array [course_name] = %d\n",sizeof(course_name)/sizeof(course_name[0]));
    int j = 0;
    while (course_name[j] != '\0')
        ++j;
    printf("\nIndex of NUL character in [course_name] array=%d\n",j);
    pause();

    // Memory view
    // Array declaration just sets aside storage for array elements
    //    +---+
    // a: |   | a[0]
    //    +---+
    //    |   | a[1]
    //    +---+
    //    |   | a[2]
    //    +---+
    //     ...
    //    +---+ 
    //    |   | a[N-1]
    //    +---+
    // 
    // T a[N] => an array variable 'a' with N elements of type T
    // NOTE: a is NOT a pointer    
    // BUT a[i] = *(a+i) = *(&a[0] + i)
    double vals[5] = {1.5,2.4,4.5,6.7,8.8};
    printf("Addressing: vals:%p &vals[0]:%p\n",(void*)vals,(void*)&vals[0]);
    printf("Indexing: vals[2]:%lf *(vals+2):%lf *(&vals[0] +2):%lf\n",vals[2],*(vals+2),*(&vals[0]+2)); 
    
    // version 2: dynamic allocation (on heap)    
    int *p = NULL;
    p = (int *)malloc(num_elems*sizeof(int)); // num_elems = 10
    assert(p != NULL); // ALWAYS CHECK - MEMORY ALLOC NOT GUARANTEED

    // Array declaration just sets aside storage for array elements
    //
    //  +---+
    //p:|   |------+
    //  +---+      |
    //             |
    //      +------+
    //      |
    //      V
    //    +---+
    //    |   | p[0]
    //    +---+
    //    |   | p[1]
    //    +---+
    //    |   | p[2]
    //    +---+
    //     ...
    //    +---+ 
    //    |   | p[N-1]
    //    +---+
    //
    // NOTE: p is a separate object from the array
    for(int i = 0 ; i < num_elems ; i++)
        p[i] = i*i;
    printf("[Pointer-based]Addressing: p:%p &p[0]:%p\n",(void*)p,(void*)&p[0]);
    printf("[Pointer-based]Indexing: p[2]:%d *(p+2):%d *(&p[0] +2):%d\n",p[2],*(p+2),*(&p[0]+2));     
    free(p); // Don't forget !
    

    // calloc: allocate and set array values to 0 
    int *zeroed_p = (int *)calloc(num_elems,sizeof(int)); 
    assert (zeroed_p != NULL);
    for(int i = 0 ; i < num_elems ; i++)
        zeroed_p[i] = i+10;    

    // ADVANCED //
    // realloc: 
    int sz = num_elems+1;
    int *extend_p = (int *)realloc(zeroed_p,sz*sizeof(int));
    assert(extend_p != NULL);
    // with reference to zeroed_p,
    // returns pointer to a new object that has size specified by [sz]
    // Contents of new object is identical to that of the old object 
    // prior to deallocation, up to lesser of new and old sizes. 
    extend_p[sz-1] = (sz-1)+10;
    printf("After realloc: ");
    for(int i = 0 ; i < sz ; i++)
        printf("%d:%d ",i,extend_p[i]);
    printf("\n");
    free(extend_p); // Note: zeroed_p has already been deallocated by realloc (by calling free internally)
    
    pause();

    // Pointer to array
    int myarr_2[5];
    int myarr[3] = {3,4,5};
    int *pt = myarr; // pt points at myarr[0]'s memory location
    int *pt2 = &myarr[1]; // pt2 points at myarr[1]'s memory location

    printf("\n Freeing pt to see what happens ...\n");
    free(pt); 

    int x = 10;
    pt = &x;         // OK. pt now points at x's memory location
        
    // Pointer to an ENTIRE array in strict sense, i.e. not just first element
    int (* threePtr)[3] = &myarr; // threePtr can ONLY point at arrays with 3 ints in them

    // ADVANCED //
    // Examples of possible declarations
    // Rule of thumb: 
    /// (0) <variable-name> is ..... <data-type>
    /// (1) Alternate between going right and left
    /// (2) Go right when you can, go left when you must !
    int *r[5];       // r is a 5-sized array of pointer to int
    int (*s)[4];     // s is a pointer to 4-sized array of int
    int (*t[8])[5];  // t is a 8-sized array of pointers to 5-sized array of int
    // Reference : https://cdecl.org/
    // 
}

void arrays_2d()
{
    int nRows = 6;
    int nCols = 7;
    int matrix[nRows][nCols];    // statically allocated

    // Dynamic allocation
    int **matrixPtr = NULL; // pointer to pointer to int
    matrixPtr = (int **)calloc(nRows,sizeof(int *)); // matrixPtr points to an array of int pointers
    assert(matrixPtr != NULL);
    for(int i = 0 ; i < nRows ; i++) {
        matrixPtr[i] = (int *)calloc(nCols,sizeof(int)); // each element in matrixPtr points to an array of int
        assert(matrixPtr[i] != NULL);
    }

    // Free up memory
    for(int i = 0 ; i < nRows ; i++) 
        free(matrixPtr[i]);
    free(matrixPtr);

}

// Function definition
// Components of a function definition – name, return type, parameters, header, body 
// name: sample_func
// return type: int
// parameters: param_1, param_2
// param_1 is a copy of a floating point value
// param_2 is a "copy" of an address value
int sample_func(float param_1, int* param_2) // header
{
    // body of function
    float absurd_mix = param_1 + (*param_2);
    *param_2 = (int)(param_1/10);

    return (int)(absurd_mix);
}

// char* is ambiguous - can be array address or char address
// need to clarify in documentation
int sample_func_2(float param_1, char* param_2) 
{
    // body of function    
    return (int)(param_1 + param_2[0]);
}

void modify_array_func_1(int *x,int n)
{
    for(int i = 0 ; i < n ; i++)
        x[i] = i*i;
}

// Below code will not compile. Why ?
/*
void modify_array_func_2(const int *x,int n)
{
    for(int i = 0 ; i < n ; i++)
        x[i] = i*i;
}
*/

float* func_returning_array(int *n)
{
    int some_number = 20;
    *n = some_number;

    float* f = (float *)calloc(some_number,sizeof(float));
    assert(f != NULL);

    return f;
}

// Why is this buggy ?
float* func_returning_array_buggy(int *n)
{
    int some_number = 20;
    *n = some_number;

    float f[some_number];
    for(int i = 0 ; i < some_number ; i++)
        f[i] = i * (i+3);

    return f;
}

void functions()
{
    // Two primary roles:
    // Enable a block of code to be called by ‘name’ 
    // Enable modularity, reusability of code 
    
    float f = 2020.02f;
    int d = 19;
    printf("\nBefore:d=%d ",d);
    int func_v = sample_func(f,&d);
    printf("After:d=%d ",d);
    pause();
    // Is the code below ok ?
    sample_func_2(300,"iiit-h");
    pause();

    // Passing arrays to function
    int nElems = 10;
    int n_arr[nElems];
    for(int i = 0 ; i < nElems ; i++)
        n_arr[i] = i+1;
    print_array(n_arr,nElems,data_types::intg);
    modify_array_func_1(n_arr,nElems);
    print_array(n_arr,nElems,data_types::intg);
    
    int numArrayElems;
    float* fVals = func_returning_array(&numArrayElems);
    
    if(fVals)
        free(fVals);
}

void structures()
{
    
    rec_1 r1,r2;
    printf("Size of structure r1 (after initialization) = %d bytes\n",sizeof(r1));
    pause();

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
    free(r1.name);
    free(r2.name);
    
    // Array of structures    
    int nRecords = 2;
    const char *name_list[nRecords];
    name_list[0] = "PJN";
    name_list[1] = "Vineet";         
    const course_type ctypArr[] = {course_type::cse,course_type::csd};
        
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

    for(int i  = 0 ; i < nRecords ; i++)
        free(acad_records[i].name);

    free(soc_record->acad.name);
               
}


int main()
{
    int ch;
    while(1)
    {
        print_choices();
        scanf("%d",&ch);
        fseek(stdin,0,SEEK_END); // flush input buffer
        switch (ch)
        {
            case 1:
                data_types();
                break;
            case 2:
                type_qualifier();
                break;
            case 3:
                pointers();
                break;
            case 4:
                arrays();
                break;
            case 5:
                arrays_2d();
                break;
            case 6:
                functions();
                break;
            case 7:
                structures();
                break;
            case 0:            
                goto endofprog;
        }                 
    }
    
    endofprog: ;
    
    return 0;
}

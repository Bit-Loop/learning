/*
* ITJ 9/7/2021
* My first hash table, used in the mim type proj
*
* REF: https://stackoverflow.com/questions/31930046/what-is-a-hash-table-and-how-do-you-make-it-in-c
* REF: https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29
* REF: 
	Understanding and implementing a Hash Table (in C)
	https://www.youtube.com/watch?v=2Ti5yvumFTU
* REF:
	Guards, Name Mangling, and extern "C" - Jacob Sorber
	https://www.youtube.com/watch?v=NeOTr0u7ALk2
* REF:
	Hash table - Wiki
	https://en.wikipedia.org/wiki/Hash_table~
* REF: 
	Big O notation - Wiki
	https://en.wikipedia.org/wiki/Big_O_notation
*/
// boiler-plate ( #ifdef guards ) start
#ifndef HASHTABLE_H // if HASHTABLE_H is not defined 
#define HASHTABLE_H // then define it here.
// end
#
// boiler-plate start
#ifdef __cplusplus //check if using a C++ compiler, if true put code in extern c block
extern "C" { // if true ^ then use C naming rules for C++ compilation
#endif

	#define TABLE_SIZE 10000
	#define FNAME_SIZE 257

	typedef struct {
		char key[FNAME_SIZE];
		char ext_pair[11];
	} bucket_ts; //ts = typedef struct

	bucket_ts* buckets[TABLE_SIZE + 1];
	bucket_ts* bucketsStorage[TABLE_SIZE + 1];


	typedef struct  {
		char ext_pair[11];
		char mt[51];
	} extMt_ts;
	
	

	
//boiler - plate bottom part below.
#ifdef __cplusplus // if true exit the extern c block
}
#endif
#endif // HASHTABLE_H end
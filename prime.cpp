#include <iostream>
#include<cstdio>
#include<cstring> 
#include<cstdlib>
#include <fstream>
#include <string>
#include<strings.h>
#define MAX 999
#define LIMIT 10000000000000

using namespace std;

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};


struct sortedLetters {
     unsigned long long int value;
     string word;
};

typedef struct sortedLetters* sortedLetterPtr;

int compare (const void* a, const void* b)
{

    if ( ((sortedLetterPtr)a)->value <  ((sortedLetterPtr)b)->value ) return -1;
    if ( ((sortedLetterPtr)a)->value == ((sortedLetterPtr)b)->value ) return 0;
    if ( ((sortedLetterPtr)a)->value >  ((sortedLetterPtr)b)->value ) return 1;
  return 0;
}

struct sortedLetters letters[MAX];
static long linesOfFile = 0;

class ReadFile {
	
	public:
	char words[MAX][MAX];
	unsigned long long product;
	
	
	ReadFile() {
		product = 1;
		linesOfFile = 0;
	}
	
	long getFileSize() {
		return linesOfFile;
	}
	
	bool checkInput(char character) {
		
		if((65 <= character && character <= 90) || (97 <= character && character <= 122)) {
			return true;
		} else {
			return false;
		}
	}
	  	
	void MapFile() {
	  
	  ifstream myfile ("C:\\Users\\test\\Desktop\\code\\wordList.dat");
  	  	
	  string line;
	  if (myfile.is_open())
	  {
	    while ( getline (myfile,line) )
	    {
	      linesOfFile++;
	      
		  for(int index = 0; index < line.length(); index++) {
		  		if(checkInput(line[index])) {
		  				product *= primes[line[index]-97];
				}   		
		  }
	      cout << line << "\t" << product <<endl;
	      
	      //harsha's code
	      letters[linesOfFile].word = line;
          letters[linesOfFile].value = product;
		
		}
	} 
	else 
		cout << "Unable to open file";
	}
	
};


 
int main ()
{
	ReadFile crossword;
	crossword.MapFile();
	//long size = crossword.getFileSize();
	
	for(int i=0;i<linesOfFile; i++) {
		cout << letters[i].word <<"\t" << letters[i].value <<endl;
	}
	
	//qsort (letters, linesOfFile, sizeof(unsigned long long int), compare);
}

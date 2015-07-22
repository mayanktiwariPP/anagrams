#include <iostream>
#include<cstdio>
#include<cstdlib>
#include <fstream>
#include <cstring>
#include<strings.h>
#define MAX 999
#define LIMIT 10000000000000

using namespace std;

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};


typedef struct sortedLetters {
     unsigned long long int value;
     const char* word;
} sortedLetters;

int compare(const void * left, const void * right) {
    const sortedLetters * a = (const sortedLetters *) left;
    const sortedLetters * b = (const sortedLetters *) right;
    if (a->value > b->value) {
        return -1;
    } else if (a->value < b->value) {
        return 1;
    } else {
        return 0;
    }
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
	      //cout << line << "\t" << product <<endl;
	      
	      char * a = new char[line.size()+1];
	      a[line.size()]=0;
	      memcpy(a,line.c_str(),line.size());
	      //harsha's code
	      letters[linesOfFile].word = a;
          letters[linesOfFile].value = product;
		  
		  //cout << letters[linesOfFile].word << "\t" << letters[linesOfFile].value <<endl;
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
	
	//qsort (letters, linesOfFile, sizeof(unsigned long long int), compare);
	
	for(int i=0;i<linesOfFile; i++) {
		cout << letters[i].word <<"\t" << letters[i].value <<endl;
	}
	
	
}

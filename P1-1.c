/*      I c o n   M a t c h
Student Name: Alex Moore
Date: Feb 08 2015

ECE 2035 Project 1-1

This program loads 8 icons (each is a 12x12 array of pixels) into a
linear array of candidates and a single icon that serves as a pattern,
which matches exactly one candidate icon.

Add code to find which of the eight candidates matches the pattern icon.
*/

#include <stdio.h>
#include <stdlib.h>

#define IconSize (12 * 12)
#define NumCandidates 8
#define CandidateArraySize (IconSize * NumCandidates)

int Load_Mem(char *InputFileName, int Candidates[], int Pattern[]);
int Load_N_Values(FILE *FP, int N, int Array[]);

int main(int argc, char *argv[]) {
  int	Candidates[CandidateArraySize];
  int	Pattern[IconSize];
  int	Length, Match=0;

  if (argc != 2) {
    printf("usage: P1-1 valuefile\n");
    exit(1);
  }
  Length = Load_Mem(argv[1], Candidates, Pattern);
  if (Length != CandidateArraySize + IconSize) {
     printf("valuefile does not contain valid data.\n");
     exit(1);
  }

  /* Your icon matching code goes here */
  int checklist[] = {0,1,2,3,4,5,6,7};
  int candndx, periconndx, i, keyPix, candPix;
<<<<<<< HEAD
  for(candndx = 0; candndx < 8; candndx++){ //will be multiplying, so ndx start at 1
  	for(periconndx = 0; periconndx < 144; periconndx++){ //for each icon, i'll be traversing 144 spots	
		keyPix = periconndx;
		candPix = periconndx+candndx*144;
		printf("Key Pixel: %d\nCandidate Pixel: %d\nCandidate: %d\n\n",keyPix,candPix,candndx);
=======
  for(candndx = 1; candndx < 9; candndx++){ //will be multiplying, so ndx start at 1
  	for(periconndx = 0; periconndx < 144; periconndx++){ //for each icon, i'll be traversing 144 spots	
		keyPix = periconndx;
		candPix = periconndx*candndx;
>>>>>>> 8981252932a54969078b759588b066193d02f845
		if(keyPix != candPix){
			checklist[candndx] = -1;
		}
	}
  }

  for(i = 0; i <8; i++){
	if(checklist[i] > -1){
		Match = i; 
	}
  }

  printf("The matching icon is %d\n", Match);
  exit(0);
}

/* This routine loads in pairs of integers of the form "Addr: Value"
from a named file in the local directory. Each pair is delimited by a
newline. The first values are placed in the passed integer arrays
Candidates and Pattern. The number of input integers is returned. */

int Load_Mem(char *InputFileName, int Candidates[], int Pattern[]) {
  int	Nc, Np;
   FILE	*FP;

   FP = fopen(InputFileName, "r");
   if (FP == NULL) {
      printf("%s could not be opened; check the filename\n", InputFileName);
      return 0;
   } else {
     Nc = Load_N_Values(FP, CandidateArraySize, Candidates);
     if (Nc == CandidateArraySize)
       Np = Load_N_Values(FP, IconSize, Pattern);
     fclose(FP);
     return Nc+Np;
   }
}

int Load_N_Values(FILE *FP, int N, int Array[]){
  int i, NumVals, Addr, Value;
  for (i = 0; i < N; i++){
    NumVals = fscanf(FP, "%d: %d", &Addr, &Value);
    if (NumVals == 2)
      Array[i] = Value;
    else 
      return(i);
  }
  return(N);
}


#include <stdio.h>


void printbin(int n){

int i=1;
while(n!=0){
 //if n xor i greater than 0 print 1
 if(n&i) {
   n^=i;
   printf("1");
  } else printf("0");

 i<<=1;
}

printf("\n");

}

int main(){


int rings=15;


// you cannot change the same bit twice in a row. Equivalently you cannot make a move that
// takes you to a previous configuration.
//
// goal is to reach 0000 all rings removed.
//
//at any point you either change the bit next to the left of the right most bit or you
//change the rightmost bit whichever move you did not make last

int prevMove; //1 = we inverted left of rightmost, 0 = we inverted rightmost
printbin(rings);

//start by removing ring 2
rings^=(1<<1);
prevMove=1; 

while(rings){

  printbin(rings);
  int n=0;

  if(prevMove){
    rings^=1;
    prevMove=0;
  } else{ 
    while(!(rings&(1<<n))) ++n; //get pos of rightmost bit
    rings^=(1<<(n+1));
    prevMove=1;
  }

}
//the output is reversed but the pattern is the same. This will solve the chinese ring puzzle.


return 0;

}

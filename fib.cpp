/*    @file fib.cpp    
      @author Matt Hoendorf <hoendomd@mail.uc.edu>
      @date 09-09-2014  

			@description Returns the fibonocci value of the n
*/

#include <iostream>
#include <stdlib.h>
#include <iostream>


#include "BigInt.h"

using namespace std;

BigInt calcFib(unsigned int stop){
  BigInt back2("0"), back1("1");
  for(unsigned int i = 2; i <= stop; i++){
    BigInt temp2 = back2;
    back2 = back1;
    back1 = back1.add(temp2);
  }
  return back1;
}

int main(int argc, char* argv[]){

  int i = argc;
  if(i<=1){
    cout << "\nPrints out the fibonacci number of the provided number" << endl;
    cout << "as a command-line argument.\n\nUsage: ./fib 5\n" << endl;
    return 0;
  }
  else{
    int stop = atoi(argv[1]);
    cout << "\nf(" << stop << ") = ";
    BigInt ans = calcFib(stop);
    cout << ans.getAsDigits() << "\n" << endl;
  }
	
	return 0;
	
}

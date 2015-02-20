#include <iostream>
#include "BigInt.h"

using namespace std;

int main(){
  // Initialize a BigInt with 5 and print as a string.
  BigInt a(125);
  cout << "a: " << a.getAsDigits() << endl;
  
  // Initialize a BigInt with a string and print as a string.  
  BigInt b("99999999");
  cout << "b: " << b.getAsLong() << endl;
  
  // Demonstrate using the add member function and create a new BigInt.
  BigInt c = a.add(b);
  cout << "a+b (c): " << c.getAsDigits() << endl;
  
  // Initialize 2 BigInts from lenghty strings.
  BigInt d("123456789012345678901234567890");
  BigInt e("123456789012345678901234567890");
  
  // Add them together a few times and print as a string.
  BigInt f = d.add(e).add(e).add(e);
  cout << "f: " << f.getAsDigits() << endl;
  /*
  // Add repeatedly
  for(int i = 0; i < 1000000; i++){
    f = f.add(e);
  }
  // Print the result!
  cout << "f: " << f.getAsDigits() << endl;
  */

}

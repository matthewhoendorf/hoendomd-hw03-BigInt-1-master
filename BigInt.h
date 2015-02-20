#ifndef BIGINT_H
#define BIGINT_H  

/**   @file BigInt.h    
      @author Matt Hoendorf <hoendomd@mail.uc.edu>
      @date 09-09-2014 
      @version 0.01   
      
      This BigInt class implements an infinitely long non-negative integer, 
      with addition possible.
      
      BitInts can be initialized via a long, a string of digits, or by the
      default constructor (value 0).
      
      BigInts can be retrieved as a string of digits or a long.
      
      */

#include <string>
#include <vector>

using namespace std;

class BigInt{

public:
  
  /**
    * Default constructor initializes the BigInt to 0
    */
  BigInt();
  
  /**
    * Creates a new BigInt from an unsigned long integer
    */
  BigInt(unsigned long number);
  
  /**
    * Creates a new BigInt from a string of digits.  Any non-number digit
    * will result in a BigInt value of 0, including the negative sign.
    */
  BigInt(const string& number);
  
  
  /**
    * Return the Bigint as a string of digits 
    */
  string getAsDigits() const;

  /**
    * Return the Bigint as an unsigned long.  Returns 0
    * if the BigInt is larger than unsigned long supports.
    */
  unsigned long getAsLong();
  
  /**
    * Adds another Bigint to the current one and returns the sum
    * as another BigInt.
    * Neither this or the other number should change.
    */
  BigInt add(const BigInt& number) const;
  
  BigInt multiply(const BigInt& number) const;
  
  BigInt carry(unsigned int num) const;
  
  void print_blocks();
  
  int compare(const BigInt& b) const;
  
  friend BigInt operator*(const BigInt& a, const float b); // Overrides *
  
  friend BigInt operator+(const BigInt& a, const float b); // Overrides + 

  friend bool operator==(const BigInt& a, const BigInt& b); // Overrides ==

  friend bool operator!=(const BigInt& a, const BigInt& b); // Overrides !=
  
  friend bool operator>(const BigInt& a, const BigInt& b); // Overrides >

  friend bool operator>=(const BigInt& a, const BigInt& b); // Overrides >=
  
  friend bool operator<(const BigInt& a, const BigInt& b); // Overrides <

  friend bool operator<=(const BigInt& a, const BigInt& b); // Overrides <=
  
  private:
  
  vector<unsigned long> number_blocks; 

};

BigInt operator+(const BigInt& a, const BigInt& b); // Overrides + operator
  
ostream& operator<<(ostream& os, const BigInt& b); // Overrides <<

#endif  

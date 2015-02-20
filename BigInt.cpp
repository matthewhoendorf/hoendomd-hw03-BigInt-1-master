/*    @file BigInt.cpp   
      @author Matt Hoendorf <hoendomd@mail.uc.edu>
      @date 09-09-2014   

			@description Implements an unlimited-sized unsigned integer.
*/
#include <string>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>
#include <vector>
#include <stdio.h>
#include <math.h>

#include <iostream>

#include "BigInt.h"

short int strtoi(char c){
  short int n = c - 48;
  return n;
}


BigInt::BigInt(){
  number_blocks.push_back(0);
}

BigInt::BigInt(unsigned long mynumber){
  int division, counter = 0, limit = 0;
  long n = mynumber;
  while(n){        
    n=n/10;
    limit++;
  }
  while(counter<limit){
		division=mynumber/10;
		number_blocks.push_back(mynumber%10);
		mynumber=division;
		counter++;
	}
}


BigInt::BigInt(const string& snumber){
	int length = snumber.length();
	if(snumber[0] == '-'){
	  number_blocks.push_back(0);
	}	
	else{
	  for(int i = length - 1; i > -1; i--){
	    number_blocks.push_back(strtoi(snumber[i]));
	  }
  }
}


string BigInt::getAsDigits() const{
  string num;
  char first_char = number_blocks.size()-1;
  for(int i = first_char; i > -1; i--){
    num.push_back(number_blocks[i]+48);
  }
  return num;
}


unsigned long BigInt::getAsLong(){
  unsigned long num = 0;
  num+=number_blocks[0];
  for(unsigned int i = 1; i < number_blocks.size(); i++){
    num+=number_blocks[i]*pow(10,i);
  }
  return num;
}

BigInt BigInt::add(const BigInt& number) const{
  int small_sum = 0;
  int carry = 0;
  BigInt sum;
  sum.number_blocks.clear();
  unsigned int size1 = number_blocks.size();
  unsigned int size2 = number.number_blocks.size();
  
  if(size1 >= size2){
    for(unsigned int i = 0; i < size2; i++){
      small_sum = number.number_blocks[i] + number_blocks[i] + carry;
      carry = small_sum/10;
      sum.number_blocks.push_back(small_sum%10);
    }
    while(size1 > size2){
      small_sum = number_blocks[size2] + carry;
      carry = small_sum/10;
      sum.number_blocks.push_back(small_sum%10);
      size2++;
    }    
  }
  else{
    for(unsigned int i = 0; i < size1; i++){
      small_sum = number.number_blocks[i] + number_blocks[i] + carry;
      carry = small_sum/10;
      sum.number_blocks.push_back(small_sum%10);
    }   
    while(size2 > size1){
      small_sum = number.number_blocks[size1] + carry;
      carry = small_sum/10;
      sum.number_blocks.push_back(small_sum%10);
      size1++;
    }  
  }
  if(carry != 0){
    sum.number_blocks.push_back(carry);
  }
  return sum;
}

BigInt BigInt::multiply(const BigInt& b) const{
  unsigned int temp = 0, temp2 = 0;
  BigInt smaller_prod;
  BigInt small_prod;
  BigInt prod;
  BigInt temp3;
  for(unsigned int i = 0; i < b.number_blocks.size(); i++){ // for size 2
    for(unsigned int j = 0; j < number_blocks.size(); j++){ // for size 1
      temp = b.number_blocks[i]*number_blocks[j]; // multiply a[i] and b[i]
      temp2 = i+j;
      smaller_prod.number_blocks.clear();
      temp3.number_blocks.clear();
      while(temp2>0 && temp!=0){
        smaller_prod.number_blocks.push_back(0);
        temp2--;
      }
      temp3 = carry(temp);
      for(unsigned int n = 0; n < temp3.number_blocks.size(); n++){
        smaller_prod.number_blocks.push_back(temp3.number_blocks[n]);
      }
      small_prod = small_prod.add(smaller_prod);
    }
    prod = prod.add(small_prod);
    small_prod.number_blocks.clear(); // clear small_prod
  }
  return prod;
}

BigInt BigInt::carry(unsigned int num) const{
  BigInt car;
  car.number_blocks.clear();
  while(num/10 != 0){
    car.number_blocks.push_back(num%10);
    num = (num - num%10)/10;
  }
  car.number_blocks.push_back(num); 
  return car;
}

// Print BigInt blocks in format "val.1:block.1 ... val.n:block.n"
void BigInt::print_blocks(){
  for(unsigned int i = 0; i < number_blocks.size(); i++){
    cout << i << ":" << number_blocks[i] << " ";
  }
  cout << endl;
}


// Compare function: >:1, <:-1, ==:0
int BigInt::compare(const BigInt& b) const{
  
  int comp = 0;
  
  if(number_blocks.size() < b.number_blocks.size()){
    comp = -1;
    return comp;
  }
  else if(number_blocks.size() > b.number_blocks.size()){
    comp = 1;
    return comp;
  }
  else{
    for(unsigned int i = 0; i < number_blocks.size(); i++){
      if(number_blocks[i] < b.number_blocks[i]){
        comp = -1;
      }
      else if(number_blocks[i] > b.number_blocks[i]){
        comp = 1;
      }
    }
    return comp;  
  }
}

/* ---------- Operator Overloading ---------- */

BigInt operator+(const BigInt& a, const float num){
  BigInt b(num);
  BigInt sum = a.add(b);
  return sum;
}

BigInt operator*(const BigInt& a, const float num){
  BigInt b(num);
  BigInt product = a.multiply(b);
  return product;
}

bool operator==(const BigInt& a, const BigInt& b){
  if(a.compare(b) == 0){
    return 1;
  }
  else{
    return 0;
  }
}

bool operator!=(const BigInt& a, const BigInt& b){
  if(a.compare(b) != 0){
    return 1;
  }
  else{
    return 0;
  }
}

bool operator<(const BigInt& a, const BigInt& b){
  if(a.compare(b) == -1){
    return 1;
  }
  else{
    return 0;
  }
}

bool operator<=(const BigInt& a, const BigInt& b){
  if(a.compare(b) == 0 || a.compare(b) == -1){
    return 1;
  }
  else{
    return 0;
  }
}

bool operator>(const BigInt& a, const BigInt& b){
   if(a.compare(b) == 1){
    return 1;
  }
  else{
    return 0;
  }
}

bool operator>=(const BigInt& a, const BigInt& b){
  if(a.compare(b) == 0 || a.compare(b) == 1){
    return 1;
  }
  else{
    return 0;
  }
}

ostream& operator<<(ostream& os, const BigInt& a){
  os << a.getAsDigits();
  return os;
}

#include <iostream>
#include <string>
#include <sstream>
#include "functions.h" 
#include <stdexcept>
#include <climits>

//returns true if sum of a & b is even
bool SumIsEven(int a, int b) {
  if((a+b)%2){
    return false;
  }
  else{
    return true;
  }
}

//returns the largest of the three integer parameters
int Largest(int a, int b, int c) {
  int d = -2000000000;
  if(a > d){
    d = a;
  }
  if (b > d) {
    d = b;
  }
  if (c > d) {
    d = c;
  }
  return d;

}

//calculates the number of boxes needed to transport apples
//if each box holds 20 apples
unsigned int BoxesNeeded(int apples) {            
  if(apples > 20 && apples % 20 != 0){
    return (1 + (apples/20));
  }
  else if(apples > 20 && apples % 20 == 0){
    return apples/20;
  }
  else if((apples > 0) && (apples <= 20)){
      return 1;
  }
  return 0;

}

//returns true if section A has a higher ratio of correct answers than section B
//will throw an exception if input is invalid
bool SmarterSection(int A_correct, int A_total, int B_correct, int B_total) {

  if(A_correct > A_total || B_correct > B_total){
    throw std::invalid_argument("Invalid argument");
  }
  else if(A_correct < 0 || A_total <= 0 ||B_correct < 0 || B_total <= 0){
    throw std::invalid_argument("Invalid argument");
  }
  else{
    return (float(A_correct)/A_total) > (float(B_correct)/B_total);
  }

}

//returns "true" if the dinner is good*
//*a good dinner is based on # of pizzas and if it's a weekend
bool GoodDinner(int pizzas, bool is_weekend) {          
  if (pizzas >= 10 && pizzas <= 20) {
    return true; //this is acceptable on weekdays
  }
  else if (pizzas > 20 && is_weekend) {
    return true; //this is also acceptable on weekends
  }
  return false;
}

//returns sum of all integers btwn low & high (inclusive)
//throws exception if low > high, or if overflow occurs
long long SumBetween(long long low, long long high) {
  long long value = 0;
  //checks if the range is invalid
  if(low > high){
    throw std::invalid_argument("Invalid argument");
  }

  //handles negative to positive ranges
  if(low < 0 && high > 0){
    if(low + high > 0){
      low = (low * (-1)) + 1;
    }
    else if(low + high < 0){
      high = (high * (-1)) -1;
    }
  }
  //there's just one number, no numbers in between
  if(low == high){
    return low;
  }
  //symmetric range would add up to 0
  if(low + high == 0){
    return 0;
  }

  //check for overflow while summing
  for (long long n = low; n <= high; n++) {
    if(((n+1) > (LLONG_MAX - value)) && value > 0){
      throw std::overflow_error("of2");
    }
    
    if(((n+1) < (LLONG_MIN - value)) && value < 0){
      throw std::overflow_error("of1");
    }
    value += n;
  }
  return value;
}

//returns product of a & b
//throws exception if the product would overflow
long long Product(long long a, long long b) {
  if(a == 0 || b == 0){
    return 0; //product is zero no matter what
  }
  //check for positive overflow
  if(a > LLONG_MAX / b && b > 0 && a > 0){
    throw std::overflow_error("of1");
  }
  //check for negative * negative overflow
  if(a < LLONG_MAX / b && b < 0 && a < 0){ 
    throw std::overflow_error("of2");
  }
  //check for negative * positive overflow
  if(a < LLONG_MIN / b && b > 0 && a < 0){
    throw std::overflow_error("of3");
  }
  //check for postive * negative overflow
  if(a > LLONG_MIN / b && b < 0 && a > 0){
    throw std::overflow_error("of4");
  }
  
  return a * b; //the multiplication is safe
}
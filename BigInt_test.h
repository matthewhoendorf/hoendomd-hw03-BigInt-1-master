#include "BigInt.h"
#include <stdexcept>

#include <cxxtest/TestSuite.h>
#include <iostream>

class BigIntTest : public CxxTest::TestSuite {

public:

// Constructors
  void testDefaultConstructorLong() {
    BigInt a;
    TS_ASSERT_EQUALS(0, a.getAsLong());
  }

  void testDefaultConstructorString() {
    BigInt a;
    TS_ASSERT_EQUALS("0", a.getAsDigits());
  }
  
  void testStringConstructorString() {
    BigInt a("123");
    TS_ASSERT_EQUALS("123", a.getAsDigits());
  }
  
  void testStringConstructorLong() {
    BigInt a("123");
    TS_ASSERT_EQUALS(123, a.getAsLong());
  }
  
  void testStringConstructorNegative() {
    BigInt a("-123");
    TS_ASSERT_EQUALS("0", a.getAsDigits());
  }
  
  void testLongConstructorString() {
    BigInt a(123);
    TS_ASSERT_EQUALS("123", a.getAsDigits());
  }
  
  void testLongConstructorLong() {
    BigInt a(123);
    TS_ASSERT_EQUALS(123, a.getAsLong());
  }
  
  void testIntAddition0() {
    BigInt a(123);
    BigInt b(999);
    BigInt c = a.add(b);
    TS_ASSERT_EQUALS(1122, c.getAsLong());
  }
  
  void testStringAddition0() {
    BigInt a("123");
    BigInt b("999");
    BigInt c = a.add(b);
    TS_ASSERT_EQUALS(1122, c.getAsLong());
  }
  
  void testIntAddition1() {
    BigInt a(1234567890);
    BigInt b(1234567890);
    BigInt c = a.add(b);
    TS_ASSERT_EQUALS("2469135780", c.getAsDigits());
  }
  
  void testStringAddition1() {
    BigInt a("1234567890");
    BigInt b("1234567890");
    BigInt c = a.add(b);
    TS_ASSERT_EQUALS("2469135780", c.getAsDigits());
  }
  
  void testIntAddition3() {
    BigInt a(123);
    BigInt b(999);
    BigInt c = a.add(b);
    TS_ASSERT_EQUALS("1122", c.getAsDigits());
  }
  
  void testStringAddition3() {
    BigInt a("123");
    BigInt b("999");
    BigInt c = a.add(b);
    TS_ASSERT_EQUALS("1122", c.getAsDigits());
  }
  
  void testIntAddition4() {
    BigInt a(1234567890);
    BigInt b(1234567890);
    BigInt c = a.add(b);
    TS_ASSERT_EQUALS("2469135780", c.getAsDigits());
  }
  
  void testStringAddition4() {
    BigInt a("1234567890");
    BigInt b("1234567890");
    BigInt c = a.add(b);
    TS_ASSERT_EQUALS("2469135780", c.getAsDigits());
  }
  
  void testStringAddition5() {
    BigInt a("123456789012345678901234567890");
    BigInt b("123456789012345678901234567890");
    BigInt c = a.add(b).add(b).add(b);
    TS_ASSERT_EQUALS("493827156049382715604938271560", c.getAsDigits());
  }
  
  void testStringAddition7() {
    BigInt a("123");
    BigInt b("-999");
    BigInt c = a.add(b);
    TS_ASSERT_EQUALS("123", c.getAsDigits());
  }
  
  void testStringAddition8() {
    BigInt a("123");
    BigInt b("-999");
    BigInt c = a.add(b);
    TS_ASSERT_EQUALS(123, c.getAsLong());
  }

  void testStringAddition9() {
    BigInt a("123");
    BigInt b("123");
    BigInt c("123");
    BigInt d = a.add(b).add(c);
    TS_ASSERT_EQUALS(369, d.getAsLong());
  }
  
  void testIntAddition6() {
    BigInt a(123);
    BigInt b(123);
    BigInt c(123);
    BigInt d = a.add(b).add(c);
    TS_ASSERT_EQUALS(369, d.getAsLong());
  }
  
  void testStringAddition10() {
    BigInt a("123");
    BigInt b("123");
    BigInt c("123");
    BigInt d = a.add(b).add(c);
    TS_ASSERT_EQUALS("369", d.getAsDigits());
  }

  void testIntAddition7() {
    BigInt a("123");
    BigInt b("123");
    BigInt c("123");
    BigInt d = a.add(b).add(c);
    TS_ASSERT_EQUALS("369", d.getAsDigits());
  }
  void testStringAddition11() {
    BigInt a("123");
    BigInt b("123");
    BigInt c("-123");
    BigInt d = a.add(b).add(c);
    TS_ASSERT_EQUALS("246", d.getAsDigits());
  }

  void testStringAddition12() {
    BigInt a("123");
    BigInt b("-123");
    BigInt c("123");
    BigInt d = a.add(b).add(c);
    TS_ASSERT_EQUALS(246, d.getAsLong());
  }
  
  void testCompare0() {
    BigInt a("123");
    BigInt b("-123");
    TS_ASSERT_EQUALS(1, a.compare(b));
  }

  void testCompare1() {
    BigInt a("123");
    BigInt b("123");
    TS_ASSERT_EQUALS(0, a.compare(b));
  }
  
  void testCompare2() {
    BigInt a("123");
    BigInt b(123);
    TS_ASSERT_EQUALS(0, a.compare(b));
  }

  void testCompare3() {
    BigInt a("123");
    BigInt b("130");
    TS_ASSERT_EQUALS(-1, a.compare(b));
  }
  
  void testCompare4() {
    BigInt a("123");
    BigInt b(1234);
    TS_ASSERT_EQUALS(-1, a.compare(b));
  }

  void testCompare5() {
    BigInt a("1234");
    BigInt b(123);
    TS_ASSERT_EQUALS(1, a.compare(b));
  }
  
  void testOperators0() {
    BigInt a("123");
    BigInt b("123");
    TS_ASSERT_EQUALS(1, a==b);
  }
  
  void testOperators1() {
    BigInt a("123");
    BigInt b("123");
    TS_ASSERT_EQUALS(0, a!=b);
  }
  
  void testOperators2() {
    BigInt a("123");
    BigInt b("123");
    TS_ASSERT_EQUALS(1, a<=b);
  }
  
  void testOperators3() {
    BigInt a("123");
    BigInt b("123");
    TS_ASSERT_EQUALS(1, a>=b);
  }
  
  void testOperators4() {
    BigInt a("123");
    BigInt b("123");
    TS_ASSERT_EQUALS(0, a>b);
  }
  
  void testOperators5() {
    BigInt a("123");
    BigInt b("123");
    TS_ASSERT_EQUALS(0, a<b);
  }
  
  void testOperators6() {
    BigInt a("123");
    BigInt b("1230");
    TS_ASSERT_EQUALS(0, a==b);
  }
  
  void testOperators7() {
    BigInt a("123");
    BigInt b("1230");
    TS_ASSERT_EQUALS(1, a!=b);
  }
  
  void testOperators8() {
    BigInt a("123");
    BigInt b("1230");
    TS_ASSERT_EQUALS(1, a<=b);
  }
  
  void testOperators9() {
    BigInt a("123");
    BigInt b("1230");
    TS_ASSERT_EQUALS(0, a>=b);
  }
  
  void testOperators10() {
    BigInt a("123");
    BigInt b("1230");
    TS_ASSERT_EQUALS(0, a>b);
  }
  
  void testOperators11() {
    BigInt a("123");
    BigInt b("1230");
    TS_ASSERT_EQUALS(1, a<b);
  }
  
  void testOperators12() {
    BigInt a("123");
    BigInt b("132");
    TS_ASSERT_EQUALS(0, a==b);
  }
  
  void testOperators13() {
    BigInt a("123");
    BigInt b("132");
    TS_ASSERT_EQUALS(1, a!=b);
  }
  
  void testOperators14() {
    BigInt a("123");
    BigInt b("132");
    TS_ASSERT_EQUALS(1, a<=b);
  }
  
  void testOperators15() {
    BigInt a("123");
    BigInt b("132");
    TS_ASSERT_EQUALS(0, a>=b);
  }
  
  void testOperators16() {
    BigInt a("123");
    BigInt b("132");
    TS_ASSERT_EQUALS(0, a>b);
  }
  
  void testOperators17() {
    BigInt a("123");
    BigInt b("132");
    TS_ASSERT_EQUALS(1, a<b);
  }
  
  void testOperators18() {
    BigInt a("123");
    a = a + 123;
    TS_ASSERT_EQUALS("246", a.getAsDigits());
  }

  void testOperators19() {
    BigInt a("123456789012345678901234567890");
    a = a + 100;
    TS_ASSERT_EQUALS("123456789012345678901234567990", a.getAsDigits());
  }
  
  void testOperators20() {
    BigInt a;
    a = a + 123;
    TS_ASSERT_EQUALS("123", a.getAsDigits());
  }
  
  void testOperators21() {
    BigInt a;
    a = a + 0;
    TS_ASSERT_EQUALS("0", a.getAsDigits());
  }
  
  void testOperators22() {
    BigInt a;
    a = a + 123 + 123;
    TS_ASSERT_EQUALS("246", a.getAsDigits());
  }
  
  void testOperators23() {
    BigInt a(10);
    a = a * 25;
    TS_ASSERT_EQUALS("250", a.getAsDigits());
  }
  
  void testOperators24() {
    BigInt a(1);
    a = a * 25;
    TS_ASSERT_EQUALS("25", a.getAsDigits());
  }
  
  void testOperators25() {
    BigInt a;
    a = a * 25;
    TS_ASSERT_EQUALS("0", a.getAsDigits());
  }
  
  void testOperators26() {
    BigInt a(999);
    a = a * 999;
    TS_ASSERT_EQUALS("998001", a.getAsDigits());
  }
  
  void testOperators27() {
    BigInt a("123456789012345678901234567890");
    a = a * 4;
    TS_ASSERT_EQUALS("493827156049382715604938271560", a.getAsDigits());
  }
  
  void testOperators28() {
    BigInt a("123456789012345678901234567890");
    a = a * 12345;
    TS_ASSERT_EQUALS("1524074060357407406035740740602050", a.getAsDigits());
  }
  
};

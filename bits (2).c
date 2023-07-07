/* 
 * CS:APP Data Lab 
 * 
 * Jannah Hassan-Badwan
 * SU ID: 770294741
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* We do support the IEC 559 math functionality, real and complex.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
/* 
 * bitAnd - (x&y) using only ~ and | 
 *   Example: bitAnd(0x6, 0x5) = 0x4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  return ~((~x)|(~y));
}
/* 
 * bitImply - an imply gate using only ~ and |
 *   Example: bitImply(0x7, 0x6) = 0xFFFFFFFE
 *   Truth table for IMPLY:
 *     A  B  ->  OUTPUT
 *     0  0  ->     1
 *     0  1  ->     1
 *     1  0  ->     0
 *     1  1  ->     1
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitImply(int x, int y) {
  return ((~x)|y);
}
/* 
 * fourthBits - return an int with every 4th bit set to 1
 *   Example: fourthBits() = -2004318072
 *   Hint: Each hex digit will have the MSB=1 and other bits as 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int fourthBits(void) {
  /* an integer with every fourth bit as 1 is achieved by starting with 
  the number 0x88 and doing 3 rounds of an eight bit left shift and addition of 
  0x88 */
  int finalResult = ((((((0x88 << 8) + 0x88) << 8) + 0x88) << 8) + 0x88);
  return finalResult;
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (least significant) to 3 (most significant)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  /* To get the wanted byte we first right shift x by 8n bits, since multiplication is 
  not legal we used several rounds of addition of n to get the desired factor of 8n. After right 
  shifting the wanted bit to the LSB place we then use the mask 0xFF and AND it together isolating
   the wanted byte alone*/
  int m = n + n + n + n;
  int finalShift = m + m;
  int wantedByte = (x >> finalShift) & 0xFF;
  return wantedByte;
}
/* 
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int replaceByte(int x, int n, int c) {
  /* To replace the byte at position n in x with byte c, we shift 0xFF 8n bits and then take the bitwise not of  it, 
  by taking the bitwise not and ANDing that result with x we are going to clear out the byte we want to 
  replace in x (by clear out we make the byte all 0s). After the that we take the byte that is going to 
  replace the byte at position n and shift it 8n bits (so it is in the same position n now) then we OR them 
  together effectively replacing the byte with byte c*/
  int m = n + n + n + n;
  int finalShift = m + m;
  int finalResult = ((x & (~(0xFF << finalShift))) | (c << finalShift));
  return finalResult;
}


/* 
 * isNotEqual - return 0 if x == y, and 1 otherwise 
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNotEqual(int x, int y) {
  /* Perform x XOR y so that if they are equal you get all 0s and if they are not equal you get a nonzero number. 
  Logical not the XOR result to get 1 if it is equal and 0 if it is not equal. 
  Logical not this result again to get the final result of 0 if they are equal and 1 if they are not equal. */
  int firstOp = x ^ y; 
  int secondOp = !firstOp;
  int thirdOp = !secondOp;
  return thirdOp;
}
/* 
 * isCapitalizedLetter - return 1 if 0x41 <= x <= 0x5A (ASCII codes for characters 'A' to 'Z')
 *   Example: isCapitalizedLetter(0x42) = 1.
 *            isCapitalizedLetter(0x3a) = 0.
 *            isCapitalizedLetter(0x70) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isCapitalizedLetter(int x) {
  /* To determine if the input is a capitalized letter or not the logic I used was to 
  take the difference between x and the lower bound number which is 0x41 (decimal 65) and also to take 
  the difference between the upper bound 0x5A (decimal 90) and x. The differences were then right shifted to isolate the sign bit.
  If the differences were negative you would get all 1s and if the differences were positive you would get all 0s. 
  If both of these differences are positive then it corresponds to an ASCII uppercase letter and it returns 1 */
  int difference1 = x + (~(0x41) + 1);
  int difference2 = 0x5A + (~(x) + 1);
  int signDifference1 = difference1 >> 31;
  int signDifference2 = difference2 >> 31;
  int finalResult = (!signDifference1) & (!signDifference2);
  return finalResult;
}
/* 
 * shortSignMag2TwosComp - Convert from sign-magnitude to two's complement
 *   where the MSB is the sign bit. 
 *   Input will be a short type (2 bytes)
 *   Example: shortSignMag2TwosComp(0x8005) = -5.
 *   You can expect inputs will be in 0x0000 ~ 0xFFFF.
 *   Hint: you can use printf("%hi") to test your result.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int shortSignMag2TwosComp(int x) {
  /*First converted the short to an int type so that the rest of the calculations can be done correctly. 
  Then got the sign of the input by right shifting 31 bits so if pos it would be all 0s and if neg it would be all 1s.
  Then found cleared the most significant bit by anding with the equivalent to the mask of 0x7fff.
  Then took the xor of the magnitude and the sign to get the ones compliment. Added 1 to the ones comp if it was neg 
  and added 0 to the ones comp if it was pos. */
  int shortToInt = x << 16;
  int signX = (shortToInt >> 31);
  int magX = shortToInt & ~(0x01 << 31);
  int onesComp = magX ^ signX;
  int maskAddSign = ~signX + 1;
  int twosComp = onesComp + maskAddSign;
  return twosComp >> 16;
}


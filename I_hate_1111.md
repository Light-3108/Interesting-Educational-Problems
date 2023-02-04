1. Using Chicken Mcnugget Theorem.
   
   Observation. We can use only 11 and 111.
   
   if gcd(m,n) (m,n are integers) is 1 then greatest integer that can't be written in the form a*m + b*n (a,b>=0 and are integers) is m*n - m - n.
   
   Hence we can find that number which is relatively small and bruteforce.
   
   
2. Better Approach
   
   x = 11*a + 111*b if this is true we print YES.
   x = 11*a + (10*11 + 1)*b
   x = 11(a + 10*b) + b
   
   we can say: a + 10*b = (int) x/11
               hence if (a = (int) x/11 - 10*b ) is positive we can make x so YES else NO

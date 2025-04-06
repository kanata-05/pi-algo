# pi-algo
Algorithms to calcuate pi, with their own twists, sure.  

## Chudnovsky Algorithm
  The algorithm is based on the negated Heegner number $d = -163$, the j-function $j \left(\tfrac{1 + i\sqrt{-163}}{2}\right) = -640320^3$,  
  and on the following rapidly convergent generalized hypergeometric series:  
  $\frac{1}{\pi} = 12 \sum_{k=0}^{\infty} {\frac{(-1)^k (6k)! (545140134k + 13591409)}{(3k)! (k!)^3(640320)^{3k + 3/2}}}$  
  
  The time complexity of the algorithm is $O\left(n (\log n)^3\right)$
  The algorithm has been used in world records with binary splitting and is currently the fastest in the world,  
  It is great for single client operations such as single computer/server computation


## Bailey-Borwein-Plouffe Algorithm
  The Bailey–Borwein–Plouffe formula (BBP formula) is a formula for π. It was discovered in 1995 by Simon Plouffe and  
  is named after the authors of the article in which it was published, David H. Bailey, Peter Borwein, and Plouffe. The formula is:  
  $\pi = \sum_{k = 0}^{\infty}\left[\frac{1}{16^k} \left(\frac{4}{8k+1}-\frac{2}{8k+4}-\frac{1}{8k + 5}-\frac{1}{8k+6}\right)\right]$  
  The BBP formula gives rise to a spigot algorithm for computing the nth base-16 (hexadecimal) digit of π (and therefore also the 4nth binary digit of π)  
  without computing the preceding digits. This does not compute the nth decimal digit of π (i.e., in base 10).[1] But another formula  
  discovered by Plouffe in 2022 allows extracting the nth digit of π in decimal. This variant will be added later on.  

  ### Bellard's formula (BBP variant)
   Bellard's formula is used to calculate the nth digit of π in base 16.  This variant will be added later on.
   Bellard's formula was discovered by Fabrice Bellard in 1997. It is about 43% faster than the Bailey–Borwein–Plouffe formula (discovered in 1995).  

   One important application is verifying computations of all digits of pi performed by other means. Rather than having to compute all of the digits twice  
   by two separate algorithms to ensure that a computation is correct, the final digits of a very long all-digits computation can be   
   verified by the much faster Bellard's formula.  

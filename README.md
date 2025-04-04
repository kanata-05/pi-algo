# pi-algo
Algorithms to calcuate pi, with their own twists, sure.  

## Chudnovsky Algorithm
  The algorithm is based on the negated Heegner number $d = -163$, the j-function $j \left(\tfrac{1 + i\sqrt{-163}}{2}\right) = -640320^3$,  
  and on the following rapidly convergent generalized hypergeometric series:  
  $\frac{1}{\pi} = 12 \sum_{k=0}^{\infty} {\frac{(-1)^k (6k)! (545140134k + 13591409)}{(3k)! (k!)^3(640320)^{3k + 3/2}}}$  
  
  The time complexity of the algorithm is $O\left(n (\log n)^3\right)$
  The algorithm has been used in world records with binary splitting and is currently the fastest in the world,  
  It is great for single client operations such as single computer/server computation

  

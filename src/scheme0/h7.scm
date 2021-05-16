; tail recursion 2
(define (sum_ls ls)
  (sum_st ls 0))

(define (sum_st ls sum_v)
  (if (null? ls)
      sum_v
      (sum_st (cdr ls) (+ sum_v (car ls)))))

(sum_ls '(1 2 3 4))

(exit)
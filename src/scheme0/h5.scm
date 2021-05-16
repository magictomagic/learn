; tail recursion 0
(define (factorial n)
  (fact_status n n))

(define (fact_status n result)
  (cond
    ((<= 0 n 1) result)
    ((> n 1) (fact_status (- n 1) (* result (- n 1))))
    (else 0)))

(factorial 5)

(exit)??
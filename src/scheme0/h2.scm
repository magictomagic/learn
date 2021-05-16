; recursion
(define (fact_r n p)
    (if (<= n p)
        p
        (* n (fact_r (- n 1) p))
    )
)

(fact_r 5 3)

(exit)
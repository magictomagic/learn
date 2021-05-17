; do 2
(define (sum_up ls)
    (do ((remain_ls ls (cdr remain_ls)) (a 0 (+ a (car remain_ls)))) ((null? remain_ls) a)))

(sum_up '(1 2 3 4 5))

(exit)
; do 1
(define (my_reverse ls)
    (do ((remain_ls ls (cdr remain_ls)) (out '() (cons (car remain_ls) out))) ((null? remain_ls) out)))

(my_reverse '(1 2 3 4 5))

(exit)
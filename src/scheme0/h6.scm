; tail recursion 1
(define (my_reverse ls)
  (reverse_status ls '()))

(define (reverse_status ls st)
  (if (null? ls)
      st
      (let ((tail_ls (cdr ls)) (head_ls (car ls)))
        (reverse_status tail_ls (cons head_ls st)))))

(my_reverse (cons 1 (cons 2 (cons 3 (cons 2 '())))))
(my_reverse (cons 1 (cons 2 (cons 3 (cons 4 '())))))

(exit)
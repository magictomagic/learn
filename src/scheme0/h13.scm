; letrec 1
(letrec ((my_reverse (lambda (ls out)
                       (if (null? ls)
                 out
                 (my_reverse (cdr ls) (cons (car ls) out))))))
  (my_reverse '(1 2 3 4 5) '()))

(define (my_reverse ls)
  (letrec ((my_reverse1 (lambda (ls out)
                       (if (null? ls)
                 out
                 (my_reverse1 (cdr ls) (cons (car ls) out))))))
    (my_reverse1 ls '())))

(my_reverse '(1 2 3 4 5))

(exit)
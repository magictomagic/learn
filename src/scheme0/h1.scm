; list cons car cdr cond define if null? '()
(define (list*2 ls)
    (if (null? ls)
        '()
        (cons (* 2 (car ls))
            (list*2 (cdr ls))
        )
    )
)
(list*2 (cons 1 (cons 2 '())))

(define (my-length ls)
    (if (null? ls)
        0
        (+ 1 (my-length (cdr ls)))
    )
)
(my-length (cons 1 (cons 2 '())))
(my-length (cons 1 (cons 2 (cons 345 '()))))

(define (ls-sum ls)
    (if (null? ls)
        0
        (+ (car ls) (ls-sum (cdr ls)))
    )
)
(ls-sum (cons 1 (cons 2 (cons 345 '()))))

(exit)
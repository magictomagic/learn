(define (two_m ls)
    (map (lambda (x) (* 2 x)) ls))

(define (tm ls1 ls2)
    (map - ls1 ls2))

(two_m '(1 3 5))
(tm '(1 2 3 4) '(8 5 2 1))

(exit)
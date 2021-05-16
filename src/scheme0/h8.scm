; let loop 0
(define (factorial n)
    (let loop ((a n) (b n))
    (if (= a 1)
        b
        (loop (- a 1) (* b (- a 1))))))

(factorial 4)

(exit)
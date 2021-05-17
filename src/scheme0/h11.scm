; save status in loop 3
(define (range n)
    (let loop ((seed 0) (ls '()))
      (if (= seed n)
          (reverse ls)
          (loop (+ 1 seed) (cons seed ls)))))

(range 6)

(exit)
; save status in loop 2
(define (find_index ls x)
    (let loop ((index 0) (ls_remain ls))
      (cond
        ((null? ls_remain) #f)
        ((eqv? x (car ls_remain)) index)
        (else (loop (+ index 1) (cdr ls_remain))))))

(find_index '(1 2 3 4) 2)

(exit)

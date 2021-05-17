; save status in loop 1
(define (delete_x ls x)
    (let loop ((head_save '()) (tail_save ls))
      (cond
         ((null? tail_save) (reverse head_save))
         ((eqv? (car tail_save) x) (loop head_save (cdr tail_save)))
         (else (loop (cons (car tail_save) head_save) (cdr tail_save))))))

(delete_x '(1 2 3 2) 2)

(exit)
; delete all x
(define (delete_x ls x)
  (if (null? ls)
  '()
  (let ((pre_ls (car ls)))
    ((if (eqv? pre_ls x)
        (lambda (y) y)
        (lambda (y) (cons pre_ls y)))
     (delete_x (cdr ls) x)))))
; notice the use of lambda

(delete_x (cons 1 (cons 2 (cons 3 (cons 2 '())))) 2)

(exit)
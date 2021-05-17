; higher-order function
(define (keep-matching-items ls proc)
    (keep-matching-items1 ls proc '()))

(define (keep-matching-items1 ls proc out)
    (cond
      ((null? ls) (reverse out))
      ((proc (car ls)) (keep-matching-items1 (cdr ls) proc (cons (car ls) out)))
      (else (keep-matching-items1 (cdr ls) proc out))))

(keep-matching-items '(1 2 -3 -4 5) positive?)

(exit)
(define (make-bank-account balance)
  (lambda (n)
    (set! balance (+ balance n))
      (if (< balance 0) #f balance)
      ))

(exit)

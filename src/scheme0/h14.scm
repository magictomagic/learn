; letrec 2
(letrec ((sumup (lambda (ls s)
                  (if (null? ls)
            s
            (sumup (cdr ls) (+ (car ls) s))))))
  (sumup '(1 2 3 4) 0))

(define (sumup ls)
    (letrec ((sumup (lambda (ls s)
                  (if (null? ls)
            s
            (sumup (cdr ls) (+ (car ls) s))))))
      (sumup ls 0)))

(sumup '(1 3 5 7))

(exit)
; letrec ((name value)) body
; always go with lambda, bind and can use name in body
(letrec ((factorial (lambda (n)
                      (if (zero? n)
                1
                (* n (factorial (- n 1)))))))
  (factorial 5))

(define (fact m)
  (letrec ((factorial (lambda (n)
                      (if (zero? n)
                1
                (* n (factorial (- n 1)))))))
  (factorial m)))


(exit)
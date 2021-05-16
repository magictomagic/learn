; find first x
(define (find_index ls x)
  (find_x ls x 0))

; use parameter to save status
; need to initialize
; so 套一层
(define (find_x ls x i)
  (if (null? ls)
      #f
      (if (eqv? x (car ls))
          i
          (find_x (cdr ls) x (+ i 1)))))

; 进击尾递归

(find_index (cons 1 (cons 2 (cons 3 (cons 2 '())))) 2)

(exit)
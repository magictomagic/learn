;;;;;;; symbol vs string ;;;;;;;
; > (equal? 'atom 'atom)
; #t
; > (eq? 'atom 'atom)
; #t
; > (eq? "atom" "atom")
; #f
; > (eqv? "atom" "atom")
; #f
; > (equal? "atom" "atom")
; #t

;;;;;;; ` vs , vs ' ;;;;;;;
; > (define a 1)
;   (define b 2)
; > (define b 2)
; > '(a b)
; (a b)
; > `(a b)
; (a b)
; > `(a ,b)
; (a 2)
; > `(,a ,b)
; (1 2)
; > (quasiquote (a (unquote b)))
; (a 2)
(define (enqueue! queue obj)
  (let ((lobj (cons obj '())))
    (if (null? (car queue))
    (begin
      (set-car! queue lobj)
      (set-cdr! queue lobj))
    (begin
      (set-cdr! (cdr queue) lobj)
      (set-cdr! queue lobj)))
    (car queue)))
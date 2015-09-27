(define (inc x) (+ 1 x))

(define (double f)
  (lambda (x) (f (f x))))

((double inc) 5)

(((double double) inc) 5)

(((double (double double)) inc) 5)

(define (cons-v x y)
  (define (dispatch m)
    (cond ((= m 0) x)
          ((= m 1) y)
          (else (display "wrong flag"))))
  dispatch)

(define (car-v c)
  (c 0))

(define (cdr-v c)
  (c 1))

(define (cons-v2 x y)
  (lambda (m) (m x y)))

(define (car-v2 c)
  (c (lambda (p q) p)))

(define (cdr-v2 c)
  (c (lambda (p q) q)))

(define (cons-v3 x y)
  (* (expt 2 x) (expt 3 y)))

(define (expt-get value base)
  (define (iter value result)
    (if (not (= 0 (remainder value base)))
        result
        (iter (/ value base) (+ result 1))))
  (iter value 0))

(define (car-v3 c)
  (expt-get c 2))

(define (cdr-v3 c)
  (expt-get c 3))

(define (display-cons-v c)
  (newline)
  (display (car-v3 c))
  (display ",")
  (display (cdr-v3 c)))

(display-cons-v (cons-v3 3 5))

(define zero (lambda (f) (lambda (x) x)))

(define (add-1 n) (lambda (f) (lambda (x) (f ((n f) x)))))


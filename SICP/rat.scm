(define (gcd x y)
  (if (= y 0)
      x
      (gcd y (remainder x y))))

(define (abs x)
  (if (< x 0)
      (- x)
      x))

(define (make-rat n d)
  (if (= d 0)
      (error "denominator can not be zero")
      (let ((g (abs (gcd n d))))
        (define n_ (/ n g))
        (define d_ (/ d g))
        (if (< d 0)
            (cons (- n_) (- d_))
            (cons n_ d_)))))

(define (numer x)
  (car x))
(define (denom x)
  (cdr x))

(define (print-rat x)
  (newline)
  (display (numer x))
  (display "/")
  (display (denom x)))

(define (add-rat x y)
  (make-rat (+ (* (numer x) (denom y)) (* (numer y) (denom x)))
            (* (denom x) (denom y))))

(define (sub-rat x y)
  (make-rat (- (* (numer x) (denom y)) (* (numer y) (denom x)))
            (* (denom x) (denom y))))

(define (mul-rat x y)
  (make-rat (* (numer x) (numer y))
            (* (denom x) (denom y))))

(define (div-rat x y)
  (make-rat (* (numer x) (denom y))
            (* (denom x) (numer y))))

(define (equal-rat? x y)
  (= (* (numer x) (denom y))
     (* (denom x) (numer y))))

(define one-half (make-rat 1 2))
(define one-third (make-rat 1 3))

(print-rat (make-rat 6 8))
(print-rat (make-rat -6 8))
(print-rat (make-rat 6 -8))
(print-rat (make-rat -6 -8))

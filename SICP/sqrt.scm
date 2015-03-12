(define (sqrt-iter guess x)
  (if (good-enough2? guess x)
      guess
      (sqrt-iter (improve guess x)
                 x)))

(define (good-enough? guess x)
  (< (abs (- (square guess) x)) 0.0001))

(define (good-enough2? guess x)
  (< (/ (abs (- (improve guess x) guess)) guess) 0.0001))

(define (square x)
  (* x x))

(define (abs x)
  (if (< x 0) (- x) x))

(define (improve guess x)
  (average guess (/ x guess)))

(define (average x y)
  (/ (+ x y) 2))

(define (sqrt x)
  (sqrt-iter 1.0 x))



(define (cube-root-iter guess x)
  (if (good-enough-cube? guess x)
      guess
      (cube-root-iter (improve-cube guess x)
                 x)))

(define (cube-root x)
  (cube-root-iter 1.0 x))

(define (good-enough-cube? guess x)
  (< (/ (abs (- (improve-cube guess x) guess)) guess) 0.0001))

(define (improve-cube guess x)
  (/ (+ (/ x (square guess))
        (* 2 guess))
     3))

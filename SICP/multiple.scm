(define (mult a b)
  (if (= b 0)
      0
      (+ a (mult a (- b 1))))) 

(define (fast-mult a b)
  (fast-mult-iter 0 a b))

(define (fast-mult-iter sum a b)
  (cond ((= b 0) sum)
        ((even? b) (fast-mult-iter sum (double a) (halve b)))
        (else (fast-mult-iter (+ sum a) a (- b 1)))))

(define (double a)
  (* 2 a))

(define (halve a)
  (/ a 2))

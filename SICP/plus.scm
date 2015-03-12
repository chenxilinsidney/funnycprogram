(define (plus-1 a b)
  (if (= a 0)
      b
      (inc (plus-1 (dec a) b))))
(define (plus-2 a b)
  (if (= a 0)
      b
      (plus-2 (dec a) (inc b))))

(define (dec x) (- x 1))
(define (inc x) (+ x 1))

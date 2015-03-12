(define (f1 n)
  (if (< n 3) n
              (+ (f1 (- n 1))
                 (* 2 (f1 (- n 2)))
                 (* 3 (f1 (- n 3))))))

(define (f-iter a b c n)
  (cond ((= n 2) c)
        ((< n 2) n)
        (else (f-iter b c (+ (* 3 a) (* 2 b) c) (- n 1)))))
(define (f2 n)
  (f-iter 0 1 2 n))

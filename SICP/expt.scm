(define (expt-v1 b n)
  (cond ((= n 0) 1)
        (else (* b (expt-v1 b (- n 1))))))

(define (expt-v2 b n)
  (expt-v2-iter 1 b n))
(define (expt-v2-iter a b n)
  (if (= 0 n)
      a
      (expt-v2-iter (* a b) b (- n 1))))

(define (fast-expt-v1 b n)
  (cond ((= n 0) 1)
        ((even? n) (square (fast-expt-v1 b (/ n 2))))
        (else (* b (fast-expt-v1 b (- n 1))))))

(define (fast-expt-v2 b n)
  (fast-expt-v2-iter 1 b n))
(define (fast-expt-v2-iter a b n)
  (cond ((= n 0) a)
        ((even? n) (fast-expt-v2-iter a (square b) (/ n 2)))
        (else (fast-expt-v2-iter (* a b) b (- n 1)))))

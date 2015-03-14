(define (expt-v1 b n)
  (cond ((= n 0) 1)
        (else (* b (expt-v1 b (- n 1))))))

(define (expt-v2 b n)
  (expt-v2-iter 1 b n))
(define (expt-v2-iter a b n)
  (if (= 0 n)
      a
      (expt-v2-iter (* a b) b (- n 1))))

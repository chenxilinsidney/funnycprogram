(define (sum-integer a b)
  (if (> a b)
      0
      (+ a (sum-integer (+ a 1) b))))


(define (sum-cubes a b)
  (if (> a b)
      0
      (+ (cube a) (sum-cubes (+ a 1) b))))

(define (cube x)
  (* x x x))

(define (pi-sum a b)
  (if (> a b)
      0
      (+ (/ 1.0 (* a (+ a 2))) (pi-sum (+ a 4) b))))

(define (sum term a next b)
  (if (> a b)
      0
      (+ (term a) (sum term (next a) next b))))

(define (inc x)
  (+ x 1))

(define (sum-cubes-v2 a b)
  (sum cube a inc b))

(define (identity x) x)

(define (sum-integer-v2 a b)
  (sum identity a inc b))

(define (pi-sum-v2 a b)
  (define (pi-sum-term x)
    (/ 1.0 (* x (+ x 2))))
  (define (pi-sum-next x)
    (+ x 4))
  (sum pi-sum-term a pi-sum-next b))

(define (integral f a b dx)
  (define (integral-next x)
    (+ x dx))
  (* (sum f (+ a (/ dx 2.0)) integral-next b) dx))

(define (integral-v3 f a b n) 
  (define h (/ (- b a) n))
  (define (integral-inner f a b k n)
    (define (pre-fix k)
      (cond ((or (= k 0) (= k n)) 1)
            ((even? k) 2)
            (else 4)))
    (define (y k)
      (+ a (* k h)))
    (if (or (> a b) (> k n))
        0
        (+ (* (pre-fix k)
              (f (y k)))
           (integral-inner f a b (+ k 1) n))))
  (* (/ h 3.0)
     (integral-inner f a b 0 n)))

(define (product-v1 a term next b)
  (if (> a b)
      1
      (* (term a)
         (product-v1 (next a) term next b))))

(define (product-v2 a term next b)
  (define (iter a result)
    (if (> a b)
      result
      (iter (next a) (* (term a) result))))
  (iter a 1))

(define (factorial-v1 n)
    (define (factorial-term x) x)
    (define (factorial-next x) (+ x 1))
    (product-v1 1 factorial-term factorial-next n))

(define (factorial-v2 n)
    (define (factorial-term x) x)
    (define (factorial-next x) (+ x 1))
    (product-v2 1 factorial-term factorial-next n))

(define (pi-4 n)
    (define (pi-term x)
      (/ (* (* 2.0 x) (+ (* 2.0 x) 2))
         (square (+ (* 2.0 x) 1))))
    (define (pi-next x) (+ x 1))
    (product-v3 1 pi-term pi-next n))

(define (accumulate-v1 combiner null-value term a next b)
   (if (> a b)
       null-value
       (combiner (term a)
                 (accumulate-v1 combiner null-value term (next a) next b))))

(define (accumulate-v2 combiner null-value term a next b)
  (define (iter a result)
    (if (> a b)
       result
       (iter (next a) (combiner (term a) result))))
  (iter a null-value))

(define (product-v3 a term next b)
  (accumulate-v2 * 1 term a next b))

(define (filter-accumulate-v1 filter combiner null-value term a next b)
   (if (not (filter a b))
       null-value
       (combiner (term a)
                 (filter-accumulate-v1 filter combiner null-value term (next a) next b))))

(define (filter-accumulate-v2 filter combiner null-value term a next b)
  (define (iter a result)
    (if (not (filter a b))
       result
       (iter (next a) (combiner (term a) result))))
  (iter a null-value))



(define (=number? expr num)
  (and (number? expr) (= expr num)))

(define (variable? v)
  (symbol? v))

(define (same-variable? v1 v2)
  (and (variable? v1) (variable? v2) (eq? v1 v2)))

(define (sum? e)
  (and (pair? e) (eq? (car e) '+)))

(define (addend e)
  (cadr e))

(define (augend e)
  (caddr e))

(define (make-sum a1 a2)
  (cond ((=number? a1 0) a2)
        ((=number? a2 0) a1)
        ((and (number? a1) (number? a2)) (+ a1 a2))
        (else (list '+ a1 a2))))

(define (product? p)
  (and (pair? p) (eq? (car p) '*)))

(define (multiplier p)
  (cadr p))

(define (multiplicand p)
  (caddr p))

(define (make-product m1 m2)
  (cond ((or (=number? m1 0) (=number? m2 0)) 0)
        ((=number? m1 1) m2)
        ((=number? m2 1) m1)
        ((and (number? m1) (number? m2)) (* m1 m2))
        (else (list '* m1 m2))))

(define (exponentation? expr)
  (and (pair? expr) (eq? (car expr) '**)))

(define (base expr)
  (cadr expr))

(define (exponent expr)
  (caddr expr))

(define (make-exponentiation ba ep)
  (cond ((=number? ep 0) 1)
        ((=number? ep 1) ba)
        (else (list '** ba ep))))

(define (derive expr var)
  (cond ((number? expr) 0)
         ((variable? expr)
           (if (same-variable? expr var) 1 0))
         ((sum? expr)
           (make-sum (derive (addend expr) var)
                      (derive (augend expr) var)))
         ((product? expr)
           (make-sum
             (make-product (multiplier expr)
                           (derive (multiplicand expr) var))
             (make-product (multiplicand expr)
                           (derive (multiplier expr) var))))
         ((exponentation? expr)
           (make-product (exponent expr)
                         (make-product (make-exponentiation (base expr)
                                        (- (exponent expr) 1))
                                       (derive (base expr) var))))
         (else
           (error "unknown expression type:" expr))))

(newline)
(display (derive '(+ x 3) 'x))
(newline)
(display (derive '(* x y) 'x))
(newline)
(display (derive '(* (* x y) (+ x 3)) 'x))
(newline)
(* 3 4)

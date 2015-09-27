(define (list-ref items n)
  (if (or (null? items) (< n 0))
      (error "can not get right values")
      (if (= n 0)
        (car items)
        (list-ref (cdr items) (- n 1)))))

(define (list-length-re items)
  (if (null? items)
      0
      (+ 1 (list-length-re (cdr items)))))
      
(define (list-length items)
  (define (iter items n)
    (if (null? items)
        n
        (iter (cdr items) (+ n 1))))
  (iter items 0))

(define (list-append items1 items2)
  (if (null? items1)
      items2
      (cons (car items1) (list-append (cdr items1) items2)))) 

(define (list-last-pair items)
  (list-ref items (- (list-length items) 1)))


(define (list-reverse-it items)
  (define (iter n)
          (if (< n 0)
          (list)
          (cons (list-ref items n) (iter (- n 1)))))
  (let ((len (list-length items)))
    (if (= len 0)
        (items)
        (iter (- len 1)))))
    
(newline)
(display (list-reverse-it (list 1 3 5 7)))
(newline)

(define (list-reverse items)
  (define (re it newit)
    (if (null? it)
        newit
        (re (cdr it) (cons (car it) newit))))
  (re items (list)))

(newline)
(display (list-reverse (list 1 3 5 7)))
(newline)

(define (map proc items)
  (if (null? items)
      (list)
      (cons (proc (car items)) (map proc (cdr items)))))

(define (scale-list items factor)
  (map (lambda (x) (* x factor)) items))

(define (square-list items)
  (map (lambda (x) (square x)) items))

(newline)
(display (scale-list (list 1 3 5 7) 2))
(newline)

(newline)
(display (square-list (list 1 3 5 7)))
(newline)

(define (count-leaves items)
  (cond ((null? items) 0)
        ((not (pair? items)) 1)
        (else (+ (count-leaves (car items))
                 (count-leaves (cdr items))))))

(newline)
(display (count-leaves (list (list 1 3) 5 7)))
(newline)

(define (filter predicate sequence)
  (cond ((null? sequence) (list))
        ((predicate (car sequence))
           (cons (car sequence)
                 (filter predicate (cdr sequence))))
        (else (filter predicate (cdr sequence)))))
        
(newline)
(display (filter odd? (list 1 2 3 4 5)))
(newline)

(define (accumulate op initial sequence)
  (if (null? sequence)
      initial
      (accumulate op (op initial (car sequence)) (cdr sequence))))

(newline)
(display (accumulate + 0 (list 1 2 3 4 5)))
(newline)

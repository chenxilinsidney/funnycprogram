(newline)
(define nil 0)
(display (car (cons 1 (cons 2 nil))))
(newline)
(display (cons 0 3))
(newline)
(display (list 1 2 3 4))

(define (list-ref items n)
  (if (or (null? items) (< n 0))
      (error "can not get right values")
      (if (= n 0)
        (car items)
        (list-ref (cdr items) (- n 1)))))

(define list-1 (list 3 33 333 3333))
(newline)
(display (list-ref list-1 2))
(newline)

(define (list-length items)
  (define (iter it n)
    (if (null? it)
        n
        (iter (cdr it) (+ n 1))))
  (iter items 0))

(newline)
(display (list-length list-1))
(newline)

(define (list-append list1 list2)
    (if (null? list1)
        list2
        (cons (car list1)
              (list-append (cdr list1) list2))))
(newline)
(display (list-append (list 1 3 5 7) (list 2 4 6 8)))
(newline)

(define (list-pair items)
  (define (iter it)
   (if (null? (cdr it))
       (car it)
       (iter (cdr it))))
  (if (null? items)
      (error "empty list")
      (iter items)))

(newline)
(display (list-pair (list 1 3 5 7)))
(newline)

(newline)
(display "null value:")
(display (list))
(newline)
(display (null? (list)))
(newline)

(define (list-reverse items)
  (define (iter it result)
   (if (null? it)
       result
       (iter (cdr it)
             (cons (car it) result))))
  (iter items (list)))

(newline)
(display (list-reverse (list 1 3 5 7)))
(newline)




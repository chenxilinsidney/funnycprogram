(define (make-segment p1 p2)
  (cons p1 p2))

(define (start-segment line)
  (car line))

(define (end-segment line)
  (cdr line))

(define (make-point x y)
  (cons x y))

(define (x-point point)
  (car point))

(define (y-point point)
  (cdr point))

(define (print-point p)
  (newline)
  (display "(")
  (display (x-point p))
  (display ",")
  (display (y-point p))
  (display ")"))

(define (midpoint-segment line)
  (make-point (/ (+ (x-point (start-segment line))
                    (x-point (end-segment line)))
                 2.0)
              (/ (+ (y-point (start-segment line))
                    (y-point (end-segment line)))
                 2.0)))

(define (make-rectangle-by-point point-1 point-2)
  (cons (abs (- (y-point point-1) (y-point point-2)))
        (abs (- (x-point point-1) (x-point point-2)))))

(define (make-rectangle-by-hw height width)
  (cons height width))

(define (height-rectangle x)
  (car x))

(define (width-rectangle x)
  (cdr x))
    
(define (double x)
  (* x 2))

(define (length-rectangle x)
  (double (+ (height-rectangle x)
             (width-rectangle x))))

(define (area-rectangle x)
  (* (height-rectangle x)
     (width-rectangle x)))

(define (print-rectangle x)
  (newline)
  (display "[")
  (display (height-rectangle x))
  (display ",")
  (display (width-rectangle x))
  (display "]")
  (newline)
  (display "lenght:")
  (display (length-rectangle x))
  (newline)
  (display "area:")
  (display (area-rectangle x)))

(define point-1 (make-point 3 8))
(define point-2 (make-point 8 9))
(define line-1 (make-segment point-1 point-2))
(print-point (midpoint-segment line-1))
(define rectangle-1 (make-rectangle-by-point point-1 point-2))
(define rectangle-2 (make-rectangle-by-hw 4 5))
(print-rectangle rectangle-1)
(print-rectangle rectangle-2)

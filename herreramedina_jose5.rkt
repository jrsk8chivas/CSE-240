;Jose Herrera Medina
;CSE 240 M-F 4:35pm -5:35pm
;Question 1
4 + 5

4 + 5 + 6

(+(* 4 2 )(* 8 8))

(+(+(* 4 2 )(* 9 9))(/ 18 2))

(/(+ 2 4 6 8 10 12 14)(+ 2 4 6))
newline
;Question 2
;Global scope name
(define four 4)
newline
four + 5

four + 5 + 6

(+(* four 2 )(* 8 8))

(+(+(* four 2 )(* 9 9))(/ 18 2))

(/(+ 2 four 6 8 10 12 14)(+ 2 four 6))
newline
;Question 3
;Take 2 inputs for base and height
;compute area of rectangle
(define (main)
  (RectArea (read) (read));read two inputs
  )
;define the area procedure
(define (RectArea base height)
 ;computes area base * height
  (* base height)
  )
(main);displays 
newline
;Question 4
;Take 3 inputs for base height and depth
;compute volume
(define (RectArea base height);area procedure
  (* base height)
  )
(define (RectVol b h d);define volume procedure take base height and depth
  (*(RectArea b h) d);uses area procedure for base and height than multiplies by depth
  )
(define (main)
  (RectVol (read) (read) (read));reads the 3 inputs for volume
)
(main)
newline
;Question 5
;Return difference between 2 rectangles
(define (RectArea base height);area procedure
  (* base height)
  )
(define (RectVol b h d);volume procedure
  (*(RectArea b h) d)
  )
(define (DiffVolume b1 h1 d1 b2 h2 d2);define the difference of volume procedure
  (- (RectVol b2 h2 d2) (RectVol b1 h1 d1));takes the inputs for the second rectangle minus the first rectangle
  )
(define (main)
  (DiffVolume (read) (read) (read) (read)(read) (read));reads the inputs for both rectangles
)
(main)
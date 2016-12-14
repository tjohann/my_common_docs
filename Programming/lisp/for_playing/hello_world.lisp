;;
;; M-x slime
;; C-c C-c -> compile defun below cursor
;; C-c C-k -> compile complete buffer and load fasl
;;
;; fasl -> fast-load file
;; http://www.cliki.net/SLIME%20Features
;;

;; first hello world
(defun hello-world()
  (format t "hello world"))

;; next hello world
(defun another-hello-world()
  (format t "another hello world"))

;; another test hello-world
(defun test-hello-world()
  (format t "try to test slime compilation"))


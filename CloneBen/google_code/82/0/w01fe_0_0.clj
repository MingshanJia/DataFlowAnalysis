;; by Jason Wolfe

; This code was developed for Clojure and clojure-contrib 1.2.0

; To execute it, call (solve-file "<stem>"), where <stem> is the name of
; the input file, minus ".in" extension.  Output will be written to
; stdout, as well as the corresponding ".out" file.

(ns codejam2011.a
  (:require [clojure.contrib [duck-streams :as io] [seq-utils :as seq] [math :as math]])
  (:import [java.util HashMap]))



(defn next-button [state [robot button]]
  (let [[robot-pos robot-time] (get state robot)]
    (assoc state robot
           [button
            (inc (apply max
                        (+ robot-time (math/abs (- robot-pos button)))
                        (map second (vals state))))])))

(defn solve [input]
  (->> (reduce next-button {'O [1 0] 'B [1 0]} input)
       vals
       (map second)
       (apply max)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;; Boilerplate IO ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(def fol "/Users/jawolfe/Projects/codejam2011/data/")


(defn read-in [x]
  (map #(partition 2 (next (read-string (str "[" % "]")))) 
       (rest (io/read-lines (str fol x)))))

(defn prn-out [f contents]
  (print contents)
  (spit (str fol f) contents))

(defn solve-file [stem]
  (prn-out (str stem ".out")
    (apply str         
      (for [[i inp] (seq/indexed (read-in (str stem ".in")))]
        (str "Case #" (inc i) ": " (solve inp) "\n")))))


(comment
    (let [psp (- (dec (* 2 k)) nk -1)
        sp (int (/ psp 2))]
    (println "s" k nk x y sp)
    (every? (fn [[dx dy]]
              (and (= (diamond-pos k input (+ x dx) (+ y dy))
                      (diamond-pos k input (+ x dx) (- y dy)))
                   (= (diamond-pos k input (- x dx) (+ y dy))
                      (diamond-pos k input (- x dx) (- y dy)))
                   (= (diamond-pos k input (+ x dx) (+ y dy))
                      (diamond-pos k input (- x dx) (+ y dy)))
                   (= (diamond-pos k input (+ x dx) (- y dy))
                      (diamond-pos k input (- x dx) (- y dy)))
                   ))
            (apply concat
              (for [d  (range 1 (inc sp))
                    :let [d (+ (if (even? psp) -1 0) (* 2 d))]
                    e (range d)]
                [[(- e d) e]]))))
  )
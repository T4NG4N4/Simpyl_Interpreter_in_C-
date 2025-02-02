Guía de Sintaxis de Simpyl

Introducción

Simpyl es un lenguaje de programación inspirado en Scheme y Python, con una sintaxis sencilla y flexible. Esta guía te ayudará a aprender desde lo básico hasta conceptos avanzados en Simpyl.

1. Variables y Asignaciones

Sintaxis:

(variable = valor)

Ejemplo:

(x = 10)
(name = "Juan")

2. Operaciones Matemáticas

Sintaxis:

(+ a b)
(- a b)
(* a b)
(/ a b)

Ejemplo:

(+ 5 3)   ; 8
(- 10 4)  ; 6
(* 6 7)   ; 42
(/ 8 2)   ; 4

3. Impresión en Consola

Sintaxis:

(print expresion)

Ejemplo:

(print "Hola Mundo")
(print (+ 3 7))

4. Definición de Funciones

Sintaxis:

(define (nombre parametros) (cuerpo))

Ejemplo:

(define (suma x y) (+ x y))
(suma 4 5)  ; 9

5. Funciones Lambda

Sintaxis:

(lambda (parametros) (cuerpo))

Ejemplo:

(define cuadrado (lambda (x) (* x x)))
(cuadrado 5)  ; 25

6. Condicionales

Sintaxis:

(if (condicion) (accion_si_verdadero) (accion_si_falso))

Ejemplo:

(if (> 10 5) (print "Mayor") (print "Menor"))

7. Bucles

Sintaxis:

(while (condicion) (cuerpo))

Ejemplo:

(define (contador x)
    (while (> x 0)
        (print x)
        (x = (- x 1))))
(contador 5)

8. Importación de Módulos

Sintaxis:

(import "nombre_modulo")

Ejemplo:

(import "math")

9. Manejo de Listas

Sintaxis:

(list elemento1 elemento2 elemento3 ...)

Ejemplo:

(define numeros (list 1 2 3 4 5))
(print numeros)

10. Depuración y Manejo de Errores

Activar el modo depuración:

(debug-on)

Inspeccionar una variable:

(inspect nombre_variable)

Conclusión

Esta guía proporciona una base sólida para programar en Simpyl. Puedes combinar estas estructuras para crear programas más avanzados. ¡Explora y experimenta con Simpyl!


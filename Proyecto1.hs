{--Ejercicio_2
1. Programa las siguientes funciones:
--}
--a) esCero :: Int -> Bool, que verifica si un entero es igual a 0.
esCero :: Int->Bool
esCero x = x==0
{--
*Main> esCero 0
True
*Main> esCero 1
False
--}

--b) esPositivo :: Int -> Bool, que verifica si un entero es estrictamente mayor a 0.
esPositivo :: Int->Bool
esPositivo x = x>0
{--
*Main> esPositivo 10
True
*Main> esPositivo (-10)
False

--}

--c) esVocal :: Char -> Bool, que verifica si un caracter es una vocal en min ́uscula.
esVocal :: Char->Bool
esVocal x = x=='a' || x=='e' || x=='i' || x=='o'|| x=='u'
{--
*Main> esVocal 'e'
True
*Main> esVocal 'r'
False
--}

--d) valorAbsoluto :: Int -> Int, que devuelve el valor absoluto de un entero ingresado.
valorAbsoluto :: Int->Int
valorAbsoluto x | x>=0 = x
                | x<0 = -x
{--
*Main> valorAbsoluto 12
12
*Main> valorAbsoluto (-12)
12
--}

--2. Program ́a las siguientes funciones usando recursion o composicion:
--a) paratodo :: [Bool] -> Bool, que verifica que todos los elementos de una lista sean True.
paratodo :: [Bool]->Bool
paratodo [] = True
paratodo (x:xs) | x==True = paratodo xs    --si se cumple, recorre la lista
                | otherwise = False

{--
*Main> paratodo [True,False]
False
*Main> paratodo [True,True]
True
--}

--b) sumatoria :: [Int] -> Int, que calcula la suma de todos los elementos de una lista de enteros.
sumatoria :: [Int] -> Int
sumatoria [] = 0
sumatoria (x:xs) = x+sumatoria xs  --agarra el primer elemento de la lista y lo suma con los demas elementos de la lista

{--
*Main> sumatoria [1,2,3,34]
40
*Main> sumatoria []
0
--}

--c) productoria :: [Int] -> Int, que calcula el producto de todos los elementos de la lista de enteros.
productoria :: [Int] -> Int
productoria [] = 1
productoria (x:xs) = x*productoria xs  --agarra el primer elemento de la lista y lo multiplica con los demas elementos de la lista

{--
*Main> productoria [1,2,3,4]
24
*Main> productoria []
1
--}

--d) factorial :: Int -> Int, que toma un numero n y calcula n!.
factorial :: Int -> Int
factorial 0 = 1
factorial n = n*factorial (n-1) --aplico recursion pero con n-1 para calcular el numero anterior a n

{--
*Main> factorial 5
120
*Main> factorial 4
24
*Main> factorial 0
1
--}

--e) Utiliza la funci ́on sumatoria para definir, promedio :: [Int] -> Int, que toma una lista de numeros no vacia y calcula el valor promedio (truncado, usando division entera).
promedio :: [Int] -> Int
promedio [] = 0
promedio (x:xs) = (sumatoria xs) `div` length xs  --usando el `div` para dividir entre la funcion sumatoria y el largo de la lista

{--
*Main> promedio [1,2,23,3,43]
17
*Main> promedio [9,10]
10
--}

--3. Programa la funcion pertenece :: Int -> [Int] -> Bool, que verifica si un numero se encuentra en una lista.
pertenece :: Int -> [Int] -> Bool
pertenece _ [] = False
pertenece n [x] = n==x
pertenece n (x:xs) | n==x = True
                   | otherwise = pertenece n xs --si n/=x va a seguir recorriendo la lista

{--
*Main> pertenece 4 [2,4,6]
True
*Main> pertenece 7 [2,4,6]
False
--}

--4. Programa las siguientes funciones que implementan los cuantificadores generales. Nota que
--el segundo parametro de cada funci ́on, es otra funcion!

{--a) paratodo' :: [a] -> (a -> Bool) -> Bool, dada una lista xs de tipo [a] y un
predicado t :: a -> Bool, determina si todos los elementos de xs satisfacen el predicado t.--}
paratodo' :: [a] -> (a -> Bool) -> Bool
paratodo' [] _ = True
paratodo' (x:xs) t = t x && paratodo' xs t  --uso una fucnion "t x" que puede ser cualquier funcion del tipo definido.

{--
*Main> paratodo' ['a','e','i','u'] esVocal  
True
*Main> paratodo' [0,0,0,0] esCero 
True
*Main> paratodo' [1,2,3,4] esCero 
False    
--}

{--b) existe' :: [a] -> (a -> Bool) -> Bool, dada una lista xs de tipo [a] y un
predicado t :: a -> Bool, determina si alg ́un elemento de xs satisface el predicado t.--}
existe' :: [a] -> (a -> Bool) -> Bool
existe' [] _ = False
existe' (x:xs) t = t x || existe' xs t  --toma una lista y un predicado, si se cumplen alguna de los dos entonces dara true.

{--
*Main> existe' [1,2,3,4] esCero 
False
*Main> existe' [1,2,3,4,0] esCero 
True
*Main> existe' ['a','e','i','u'] esVocal  
True
*Main> existe' ['a','y','t','r'] esVocal  
True
--}

{--c) sumatoria' :: [a] -> (a -> Int) -> Int, dada una lista xs de tipo [a] y una
funcion t :: a -> Int (toma elementos de tipo a y devuelve enteros), calcula la
suma de los valores que resultan de la aplicacion de t a los elementos de xs.--}
sumatoria' :: [a] -> (a -> Int) -> Int
sumatoria' [] _ = 0
sumatoria' (x:xs) t = t x + sumatoria' xs t

{--
*Main> sumatoria' [1,2,3,4] valorAbsoluto 
10
*Main> sumatoria' [(-1),2] valorAbsoluto 
3
--}

{--d) productoria' :: [a] -> (a -> Int) -> Int, dada una lista de xs de tipo [a]
y una funcion t :: a -> Int, calcula el producto de los valores que resultan de la
aplicacion de t a los elementos de xs.--}
productoria' :: [a] -> (a -> Int) -> Int
productoria' [] _ = 1
productoria' (x:xs) t = t x * productoria' xs t

{--
*Main> productoria' [1,0,(-1)] valorAbsoluto 
0
*Main> productoria' [1,2,2,34] valorAbsoluto 
136
*Main> productoria' [1,(-1)] valorAbsoluto 
1
--}

{--5. Definı nuevamente la funcion paratodo, pero esta vez usando la funcion paratodo' (sin
recursion ni an ́alisis por casos!).
--}

paratodo'' :: [Bool]->Bool
paratodo'' xs = paratodo' xs (==True)  --aca nuestro t va a ser igual a (==True)

{--
6. Utilizando las funciones del ejercicio 4, programa las siguientes funciones por composicion,
sin usar recursion ni analisis por casos.--}

{--a) todosPares :: [Int] -> Bool verifica que todos los numeros de una lista sean
pares.--}

--necesito una funcion auxiliar para ver si un numero es par.
esPar :: Int -> Bool
esPar x = x `mod` 2 == 0
todosPares :: [Int] -> Bool
todosPares xs = paratodo' xs esPar  --nuestro "t" es la funcion esPar.

{--ejemplo:
*Main> todosPares [1,2,3,34,45]
False
*Main> todosPares [2,2,2,34,42]
True
--}

{--b) hayMultiplo :: Int -> [Int] -> Bool verifica si existe algun numero dentro del
segundo parametro que sea m ́ultiplo del primer par ́ametro.--}

--necesito una funcion auxiliar para saber si algun numero es multiplo de otro.
esMultiplo :: Int -> Int -> Bool
esMultiplo x y = x `mod` y == 0

hayMultiplo :: Int -> [Int] -> Bool
hayMultiplo x xs = existe' xs (esMultiplo x)  --aca nuestro "t" es la funcion "esMultiplo x"

{--ejemplo:
*Main> hayMultiplo 10 [33,21,32]
False
*Main> hayMultiplo 10 [33,21,10]
True
--}


{--c) sumaCuadrados :: Int -> Int, dado un numero no negativo n, calcula la suma de
los primeros n cuadrados
Ayuda: En Haskell se puede escribir la lista que contiene el rango de numeros entre n
y m como [n..m].--}

--necesito una funcion auxiliar que me ayude a calcular el cuadrado de un numero.
elCuadrado :: Int -> Int
elCuadrado x = x*x

sumaCuadrados :: Int -> Int
sumaCuadrados n = sumatoria' [0..n] elCuadrado --lo que hace el rango [0..n] es ir recorriendo la lista de 0 hasta el numero
                                               -- que elegimos. y va sumando los cuadrados de cada uno

{--ejemplo:
*Main> sumaCuadrados 3
14
*Main> sumaCuadrados 2
5
*Main> sumaCuadrados 10
385
--}

{--d) Programar la fucion existeDivisor::Int-> [Int] -> Bool, que dado en entero n
y una lista ls , devuelve True si y solo si, existe algun elemento en ls que divida a na.--}

--necesito una funcion auxiliar que me diga si un numero es divisible por otro.
elDivisor :: Int -> Int -> Bool
elDivisor x y = x `mod` y == 0

existeDivisor::Int-> [Int] -> Bool
existeDivisor n xs = existe' xs (elDivisor n) --aca nuestro "t" es la funcion "elDivisor" 

{--ejemplo:
*Main> existeDivisor 2 [1,2,3,4,45]
True
*Main> existeDivisor 2 [17,23,3,43,45]
False
--}

{--e) Utilizando la funcion del apartado anterior, definı la funcion esPrimo:: Int -> Bool,
que dado un entero n, devuelve True si y solo si n es primo.
Ayuda: En Haskell se puede escribir la lista que contiene el rango de numeros entre n
y m como [n..m].--}

esPrimo :: Int -> Bool
esPrimo n = n>1 && not (existeDivisor n [2..(n-1)])

--necesitamos un n mayor que 1 y que no tenga divisores anteriores al numero n

{--ejemplo:
*Main> esPrimo 4
False
*Main> esPrimo 2
True
*Main> esPrimo 23243342
False
--}

{--f ) ¿Se te ocurre como redefinir factorial (ej. 2d) para evitar usar recursion?--}

factorial' :: Int -> Int
factorial' n = productoria' [1..n] id --uso la funcion "t" en este caso va a ser la funcion identidad


{--g) Programar la funcion multiplicaPrimos :: [Int] -> Int que calcula el producto
de todos los numeros primos de una lista.--}

--necesito una funcion que me de una lista de primos.
listaPrimos :: [Int] -> [Int]
listaPrimos [] = []
listaPrimos (x:xs) | esPrimo x = x:listaPrimos xs
                   | otherwise = listaPrimos xs

{--ejemplo:
*Main> listaPrimos [1,2,3,34,45]
[2,3]
*Main> listaPrimos [1,2,3,9,7,11,17]
[2,3,7,11,17]
--}

multiplicaPrimos :: [Int] -> Int
multiplicaPrimos xs = productoria' (listaPrimos xs) id --uso nuevamente la funcion identidad. 

{--ejemplo:
*Main> multiplicaPrimos [1,2,3,34,454]
6
*Main> multiplicaPrimos [1,2,3,17,5,3]
1530
*Main> multiplicaPrimos [1,4,6,8,9]
1
--}

{--h) Programar la funcion esFib :: Int -> Bool, que dado un entero n, devuelve True
si y s ́olo si n esta en la sucesion de Fibonacci.
Ayuda: Realizar una funcion auxiliar fib :: Int -> Int que dado un n devuelva el
n-esimo elemento de la sucesion.--}

fib :: Int -> Int
fib 0 = 0
fib 1 = 1
fib n = fib (n-1) + fib (n-2)

esFib :: Int -> Bool
esFib n = existe' [0..(n+1)] ((n==).fib)   --(n==).fib es una composición de funciones. Toma el resultado de fib y verifica si es igual a n

{--i) Utilizando la funcion del apartado anterior, definı la funcion todosFib :: [Int] -> Bool
que dada una lista xs de enteros, devuelva si todos los elementos de la lista pertenecen
(o no) a la sucesion de Fibonacci.--}

todosFib :: [Int] -> Bool
todosFib xs = paratodo' xs esFib --aca nuestro "t" es la fucnion esFib

{--ejemplo:
*Main> todosFib [1,2,23,23]
False
*Main> todosFib [1,2,5,8]
True
--}

--Ejercicio7
--map y filter
{--¿Que hacen estas funciones?
map agarra una funcion y aplica esa funcion a los elemntos de una lista, una vez hecho devuelve la lista con los cambios hechos
filter agarra un predicado y una lista, si se cumple entonces devuelve la lista con los elementos que cumplen el predicado. 
¿A que equivale la expresion map succ [1, -4, 6, 2, -8], donde succ n = n+1?
es equivalente a [2,-3,7,3,-7]
¿Y la expresion filter esPositivo [1, -4, 6, 2, -8]?
es equivalente a [1,6,2]
--}

{--8. Programa una funcion que dada una lista de numeros xs, devuelve la lista que resulta de
duplicar cada valor de xs.--}

{--a) Definila usando recursion.--}
duplica :: [Int] -> [Int]
duplica [] = []
duplica (x:xs) = (x*2):duplica xs

{--ejemplo:
*Main> duplica [1,2,3,4]
[2,4,6,8]
--}

{--b) Definila utilizando la funcion map.--}
--defino una funcion para usarla con map
duplica' :: Int -> Int
duplica' x = 2*x

duplicaConMap :: [Int] -> [Int]
duplicaConMap xs = map duplica' xs

{--ejemplo:
*Main> duplicaConMap [1,2,23,34,4]
[2,4,46,68,8]
--}

{--9. Programa una funcion que dada una lista de numeros xs, calcula una lista que tiene como
elementos aquellos numeros de xs que son primos.--}

--a) Definila usando recursion.
filtraPrimos :: [Int] -> [Int]
filtraPrimos [] = []
filtraPrimos (x:xs) | esPrimo x = x:filtraPrimos xs  --si se cumple que x es primo, entonces lo va a ir agregando a la lista 
                    | otherwise = filtraPrimos xs    -- en cualquier otro caso recorre la lista

{--ejemplo:
*Main> filtraPrimos [1,2,3,4,5,7,11,7]
[2,3,5,7,11,7]
*Main> filtraPrimos [1,2,3,4,5,56]
[2,3,5]
--}

--b) Definila utilizando la funcion filter.
filtraPrimosConfilter :: [Int] -> [Int]
filtraPrimosConfilter xs = filter esPrimo xs

{--ejemplo:
*Main> filtraPrimosConfilter [1,2,3,4,5,667,7,11]
[2,3,5,7,11]
--}

--c) Revissa tu definicion del ejercicio 6g. ¿Como podes mejorarla?
multiplicaPrimos' :: [Int] -> Int
multiplicaPrimos' xs = productoria (filtraPrimosConfilter xs) --calcula el producto de numeros primos filtrados.

{--10. La funcion primIgualesA toma un valor y una lista, y calcula el tramo inicial mas largo de
la lista cuyos elementos son iguales a ese valor. Por ejemplo:
primIgualesA 3 [3,3,4,1] = [3,3]
primIgualesA 3 [4,3,3,4,1] = []
primIgualesA 3 [] = []
primIgualesA 'a' "aaadaa" = "aaa"--}

--a) Programa primIgualesA por recursion.
primIgualesA ::Eq a =>  a -> [a] -> [a]
primIgualesA _ [] = []
primIgualesA a (x:xs) | a==x = a:primIgualesA a xs
                      | otherwise = []  --uso lista vacia para que no siga recorriendo la lista.

{--ejemplo:
*Main> primIgualesA 'a' "aaadaaa"
"aaa"
*Main> primIgualesA 3 [3,3,4,1]
[3,3]
--}

--b) Programa nuevamente la funcion utilizando takeWhile.
{--se usa takeWhile para tomar elementos de la lista mientras sean iguales a n. 
Cuando encuentra el primer elemento que no es igual a n, deja de tomar elementos y devuelve la porcion inicial de la lista que satisface la condicion.--}

primIgualesA' ::Eq a =>  a -> [a] -> [a]
primIgualesA' a xs = takeWhile (==a) xs

{--ejemplo:
*Main> primIgualesA' 3 [3,3,4,1]
[3,3]
*Main> primIgualesA' 'a' "aaadaaa"
"aaa"
--}

{--11. La funcion primIguales toma una lista y devuelve el mayor tramo inicial de la lista cuyos
elementos son todos iguales entre si. Por ejemplo:
primIguales [3,3,4,1] = [3,3]
primIguales [4,3,3,4,1] = [4]
primIguales [] = []
primIguales "aaadaa" = "aaa"--}

--a) Programa primIguales por recursion.
primIguales :: Eq a => [a]->[a]
primIguales [] = []
primIguales (x:xs) | x==(head xs) = x:primIguales xs --vamos comparando si el primer elento de la lista es igual al encabezado de la lista 
                   | otherwise = [x]                --en cualquier otro caso devuelve el primer elemento de la lista.

{--ejemplo:
*Main> primIguales [3,3,4,1]
[3,3]
*Main> primIguales []
[]
*Main> primIguales "aaadaaa"
"aaa"
--}

--b) Usa cualquier version de primIgualesA para programar primIguales. Esta permitido dividir en casos, pero no usar recursion.
primIguales' :: Eq a => [a]->[a]
primIguales' (x:xs) = x:primIgualesA' x xs 

--construye una nueva lista concatenando el primer elemento (x) con la llamada a la función auxiliar primIgualesA' x xs

{--
*Main> primIguales' [1,1,1,2,3,2]
[1,1,1]
*Main> primIguales' [1,2,1,2,3,2]
[1]
--}



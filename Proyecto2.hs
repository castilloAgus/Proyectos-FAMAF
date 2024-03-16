--EJERCICIO 2.
--1
--a) Implementa el tipo Carrera como esta definido arriba.
data Carrera = Matematica | Fisica | Computacion | Astronomia deriving (Eq,Ord,Show)

{--b) Definı la siguiente funcion, usando pattern matching : titulo :: Carrera -> String
que devuelve el nombre completo de la carrera en forma de string. Por ejemplo, para el
constructor Matematica, debe devolver ”Licenciatura en Matematica”.--}
titulo :: Carrera -> String
titulo Matematica = "Licenciatura en Matematica"
titulo Fisica = "Licenciatura en Fisica"
titulo Computacion = "Licenciatura en Ciencias de la Computacion"
titulo Astronomia = "Licenciatura en Astronomia"

{--ejemplo:
*Main> titulo Fisica
"Licenciatura en Fisica"
*Main> titulo Computacion
"Licenciatura en Ciencias de la Computacion"
--}

{--c) Para escribir musica se utiliza la denominada notacion musical, la cual consta de
notas (do, re, mi, ...). Ademas, estas notas pueden presentar algun modificador 
(sostenido) o  (bemol), por ejemplo do sostenido, si bemol, etc. Por ahora nos vamos a olvidar de
estos modificadores (llamados alteraciones) y vamos a representar las notas basicas.
Definir el tipo NotaBasica con constructores Do, Re, Mi, Fa, Sol, La y Si--}
data NotaBasica = Do | Re | Mi | Fa | Sol | La | Si deriving (Eq,Ord,Show)

{--d) El sistema de notacion musical anglosajon, tambien conocido como notacion o cifrado
americano, relaciona las notas basicas con letras de la A a la G. Este sistema se usa por
ejemplo para las tablaturas de guitarra. 
--}
cifradoAmericano :: NotaBasica -> Char
cifradoAmericano Do = 'C'
cifradoAmericano Re = 'D'
cifradoAmericano Mi = 'E'
cifradoAmericano Fa = 'F'
cifradoAmericano Sol = 'G'
cifradoAmericano La = 'A'
cifradoAmericano Si = 'B'

{--ejemplo:
*Main> cifradoAmericano Do
'C'
*Main> cifradoAmericano Si
'B'
--}

--2
{--a) Completar la definicion del tipo NotaBasica para que las expresiones
*Main> Do <= Re
*Main> Fa `min` Sol--}

{--*Main> Do <= Re
True
*Main> Fa `min` Sol
Fa
--}

--3. Polimorfismo ad hoc
{-a) Definir usando polimorfismo ad hoc la funcion minimoElemento que calcula (de manera
recursiva) cual es el menor valor de una lista de tipo [a]. Asegurarse que solo este
definida para listas no vacias.--}
minimoElemento :: Ord a => [a] -> a 
minimoElemento [] = error "no esta definida"
minimoElemento [x] = x
minimoElemento (x:xs)| x>=(minimoElemento xs) = minimoElemento xs  --va recorriendo la lista de elementos y se va fijando cual es el minimo
                     |otherwise = x

{--ejemplo:
*Main> minimoElemento [3,2,1,3]
1
*Main> minimoElemento [3,2,1,3,(-1)]
-1
--}

{--b) Definir la funcion minimoElemento de manera tal que el caso base de la recursion
sea el de la lista vacia. Para ello revisar la clase Bounded.
Ayuda: Para probar esta funcion dentro de ghci con listas vacias, indicar el tipo concreto con tipos de la clase Bounded,
por ejemplo: ([1,5,10]::[Int]), ([]::[Bool]),etc.--}
minimoElemento' :: (Ord a, Bounded a) => [a] -> a  --la restricción Bounded a significa que el tipo de elemento debe tener un valor minimo (definido por minBound).
minimoElemento' [] = minBound --nos va a dar el minimo posible.
minimoElemento' [x] = x
minimoElemento' (x:xs) = min x  (minimoElemento' xs)

{--ejemplo:
*Main> minimoElemento' ([23,3,2,1,2]::[Int])
1
*Main> minimoElemento' ([23,3]::[Int])
3
--}

--c) Usar la funcion minimoElemento para determinar la nota mas grave de la melodia: [Fa, La, Sol, Re, Fa]
{--ejemplo:
*Main> minimoElemento [Fa, La, Sol, Re, Fa]
Re--}

--4. Sinonimo de tipos; constructores con parametros. 

--a) Implementa el tipo Deportista y todos sus tipos accesorios (NumCamiseta, Altura, Zona, etc) tal como est´an definidos arriba.
-- Sinonimos de tipo
type Altura = Int
type NumCamiseta = Int
-- Tipos algebraicos sin parametros (aka enumerados)
data Zona = Arco | Defensa | Mediocampo | Delantera deriving (Show,Eq)
data TipoReves = DosManos | UnaMano deriving (Show,Eq)
data Modalidad = Carretera | Pista | Monte | BMX deriving (Show,Eq)
data PiernaHabil = Izquierda | Derecha deriving (Show,Eq)
--- Sinonimo
type ManoHabil = PiernaHabil

-- Deportista es un tipo algebraico con constructores parametricos
data Deportista =   Ajedrecista -- Constructor sin argumentos
                  | Ciclista Modalidad -- Constructor con un argumento
                  | Velocista Altura -- Constructor con un argumento
                  | Tenista TipoReves ManoHabil Altura -- Constructor con tres argumentos
                  | Futbolista Zona NumCamiseta PiernaHabil Altura -- Constructor con
                  deriving (Show,Eq)
--b) ¿Cual es el tipo del constructor Ciclista?
{--*Main> :t Ciclista
Ciclista :: Modalidad -> Deportista--}

{--c) Programa la funcion contar_velocistas :: [Deportista] -> Int que dada una
lista de deportistas xs, devuelve la cantidad de velocistas que hay dentro de xs.
Programar contar_velocistas sin usar igualdad, utilizando pattern matching.--}
contar_velocistas :: [Deportista] -> Int
contar_velocistas [] = 0
contar_velocistas (Velocista a:xs) = 1+contar_velocistas xs 
contar_velocistas (_:xs) = contar_velocistas xs

{--ejemplo:
*Main> contar_velocistas [Velocista 2, Ajedrecista, Ajedrecista]
1
*Main> contar_velocistas [Ajedrecista, Ajedrecista, Ajedrecista]
0
--}

{--d) Programa la funcion contar_futbolistas :: [Deportista] -> Zona -> Int que
dada una lista de deportistas xs, y una zona z, devuelve la cantidad de futbolistas
incluidos en xs que juegan en la zona z. No usar igualdad, solo pattern matching.--}
contar_futbolistas :: [Deportista] -> Zona -> Int
contar_futbolistas [] _ = 0
contar_futbolistas (Futbolista Arco _ _ _:xs) Arco = 1+contar_futbolistas xs Arco 
contar_futbolistas (Futbolista Defensa _ _ _:xs) Defensa = 1+contar_futbolistas xs Defensa
contar_futbolistas (Futbolista Mediocampo _ _ _:xs) Mediocampo = 1+contar_futbolistas xs Mediocampo
contar_futbolistas (Futbolista Delantera _ _ _:xs) Delantera = 1+contar_futbolistas xs Delantera
contar_futbolistas (_:xs) z = contar_futbolistas xs z

{--ejemplo
*Main> contar_futbolistas [Futbolista Arco 21 Derecha 21, Ajedrecista] Arco
1
*Main> contar_futbolistas [Futbolista Arco 21 Derecha 21, Ajedrecista,Futbolista Arco 32 Derecha 2] Arco
2
--}

--e) ¿La funcion anterior usa filter? Si no es ası, reprogramala para usarla.
--necesito una funcnion que me calcule si dos zonas son iguales.
mismaZona :: Zona -> Deportista -> Bool
mismaZona Arco (Futbolista Arco _ _ _) = True
mismaZona Defensa (Futbolista Defensa _ _ _) = True
mismaZona Mediocampo (Futbolista Mediocampo _ _ _) = True
mismaZona Delantera (Futbolista Mediocampo _ _ _) = True
mismaZona _ _ = False

contar_futConFilter :: [Deportista] -> Zona -> Int
contar_futConFilter (Futbolista z _ _ _:xs) zna = length (filter (mismaZona zna) xs) --uso el length para contar cuantas veces se cumple el predicado.

{--ejemplo:
*Main> contar_futConFilter [(Futbolista Mediocampo 3 Derecha 150), (Futbolista Arco 1 Izquierda 140), (Futbolista Delantera 10 Izquierda 160), (Futbolista Arco 23 Derecha 180)] Arco 
2
*Main> contar_futConFilter [(Futbolista Mediocampo 3 Derecha 150), (Futbolista Arco 1 Izquierda 140), (Futbolista Delantera 10 Izquierda 160), (Futbolista Arco 23 Derecha 180)] Mediocampo 
0
--}

--5. Definici´on de clases.

--a) Implementa la funcion sonidoNatural como esta definida arriba.
sonidoNatural :: NotaBasica -> Int
sonidoNatural Do = 0
sonidoNatural Re = 2
sonidoNatural Mi = 4
sonidoNatural Fa = 5
sonidoNatural Sol = 7
sonidoNatural La = 9
sonidoNatural Si = 11

--b) Definir el tipo enumerado Alteracion que consta de los constructores Bemol, Natural y Sostenido.
data Alteracion = Bemol | Natural | Sostenido

{--c) Definir el tipo algebraico NotaMusical que debe tener un solo un constructor que llamaremos Nota el cual toma dos parametros. El primer parametro es de tipo NotaBasica
y el segundo de tipo Alteracion. De esta manera cuando se quiera representar una nota alterada se puede usar como segundo parametro del constructor un Bemol o Sostenido y si se quiere representar
una nota sin alteraciones se usa Natural como segundo parametro.--}
data NotaMusical = Nota NotaBasica Alteracion

{--d) Defini la funcion sonidoCromatico :: NotaMusical -> Int que devuelve el sonido
de una nota, incrementando en uno su valor si tiene la alteracion Sostenido, decrementando en uno si tiene la alteracion Bemol y dejando su valor intacto si la alteracion es Natural--}
sonidoCromatico :: NotaMusical -> Int
sonidoCromatico (Nota n Bemol) = sonidoNatural n-1
sonidoCromatico (Nota n Sostenido) = sonidoNatural n+1
sonidoCromatico (Nota n Natural) = sonidoNatural n

{--ejemplo:
*Main> sonidoCromatico (Nota Do Natural)
0
*Main> sonidoCromatico (Nota Re Sostenido)
3
*Main> sonidoCromatico (Nota Re Bemol)
1
--}

{--e) Inclui el tipo NotaMusical a la clase Eq de manera tal que dos notas que tengan el
mismo valor de sonidoCromatico se consideren iguales.--}
instance Eq NotaMusical where
    (Nota n a) == (Nota n2 a2) = sonidoCromatico (Nota n a) == sonidoCromatico (Nota n2 a2)

{--ejemplo:
*Main> Nota Do Bemol == Nota Re Sostenido
False
*Main> Nota Mi Bemol == Nota Re Sostenido
True
--}
{--f) Inclui el tipo NotaMusical a la clase Ord definiendo el operador <=. Se debe definir
que una nota es menor o igual a otra si y solo si el valor de sonidoCromatico para la primera es menor o igual al valor de sonidoCromatico para la segunda.--}
instance Ord NotaMusical where
    (Nota n a) <= (Nota n2 a2) = sonidoCromatico (Nota n a) <= sonidoCromatico (Nota n2 a2)

{--ejemplo:
*Main> Nota Mi Bemol <= Nota Re Sostenido
True
*Main> Nota Do Bemol >= Nota Re Sostenido
False
--}

--6. Tipos enumerados con polimorfismo.
--a) Definir la funcion primerElemento que devuelve el primer elemento de una lista no vacia, o Nothing si la lista es vacia.
primerElemento :: [a] -> Maybe a
primerElemento [] = Nothing
primerElemento xs = Just (head xs)

{--ejemplo:
*Main> primerElemento [1,2,3]
Just 1
*Main> primerElemento "hola"
Just 'h'
--}

--7. Tipos recursivos.
data Cola = VaciaC | Encolada Deportista Cola deriving Show

--a) Programa las siguientes funciones:
{--1) atender :: Cola -> Maybe Cola, que elimina de la cola a la persona que esta en la primer posicion de una cola,
por haber sido atendida. Si la cola esta vacia, devuelve Nothing.--}
atender :: Cola -> Maybe Cola
atender VaciaC = Nothing
atender (Encolada d VaciaC) = Nothing
atender (Encolada d (Encolada d2 c)) = Just (Encolada d2 c) 

{--ejemplo:
Just (Encolada Ajedrecista VaciaC)
*Main> atender (Encolada Ajedrecista VaciaC)
Nothing
--}

--2) encolar :: Deportista -> Cola -> Cola, que agrega una persona a una cola de deportistas, en la ultima posicion.
encolar :: Deportista -> Cola -> Cola
encolar d VaciaC = (Encolada d VaciaC)
encolar d (Encolada d2 v) = (Encolada d2 (encolar d VaciaC))  --uso la funcion encolar de forma recursiva para que agregue un derpotista al final de la cola en caso que la cola este vacia.
{--ejemplo:
*Main> encolar (Ciclista Pista) (Encolada Ajedrecista VaciaC)
Encolada Ajedrecista (Encolada (Ciclista Pista) VaciaC)
*Main> encolar Ajedrecista VaciaC
Encolada Ajedrecista VaciaC
--}

{--3) busca :: Cola -> Zona -> Maybe Deportista, que devuelve el/la primera futbolista dentro de la cola que 
juega en la zona que se corresponde con el segundo parametro. Si no hay futbolistas jugando en esa zona devuelve Nothing.--}
busca :: Cola -> Zona -> Maybe Deportista
busca VaciaC _ = Nothing
busca (Encolada (Futbolista z n p a) v) zna | z==zna = Just (Futbolista z n p a) 
                                            | otherwise = busca v zna
busca (Encolada _ v) zna = busca v zna

{--ejemplo:
*Main> busca (Encolada (Futbolista Arco 2 Derecha 2) (Encolada (Futbolista Defensa 3 Derecha 2) VaciaC)) Arco
Just (Futbolista Arco 2 Derecha 2)
*Main> busca VaciaC Arco
Nothing
*Main> busca (Encolada (Futbolista Arco 2 Derecha 2) VaciaC) Arco
Just (Futbolista Arco 2 Derecha 2)
--}

--b) ¿A que otro tipo se parece Cola?.
--el tipo cola se parece a una funcion recursiva de listas

--8. Tipos recursivos y polimorficos.

data ListaAsoc a b = Vacia | Nodo a b (ListaAsoc a b) deriving Show

--a) ¿Como se debe instanciar el tipo ListaAsoc para representar la informacion almacenada en una guia telefonica?
type GuiaTelefonica = ListaAsoc String Int
--donde String representa el nomre de la persona e Int el numero de telefono.

--b) Programa las siguientes funciones:
--1) la_long :: ListaAsoc a b -> Int que devuelve la cantidad de datos en una lista.
la_long :: ListaAsoc a b -> Int
la_long Vacia = 0
la_long (Nodo a b l) = 1+la_long l  --va contando la cantidad de veces aparece "l" que es nuestra variable recursiva

{--ejemplo:
*Main> la_long Vacia
0
*Main> la_long (Nodo 12 12 (Nodo 3 2 Vacia))
2
--}

--2) la_concat :: ListaAsoc a b -> ListaAsoc a b -> ListaAsoc a b, que de vuelve la concatenacion de dos listas de asociaciones.
la_concat :: ListaAsoc a b -> ListaAsoc a b -> ListaAsoc a b
la_concat Vacia Vacia = Vacia
la_concat (Nodo a b lv) Vacia = (Nodo a b lv)
la_concat Vacia (Nodo a b lv) = (Nodo a b lv)
la_concat (Nodo a b lv) (Nodo a1 b2 lv2) = (Nodo a b (la_concat lv (Nodo a1 b2 lv2))) --lo que hago es agregar la funcion recursiva en donde iria lv "lista vacia" 

{--ejemplo:
*Main> la_concat (Nodo 2 1 (Nodo 2 1 Vacia)) (Nodo 3 12 Vacia)
Nodo 2 1 (Nodo 2 1 (Nodo 3 12 Vacia))
*Main> la_concat (Nodo 2 1 Vacia) Vacia
Nodo 2 1 Vacia
--}

{--3) la_agregar :: Eq a => ListaAsoc a b -> a -> b -> ListaAsoc a b, que
agrega un nodo a la lista de asociaciones si la clave no esta en la lista, o actualiza el valor si la clave ya se encontraba.--}
la_agregar :: Eq a => ListaAsoc a b -> a -> b -> ListaAsoc a b
la_agregar Vacia a b = (Nodo a b Vacia)
la_agregar (Nodo a1 b1 lv) a2 b2 | a1/=a2 = (Nodo a1 b1 (la_agregar lv a2 b2)) --agrego en donde iba la lista vacia la funcion de manera recursiva.
                                 | otherwise = (Nodo a1 b2 lv) --si son iguales la clave va a ser la misma pero b1 cambia por el valor de b2

{--ejemplo:
*Main> la_agregar (Nodo 12 11 Vacia) 12 32
Nodo 12 32 Vacia
*Main> la_agregar (Nodo 12 11 (Nodo 23 3 Vacia)) 12 32
Nodo 12 32 (Nodo 23 3 Vacia)
--}

{--4) la_pares :: ListaAsoc a b -> [(a, b)] que transforma una lista de asociaciones en una lista de pares clave-dato.--}
la_pares :: ListaAsoc a b -> [(a, b)]
la_pares Vacia = []
la_pares (Nodo a b lv) = (a,b):la_pares lv

{--ejemplo:
*Main> la_pares (Nodo 12 "hola" (Nodo 2 "chau" Vacia))
[(12,"hola"),(2,"chau")]
*Main> la_pares Vacia
[]
--}

{--5) la_busca :: Eq a => ListaAsoc a b -> a -> Maybe b que dada una lista
y una clave devuelve el dato asociado, si es que existe. En caso contrario devuelve Nothing.--}
la_busca :: Eq a => ListaAsoc a b -> a -> Maybe b
la_busca Vacia _ = Nothing
la_busca (Nodo a1 b lv) a2 | a1==a2 = Just b  --si las claves son iguales nos devuelve el dato
                           | otherwise = la_busca lv a2  --en cualquier otro caso sigue buscando en la funcion.

{--ejemplo:
*Main> la_busca Vacia 12
Nothing
*Main> la_busca (Nodo 12 2 (Nodo 32 23 Vacia)) 12
Just 2
*Main> la_busca (Nodo 12 2 (Nodo 32 23 Vacia)) 32
Just 23
--}

--6) la_borrar :: Eq a => a -> ListaAsoc a b -> ListaAsoc a b que dada una clave a elimina la entrada en la lista.
la_borrar :: Eq a => a -> ListaAsoc a b -> ListaAsoc a b
la_borrar a Vacia = Vacia
la_borrar a1 (Nodo a2 b2 lv) | a1==a2 = lv
                             | otherwise = (Nodo a2 b2 (la_borrar a1 lv))

{--ejemplo:
*Main> la_borrar 21 (Nodo 2 3 (Nodo 21 4 Vacia))
Nodo 2 3 Vacia
*Main> la_borrar 213 (Nodo 2 3 (Nodo 21 4 (Nodo 213 31 Vacia)))
Nodo 2 3 (Nodo 21 4 Vacia)
--}

--9. (Punto *)
data Arbol a = Hoja | Rama (Arbol a) a (Arbol a) deriving (Show,Eq)

type Prefijos = Arbol String

can , cana , canario , canas , cant , cantar , canto :: Prefijos
can = Rama cana "can" cant
cana = Rama canario "a" canas
canario = Rama Hoja "rio" Hoja
canas = Rama Hoja "s" Hoja
cant = Rama cantar "t" canto
cantar = Rama Hoja "ar" Hoja
canto = Rama Hoja "o" Hoja

--a) a_long :: Arbol a -> Int que dado un arbol devuelve la cantidad de datos almacenados.
a_long :: Arbol a -> Int
a_long Hoja = 0
a_long (Rama a1 a2 h) = 1+a_long h

{--ejemplo:
*Main> a_long (Rama (Rama Hoja 23 Hoja) 4 Hoja)
1
*Main> a_long (Rama (Rama Hoja 23 Hoja) 4 (Rama (Rama Hoja 42 Hoja) 323 Hoja))
2
--}

--b) a_hojas :: Arbol a -> Int que dado un arbol devuelve la cantidad de hojas.
a_hojas :: Arbol a -> Int
a_hojas Hoja = 1
a_hojas (Rama a1 a2 h) | (a1==Hoja && h==Hoja) = 2+a_hojas h
--c) a_inc :: Num a => Arbol a -> Arbol a que dado un arbol que contiene numeros, los incrementa en uno.
{--d) a_map :: (a -> b) -> Arbol a -> Arbol b que dada una funcion y un arbol,
devuelve el arbol con la misma estructura, que resulta de aplicar la funcion a cada uno
de los elementos del arbol. Revisa la definicion de la funcion anterior y reprogramala
usando a_map--}

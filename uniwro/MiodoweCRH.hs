module Miodowe (Komorka, Plansza, Generator, Zadanie(..),
                naPlanszy, plansza, rozwiaz) where

import Monad
import List

type Generator a = [a]

type Komorka = (Int,Int)
type Plansza = [Komorka]
data Zadanie = Zadanie {
        rozmiar :: Int,
        liczbaWysp :: Int,
        wielkoscWysp :: Int,
        czarne :: Plansza
     }
type Plansza2 = (Plansza, Plansza)

naPlanszy :: Int -> Komorka -> Bool
naPlanszy rozmiar (x,y) =
   abs y <= rozmiar && abs x + abs y <= 2 * rozmiar

sasiad :: Komorka -> Generator Komorka
sasiad (x,y) = [ (x+dx,y+dy) | dy <- [-1..1],
                               let adx = 2 - abs dy,
                               dx <- [-adx, adx] ]

plansza :: Int -> Plansza
plansza rozmiar = [(x,y) | x <- [-2 * rozmiar .. 2 * rozmiar],
                           y <- [-rozmiar .. rozmiar],
                           (x `mod` 2 == 0) == (y `mod` 2 == 0),
                           naPlanszy rozmiar (x,y)]

{-
 - Lukasz Sliwa, 2008-03-30 19:21:32
 -
 - Program dziala w nastepujacy sposob:
 - 	1. Generuje pewne wyspy wraz z ich otoczkami, by usunac powtorzenia
 - 		caly czas zapamietuje, ktore komorki sa juz w wyspie, a ktore jeszcze nie.
 - 		Cala idea polega na tym, ze alko komorka jest w wyspie, albo jej nie ma
 - 		(czyli jest czarnym polem).
 - 	2. Generuje pewna liczbe wysp - generowanie wysp odbywa sie wtedy, gdy da
 - 		sie z zrobic wyspy - bo po co szukac rozwiazan, jesli jestesmy w stanie
 - 		wyliczyc, ze np. zabraknie bialych pol dla ostatniej wyspy?
 - 	3. Generowanie kolejnych wysp odbywa sie na bierzaca, czyli jesli mam jedna wyspe
 - 		w rozwiazaniu, to szukam do niej drugiej pasujacej, a potem trzeciej
 - 		itd. az do n-tej
 - 	4. Gdy liczba k-elementowych wysp wynosi n to wypisuje rozwiazanie i szukam dalej,
 - 		ale nie analizuje juz tych wysp, ktore byly w rozwiazaniu (przez
 - 		to oszczedzam czas)
 - 
 - Program dziala nastepujaca na 'gentoo linux' Intel Celeron 2.66GHz, 512MB ram:
 -
 - przyklad1.txt - 1 min 48 s
 - przyklad2.txt - 26s
 - przyklad3.txt - 0.59s
 - 
 - Przy rozwiazaniu korzystalem z Monad i MonadPlus. Kod nie jest długi, ale ma sporo komentarzy
 - i odstepow miedzy wierszami dla lepszej czytelnosci.
 -
 -}

sasiaduja :: Komorka -> Komorka -> Bool
sasiaduja (a,b) (x,y) = 2 - abs (a - x) == abs (b - y) && a /= x

bialePola :: Int -> Plansza -> Plansza
bialePola rozmiar czarne = (plansza rozmiar) \\ czarne

{- ruszajMalyWojowniku zawiera jedno rozwiazanie zadania,
 - kolejne sa generowane jest istnieja -}
rozwiaz :: Zadanie -> Generator Plansza
rozwiaz (Zadanie rozmiar liczbaWysp wielkoscWysp czarne) = 
	(do
		ruszajMalyWojowniku <- zbiorWysp liczbaWysp wielkoscWysp (bialePola rozmiar czarne)
		return ( ((bialePola rozmiar czarne)  ++ czarne) \\ ruszajMalyWojowniku) 
	)

czyDaSie :: Plansza -> Int -> Int -> Bool
czyDaSie dostepnePola liczbaWysp wielkoscWysp = 
	length dostepnePola >= liczbaWysp * wielkoscWysp - 1

{- generuje otoczke biorac pole i sprawdzajac, czy jakies
 - z podanej listy sasiaduja z nim - zwraca liste -}
generujOtoczke :: Plansza -> Plansza
generujOtoczke (pole:dostepne) = [e | e <- dostepne, sasiaduja e pole]

{- funkcja generuje kolejne wyspy, a wlasciwie to cala kraine wysp :) -}
zbiorWysp :: Int -> Int -> Plansza -> Generator Plansza
zbiorWysp 0 _ _ = return [] -- gdy liczbaWysp = 0 to zwraca pusta liste
zbiorWysp liczba wielkosc t@(pole:dostepne) = 
	zbiorWysp liczba wielkosc dostepne  -- rekurenycjnie po reszcie rozwiazan
		`mplus`
	(do
		guard (czyDaSie dostepne liczba wielkosc) -- jesli da sie jeszcze cos wygenerowac to guard zwraca True
		wyspa <- nowa (wielkosc-1) dostepne ([pole], generujOtoczke t)
		xs <- zbiorWysp (liczba-1) wielkosc (dostepne \\ (fst wyspa ++ [pol | element <- fst wyspa, pol <- sasiad element]))
		return (fst wyspa ++ xs)
	)
zbiorWysp _ _ _ = mzero

{- funkcja 'nieJestWOtoczce' sprawdza czy komorka nie jest w otoczce
 - przy pomocy 'elem' -}
nieJestWOtoczce :: Komorka -> Plansza -> Bool
nieJestWOtoczce e otoczkaa = (e `elem` otoczkaa) == False

{- generuje plansze z nowymi wolnymi polami przy otoczce -}
wolnePola :: Plansza -> Komorka -> Plansza -> Plansza
wolnePola dostepne pole otoczka = dostepne \\ (pole : takeWhile (/= pole) otoczka)

{- kazda zmiana w wyspie powoduje utworzenie nowej otoczki,
 - funkcja 'nowaOtoczka' zapewnia tworzenie nowychOtoczek -}
nowaOtoczka :: Komorka -> Plansza -> Plansza -> Plansza
nowaOtoczka p otoczka wolne = 
	(dropWhile (/= p) otoczka \\ [p])
		`mplus` 
	(do 
		e <- wolne
		guard(sasiaduja e p && nieJestWOtoczce e otoczka) -- guard sprawdza e sasiaduje z p i czy czasem nie sa w otoczce
							       -- jesli nie jest w otoczce to mozemy wrzucic
		return e
	)

nowa :: Int -> Plansza -> Plansza2 -> Generator Plansza2
nowa 0 _ wyspa = return wyspa
nowa wielkoscWyspy dostepne (xs, otoczka) = 
	(do
		komorka <- otoczka
		let w = wolnePola dostepne komorka otoczka
		ys <- nowa (wielkoscWyspy-1) w (komorka:xs, nowaOtoczka komorka otoczka w)
		return ys
	)

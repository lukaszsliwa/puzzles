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
type Para = (Plansza, Plansza)

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

--zwraca prawdy, gdy dwie komorki sa sasiadami
sasiady :: Komorka -> Komorka -> Bool
sasiady (a,b) (x,y) = a /= x && 2 - abs(a-x) == abs(b-y)


--generuje rozwiazania
rozwiaz :: Zadanie -> Generator Plansza
rozwiaz (Zadanie rozmiar liczbaWysp wielkoscWysp czarne) = do
	rozwiazanie <- wyspy liczbaWysp wielkoscWysp dost
	return ( (dost  ++ czarne) \\ rozwiazanie ) 
		where
			dost = (plansza rozmiar) \\ czarne

-- tworzy otoczke
otoczka :: Komorka -> Plansza -> Plansza
otoczka komorka wolne = [e | e <- wolne, sasiady e komorka]

-- sprawdza, czy oplaca sie dalej szukac wysp
sprawdz :: Int -> Int -> Int -> Bool
sprawdz wolne li wie =  wolne >= li * wie - 1

-- generuje wyspy
wyspy :: Int -> Int -> Plansza -> Generator Plansza
wyspy 0 _ _ = return []
wyspy liczbaWysp wielkoscWysp (pole:wolne) = 
	wyspy liczbaWysp wielkoscWysp wolne 
		++ 
	(do
		guard( sprawdz (length wolne) liczbaWysp  wielkoscWysp )
		wyspa <- nowa (wielkoscWysp-1) wolne ([pole], otoczka pole wolne)
		reszta <- wyspy (liczbaWysp-1) wielkoscWysp ( wolne \\ (fst wyspa ++ [p | el <- fst wyspa, p <- sasiad el]) )
		return (fst wyspa ++ reszta) 
	)
wyspy _ _ _ = mzero

-- sprawdza, czy komorka jest w otoczce
jestwotoczce :: Komorka -> Plansza -> Bool
jestwotoczce e kolo = e `elem` kolo

-- robi otoczki
otoczkuj :: Komorka -> Plansza -> Plansza -> Plansza
otoczkuj pole otoczka d = 
	(dropWhile (/= pole) otoczka \\ [pole]) 
		++ 
	[e | e <- d, sasiady e pole, not (jestwotoczce e otoczka)]

-- robi nowa wyspe
nowa :: Int -> Plansza -> Para -> Generator Para
nowa 0 _ wyspa = return wyspa
nowa wielkosc dostepne (m, o) = 
	(do
		pole <- o
		let d = dostepne \\ (pole : takeWhile (/= pole) o)
		nast <- nowa (wielkosc-1) d (pole:m, otoczkuj pole o d)
		return nast
	)

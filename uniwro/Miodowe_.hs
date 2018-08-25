module Miodowe (Komorka, Plansza, Generator, Zadanie(..),
                naPlanszy, plansza, rozwiaz) where

import List
import Monad

type Generator a = [a]

type Komorka = (Int,Int)
type Plansza = [Komorka]
data Zadanie = Zadanie {
        rozmiar :: Int,
        liczbaWysp :: Int,
        wielkoscWysp :: Int,
        czarne :: Plansza
     }

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

wyspy :: Zadanie -> Generator Plansza
wyspy (Zadanie rozmiar liczbaWysp wielkoscWysp czarne) =
	 wyspy' $ plansza rozmiar \\ czarne where
		wyspy' [] = []
		wyspy' (pole:plansza) = wysepka ++ (wyspy' plansza \\ wysepka) where
			wysepka = wyspa pole wielkoscWysp []
			wyspa (x,y) n pola = 
				if n == 0
					then 
						if length pola == wielkoscWysp
							then sort (pola : [])
							else []
						else
							licz (filter (naPlanszy rozmiar) ((sasiad (x,y) \\ czarne) \\ pola)) where
								licz [] = []
								licz (x:xs) = wyspa x (n-1) (x:pola) ++ licz xs

rozwiaz :: Zadanie -> Generator Plansza
rozwiaz zadanie@(Zadanie rozmiar liczbaWysp wielkoscWysp czarne) = wyspy zadanie



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
{-
 - Lukasz Sliwa, 2008-03-25, 14:43:44
 -
 - rozwiazanie dziala zbyt dlugo dla testow Pana Wierzbickiego,
 - ale dobrze radzi sobie z mniejszymi testami
 -
 - program mozna podzielic na kilka etapow:
 - 1. Generowanie wszystkich wysp na podanej planszy, bez duplikatow - aby usuwac
 - 	dublujace sie komorki, skorzystalem z wlasnosci DFS'a, czyli zapamietauje
 - 	te wierzcholki, ktore zostaly odwiedzone juz w liscie 'bylo' :)
 - 	i analizuje te, ktore jeszcze nie zostaly odwiedzone.
 -
 - 	za operacje generacji wysp odpowiedzialne sa funkcje: rozwiaz', wyspy, iteruj
 -
 - 2. Laczenie wysepek po k, gdzie k to liczba wysp w rozwiazaniu. Przy okazji laczenia
 - 	sprawdzam, czy w ogole dwie wyspy, ktore chcemy wrzucic do rozwiazania, maja wspolne
 - 	komorki lub sa sasiadami. Jesli nadaja sie do rozwiazania to je dodaje i szukam kolejnych
 - 	wysp tak by plansza miala tyle wysp ile chcemy, czyli 'liczbaWysp' 
	
 -	Program jest krotki, tylko ma sporo komentarzy. Chcialem uniknac sytuacji,
 -	w ktorej sprawdzajacy nie bedzie mogl sie doczytac, a komentarze
 -	usprawniaja czytanie rozwiazania :)
 -}



{- funkcja 'otoczkaZWyspy' tworzy otoczke komorek, ktore leza na planszy, wraz z komorkami
 - wokol, ktorych zostala utworzona;
 - do generowania uzywana jest funkcja 'union', ktore powoduje, ze wierzcholki w otoczce nie
 - dubluja sie,
 - filter "odsiewa" te komorki, ktore sa poza plansza :) -}
otoczkaZWyspa :: Plansza -> Int -> Plansza
otoczkaZWyspa [] _ = mzero
otoczkaZWyspa (w:wyspa) rozmiar = filter (naPlanszy rozmiar) (w : sasiad w) `union` otoczkaZWyspa wyspa rozmiar

rozwiaz :: Zadanie -> Generator Plansza
rozwiaz (Zadanie rozmiar liczbaWysp wielkoscWysp czarne) = generuj (rozwiaz' (plansza rozmiar \\ czarne) czarne) [] liczbaWysp where
	{- funkcja 'rozwiaz'' tworzy liste wszystkich mozliwych wysp na planszy
	 -
	 - wywoluje rekurencyjnie makro 'wyspa', ktore jest generatorem plansz 
	 -
	 -}
	rozwiaz' [] _ = mzero
	rozwiaz' (x:xs) bylo = wyspa ++ rozwiaz' xs  [] where 
		wyspa :: Generator Plansza
		wyspa = (wyspy [x] (wielkoscWysp - 1) bylo)  where
			{- funkcja 'wyspy' tworzy generator plansz ze wszystkimi wyspami -}
			wyspy :: Plansza -> Int -> Plansza -> Generator Plansza
			wyspy [] _ _ = mzero
			wyspy t@((a,b):pola) n bylo -- 't' jest zbiorem komorek na wyspie, ktore aktualnie posiadamy
						    -- 'n' to niedomiar komorek (jesli 'n == 0' to znaczy, 
						    -- 			ze wyspa ma tyle komorek ile chcemy)
						    -- 'bylo' to zbior komorek, ktore przeanalizowalismy juz
						    --
				| n == 0 = return (t) -- gdy 'n == 0' to zwraca komorki, ktore sa w wyspie
				| otherwise = iteruj p ((a,b):bylo) where -- w przeciwnym razie iteruje po sasiadach
						{- 'p' jest generuje sasiadow komorki (a,b), ktorych nie bylo w odwiedzonych
						 - oraz, ktorzy sa na planszy 
						 - wykorzystuje do tego 'filter' -}
						p :: Plansza
						p = filter (naPlanszy rozmiar) (sasiad (a,b) \\ bylo)
						
						{- funkcja 'iteruj' przechodzi sobie po kolejnych sasiadach
						 - wywolujac dla kazdego funkcje 'wyspy' (wiersz 55)
						 - i przy okazji dorzuca analizowany aktualnie wierzcholek
						 - do zbioru 'bylo' (ktory jest zbiorem przejrzanych wierzcholkow)
						 - i szuka dalej wierzcholkow do wyspy ... -}
						iteruj :: Plansza -> Plansza -> Generator Plansza
						iteruj [] _ = mzero
						iteruj (x:xs) bylo = wyspy (x:t) (n-1) (x:bylo) ++ iteruj xs (x:bylo)

	{- funkcja 'generuj' generuje wszystkie poprawne rozwiazania zadania sprawdzajac
	 - wszystkie k-elementowe zbiory, zlozone z wysp, gdzie k wynosi 'liczbaWysp', czyli
	 - majac wszystkie mozliwe wyspy (bez duplikatow) tworzymy z nich
	 - plansze po k-wysp i sprawdzamy czy nadaja sie do rozwiazania :) -}
	generuj :: Generator Plansza -> Plansza -> Int -> Generator Plansza
	generuj [] _ _ = mzero
	generuj (w:wyspy) pl n = 
		{- gdy liczba wysp w 'pl' wynosi juz 'liczbaWysp' (licznik n zniza sie w dol, wiec
		 - sprawdzamy, czy 'n == 0' to znaczy, ze mamy tyle wysp ile chcielismy -}
		if n == 0
			then
				{- ale dla pewnosci sprawdzamy, czy liczba bialych pol w wyspach
				 - jest odpowiednia do rozmiaru wszystkich wysp :) -}
				if length pl == liczbaWysp * wielkoscWysp
					then return (plansza rozmiar \\ pl)
					else mzero
			else
				{- sprawdzenie przeciec krawedzi dwoch wysp oraz ich rozmiarow
				 - 'sprawdzKrawedz' (wiersz 81)
				 -
				 - 'length (w `union` pl) == length w + length pl' to nic innego
				 - jak sprawdzenie, czy dwa zbiory wysp maja wspolne elementy -}
				if sprawdzKrawedzie w pl && length (w `union` pl) == length w + length pl
					then
						{- jesli test poprawnosci zwrocil True to wywoluje
						 - rekurencyjnie funkcje generuj z powiekszona liczba wysp
						 - oraz druga funkcje generuj do przejrzenia innych 
						 - mozliwych polaczen -}
						generuj wyspy (w `union` pl) (n-1) ++ generuj wyspy pl n
					else
						{- chyba, ze test sie nie powiodl, wtedy szukamy dalej -}
						generuj wyspy pl n 
					where
						{- funkcja 'sprawdzKrawedzie' pobiera dwie wyspy i sprawdza, czy
						 - roznica zbiorow ich pol (razem z otoczkami) ma przeciecia
						 - jesli liczba przeciec > 0 to znaczy, z nie mozna ich 
						 - wziac do rozwiazania -}
						sprawdzKrawedzie w pl = 
							{- funkcja 'otoczkaZWysp' (wiersz 33) generuje wyspe z jej otoczka -}
							length (otoczkaZWyspa w rozmiar `intersect` otoczkaZWyspa pl rozmiar ) == 0





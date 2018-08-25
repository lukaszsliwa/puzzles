{-
 - Implementacja metody dedukcyjnej rozwiazywania nonogramow.
 - Autor: Lukasz Sliwa
 -
 - Przy pisaniu korzystalem z: http://pl.wikipedia.org/wiki/Nonograms
 - 
 - W jednym z testow przykladowych jest blad - przyklad3.nono - niezgadzaja sie dane wejsciowe
 - dlatego program wyrzuci wyjatek I/O
 -
 -}

module Main where
 
import List
import Monad
import Char
import Maybe
 
-- zwraca String z rysunkami oddzielonymi
-- podwojnym odstepem
nonogram :: [[Int]] -> [[Int]] -> String
nonogram w k = nonogram' (rozwiaz w k) 
	where
		nonogram' [] = "Brak wiecej rozwiazan\n"
		nonogram' (g:gs) = rysuj g ++ "\n\n" ++ nonogram' gs
	
 
-- szuka wszystkich rozwiazan obrazka przez
-- odgadywanie czesci rozwiazan, a reszte przez naiwne sprawdzenie
-- umieszcza rozwiazania w liscie wczesniej sprawdzajac,
-- czy liczba kolumn (po transpozycji wierszy z kolumnami) jest poprawna
rozwiaz :: [[Int]] -> [[Int]] -> [[[Bool]]]
rozwiaz wiersze kolumny =
	do
		r <- odgaduj
		p <- reszta r
		guard(map dlugosc (transpose p) == kolumny)
		return(p)
	where
		odgaduj = odgadujPola wiersze kolumny
		reszta r = zipWithM (wybierzWiersz $ length kolumny) wiersze r
		dlugosc = map length . filter head . group
 
odgadujPola :: [[Int]] -> [[Int]] -> [[[Maybe Bool]]]
odgadujPola wiersze kolumny = maybeToList $ trasa ruch plansza
	where
		-- 'plansza' tworzy liste Maybe o dlugosci wszystkich wierszy
		-- i w miejsce kazdego elementu wstawia tyle kolumn z wartoscia Nothing
		-- ile wskazuje 'length kolumny'
		-- czyli uogolniajac - tworzymy pusta plansze: liczba wierszy x liczba kolumn :)
		plansza = replicate (length wiersze) (replicate (length kolumny) Nothing)
		-- przekaznik monady, ktory odpowiada za pojedynczy ruch na planszy
		ruch = (popraw (length kolumny) wiersze . transpose) <-+-> (popraw (length wiersze) kolumny . transpose)
		popraw n = zipWithM (spojnosc n)
		(foo <-+-> go) x = go x >>= foo
 
-- powtarzamy wywolanie f dopoki punkt nie jest osiagalny
-- ogolnie: funkcja 'trasa' odpowiada za spojnosc calego rysunku
trasa :: (Monad m, Eq a) => (a -> m a) -> a -> m a
trasa foo p = do
		pp <- foo p
		if pp == p 
			then return p 
			else trasa foo pp
 
-- wyznacza mozliwe spojne obszary, w ktorych mozna wstawic
-- blok o k kolumnach i n wierszach
spojnosc :: Int -> [Int] -> [Maybe Bool] -> Maybe ([Maybe Bool])
spojnosc n k cz = spojnosc' (wybierzWiersz n k cz) where
	spojnosc' [] = Nothing
	spojnosc' rs = Just ((foldr1zipWith) (map (map Just) rs)) where
			podstawienie a b = case a == b of { True -> a ; otherwise -> Nothing }
			foldr1zipWith = foldr1 (zipWith podstawienie)
 
-- wyznacza wiersze o dlugosci n, w ktore mozna wstawic spojny obszar
wybierzWiersz :: Int -> [Int] -> [Maybe Bool] -> [[Bool]]
wybierzWiersz n [] [] = [[]]
wybierzWiersz n ks [] = []
wybierzWiersz n ks (Nothing:cz) = wybierzWiersz' n ks True cz ++ wybierzWiersz' n ks False cz
wybierzWiersz n ks (Just s:cz) = wybierzWiersz' n ks s cz

wybierzWiersz' :: Int -> [Int] -> Bool -> [Maybe Bool] -> [[Bool]]
wybierzWiersz' n kol False cz = 
	do 
		wiersz <- wybierzWiersz (n - 1) kol cz
		return(False : wiersz) 
wybierzWiersz' n [k] True cz =
	do
		guard(n >= k && all (/= Just False) p && all (/= Just True) t)
		return(replicate k True ++ replicate (n - k) False)
	where 
		(p, t) = splitAt (k - 1) cz
wybierzWiersz' n (k:ks) True cz =
	do
		guard(n > k + 1 && all (/= Just False) p && pusty /= Just True)
		wiersz <- wybierzWiersz (n - k - 1) ks cz'
		return(replicate k True ++ False : wiersz)
	where 
		(p, pusty:cz') = splitAt (k - 1) cz

-- funkcja komorka zwraca stan komorki:
-- * jesli prawda to zwraca X
-- * jesli falsz to zwraca odstep
komorka :: Bool -> Char
komorka stan = case stan of { True -> 'X' ; otherwise -> ' ' }

-- funkcja rysuj pobiera liste list z wartosciami boolowskimi
-- i na podstawie tego co zwroci funkcja komorka x
-- maluje linia po linii caly rysunek z odstepami miedzy wierszami
rysuj :: [[Bool]] -> String
rysuj [] = []
rysuj (s:ss) =
	do
		x <- s
		return(komorka x)
	`mplus` return('\n') 
	`mplus` rysuj ss

-- wczytuje linie z lista w postaci: [1,2,3]
wczytajLinie :: IO [Int]
wczytajLinie = readLn

-- czyta okreslono liczbe linii (w parametrze 'ile')
czytaj ile = 
        if ile <= 0
                then return []
                else do
                        p <- wczytajLinie --wczytujemy pojedyncza linie
                        ps <- czytaj (ile - 1) -- i przechodzimy rekurencyjnie dalej
                        return (p : ps) -- zwracamy liste

main :: IO ()
main = do 
	(szerokosc, wysokosc) <- readLn
	sz <- czytaj szerokosc
	getChar
	wy <- czytaj wysokosc
	putStr $ nonogram wy sz


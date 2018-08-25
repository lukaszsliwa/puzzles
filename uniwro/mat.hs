{-
 -
 -}

module Main where
 
import Data.List
import Control.Monad
import Data.Char
import Data.Maybe
 
-- zwraca String z rysunkami
start :: [[Int]] -> [[Int]] -> String
start w k = s (szukajRozwiazan w k) 
	where
		s [] = "Brak"
		s t@(g:gs) = if t == [] 
				then "Brak" 
				else 
					if gs == [] 
						then pokazNonogram g ++ "\n\n" ++ "Brak wiecej rozwiazan"
						else pokazNonogram g ++ "\n\n" ++ s gs
	
 
-- szuka wszystkich rozwiazan obrazka przez
-- odgadywanie czesci rozwiazan, a reszte przez naiwne sprawdzenie
-- umieszcza rozwiazania w liscie wczesniej sprawdzajac,
-- czy liczba kolumn (po transpozycji wierszy z kolumnami) jest poprawna
szukajRozwiazan :: [[Int]] -> [[Int]] -> [[[Bool]]]
szukajRozwiazan wiersze kolumny = 
	[ p | 	r <- deduk wiersze kolumny, 
		p <- zipWithM (wyznaczWiersz $ length kolumny) wiersze r, 
		map dlugosc (transpose p) == kolumny ]
	where
		dlugosc = map length . filter head . group


spoj [] = Nothing 
spoj rs = Just (ifun (map (map Just) rs)) where
			podst a b = case a == b of { True -> a ; otherwise -> Nothing }
			ifun = foldr1 (zipWith podst)


-- dedukcyjne podejscie do rozwiazywanego obrazka
deduk :: [[Int]] -> [[Int]] -> [[[Maybe Bool]]]
deduk wiersze kolumny = maybeToList $ droga przesun plac
	where
		klen = length kolumny
		wlen = length wiersze
		--pomocniczy operator <&>
		(p <&> q) x = q x >>= p
		--tworzy pusty plac na malunek - liczba wierszy razy liczba kolumn
		plac = replicate (length wiersze) (replicate (length kolumny) Nothing)
		--monada i operator <&>
		przesun = (po klen wiersze . transpose) <&> (po wlen kolumny . transpose)
		po n = zipWithM (spojnosc n)
 
-- spojnosc calego rysunku
droga :: (Monad m, Eq a) => (a -> m a) -> a -> m a
droga fun p = (do a <- fun p ; if a == p then return p else droga fun a)
 
-- wyznacza mozliwe spojne obszary, w ktorych mozna wstawic
-- blok o k kolumnach i n wierszach
spojnosc :: Int -> [Int] -> [Maybe Bool] -> Maybe ([Maybe Bool])
spojnosc n k cz = spoj (wyznaczWiersz n k cz)
 
-- wyznacza wiersze o dlugosci n, w ktore mozna wstawic spojny obszar
wyznaczWiersz :: Int -> [Int] -> [Maybe Bool] -> [[Bool]]
wyznaczWiersz n [] [] = [[]]
wyznaczWiersz n ks [] = []
wyznaczWiersz n ks (Nothing:cz) = 
	wyznaczWiersz' n ks True cz ++ wyznaczWiersz' n ks False cz
wyznaczWiersz n ks (Just s:cz) = 
	wyznaczWiersz' n ks s cz

wyznaczWiersz' :: Int -> [Int] -> Bool -> [Maybe Bool] -> [[Bool]]
wyznaczWiersz' n ks False cz = [ False : row | row <- wyznaczWiersz (n-1) ks cz ]
wyznaczWiersz' n [k] True cz = [ replicate k True ++ replicate (n-k) False | n >= k && all (/= Just False) p && all (/= Just True) t ]
	where 
		(p, t) = splitAt (k-1) cz
wyznaczWiersz' n (k:ks) True cz = [ replicate k True ++ False : row | n > k+1 && all (/= Just False) p && pusty /= Just True, row <- wyznaczWiersz (n - k - 1) ks cz' ]
	where 
		(p, pusty:cz') = splitAt (k - 1) cz

-- zwraca pojedynczy wiersz obrazka
-- zamieniajac puste pola na *, a pelne na #
nonoWiersz :: [Bool] -> String
nonoWiersz s = [ piksel x | x <- s ] ++ "\n" where
	piksel True = '#'
	piksel False = '*'

-- funkcja rysuj pobiera liste list z wartosciami boolowskimi 
-- i maluje linia po linii caly rysunek z odstepami miedzy wierszami
pokazNonogram :: [[Bool]] -> String
pokazNonogram [] = []
pokazNonogram (s:ss) = nonoWiersz s ++ pokazNonogram ss

wczytList :: IO [Int]
wczytList = readLn -- wczytujemy linie z lista [10,34,1,0] - haskell sam zamienia wszystko :)

-- wczytywanie kolejnych linii dopoki licznik jest > 0
wczytuj licznik = case licznik > 0 of { 
				True -> (do
					 x <- wczytList --wczytanie pojedycznej linii
					 xs <- wczytuj (licznik-1)
					 return (x : xs) ) ; 
				otherwise -> return [] }

main :: IO ()
main = do 
	(s, w) <- readLn
	a <- wczytuj s ; getChar ; b <- wczytuj w ;
	putStrLn $ start b a 


module Main where

import Char
import IO(isEOF)
import List
import Monad 

data Square = Blank | Cross deriving (Eq)
instance Show Square where
	show Blank = " "
	show Cross = "X" 

--create all possibilities of arranging the given blocks in a line of "n" elements
rows n []             = [replicate n Blank]
rows n (k:ks) | n < k = []
rows n (k:ks)         = 
	[Blank : row | row <- rows (n-1) (k:ks)] 
	++
	if null ks then [replicate k Cross ++ replicate (n-k) Blank]
        	else [replicate k Cross ++ Blank : row | row <- rows (n-k-1) ks]
	                          
-- contract a given line into the block format
-- i.e. contract [Cross,Blank,Cross] == [1,1]
contract = map length . filter (\(x:_) -> x==Cross) . group
	                           
-- create all solutions by combining all possible rows in all possible ways
-- then pick a solution and check whether its block signature fits
solver horz vert = filter fitsVert possSolution
	where 
		possSolution = sequence $ map (rows (length vert)) horz
        	fitsVert rs  = map contract (transpose rs) == vert
	                                          
-- output the (first) solution
nonogram horz vert = printSolution $ head $ solver horz vert
	where printSolution = putStr . unlines . map (concatMap show) . transpose

toList :: String -> [Int]
toList t = if length t == 2 
		then []
		else toList' t 0 where
			toList' :: String -> Int -> [Int]
			toList' t@(x:xs) n  
				| x == ']' = n : []
				| x == '[' || x == ' ' = toList' xs 0
				| x == ',' = n : toList' xs 0
				| otherwise = toList' xs (10 * n + (digitToInt x))

main :: IO ()
main = do 
	 (szerokosc, wysokosc) <- readLn
	 sz <- czytaj szerokosc
	 getChar
	 wy <- czytaj wysokosc
	 --print (sz ++ wy)
	 nonogram sz wy
	 --nonogram [[3],[2,1],[3,2],[2,2],[6],[1,5],[6],[1],[2]] [[1,2],[3,1],[1,5],[7,1],[5],[3],[4],[3]]

--czytaj :: Int -> [[Int]]
czytaj ile = 
	if ile <= 0
		then return []
		else do
			p <- getLine
			ps <- czytaj (ile - 1)
			return (toList p : ps)


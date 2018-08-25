module Main where
 
import Control.Monad
import Data.List
import Data.Maybe
import Char
 
type Row s = [s]
type Grid s = [Row s]
 
-- partial information about a square
type Square = Maybe Bool
 
-- Print the first solution (if any) to the nonogram
nonogram :: [[Int]] -> [[Int]] -> String
nonogram rs cs = case solve rs cs of
        [] -> "Brak rozwiazania\n"
        (grid:_) -> showGrid rs cs grid
 
-- All solutions to the nonogram
solve :: [[Int]] -> [[Int]] -> [Grid Bool]
solve rs cs = [grid' |
                        -- deduce as many squares as we can
                grid <- maybeToList (deduction rs cs),
                        -- guess the rest, governed by rs
                grid' <- zipWithM (rowsMatching nc) rs grid,
                        -- check each guess against cs
                map contract (transpose grid') == cs]
  where nc = length cs
        contract = map length . filter head . group
 
-- A nonogram with all the values we can deduce
deduction :: [[Int]] -> [[Int]] -> Maybe (Grid Square)
deduction rs cs = converge step init
  where nr = length rs
        nc = length cs
        init = replicate nr (replicate nc Nothing)
        step = (improve nc rs . transpose) <.> (improve nr cs . transpose)
        improve n = zipWithM (common n)
        (g <.> f) x = f x >>= g
 
-- repeatedly apply f until a fixed point is reached
converge :: (Monad m, Eq a) => (a -> m a) -> a -> m a
converge f s = do
        s' <- f s
        if s' == s then return s else converge f s'
 
-- common n ks partial = commonality between all possible ways of
-- placing blocks of length ks in a row of length n that match partial.
common :: Int -> [Int] -> Row Square -> Maybe (Row Square)
common n ks partial = case rowsMatching n ks partial of
        [] -> Nothing
        rs -> Just (foldr1 (zipWith unify) (map (map Just) rs))
  where unify :: Square -> Square -> Square
        unify x y
          | x == y = x
          | otherwise = Nothing
 
-- rowsMatching n ks partial = all possible ways of placing blocks of
-- length ks in a row of length n that match partial.
rowsMatching :: Int -> [Int] -> Row Square -> [Row Bool]
rowsMatching n [] [] = [[]]
rowsMatching n ks [] = []
rowsMatching n ks (Nothing:partial) =
        rowsMatchingAux n ks True partial ++
        rowsMatchingAux n ks False partial
rowsMatching n ks (Just s:partial) = 
        rowsMatchingAux n ks s partial
 
rowsMatchingAux :: Int -> [Int] -> Bool -> Row Square -> [Row Bool]
rowsMatchingAux n ks False partial =
        [False : row | row <- rowsMatching (n-1) ks partial]
rowsMatchingAux n [k] True partial =
        [replicate k True ++ replicate (n-k) False |
                n >= k && all (/= Just False) front && all (/= Just True) back]
  where (front, back) = splitAt (k-1) partial
rowsMatchingAux n (k:ks) True partial =
        [replicate k True ++ False : row |
                n > k+1 && all (/= Just False) front && blank /= Just True,
                row <- rowsMatching (n-k-1) ks partial']
  where (front, blank:partial') = splitAt (k-1) partial
 
showGrid :: [[Int]] -> [[Int]] -> Grid Bool -> String
showGrid rs cs ss = unlines (zipWith showRow rs ss)
  where showRow rs ss = concat [[cellChar s] | s <- ss] ++ " "
        cellChar True = 'X'
        cellChar False = ' '

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

czytaj ile = 
        if ile <= 0
                then return []
                else do
                        p <- getLine
                        ps <- czytaj (ile - 1)
                        return (toList p : ps)

main :: IO ()
main = do 
         (szerokosc, wysokosc) <- readLn
         sz <- czytaj szerokosc
         getChar
         wy <- czytaj wysokosc
	 --print $ show (sz, wy)
         putStr $ nonogram sz wy
  

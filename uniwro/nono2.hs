module Main where
 
import qualified Data.Set as Set
import Data.Set (Set)
import qualified Data.Map as Map
import Data.Map (Map)
import Data.List
import Char 

------------------------------------------------------------------------
-- Cells
 
-- | The value of a single cell
newtype Value = Value Int
	deriving (Eq, Ord, Show)
 
-- | Negative values encode empty cells, positive values filled cells
empty (Value n) = n <= 0
full = not . empty
 
type Choice = Set Value
 
------------------------------------------------------------------------
-- Puzzle
 
type Grid = [[Choice]]
 
-- | Datatype for solved and unsolved puzzles
data Puzzle = Puzzle
	-- | List of rows, containing horizontal choices for each cell
	{ gridH :: Grid
	-- | List of columns, containing vertical choices for each cell
	, gridV :: Grid
	-- | What is allowed before/after a specific value?
	--   (after (Value 0)) are the values allowed on the first position
	, afterH, beforeH :: [Value -> Choice]
	, afterV, beforeV :: [Value -> Choice]
	}
 
instance Eq Puzzle where
	p == q = gridH p == gridH q
 
instance Show Puzzle where
	show = dispGrid . gridH

-- | Transpose a puzzle (swap horizontal and vertical components)
transposeP :: Puzzle -> Puzzle
transposeP p = Puzzle
	{ gridH      = gridV p
	, gridV      = gridH p
	, afterH     = afterV p
	, beforeH    = beforeV p
	, afterV     = afterH p
	, beforeV    = beforeH p
	}
 
-- | Display a puzzle
dispGrid = concatMap (\r -> "[" ++ map disp'' r ++ "]\n")
 where	disp'' x
	 | Set.null     x = 'E'
	 | setAll full  x = '#'
	 | setAll empty x = '.'
	 | otherwise      = '/'
 
------------------------------------------------------------------------
-- Making puzzles
 
-- | Make a puzzle, when given the numbers at the edges
puzzle :: [[Int]] -> [[Int]] -> Puzzle
puzzle h v = Puzzle
	{ gridH   = map (replicate cols . Set.fromList) ordersH
	, gridV   = map (replicate rows . Set.fromList) ordersV
	, afterH  = map mkAfter ordersH
	, beforeH = map mkAfter (map reverse ordersH)
	, afterV  = map mkAfter ordersV
	, beforeV = map mkAfter (map reverse ordersV)
	}
 where	rows = length h
	cols = length v
	ordersH = map order h
	ordersV = map order v
 
-- | Order of allowed values in a single row/column
--   Input = list of lengths of filled cells, which are separated by empty cells
--   Repeats empty values, because those values may be repeated
--   example:
--     order [1,2,3] = map Value [-1,-1, 1, -2,-2, 2,3, -4,-4, 4,5,6, -7,-7]
order :: [Int] -> [Value]
order = order' 1
 where	order' n []     = [Value (-n), Value (-n)] -- repeated empty cells allowed at the end
	order' n (x:xs) = [Value (-n), Value (-n)] ++ map Value [n..n+x-1] ++ order' (n+x) xs
 
-- | What values are allowed after a given value in the given order?
mkAfter :: [Value] -> Value -> Choice
mkAfter order = (mkAfterM order Map.!)
 
mkAfterM order  = Map.fromListWith (Set.union) aftersL
 where	aftersL = -- after the start (0) the first non empty value, at position 2 is allowed
	          -- this is a bit of a hack
	          (if length order > 2
	            then [(Value 0, Set.singleton (order !! 2))]
	            else []) ++
	          -- after each value comes the next one in the list
	          zip (Value 0:order) (map Set.singleton order)
 
------------------------------------------------------------------------
-- Classifying puzzles
 
-- | Is a puzzle completely solved?
done :: Puzzle -> Bool
done = all (all ((==1) . Set.size)) . gridH
 
-- | Is a puzzle invalid?
invalid :: Puzzle -> Bool
invalid = any (any Set.null) . gridH
 
------------------------------------------------------------------------
-- Solving
 
-- | Solve a puzzle deterministicly, i.e. don't make any guesses
-- make sure
solveD :: Puzzle -> Puzzle
solveD = takeSame . iterate step
 
-- | All solving steps combined, the orientation after a step is the same as before
step = efStep . transposeP . hStep . transposeP . hStep
 
-- | A step in the solving process.
--   Propagate allowed values after from left to right
hStep p = p { gridH = gridH'' }
 where	gridH'  = zipWith hStepLTR (afterH  p) (gridH p) -- left to right
	gridH'' = zipWith hStepRTL (beforeH p) (gridH')  -- right to left
 
-- | hStep on a single row, from left to right, after is a function that gives the allowed after values
hStepLTR after row = hStepLTR' (after (Value 0)) row
 where	hStepLTR' _         []     = []
	hStepLTR' afterPrev (x:xs) = x' : hStepLTR' afterX' xs
	 where	x'      = Set.intersection x afterPrev
		afterX' = Set.unions $ map after $ Set.toList x'
-- | Same as hStepRTL, but from right to left, should be given allowed before values
hStepRTL before = reverse . hStepLTR before . reverse
 
-- | A step in the solving process
--   Combine horizontal and verticall grids, empty/full in one <-> empty/full in the oter
--   Note: we transpose gridV, to make it compatible with gridH (row-of-cells)
efStep puzzle = puzzle { gridH = gridH', gridV = transpose gridV't }
 where  (gridH', gridV't) = zzMap ef (gridH puzzle) (transpose (gridV puzzle))
	-- Step on a single cell
	ef h v = filterCell empty . filterCell full $ (h,v)
	-- Step on a single cell, for a single predicate, if either h or v satisfies the predicate
	-- then the other is filtered so it will satisfy as well
	filterCell pred (h,v) 
	 | setAll pred h = (h, Set.filter pred v)
	 | setAll pred v = (Set.filter pred h, v)
	 | otherwise     = (h, v)
 
------------------------------------------------------------------------
-- Guessing
 
-- | Solve a puzzle, gives all solutions
solve :: Puzzle -> [Puzzle]
solve puzzle
 | done    puzzle' = [puzzle'] -- single solution
 | invalid puzzle' = []        -- no solutions
 | otherwise       = concatMap solve (guess puzzle') -- we have to guess
 where puzzle' = solveD puzzle
 
-- | Split a puzzle into multiple puzzles, by making a guess at the first position with multiple choices
--   we return all possible puzzles for making a guess at that position
guess :: Puzzle -> [Puzzle]
guess puzzle = map (\gh -> puzzle {gridH = gh} ) gridHs
 where gridHs = trySplit (trySplit splitCell) (gridH puzzle)
 
-- | Try to split a cell into multiple alternatives
splitCell :: Choice -> [Choice]
splitCell = map Set.singleton . Set.toList
 
-- | Try to split a single item in a list using the function f
--   Stops at the first position where f has more than 1 result.
--   TODO: A more soffisticated guessing strategy might be faster.
trySplit :: (a -> [a]) -> [a] -> [[a]]
trySplit f []     = []
trySplit f (x:xs)
 | length fx  > 1 = zipWith (:) fx (repeat xs) -- This element is split, don't look further
 | length fxs > 1 = map (x:) fxs               -- The list is split furter on
 | otherwise      = []
 where	fx  = f x
	fxs = trySplit f xs
 
------------------------------------------------------------------------
-- Utilities
 
-- | Set.all, similair to Data.List.all
setAll f = all f . Set.toList
 
-- | Map a function simultaniously over two lists, like zip
zMap :: (a -> b -> (c, d)) -> [a] -> [b] -> ([c], [d])
zMap f a b = unzip $ zipWith f a b
 
-- | Map a function simultaniously over two lists of lists, like zip
zzMap :: (a -> b -> (c, d)) -> [[a]] -> [[b]] -> ([[c]], [[d]])
zzMap f a b = unzip $ zipWith (zMap f) a b
 
-- | Find the first item in a list that is repeated
takeSame :: Eq a => [a] -> a
takeSame (a:b:xs)
 | a == b    = a
 | otherwise = takeSame (b:xs)

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
         
         print $ printNono $ puzzle sz wy
         

--czytaj :: Int -> [[Int]]
czytaj ile = 
        if ile <= 0
                then return []
                else do
                        p <- getLine
                        ps <- czytaj (ile - 1)
                        return (toList p : ps)

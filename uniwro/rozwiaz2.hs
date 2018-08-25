module Main where

import Miodowe (Zadanie(..), rozwiaz)
import IO (isEOF)

main :: IO ()
main = do
(rozmiar, liczbaWysp, wielkoscWysp) <- readLn
czarne <- czytaj
print $ rozwiaz (Zadanie rozmiar liczbaWysp wielkoscWysp czarne) where
czytaj = do
koniec <- isEOF
if koniec
	then return []
	else do
		p <- readLn
		ps <- czytaj
		return (p : ps)

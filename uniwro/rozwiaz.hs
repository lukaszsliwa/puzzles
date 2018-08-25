module Main where

import Miodowe(Komorka, Plansza, Generator, Zadanie(Zadanie),
               naPlanszy, plansza, rozwiaz)
import Graphics.HGL(Graphic, Point, RGB(RGB), BkMode(Opaque), Key,
                    runGraphics, withWindow_, drawInWindow, clearWindow,
                    createBrush, selectBrush, polygon, getKey, keyToChar,
                    setTextAlignment, HAlign(Center), VAlign(Top,Bottom),
                    setBkMode, text)
import IO(isEOF)
import List((\\), unfoldr)
import Char(toUpper)

rysujPlansze :: Point -> Double -> Plansza -> Graphic
rysujPlansze (x0,y0) promien = mapM_ rysuj where
   rysuj (x,y) = polygon [ (u,v) |
      i <- [0..6],
      let phi = fromIntegral i * pi / 3,
      let u = x0 + round (promien * sin phi + fromIntegral x * dx),
      let v = y0 - round (promien * cos phi + fromIntegral y * dy) ]
   dx = (sqrt 3 / 2) * promien + 1
   dy = (3/2) * promien + 2

okno :: Zadanie -> IO ()
okno dane@(Zadanie rozmiar _ _ czarne) = runGraphics $
   withWindow_ tytul wymiary $ \ w -> do
      bialyPedzel <- createBrush $ RGB 255 255 255
      szaryPedzel <- createBrush $ RGB 32 32 32
      drawInWindow w $ do
         setTextAlignment (Center,Top)
         text (polPikseli,marg) "Dane wejsciowe"
         selectBrush bialyPedzel
         rysujPlansze srodek (fromIntegral promien)
            (plansza rozmiar \\ czarne)
         setTextAlignment (Center,Bottom)
         setBkMode Opaque
         text (polPikseli,pikseli-marg) "Rozwiazuje..."
      (let
         wyswietl n [] = do
            drawInWindow w . text (polPikseli, pikseli-marg) $
               "Brak " ++ (if n>1 then "dalszych " else "")
                  ++ "rozwiazan; dowolny klawisz: koniec"
            getKey w
            return ()
         wyswietl n (wynik:wyniki) = do
            drawInWindow w . text (polPikseli, pikseli-marg) $
               "Q: koniec; inny klawisz: "
               ++ (if n>1 then "kolejne " else "") ++ "rozwiazanie"
            k <- getKey w
            if (toUpper . keyToChar) (k::Key) == 'Q'
               then return ()
               else do
                  clearWindow w
                  drawInWindow w $ do
                     setTextAlignment (Center,Top)
                     text (polPikseli, marg) $ "Rozwiazanie " ++ show n
                     selectBrush bialyPedzel
                     rysujPlansze srodek (fromIntegral promien)
                        (plansza rozmiar \\ wynik)
                     selectBrush szaryPedzel
                     rysujPlansze srodek (fromIntegral promien)
                        (wynik \\ czarne)
                     setTextAlignment (Center,Bottom)
                     text (polPikseli, pikseli-marg) "Rozwiazuje..."
                  wyswietl (n+1) wyniki
       in
          wyswietl 1 $ rozwiaz dane)
   where
      marg = 10
      promien = 30
      pikseli = (9 * rozmiar * promien) `div` 2
      wymiary = (pikseli,pikseli)
      polPikseli = pikseli `div` 2
      srodek = (polPikseli, polPikseli)
      tytul = "Miodowe wyspy"

main :: IO ()
main = do
   (rozmiar, liczbaWysp, wielkoscWysp) <- readLn
   czarne <- czytaj
   okno (Zadanie rozmiar liczbaWysp wielkoscWysp czarne) where
   czytaj = do
      koniec <- isEOF
      if koniec
         then return []
         else do
            p <- readLn
            ps <- czytaj
            return (p : ps)

-- TWI, 8 marca 2008

module TicTacToe where

import Data.List (intercalate, transpose)
import Data.Maybe (isJust, fromJust)
import System.IO (hFlush, stdout)
import Control.Monad (when)

-- Типы данных
data Player = X | O deriving (Eq, Show)
type Cell = Maybe Player
type Board = [[Cell]]

-- Инициализация пустой доски 3x3
emptyBoard :: Board
emptyBoard = replicate 3 (replicate 3 Nothing)

-- Проверка победы
winningLines :: Board -> [[Cell]]
winningLines board = 
  board ++ transpose board ++ diagonals board
  where
    diagonals b = [[b !! i !! i | i <- [0..2]], 
                  [b !! i !! (2 - i) | i <- [0..2]]]

isWinner :: Player -> Board -> Bool
isWinner player board = 
  any (all (== Just player)) (winningLines board)

-- Проверка ничьи
isDraw :: Board -> Bool
isDraw board = all (all isJust) board && 
               not (isWinner X board || isWinner O board)

-- Ход игры
makeMove :: Board -> Player -> (Int, Int) -> Maybe Board
makeMove board player (row, col)
  | row < 0 || row > 2 || col < 0 || col > 2 = Nothing
  | isJust (board !! row !! col) = Nothing
  | otherwise = Just $ updateBoard board row col (Just player)
  where
    updateBoard b r c val =
      take r b ++ 
      [take c (b !! r) ++ [val] ++ drop (c + 1) (b !! r)] ++
      drop (r + 1) b

-- Отображение доски
showCell :: Cell -> String
showCell Nothing = " "
showCell (Just X) = "X"
showCell (Just O) = "O"

displayBoard :: Board -> String
displayBoard board =
  intercalate "\n-----------\n" $
  map (intercalate " | " . map showCell) board

-- Игровой цикл
gameLoop :: Board -> Player -> IO ()
gameLoop board player = do
  putStrLn $ "\n" ++ displayBoard board ++ "\n"
  
  if isWinner X board then putStrLn "X победил!"
  else if isWinner O board then putStrLn "O победил!"
  else if isDraw board then putStrLn "Ничья!"
  else do
    putStr $ show player ++ ", ваш ход (ряд столбец): "
    hFlush stdout
    input <- getLine
    case map read (words input) of
      [row, col] -> case makeMove board player (row-1, col-1) of
        Just newBoard -> gameLoop newBoard (if player == X then O else X)
        Nothing -> do
          putStrLn "Некорректный ход!"
          gameLoop board player
      _ -> do
        putStrLn "Введите два числа через пробел!"
        gameLoop board player

-- Точка входа (верхний уровень с IO)
main :: IO ()
main = do
  putStrLn "Добро пожаловать в Крестики-Нолики!"
  putStrLn "Вводите координаты в формате: ряд столбец (например: 2 3)"
  gameLoop emptyBoard X
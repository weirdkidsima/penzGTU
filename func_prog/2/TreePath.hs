module TreePath where

data Tree a = Node a [Tree a]

pathLengths :: Tree a -> [Int]
pathLengths (Node _ []) = [0]  -- Базовый случай: лист
pathLengths (Node _ children) = 
  mergeAll (map (add1 . pathLengths) children)
  where
    add1 [] = []
    add1 (x:xs) = x + 1 : add1 xs

    mergeAll [] = []
    mergeAll (xs:xss) = append xs (mergeAll xss)

    append [] ys = ys
    append (x:xs) ys = x : append xs ys
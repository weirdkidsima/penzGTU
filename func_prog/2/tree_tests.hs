module TreeTests where

data Tree a = Node a [Tree a] deriving (Show)

-- Тестовые данные
testTrees :: [Tree String]
testTrees =
  [ Node "A" [],                                  -- A
    Node "A" [Node "B" []],                       -- A -> B
    Node "A" [Node "B" [Node "C" []], Node "D" []] -- A -> (B -> C), D
  ]

-- Автоматизированные тесты для pathLengths
testPathLengths :: IO ()
testPathLengths = do
  putStrLn "Testing pathLengths:"
  print $ pathLengths (testTrees !! 0)  -- [0]
  print $ pathLengths (testTrees !! 1)  -- [1]
  print $ pathLengths (testTrees !! 2)  -- [2,1]

-- Автоматизированные тесты для findLabelPath
testFindLabel = do
  putStrLn "\nTesting findLabelPath:"
  print $ findLabelPath (testTrees !! 0) "A"  -- Just 0
  print $ findLabelPath (testTrees !! 2) "C"  -- Just 2
  print $ findLabelPath (testTrees !! 2) "X"  -- Nothing
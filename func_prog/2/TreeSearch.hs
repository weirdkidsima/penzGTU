module TreeSearch where

data Tree a = Node a [Tree a]

findLabelPath :: Eq a => Tree a -> a -> Maybe Int
findLabelPath (Node label []) target 
  | label == target = Just 0
  | otherwise = Nothing
findLabelPath (Node _ children) target =
  searchChildren children
  where
    searchChildren [] = Nothing
    searchChildren (t:ts) =
      case findLabelPath t target of
        Just depth -> Just (depth + 1)
        Nothing -> searchChildren ts
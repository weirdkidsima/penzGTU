replace :: Eq a => [a] -> [a] -> [a] -> [a]
replace [] _ _ = []
replace (x:xs) l2 l3 =
  if x `elem` l2
    then head l3 : replace xs l2 (tail l3)
    else x : replace xs l2 l3
    
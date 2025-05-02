difference :: [String] -> [String] -> [String]
difference [] _ = []
difference (x:xs) l2 =
  if x `elem` l2
    then difference xs l2
    else x : difference xs l2
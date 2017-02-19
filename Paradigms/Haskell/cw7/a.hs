foldl' :: (a -> b -> a) -> a -> [b] -> a
foldl' _ z [] = z
foldl' f z (x:xs) = foldl' f (f z x) xs

foldr' :: (b -> a -> a) -> a -> [b] -> a
foldr' _ z [] = z
foldr' f z (x:xs) = f x (foldr' f z xs)

reverse' xs = foldl' (flip (:)) [] xs
foldl'' f z xs = foldr' (\x a acc -> a (f acc x)) id xs z

and' :: [Bool] -> Bool
and' = foldr' (&&) True
or' :: [Bool] -> Bool
or' = foldr' (||) True
length' :: [a] -> Int
length' = foldr' (\_ b -> b + 1) 0
bin2int :: [Int] -> Int
bin2int = foldl' (\x y -> x * 2 + y) 0
map' :: b -> [a] -> [a]
--к какждому элементу списка применяет функцию и возвращает список
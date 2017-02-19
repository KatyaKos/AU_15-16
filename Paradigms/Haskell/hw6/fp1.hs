import Data.Char (digitToInt, ord)

head' :: [a] -> a
head' (x:xs) = x

tail' :: [a] -> [a]
tail' [] = []
tail' (_:xs) = xs

take':: Int -> [a] -> [a]
take' 0 xs = []
take' n (x:xs) = x : take' (n - 1) xs

drop':: Int -> [a] -> [a]
drop' 0 xs = xs
drop' n [] = []
drop' n (_:xs) = drop' (n - 1) xs

--чтобы как функцию f подставлять, для тестов
even' :: Int -> Bool
even' x | x `mod` 2 == 0 = True
		| otherwise = False

filter' :: (a -> Bool) -> [a] -> [a]
filter' _ [] = []
filter' f (x:xs) = if (f x == True) then x:(filter' f xs) else filter' f xs

foldl' :: (a -> b -> a) -> a -> [b] -> a
foldl' _ z [] = z
foldl' f z (x:xs) = foldl' f (f z x) xs

concat' :: [a] -> [a] -> [a]
concat' [] l1 = l1
concat' (l:l1) l2 = l:concat' l1 l2

quickSort' :: Ord a => [a] -> [a]
quickSort' [] = []
quickSort' (x:l) = concat' (quickSort' (filter' ((>) x) l)) (concat' (filter' ((==) x) (x:l)) (quickSort' (filter' ((<) x)l)))



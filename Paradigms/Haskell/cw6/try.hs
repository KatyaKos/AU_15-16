import Data.Char (digitToInt, ord)

x = 2
y = 42  --связали

add :: Int -> Int -> Int  -- по дефолту: Int->(Int->Int)
add x y = x + y  -- определение add
add' x = \ y -> x + y  -- \ лямбда функция
add'' = \x y -> x + y

foo = let z = x + y  --глобальная foo let связывает
	  s = z + z
      in print s

add2 = add 2 -- карирование, вызываем функцию не от всех, возвращает функцию отоставшихся
-- oops = print add 1 2 ошибка! без скобок слева направо выполняется
fortyTwo = add 40 2   -- вызов add
{-
hi
-}

printThree = print(add 1 2)

z = 1  --связали
--z = 2  -- ошибка, уже связаны

--нет циклов, но ест рекурсии
factorial n = if n > 1
			  then n * factorial (n-1)
			  else 1
--эта штука работает медленно, как сделать быстрее? хвостовая функция

factorial' n' = helper 1 n'
	where helper acc n = if n > 1
						 then helper (acc * n) (n - 1)
						 else acc

--let in
factorial'' n' =
	let helper acc n = if n > 1
					   then helper (acc * n) (n - 1)
					   else acc
	in helper 1 n'

--guard
factorial''' ::Int -> Int
factorial''' n' = helper 1 n'
	where helper acc n | n > 1 = helper (acc * n) (n - 1)
					   | n < 2 = acc
					   | otherwise = acc

mult x1 x2 = x1 * x2

--pattern matching
gcd' a 0 = a
gcd' a b = gcd' b (mod a b)
listCons :: Bool
-- списки, встроенные, список однотипных элементов
listCons = (1::Int):2:3:[] == [1,2,3]
--listCons = 1:2:[3] == [1,2,3]

whoami [] = []
whoami [x] = [x]
whoami (x : _ : xs) = x : (whoami xs) --выводит только нечетные элементы списка

evens xs = [x | x <- xs, x `mod` 2 == 0] --list comperehensions

--fibonachi
fib :: Int->Int
fib n' = helper 1 1 n'
	where helper pr1 pr2 n  | n > 2 = helper (pr1 + pr2) pr1 (n - 1)
							| otherwise = pr1

toDigits :: Int -> [Int]
toDigits n = helper [] n
	where helper xs n   |   n > 0 = let r = n `mod` 10
										n = n div 10
									in r:xs
						|	otherwises
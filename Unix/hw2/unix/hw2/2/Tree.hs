import Data.List
import Control.Monad
import System.Environment


data BinaryTree = Vertex BinaryTree BinaryTree | EmptyTree

createTree :: Integer -> BinaryTree
createTree 0 = EmptyTree
createTree levelCount = Vertex (createTree (levelCount - 1))
                               (createTree (levelCount - 1))

instance Show BinaryTree where
    show EmptyTree = ""
    show tree = intercalate "\n" (fst $ genLines tree)
      where
        node = "o"
        genLines (Vertex EmptyTree EmptyTree) = (["|", node], 1)
        genLines (Vertex lt rt) =
            let (ls, ln) = genLines lt;
                (rs, rn) = genLines rt;
                lm = ln `div` 2;
                rm = rn `div` 2;
                n = ln + rn + 3;
                m = n `div` 2;
                line1 = (replicate m ' ') ++ "|" ++ (replicate m ' ');
                line2 = (replicate lm ' ') ++ "+" ++ (replicate lm '-') ++
                        "-" ++ node ++ "-" ++
                        (replicate lm '-') ++ "+" ++ (replicate lm ' ') in
            (line1 : line2 : map (\(l, r) -> l ++ "   " ++ r) (zip ls rs), n)

main :: IO ()
main = do
    levelCount <- liftM (read . head) getArgs
    print $ createTree levelCount

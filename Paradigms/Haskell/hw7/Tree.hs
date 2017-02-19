import Prelude hiding (lookup, tree)

data BinaryTree k v = Nil | Node k v (BinaryTree k v) (BinaryTree k v) deriving (Eq, Show)

lookup :: Ord k => k -> BinaryTree k v -> Maybe v
lookup k Nil = Nothing
lookup k1 (Node k v l r)    | k == k1 = Just v
							| k <  k1 = (lookup k1 r)
							| otherwise = (lookup k1 l)

insert :: Ord k => k -> v -> BinaryTree k v -> BinaryTree k v
insert k v Nil = Node k v Nil Nil
insert k v (Node k1 v1 l r)     | k1 < k = Node k1 v1 l (insert k v r)
								| k == k1 = Node k v1 l r
								| otherwise = Node k1 v1 (insert k v l) r

merge :: Ord k => BinaryTree k v -> BinaryTree k v -> BinaryTree k v
merge tr Nil = tr
merge Nil tr = tr
merge (Node k1 v1 l1 r1) (Node k2 v2 l2 r2) | k1 < k2 = merge (merge l1 r1) (insert k1 v1 (Node k2 v2 l2 r2))
											| otherwise = merge (insert k2 v2 (Node k1 v1 l1 r1)) (merge l2 r2)

delete :: Ord k => k -> BinaryTree k v -> BinaryTree k v
delete k Nil = Nil
delete k1 (Node k v l r)    | k == k1 = merge l r
							| k < k1 = merge (insert k v l) (delete k1 r)
							| otherwise = merge (delete k1 l) (insert k v r)
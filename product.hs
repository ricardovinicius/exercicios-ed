product' :: [Int] -> Int {-A função product' tem como pattern a entrada de uma lista de inteiros e 
                      a saída de um inteiro -}
product' [] = 1 {-Se a lista estiver vazia, a função retorna 1-}
product' (x:xs) = x * product' xs {-Se a lista não for vazia, a função divide a lista em cabeça (x) e cauda (xs)
                                    e retorna como resultado o produto da cabeça (x) com o resultado da chamada
                                    recursiva passando como parâmetro a cauda (xs)-}

{-Obs: a notação (a:as) ou (x:xs) representa uma notação presente na linguagem Haskell que separa
uma lista em cabeça e cauda, sendo o (x) a cabeça, que é o primeiro elemento da lista;
e o (xs) a cauda, sendo uma lista resultante, que é a lista só que sem o primeiro elemento-}
b = [1,2,3,4,5] {-Inicializa a lista b-}

main = print (product' b) {-Inicializa a função main chamando a função print como parâmetro a função product'-}

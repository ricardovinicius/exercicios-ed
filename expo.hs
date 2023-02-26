expo' :: Int -> Int -> Int {-A função product' tem como pattern a entrada de dois inteiros e 
                            a saída de um inteiro -}
expo' x y                           {-expo' é uma função condicional, portanto: -}
    | y > 0 = x * expo' x (y - 1)   {-se y for maior que 0 retorna o produto de x pela resultado da chamada recursiva de expo
                                     com parâmetros x e y - 1-}
                                    {-Entenda x como a base, e y como o expoente. a função vai chamar recursivamente até y ser 0-}
    | otherwise = 1 {-Quando y for 0, ela retorna 1. atendendo também o caso base da potenciação de quando o expoente for 0-}

main = print (expo' 2 8) {-Inicializa a função main chamando a função print como parâmetro a função expo'-}

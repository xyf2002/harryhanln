module Main where

sayHello :: String -> IO ()
sayHello x = putStrLn("Hello, " ++ x ++ "!")

triple x = x * 3

y = 2
x = 4

main :: IO ()
main = 
  do
    let z = 1 + (23 `rem` 7)
    -- show() function converts it to printalbe string`
    -- '++' is string concatenation 
    print("`rem` make function an infix: " ++ show(z))
    let z = 1 + (rem 23 7)
    print("No infix: " ++ show z)

    print("x/y = " ++ show(x/y))
    print("(/)x y = " ++ show((/) x y))

    -- lambda 
    -- lambda x.x 
    let double = \x ->  x + 10 
    print (identity(4))

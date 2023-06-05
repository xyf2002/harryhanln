module Main where

sayHello :: String -> IO ()
sayHello x = putStrLn("Hello, " ++ x ++ "!")

triple x = x * 3

y = 3 
x = 4

main :: IO ()
main = 
  do print((triple y))

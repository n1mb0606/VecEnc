# VecEnc
String Encrypt to vector
ex)
[Encrypt]
    3 1 2      9 7 8
    5 9 7      4 2 3
    8 6 4      1 5 6
 (Char to Vector) (Vector to Char)

{Char to Vector Map}
Start Point = [0, 1] ('1')
 Char to Encrypt = [1, 1] ('9')
Vector Difference = [1, 0] 

{Vector to Char Map}
Vector Diff to Char = [1, 0]
[1, 0] = [4, 0] ('4')

'9' => '4'

[Decrypt]
    3 1 2      9 7 8
    5 9 7      4 2 3
    8 6 4      1 5 6
 (Char to Vector) (Vector to Char)

 {Vector to Char Map}
 '4' == [1, 0]
 
 {Char to Vector Map}
Start Point = [0, 1] ('1')
Vector Diff = [1, 0]
[0, 1] + [1, 0] = [ 1, 1]('9')

'4' => '9'

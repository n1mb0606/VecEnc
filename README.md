# VecEnc
String Encrypt to vector <br/>
ex)<br/>
[Encrypt]<br/>
    3 1 2&nbsp;&nbsp;9 7 8<br/>
    5 9 7&nbsp;&nbsp;4 2 3<br/>
    8 6 4&nbsp;&nbsp;1 5 6<br/>
 (Char to Vector) (Vector to Char)<br/>
<br/>
{Char to Vector Map}<br/>
Start Point = [0, 1] ('1')<br/>
 Char to Encrypt = [1, 1] ('9')<br/>
Vector Difference = [1, 0] <br/>
<br/>
{Vector to Char Map}<br/>
Vector Diff to Char = [1, 0]<br/>
[1, 0] = [4, 0] ('4')<br/><br/>

'9' => '4'<br/><br/>

[Decrypt]<br/>
    3 1 2&nbsp;&nbsp;9 7 8<br/>
    5 9 7&nbsp;&nbsp;4 2 3<br/>
    8 6 4&nbsp;&nbsp;1 5 6<br/>
 (Char to Vector) (Vector to Char)<br/><br/>

 {Vector to Char Map}<br/>
 '4' == [1, 0]<br/><br/>
 
 {Char to Vector Map}<br/>
Start Point = [0, 1] ('1')<br/>
Vector Diff = [1, 0]<br/>
[0, 1] + [1, 0] = [ 1, 1]('9')<br/><br/>

'4' => '9'<br/>

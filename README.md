Esse código implementa uma possivel solução para o problema "1022 - TAD Racional" da plataforma beecrowd (antigo URI).

O código implementa um Tipo Abstrato de Dados para representar um número racional ($\mathbb{Q}$), i.e. uma fração. O código também implementa um comjunto de operações básicas para trabalhar com frações.

O TAD e suas operações podem ser realocados para uma novo arquivo para serem utilizados separadamentes como um modulo ou biblioteca. Para isso bastaria criar um arquivo de cabeçalho ('.h' ou '.hpp') para o TAD e colocar o todo códico exceto a função main em um novo arquivo expecifico para o TAD.

Para testar o programa basta compila-lo com um compilador c++ e rodar o arquivo executavel.

o programa recebe inicialmente um número $N$ de operações que serão realizadas
cada uma das $N$ seguintes linhas é dada no formato:

$n1$ / $d1$ ($c$) $n2$ / $d2$ 

onde:
$n1$ é o numerador da primeira fração
$d1$ é o denominador da primeira fração  
$n2$ é o numerador da primeira fração
$d2$ é o denominador da primeira fração
$c$ é uma operação (+,-,/ ou *)

Para cada um dessas $N$ linhas o programa retornará o resultado e sua forma irredutivel.


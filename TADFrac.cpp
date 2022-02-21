#include <stdio.h>
#include <iostream>

using namespace std;

typedef long long int LL;


/** TAD que implementa uma fração */
typedef struct{
	LL num;	/** < numerador da fração */
	LL den;	/** < denominador da fração */
} frac;


/**
LL mdc(LL a,LL b)
	
	Função que usa o algoritimo de Euclides para calcular o minimo divisor comum entre dois números

	@param a operando 1, inteiro longo
	@param b operando 2, inteiro longo

	@return iteiro longo, mdc de $a e $b

*/
LL mdc(LL a,LL b){
	if(b==0)return a;
	return mdc(b,a%b);
}

/**
LL mmc(LL a,LL b)

	Função que calcula o minimo multiplo comum entre dois números utilizando a relação entre mdc e mmc

	@param a operando 1, inteiro long
	@param b operando 2, inteiro long

	@return inteiro longo, mmc de $a e $b

*/
LL mmc(LL a,LL b){
	return (a*b)/mdc(a,b);
}

/**
printFrac(Frac a)

	Função que imprime uma fração do TAD frac

	$param a TAD frac, fração que será impressa

*/
void printFrac(frac a){
	printf("%lld/%lld",a.num,a.den);
}

/**
fracreduz(frac a)
	
	função que recebe uma fração(TAD frac) e retorna a forma reduzida dessa fração

	@param a fração para ser reduzida

	@return TAD frac, fração recebida em $a na forma irredutivel

*/
frac reduz(frac a){
	LL sp=mdc(a.num,a.den);
	a.num/=sp;
	a.den/=sp;
	if(a.den<0){
		a.num=-a.num;
		a.den=-a.den;
	}
	return a;
}

/**
frac mult(frac a,frac b)
	
	função que calcula a multiplicação de duas frações

	@param a fração multiplicando
	@param b fração multiplicador

	@return TAD frac, produto de $a e $b
	
*/
frac mult(frac a,frac b){
	a.num *= b.num;
	a.den *= b.den;
	return a;
}

/**
frac divf(frac a, frac b)
	
	Função que calcula a divisão entre frações

	@param a fração dividendo
	@param b fração divisor

	@return TAD frac, quociente da divisão de $a por $b

*/
frac divf(frac a, frac b){
	a.num *= b.den;
	a.den *= b.num;
	return a;
}


/**
frac sum(frac a, frac b)

	Função que calcula a soma entre duas frações
	
	@param a fração da primeira parcela
	@param b fração da segunda parcela

	@return TAD frac, soma de $a + $b

*/
frac sum(frac a, frac b){
	frac r;
	r.den = a.den*b.den;
	r.num = a.num*(r.den/a.den)+b.num*(r.den/b.den);
	return r;
}

/**
frac sub(frac a, frac b)

	Funação que calcula a subtração entre duas frações

	@param a fração, subtraendo
	@param b fração, subtrator

	@return TAD frac, diferença entre $a - $b

*/
frac sub(frac a, frac b){
	frac r;
	r.den = a.den*b.den;
	r.num = a.num*(r.den/a.den)-b.num*(r.den/b.den);
	return r;
}

int main(void){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		char o;
		frac a,b,r;
		scanf("%lld / %lld %c %lld / %lld",&a.num,&a.den,&o,&b.num,&b.den);
		switch(o){
			case '+':
				r = sum(a,b);
				break;
			case '-':
				r = sub(a,b);
				break;
			case '*':
				r = mult(a,b);
				break;
			case '/':
				r = divf(a,b);
				break;
		}
		printFrac(r);
		printf(" = ");
		printFrac(reduz(r));
		puts("");
	}
	return 0;
}


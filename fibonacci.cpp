#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctime>

using namespace std;



//Fibonacci forma recursivo ingenuo
long long int Fib(long long int n){
	
	long long fn;
	
	if ((n == 0) || (n == 1)){	

		return n;
		
	}else{
		return Fib(n-1) + Fib(n-2);
	}

}
//Fibonacci por laco de repeticao
long long int Fib_2(int n){
	long long int f_n2 = 1;
	long long int f_n1 = 1;
	long long int f = 1;
	
	for(int i = 2; i<n;i++){
		f = f_n1 + f_n2;
		f_n2 = f_n1;
		f_n1 = f;
	
	}
	if (n==0){
		return 0;
	}else{
		return f;
	}

}
//Fibonacci usando formula
long long int Fib_3(long long int n){
	double raiz_5 = sqrt(5);
	double Fn = 0, term1 = 0,term2 = 0;

	term1 = pow(((1+ raiz_5)/2),n);
	term2 = pow(((1- raiz_5)/2),n);

	Fn = (1/raiz_5) * (term1 - term2);

	return round(Fn);  
	
}
//funcao auxiliar
long long int powMatrix(long long int matrix[2][2], long long int n)
{
	long long int matrixAux[2][2];
    long long int matrixAux2[2][2];

    matrixAux[0][0] = matrix[0][0];
    matrixAux[0][1] = matrix[0][1];
    matrixAux[1][0] = matrix[1][0];
    matrixAux[1][1] = matrix[1][1];

    matrixAux2[0][0] = matrix[0][0];
    matrixAux2[0][1] = matrix[0][1];
    matrixAux2[1][0] = matrix[1][0];
    matrixAux2[1][1] = matrix[1][1];

    for(int m=0; m<n; m++)
    {
        for (int i=0; i<2; i++)
        {
            for (int j=0; j<2; j++)
            {
                matrixAux[i][j] = 0;
                for (int k=0; k<2; k++)
                {
                    matrixAux[i][j] += matrixAux2[i][k] * matrix[k][j];
                }
            }
        }
        matrixAux2[0][0] = matrixAux[0][0];
        matrixAux2[0][1] = matrixAux[0][1];
        matrixAux2[1][0] = matrixAux[1][0];
        matrixAux2[1][1] = matrixAux[1][1];
    }
    return matrixAux[1][1];
}

//Fibonacci usando matriz
long long int  Fib_4(long long int n){
	long long int matrix[2][2] = {{1,1},{1,0}};

    if(n==1)
    {
        return matrix[0][0];
    }
    else
    {
        return powMatrix(matrix,n);
    }

}
int main(){
	int n;
	clock_t t;
		
	cout<<"N: ";
	cin >> n;
	
	
	t = clock();
	cout << Fib(n)<<endl; // fibonacci recursivo ingenuo
	t = clock() - t;

	printf("tempo = %fs\n",((float)t)/CLOCKS_PER_SEC);	
	

	/*
	t = clock();	
	cout << Fib_2(n)<<endl;
	t = clock() - t;

	printf("tempo = %fs\n",((float)t)/CLOCKS_PER_SEC);	
	*/
	
	/*
	t = clock();
	cout << Fib_3(n)<<endl;
	t = clock() - t;
	printf("tempo = %fs\n",((float)t)/CLOCKS_PER_SEC);	
	*/	
	
	/*
	t = clock();
	cout << Fib_4(n)<<endl;
	t = clock() - t;

	printf("tempo = %fs\n",((float)t)/CLOCKS_PER_SEC);	
	*/
	return 0;
}
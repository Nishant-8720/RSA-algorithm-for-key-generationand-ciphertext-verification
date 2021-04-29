#include<iostream>
#include<math.h>
using namespace std;

// check no is prime or not
bool checkPrimeNumber(long int n) {
    bool isPrime = true; 
    if (n == 0 || n == 1) {
        isPrime = false;
    }
    else {
        for (int i = 2; i <= n / 2; ++i) {
            if (n % i == 0) {
                isPrime = false;
                break;
            }
        }
    }
    return isPrime;
}

int main()
{
	long int p, q, e, plaintext;
	
		cout<<"\n Enter the value of P(Must be Prime) : ";
		cin>>p;
		if(!checkPrimeNumber(p)){
			cout<<"\n Enter the value of P(Must be Prime) : ";
			cin>>p;
			checkPrimeNumber(p);
		}
		cout<<"\n Enter the value of Q(Must be Prime) : ";
		cin>>q;
		if(!checkPrimeNumber(q)){
			cout<<"\n Enter the value of P(Must be Prime) : ";
			cin>>q;
			checkPrimeNumber(q);
		}
		cout<<"\n Enter the Number 'e' value of Text : ";
		cin>>e;
		cout<<"\n Enter the Plaintext : ";
		cin>>plaintext;
		long int n=p*q; 
		long int p1=(p-1);
		long int q1=(q-1);
		long int phi=p1*q1;
		//Private key generation 
		long int d=1;
		for(long int i=0;i<e;i++){
			d=d*e;
			d=d%phi;
		}
		cout<<"\n\n**********OUTPUT**************";
		cout<<"\n\n PU = "<<e<<" , "<<n;
		cout<<"\n\n PR = "<<d<<" , "<<n;
		//Encryption Formula enc=plaintext^e mod n
		long int k=1;
		for(long int i=0;i<e;i++)
		{
			k=k*plaintext;
			k=k%n;
		}
		long int enc=k;
		cout<<"\n\n Encryption Cypertext : "<<enc;

		//Decryption Formula dec=cyphertext^d mod n 
		long int j=1;
		for(long int i=0;i<d;i++)
		{
			j=j*k;
			j=j%n;
		}
		long int dec=j ;
		cout<<"\n\n Decryption : "<<dec;
		cout<<"\n\n****************************";
	return 0;
}
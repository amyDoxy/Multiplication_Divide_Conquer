#include <stdio.h>
#include <iostream> 
#include <sstream>    
#include <iomanip> 
#include <math.h>
using namespace std;

bool isPowerOf2(int num) {
   if (num == 0) return false;
   // if a number 'num' is a power of 2 then
   // (num & num-1) is 0
   bool is_pow = !(num & (num-1));
   return is_pow;
}

void display(){
	cout <<"Hello from Miss Vallen"<<endl;
}

void deleteMessage(){
	cout <<"Message deleted by Miss Vallen"<<endl;
}

int getSize(int number){
	
	int quotient= 1,  i;
	
		//Vu que nous allons entre dans la boucle while au moins une fois, On donne à i la valeur 1
	i = 1;
	quotient = number / 10;
	while(quotient != 0){
	
		quotient = quotient / 10;
		i++;
	}
	return i;
	
}

int* convertIntToArray(int number){
	int i = 0, p = 0; 
	int sizeOfNumber = getSize(number);
	int* arrayOfDigit = NULL;
	int* array = NULL;
	arrayOfDigit = new int[sizeOfNumber]; 
	array = new int[sizeOfNumber];

	while (number) { 
  	  arrayOfDigit[i++] = number % 10; 
  	  number /= 10; 
	}

	for(int j = sizeOfNumber-1; j >= 0; j--){
		array[p] = arrayOfDigit[j];
		p++;
	}
	return array;
}

void divideAndConquer(int multiplier , int multiplicand){
	
	int p = 0, q = 0, n = 0, valeur1, valeur2;
	 int sizeMultiplier = getSize(multiplier);
	 int sizeMultiplicand = getSize(multiplicand);
	
	
	
}


int multiplicationOneByOne(int val1, int val2){

	int *arrayVal1 = convertIntToArray(val1);
	int *arrayVal2 = convertIntToArray(val2);
	int result = 0;
	cout<<endl;
	for(int i = 0; i <2; i++){

		for(int j = 0; j < 2; j++){
			
			int decalageVal1 = 2 -(i+1);
			int decalageVal2 = 2 - (j+1);


			int decalageTotal = decalageVal1 + decalageVal2;
			int produit = arrayVal1[i] * arrayVal2[j];
			int produitDecale = produit*pow(10, decalageTotal);
			cout << arrayVal1[i] <<" * " << arrayVal2[j] << " = " << produit;

			result += produitDecale;

			cout <<endl;

		}
	}

	return result;
}


void multiplication(int* multiplier, int* multiplicand, int sizeArray){
	int produit =0;

	for(int i = 0; i <sizeArray-1; i+=2){

		for(int j = 0; j < sizeArray-1; j+=2){
			cout <<endl;
			int valMultiplier = (multiplier[i] * 10) + multiplier[i+1];
			int valMultiplicand = (multiplicand[j] * 10) + multiplicand[j+1];

			int decalageVal1 = sizeArray -(i+2);
			int decalageVal2 = sizeArray- (j+2);
			int decalageTotal = decalageVal1 + decalageVal2;
			cout << valMultiplier <<" * " << valMultiplicand <<endl;
			int resultOneByOne = multiplicationOneByOne(valMultiplier, valMultiplicand) ;
			int produitDecale = resultOneByOne*pow(10, decalageTotal);
			cout << valMultiplier <<" * " << valMultiplicand << " = "<< resultOneByOne<<endl;

			produit += produitDecale;
			
		}
		cout <<endl;
	}
	cout <<"Le prodiuit de la multiplication = "<< produit<< endl;
}


int main(){
	
	//divideAndConquer(981, 1234);
		int nombre1 ;
	int nombre2 ;
	std::ostringstream oss;
	
	
	cout << "veuillez inserer 1 nbr: "<<endl;
	cin >> nombre1;
	cout << "veuillez inserer le 2e nbr: " <<endl;
	cin >> nombre2;
	int nbreDeChiffre1 = (int) (1 + log10(nombre1));
	int nbreDeChiffre2 = (int) (1 + log10(nombre2));

	cout << "le nbr de chiffre num 1 : " << nbreDeChiffre1 << endl;
	cout << "le nbr de chiffre num 2 : " << nbreDeChiffre2 << endl;
	
	//Ici on cherche le nombre ayant le plus de chiffres entre les deux
	
	if(nbreDeChiffre1 >= nbreDeChiffre2){
		int nbreGrand = nbreDeChiffre1;
		 bool is_pow_2 = isPowerOf2(nbreGrand);
		 if(is_pow_2){
	 		//ici on ajoute au plus petit nbreGrand - nbreChiffre2 0 ;
	 		//exemple concret:981 a 3 chiffre, ns allons ajouter 4 - 3= 1 zero devant 981
	 	
	 		oss << setfill ('0') <<setw (nbreGrand);
 			oss << nombre2 <<endl;
 			string s = oss.str();
    		cout<<s<<endl;
   
			char *cstr = new char[s.length() + 1];
			strcpy(cstr, s.c_str());
			int nombre2 = atoi(cstr);


	 	}
	}else{
		int nbreGrand = nbreDeChiffre2;
		 bool is_pow_2 = isPowerOf2(nbreGrand);
		 if(is_pow_2){
	 		
	 	
	 		oss << setfill ('0') <<setw (nbreGrand);
 			oss << nombre1 <<endl;
 			string s = oss.str();
    		cout<<s<<endl;
   
			char *cstr = new char[s.length() + 1];
			strcpy(cstr, s.c_str());
			int nombre1 = atoi(cstr);
	 	}
	 	
	}
	int* array1 = convertIntToArray(nombre1);
	int *array2 = convertIntToArray(nombre2);
	int size1 = sizeof(array1)/sizeof(array1[0]);
	int size2 = sizeof(array2)/sizeof(array2[0]);
	int size =(size1 >= size2)?size1: size2;

	multiplication(array1, array2, 4);
	cout <<"Hello"<<endl;
	return 0;
}

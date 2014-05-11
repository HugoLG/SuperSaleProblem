#include <iostream>

using namespace std;

double vPos = 0;
double vAcum = 0;
double pAcum = 0;
double valorOptimo = 0;

double mat [1005][3];

void ordenarMat(int n) {
	for(int a = 0; a<n; a++) {
		for(int b = 0; b<n-1; b++) {
			if(mat[b][2] <= mat[b+1][2]) {
				double tempvp, tempv, tempp;
				tempv = mat[b][0];
				tempp = mat[b][1];
				tempvp = mat[b][2];
				mat[b][0] = mat[b+1][0];
				mat[b][1] = mat[b+1][1];
				mat[b][2] = mat[b+1][2];
				mat[b+1][0] = tempv;
				mat[b+1][1] = tempp;
				mat[b+1][2] = tempvp;
			}
		}
	}
}

double calcularValorPosible (int indice, int indiceMax, double pesoMax) {
	double tempPeso = pAcum;
	double resultVP = vAcum;
	int x;
	for(int i=indice; i<indiceMax; i++) {
		if(mat[indice][1] + tempPeso < pesoMax) {
			resultVP += mat[indice][0];
			tempPeso += mat[indice][1];
			x = indice;
		} 
	}
	
	resultVP += (pesoMax - tempPeso)*(mat[x+1][1]);
	
	return resultVP;
}

double valor(int iAct, int iMax, int pMax) {
	double tempvPos = calcularValorPosible(iAct, iMax, pMax);
	double tempvAcum = 0;
	double temppAcum = 0;
	
	
	
	return 0.0;
}

int main() {
	int casos;
	cin >> casos;

	while(casos > 0) {
		int numObj;
		cin >> numObj;
		
		for(int i=0; i<numObj; i++) {
			cin >> mat[i][0];
			cin >> mat[i][1];
			mat[i][2] = mat[i][0] / mat[i][1];
		}

		ordenarMat(numObj);
		
		int numPersonas;
		cin >> numPersonas;
		
		while(numPersonas > 0) {
			valorOptimo = 0;
			
			double pesoMax;
			cin >> pesoMax;
			
			
			
			numPersonas--;
		}
		
		/* Imprimir tabla de objetos
		cout<<"Valor	Peso	Valor/Peso"<<endl;
		for(int i=0; i<numObj; i++) {
			cout<<mat[i][0]<<"  "<<mat[i][1]<<"  "<<mat[i][2]<<endl;
		}
		*/

		casos--;
	}	


}


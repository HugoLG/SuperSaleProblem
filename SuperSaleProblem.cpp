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

double calcularValorPosible (int indice, int indiceMax, double pesoMax, double va, double pa) {
	double tempPeso = pa;
	double resultVP = va;

	while( (mat[indice][1] + tempPeso <= pesoMax) && (indice < indiceMax) ) {
		resultVP += mat[indice][0];
		tempPeso += mat[indice][1];
		indice++;
		//~ cout << "resultVP #" << indice << "  " << resultVP << endl;
	}
	
	resultVP += (pesoMax - tempPeso)*(mat[indice][2]);
	
	return resultVP;
}

double calcularPesoAcum(int indice, double pa) {
	pa += mat[indice][1];
	
	return pa;
}

double calcularValAcum(int indice, int indiceMax, double va) {
	va += mat[indice][0];
	
	return va;
}

void valor(int indice, int indiceMax, double pesoMax, double vp, double va, double pa) {
	//~ double hijo1 = 0.0, hijo2 = 0.0;
	if(indice < indiceMax && pa <= pesoMax) {
		
		if(calcularValorPosible(indice, indiceMax, pesoMax, va, pa) > valorOptimo) {
			double tempValor = calcularValAcum(indice,indiceMax, va);
			double tempPeso = calcularPesoAcum(indice, pa);
			if(tempValor > valorOptimo && tempPeso <= pesoMax) {
				valorOptimo = tempValor;
			}
			
			valor(indice+1, indiceMax, pesoMax, calcularValorPosible(indice+1, indiceMax, pesoMax, tempValor, tempPeso), tempValor, tempPeso);
			valor(indice+1, indiceMax, pesoMax, calcularValorPosible(indice+1, indiceMax, pesoMax, vp, va), va, pa); 
		}
		
	}
	//~ return max(hijo1, hijo2);
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
		//~ cout << "Valor Optimo: " << valorOptimo << endl;
		//~ valor(0,numObj, 16, 115, 0,0);
		//~ cout << "Valor Optimo: " << valorOptimo << endl;
		
		int numPersonas;
		cin >> numPersonas;
		
		double result = 0;
		while(numPersonas > 0) {
			valorOptimo = 0;
			
			double pesoMax;
			cin >> pesoMax;
			
			double vp = calcularValorPosible(0, numObj, pesoMax, 0, 0);
			
			valor(0, numObj, pesoMax, vp, 0, 0);
			
			//~ cout << "resultado parcial:  " << valorOptimo << endl;
			result += valorOptimo;
			numPersonas--;
		}
		
		//~ cout<<"Valor	Peso	Valor/Peso"<<endl;
		//~ for(int i=0; i<numObj; i++) {
			//~ cout<<mat[i][0]<<"  "<<mat[i][1]<<"  "<<mat[i][2]<<endl;
		//~ }
		
		cout << result << endl;

		casos--;
	}	


}


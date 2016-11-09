#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define L 5
#define lp 2
#define d 1
#define h 0.02
#define V0 100
#define N 125000
#define saltofila 250
#define w 1.97
#define dim 62500
void actualizar(float *v);
void iniciarEx(float *Ex,float *v);
void iniciarEy(float *Ey,float *v);

int main(){
  /*Inicializo la lista de potenciales */
  float *v;
  int i;
  int k;
  v=malloc(dim*sizeof(float));
  for(i=0;i<24824;i++){
    v[i]=1.0;
  }
  for(i=24824;i<=24924;i++){
    v[i]=((float)V0)/2.0;
  }
  for(i=24925;i<37324;i++){
    v[i]=1.0;
  }
  for(i=37324;i<=37424;i++){
    v[i]=-((float)V0)/2.0;
  }
  for(i=37425;i<dim;i++){
    v[i]=1.0;
  }
  /* Saco promedios N veces*/
  for(i=0;i<N;i++){
    actualizar(v);
  }
  /*Defino las lista de los campos electricos*/
  float *Ex;
  float *Ey;
  Ex=malloc(dim*sizeof(float));
  Ey=malloc(dim*sizeof(float));
  iniciarEx(Ex,v);
  iniciarEy(Ey,v);
  


  
  /*imprimo los datos*/
  for(i=0;i<250;i++){
   
    for(k=0;k<250;k++){
      printf("%f ",v[(250*i)+k]);
       }
    for(k=0;k<250;k++){
      printf("%f ",Ex[(250*i)+k]);
       }
    for(k=0;k<250;k++){
      if(k==249){
	printf("%f \n",Ey[(250*i)+k]);
      }
      else{
	printf("%f ",Ey[(250*i)+k]);
      }
       }
  }
  
  return 0;
}

void actualizar(float* v){
  v[0]=(1-w)*v[0]+(w/4)*(v[1]+v[250]);
  int i;
  for(i=1;i<249;i++){
    v[i]=(1-w)*v[i]+(w/4)*(v[i+1]+v[i-1]+v[i+250]);
  }
  v[249]=(1-w)*v[249]+(w/4)*(v[248]+v[499]);
  for(i=250;i<24824;i++){
    if(i%250==0){
      v[i]=(1-w)*v[i]+(w/4)*(v[i+1]+v[i-250]+v[i+250]);
    }
    else if(i%250==249){
      v[i]=(1-w)*v[i]+(w/4)*(v[i-1]+v[i-250]+v[i+250]);
    }
    else{
      v[i]=(1-w)*v[i]+(w/4)*(v[i-1]+v[i+1]+v[i-250]+v[i+250]);
      }
  }
  for(i=24925;i<37324;i++){
    if(i%250==0){
      v[i]=(1-w)*v[i]+(w/4)*(v[i+1]+v[i-250]+v[i+250]);
    }
    else if(i%250==249){
      v[i]=(1-w)*v[i]+(w/4)*(v[i-1]+v[i-250]+v[i+250]);
    }
    else{
      v[i]=(1-w)*v[i]+(w/4)*(v[i-1]+v[i+1]+v[i-250]+v[i+250]);
    }
  }
  for(i=37425;i<62250;i++){
    if(i%250==0){
      v[i]=(1-w)*v[i]+(w/4)*(v[i+1]+v[i-250]+v[i+250]);
    }
    else if(i%250==249){
      v[i]=(1-w)*v[i]+(w/4)*(v[i-1]+v[i-250]+v[i+250]);
    }
    else{
      v[i]=(1-w)*v[i]+(w/4)*(v[i-1]+v[i+1]+v[i-250]+v[i+250]);
      }
  }
  v[62250]=(1-w)*v[62250]+(w/4)*(v[62251]+v[62000]);
  for(i=62251;i<=62498;i++){
    v[i]=(1-w)*v[i]+(w/4)*(v[i-1]+v[i+1]+v[i-250]);
  }
  v[62499]=(1-w)*v[62499]+(w/4)*(v[62498]+v[62249]);
  
}

void iniciarEx(float* Ex, float* v){
  int i;
  for(i=0;i<dim;i++){
    if(i%250==0){
      Ex[i]=-v[i+1]/(2.0*h);
    }
    else if(i%250==249){
      Ex[i]=v[i-1]/(2.0*h);
    }
    else{
      Ex[i]=(v[i-1]-v[i+1])/(2.0*h);
    }
  }
}

void iniciarEy(float* Ey,float* v){
  int i;
  for(i=0;i<250;i++){
    Ey[i]=-v[i+250]/(2.0*h);
  }
  for(i=250;i<62250;i++){
    Ey[i]= (v[i-250]-v[i+250])/(2.0*h);
  }
  for(i=62250;i<62500;i++){
    Ey[i]=v[i-250]/(2.0*h);
  }
}

/* Program wczytujący dane i obliczajacy stopnie grafu i jego wierzcholkow
*(C) 2015 Marcin Dawidowski
*/

#include <stdio.h>
int main(){
  int vertices, edges; 
  int i, j, x, y; 
  int v1 = 0, v2 = 0, status = 0; 
  int vmax = 0, degree = 0; 
  printf("Prosze podac liczbe wierzcholkow.\n");
  scanf("%d", &vertices);
  printf("Prosze podac liczbe krawedzi.\n");
  scanf("%d", &edges);
  // tworzenie pustej tablicy (macierzy) dla grafu
int graph[vertices][edges];
 for (i = 0; i < vertices; i++) {
    for (j = 0; j < vertices; j++) {
      graph[i][j] = 0; } }
 
// wczytywanie danych
  for(x = 0; x < edges; x++){ 
    do{
      status = 1;
      printf("Prosze wprowadzic pierwszy wierzcholek %d krawedzi: \t", x+1);
      scanf("%d",&v1);
      printf("Prosze wprowadzic drugi wierzcholek %d krawedzi: \t", x+1);
      scanf("%d",&v2);
      // sprawdzanie poprawnosci wprowadzanych danych
    if (v1 < 1 || v2 < 1){
        printf("Zle! Indeks Wierzcholkow nie moze byc mniejszy niz 1.\n");
        status=0; }
    if (v1 > vertices || v2 > vertices){
        printf("Zle! Wierzcholek nie moze byc wiekszy niz: (%d)!\n", vertices);
        status=0; }

   

   printf(" \n"); 
  }
     while (!status);
     // wczytywanie do tablicy
     graph[v1-1][v2-1] += 1;
     graph[v2-1][v1-1] += 1; 
  }


//obliczanie stopnia wierzcholkow
  for(x = 0; x < vertices; x++){
    for(y = 0; y <= vertices - 1; y++){
      degree += graph[x][y]; }
      printf("Wierzcholek %d ma stopien %d. \n", x+1, degree);
  // obliczanie stopnia grafu
      if ( degree > vmax ){
      vmax = degree;
      }
      degree=0;
      } 

printf(" \n");
printf("Stopien grafu wynosi: %d\n", vmax); 
return 0;
}

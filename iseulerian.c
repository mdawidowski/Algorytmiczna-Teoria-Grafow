/* Program wczytujący dane i obliczajacy stopnie grafu i jego wierzcholkow
*(C) 2015 Marcin Dawidowski
*/

#include <stdio.h>
int main(){
  int vertices, edges; 
  int i, j, x, y = 0;
  int v1 = 0, v2 = 0, status = 0; 
  int memory[y];     // ciąg kolejno wybranych cyfr
  int vmax = 0, degree = 0; 
  printf("Prosze podac liczbe wierzcholkow.\n");
  scanf("%d", &vertices);
  printf("Prosze podac liczbe krawedzi.\n");
  scanf("%d", &edges);
  // tworzenie pustej tablicy (macierzy) dla grafu
  int pom = 0;
  int graph[vertices][edges];
  int visited[y];
  for (i = 0; i < vertices; i++) {
    for (j = 0; j < vertices; j++) {
      graph[i][j] = 0;
      visited[i] = 0;
      memory[i] = 0; } }
 

// wczytywanie danych
   for(x = 0; x < edges; x++){ 
     
    do{
      status = 1;
      printf("Prosze wprowadzic pierwszy wierzcholek %d krawedzi: \t", x+1);
      scanf("%d",&v1);
      memory[y] = v1;
      printf("Prosze wprowadzic drugi wierzcholek %d krawedzi: \t", x+1);
      scanf("%d",&v2);
      memory[y+1] = v2;
      y += 2;
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
           if (degree <= 0 || degree % 2 !=0){
       printf("Graf niespojny lub posiada wierzcholek nieparzystego stopnia\n");
      return 0;}
     
  // obliczanie stopnia grafu
	if ( degree > vmax ){
	  max = degree;
	}
	  degree=0; 
	} 
  
  printf(" \n");
  printf("Stopien grafu wynosi: %d\n", vmax); 
      
  printf("\n\t Macierz sasiedztwa ma nastepujaca postac :\n");

  for(x=0; x<vertices; x++){
    for(y=0; y<vertices-1; y++){     
      printf("\t %d",graph[x][y]);} 
    printf("\t %d\n",graph[x][y]);}
 
 y = 0;
 
  //sprawdzanie czy graf jest grafem eulerowskim

 for(y = 0; y < vertices; y++){
   pom = memory[y];
   visited[pom] += 1;
 }
   for(y = 0; y < vertices; y++){
     if(visited[y] = 0 ){
   printf("Graf nie jest grafem eulerowskim");}
     else printf("Graf jest eulerowski");
 } 
}

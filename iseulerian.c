//program sprawdzający czy graf jest eulerowski
#include <stdio.h>

	int vertices, edges;								
	int i, j, x, y;						
	int start = 0, stop = 0, status = 0;	
	int max = 0, degree = 0;		
	int wiersz = 0, kolumna = 0;		
	int pa;
	int graf[1][1];
	
int main(){

	printf("Proszę podać liczbę wierzchołków: \t");
	scanf("%d", &vertices);
	
	printf("Proszę podać liczbę krawędzi: \t\t");
	scanf("%d", &edges);
	
	int graf[vertices][vertices];
	
	// zerowanie macierzy
	for (i=0; i<vertices; i++) {
		for (j=0; j<vertices; j++) {
			graf[i][j] = 0; } }

	// wczytywanie grafu	
	for(x=0; x<edges; x++){				
		do{
			status= 1;
			printf("Prosze wprowadzic pierwszy wierzcholek krawedzi %d: \t", x+1);
			scanf("%d",&start);
			printf("Prosze wprowadzic drugi wierzcholek krawedzi %d: \t", x+1);
			scanf("%d",&stop);            
               	
            if (start < 1 || stop < 1){ 
               	printf("Error!! Indeks Wierzcholkow nie moze byc mniejszy od 1.\n");
               	status=0;	}

            if (start > vertices || stop > vertices){
               	printf("Error!! Wierzcholek nie moze byc wiekszy od liczby: (%d)!\n", vertices);
               	status=0;	}
        }        
		while (!status);
        
	if (graf[start-1][stop-1]==1){
		printf("Podany Graf nie moze byc multigrafem.\n");
	return main();	}
	
	// wczytywanie do macierzy dwuwymiarowej 'graf'
	graf[start-1][stop-1] += 1;
	graf[stop-1][start-1] += 1; 
	
	}	// koniec duzego fora
	
	printf(" \n");	// linia przerwy
	
	// stopien wierzcholka
	for(x=0; x<vertices; x++){    
		for(y=0; y<=vertices-1; y++){       		   
			degree += graf[x][y]; }
		  if(degree%2==0){
			pa+=1; }
		                        
		  printf("\t Wierzcholek o numerze %d ma stopien %d. \n", x+1, degree);
	          if ( degree > max ){ 
			max = degree;
		}
       		degree=0; 
	}	// koniec malego fora
	
	printf(" \n");
	printf("\t Stopien grafu wynosi: %d\n", max);	// Stopien grafu
	
	printf("\n\t Macierz sasiedztwa ma nastepujaca postac :\n");
	for(x=0; x<vertices; x++){
   	for(y=0; y<vertices-1; y++){     
		printf("\t %d",graf[x][y]);} 
        printf("\t %d\n",graf[x][y]);}
		
	//Trzeci for
	for(x=0;x<vertices;x++){    
		for(y=0;y<=vertices-1;y++){
			if(vertices%2==0){
				if(graf[y][x]==1){
				wiersz=1; }
				if(graf[y][x]==0){
				kolumna=1; }
            }    
			else{
			if(graf[y][x]==1){
            wiersz=1; }
			if(graf[y][x]==0){
			kolumna=1; }
			}
		} 
	}
	
	printf(" \n");
	
//	printf("pa= %d, max= %d, wiersz= %d, kolumna= %d.\n", pa, max, wiersz, kolumna); 
	
	if(vertices>edges){
		printf("\t Niestety. Graf nie jest eulerowski. \n"); }
		else {
			if(pa>=1 & max%2==0 & wiersz==kolumna){
			printf("\t Graf jest eulerowski \n"); }
				else{
					printf("\t Niestety. Graf nieeulerowski.\n"); }
		}

return 0;
}

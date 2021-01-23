#include <stdio.h>
#define MAX_PARTICIPANTES 10

void leerHoras(int salida[], int llegada[], int num_participantes);
void ganador(int salida[], int llegada[], int num_participantes, int *identificador_ganador);

int main(){
	int vectSalida[MAX_PARTICIPANTES], vectLlegada[MAX_PARTICIPANTES], ids[MAX_PARTICIPANTES];
	int i, nparticipantes;
	
	printf("Cuantos participantes habrá en el rally? ");
	scanf("%d", &nparticipantes);

	while(nparticipantes > MAX_PARTICIPANTES){
		printf("El numero máximo de participantes es %d, cuántos participantes habrá en el rally? ", MAX_PARTICIPANTES);
		scanf("%d", &nparticipantes);
		
	}

	leerHoras(vectSalida, vectLlegada, nparticipantes);
	
	ganador(vectSalida, vectLlegada, nparticipantes, ids);
	
	return 0;
}


void leerHoras(int salida[], int llegada[], int num_participantes){
	int i;
	for(i=0; i < num_participantes; i++){
		printf("Teclee la hora de salida del automovil #%d ( en segundos ): ", i+1);
		scanf("%d", &salida[i]);

		printf("Teclee la hora de llegada del automovil #%d ( en segundos ):", i+1);
		scanf("%d", &llegada[i]);
	}
}


void ganador(int salida[], int llegada[], int num_participantes, int *identificador_ganador){
	int i = 0, idgan;
	int minLlegada = llegada[0] - salida[0];

	while(i < num_participantes){
		*(identificador_ganador+i) = i+1;

		if((llegada[i] - salida[i]) < minLlegada){
			minLlegada = llegada[i] - salida[i];
			idgan = i+1;
		}
		i++;
	}

	printf("El ganador con el id %d es el ganador con %d segundos de diferencia\n", idgan, minLlegada);
}

#include <stdio.h>
#include <mpi.h>


int main(int argc, char** argv){
	//memulai program dengan memanggil fungsi environment
	//MPI_init(NULL,NULL);
	MPI_Init(NULL,NULL);
	
	//mendapat nilai jumlah processor yang bekerja
	int world_size;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
	
	//mendapat nilai rank id processor
	int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
	
	int token;
	if(world_rank != 0){
		MPI_Recv(&token, 1, MPI_INT, world_rank -1,0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("proses %d menerima token %d dari proses %d \n", world_rank, token, world_rank-1);
	}else{
		//menentukan nilai token saat proses 0
		token=-1;
	}
	MPI_Send(&token, 1, MPI_INT,(world_rank+1)%world_size,0,MPI_COMM_WORLD);
	
	//sekarang proses 0 menerima lagi 
	if(world_rank == 0){
		MPI_Recv(&token, 1, MPI_INT, world_size-1, 0, MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		printf("Proses %d menerima token %d dari proses %d\n",world_rank,token,world_size-1);
	}

	
	MPI_Finalize();
}
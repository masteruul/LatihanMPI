#include <stdio.h>
#include <mpi.h>


int main(int argc, char** argv){
	//memulai program dengan memanggil fungsi environment
	//MPI_init(NULL,NULL);
	MPI_INIT(NULL,NULL);
	
	//mendapat nilai jumlah processor yang bekerja
	int world_size;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
	
	//mendapat nilai rank id processor
	int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
	
	int number;
	if(world_rank == 0){
		number = -1;
		//MPI_Send(void* data,int count,MPI_Datatype datatype,int destination,int tag,MPI_Comm communicator)
		MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
		printf("Proses 1 dikirim, data yang dikirim %d dari proses %d\n",number,world_rank);
	}else if(world_rank == 1){
		//MPI_Recv(void* data,int count,MPI_Datatype datatype,int source,int tag,MPI_Comm communicator,MPI_Status* status)
		MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		printf("Proses 1 diterima, data yang diterima %d dari proses %d\n",number,world_rank);
	}
	
	MPI_Finalize();
}
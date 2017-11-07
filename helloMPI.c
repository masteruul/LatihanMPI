#include <mpi.h>
#include <stdio.h>


int main(int argc, char** argv){
	//memulai program dengan memanggil fungsi environment 
	MPI_Init(NULL,NULL);
	
	
	//mendapat nilai jumlah processor yang bekerja
	int world_size;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
	
	//mendapat nilai rank id processor
	int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
	
	//mendapatkan nama pemroses(computer) yang bekerja
	char processor_name[MPI_MAX_PROCESSOR_NAME];
	int name_len;
	MPI_Get_processor_name(processor_name, &name_len);
	
	//mencetak kata hello_ganteng ke layar
	printf("Hello Ganteng !! , dapet salam dari computer %s, rank %d"
			" dari %d processor\n",processor_name, world_rank, world_size);
			
	//Mengakhiri Environment MPI
	MPI_Finalize();
	
	
}
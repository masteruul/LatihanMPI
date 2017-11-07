/*
	created by M Syamsul Huda
	inspired from our creator ||ALLAH SWT|| that make internet and google usefully :)
*/
#include <stdio.h>
#include <mpi.h>



int main(int argc, char** argv){
	//memulai program dengan memanggil fungsi environment
	//MPI_init(NULL,NULL);
	MPI_Init(NULL,NULL);
	
	const int maxpingpong=10;
	//mendapat nilai jumlah processor yang bekerja
	int world_size;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
	
	//mendapat nilai rank id processor
	int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
	
	if(world_size % 2 != 0){
		printf("World size harus berukuran 2 atau kelipatannya untuk %s \n",argv[0]);
		//memanggil fungsi pembatalan program
		MPI_Abort(MPI_COMM_WORLD,1);
	}
	
	//Ping pong algoritm
	
	int ping_pong_count = 0 ;
	int partner_rank = (world_rank+1) % 2;
	
	while(ping_pong_count < maxpingpong){
		if(world_rank == ping_pong_count%2 ){
			//naikkan indeks ping pong sebelum dikirim
			ping_pong_count++;
			MPI_Send(&ping_pong_count, 1, MPI_INT, partner_rank, 0, MPI_COMM_WORLD);
			printf("%d mengirim & menaikkan nilai ping_pong %d ke %d\n",world_rank, ping_pong_count, partner_rank);
		}else{
			MPI_Recv(&ping_pong_count, 1, MPI_INT, partner_rank, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			printf("%d menerima  nilai ping_pong %d dari %d\n",world_rank, ping_pong_count, partner_rank);
		}
		
	}
	
	MPI_Finalize();
}
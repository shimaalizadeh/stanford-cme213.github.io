#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    // Initialize the MPI environment
    MPI_Init(NULL, NULL);

    // Find out the rank and size
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    srand(rank); // Initialize the random number generator
    int number_send, number_recv;
    number_send = rand() % 100;

    if (rank % 2 == 0)
    {
        int rank_receiver = rank == world_size - 1 ? 0 : rank + 1;
        MPI_Send(&number_send, 1, MPI_INT, rank_receiver,
                 0, MPI_COMM_WORLD);
        printf("Process %d sent \t\t %2d to   process %d\n", rank,
               number_send, rank_receiver);
    }
    else
    {
        int rank_sender = rank == 0 ? world_size - 1 : rank - 1;
        MPI_Recv(&number_recv, 1, MPI_INT, rank_sender,
                 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process %d received \t %2d from process %d\n", rank,
               number_recv, rank_sender);
    }

    if (rank % 2 == 1)
    {
        int rank_receiver = rank == world_size - 1 ? 0 : rank + 1;
        MPI_Send(&number_send, 1, MPI_INT, rank_receiver,
                 0, MPI_COMM_WORLD);
        printf("Process %d sent \t\t %2d to   process %d\n", rank,
               number_send, rank_receiver);
    }
    else
    {
        int rank_sender = rank == 0 ? world_size - 1 : rank - 1;
        MPI_Recv(&number_recv, 1, MPI_INT, rank_sender,
                 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process %d received \t %2d from process %d\n", rank,
               number_recv, rank_sender);
    }

    MPI_Finalize();

    return 0;
}

void slide()
{

    if (rank % 2 == 0)
    {
        int rank_receiver = rank == world_size - 1 ? 0 : rank + 1;
        MPI_Send(&number_send, 1, MPI_INT, rank_receiver,
                 0, MPI_COMM_WORLD);
    }
    else
    {
        int rank_sender = rank == 0 ? world_size - 1 : rank - 1;
        MPI_Recv(&number_recv, 1, MPI_INT, rank_sender,
                 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }

    if (rank % 2 == 1)
    {
        int rank_receiver = rank == world_size - 1 ? 0 : rank + 1;
        MPI_Send(&number_send, 1, MPI_INT, rank_receiver,
                 0, MPI_COMM_WORLD);
    }
    else
    {
        int rank_sender = rank == 0 ? world_size - 1 : rank - 1;
        MPI_Recv(&number_recv, 1, MPI_INT, rank_sender,
                 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }
}
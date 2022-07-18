#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h> 
#include <stdlib.h>

#define SEMKEYPATH "."
#define SEMKEYID 1
#define SHMKEYPATH "."
#define SHMKEYID 1
#define NUMSEMS 2

typedef struct
{
	int id;
	char string[BUFSIZ];
} msgs;

typedef struct
{
	int id;
	char bank[11], deck1[11], deck2[11];
} games;

int main()
{
	int rc, semid, shmid;
	msgs* shm_address;

	struct sembuf operations[2];
	struct shmid_ds shmid_struct;

	short sarray[NUMSEMS];

	std::string buf, num_buf;

	int semkey = ftok(".", 'm');
	int id = 0, num = 0, buf_num = 0, sum1 = 0, sum2 = 0, pos = 0, start_game_flag = 0;
	games g_arr[5];
	if (semkey < 0) // proof key
	{
		printf("Wrong key\n");
		return 1;
	}

	int shmkey = ftok(".", 'm');
	if (shmkey < 0) // proof key
	{
		printf("Wrong key\n");
		return 1;
	}


	/* Создаем набор семафоров на основе IPC ключа. Количество семафоров равно двум.*/

	semid = semget(semkey, NUMSEMS, 0666 | IPC_CREAT | IPC_EXCL);

	if (semid == -1)
	{
		perror("server: semget() failed");
		return -1;
	}

	sarray[0] = 0;
	sarray[1] = 1;
	rc = semctl(semid, 1, SETALL, sarray);
	if (rc == -1)
	{
		perror("server: semctl() initialization failed");
		return -1;
	}
	/* Создаем сегмент разделяемой памяти постоянного размера.*/
	shmid = shmget(shmkey, sizeof(shm_address), 0666 | IPC_CREAT | IPC_EXCL);
	if (shmid == -1)
	{
		perror("server: shmget() failed");
		return -1;
	}
	shm_address = (msgs*)shmat(shmid, NULL, 0); /* Присоединяем сегмент разделяемой памяти к процессу серверу*/



	for (int i = 0; i < 5; i++)
	{
		g_arr[i].id = -1;
	}


	int n = 1, m = 1;

	while (1)
	{

		operations[0].sem_num = 0;
		operations[0].sem_op = -1;
		operations[0].sem_flg = 0;

		operations[1].sem_num = 1;
		operations[1].sem_op = 0;
		operations[1].sem_flg = 0;
		rc = semop(semid, operations, 2);
		if (rc == -1)
		{
			perror("server: semop() failed");
			return -1;
		}
		printf("Start reading\n\n");
		start_game_flag = 1;
		id = shm_address->id;
		buf.clear();

		printf("Now working pid %d\n\n", id);

		for (int i = 0; i < 5; i++)
		{
			if (g_arr[i].id == id)
			{
				printf("For pid %d game %d already exists\n\n", id, i);
				pos = i;
				start_game_flag = 0;
				break;
			}
		}

		printf("Start_game_flag = %d\n\n", start_game_flag);

		if (start_game_flag == 1)
		{
			srand(time(NULL));

			for (int i = 0; i < 5; i++)
			{
				if (g_arr[i].id == -1)
				{
					printf("For pid %d creating game %d\n\n", id, i);
					g_arr[i].id = id;
					pos = i;
					start_game_flag = 0;
					break;
				}
			}

			for (int i = 0; i < 11; i++)
			{
				g_arr[pos].bank[i] = 1;
				g_arr[pos].deck1[i] = 0;
				g_arr[pos].deck2[i] = 0;
			}
			num = rand() % 10 + 1;

			while (g_arr[pos].bank[num] != 1)
			{
				num = rand() % 10 + 1;
			}

			g_arr[pos].bank[num] = 0;
			g_arr[pos].deck1[0] = num;
			buf_num = num;

			while (g_arr[pos].bank[num] != 1)
			{
				num = rand() % 10 + 1;
			}

			g_arr[pos].bank[num] = 0;
			g_arr[pos].deck2[0] = num;



			sprintf(shm_address->string, "Player1:\nYour card is: %d\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPlayer2:\nYour card is: %d\n", buf_num, num);
			buf = "Player1:\nYour";



		}
		else
		{

			if (shm_address->string[0] == 'Y')
			{
				num = rand() % 10 + 1;

				while (g_arr[pos].bank[num] != 1)
				{
					num = rand() % 10 + 1;
				}

				g_arr[pos].bank[num] = 0;
				g_arr[pos].deck1[n] = num;
				n += 1;
			}

			if (shm_address->string[1] == 'Y')
			{
				num = rand() % 10 + 1;

				while (g_arr[pos].bank[num] != 1)
				{
					num = rand() % 10 + 1;
				}

				g_arr[pos].bank[num] = 0;
				g_arr[pos].deck2[m] = num;
				m += 1;
			}
			buf = "Player1, your cards: # ";
			for (int i = 1; i < 11; i++)
			{
				if (g_arr[pos].deck1[i] != 0)
				{
					buf += std::to_string(g_arr[pos].deck1[i]);
					buf += " ";
				}
			}
			buf += "\n\nPlayer2, your cards: # ";
			for (int i = 1; i < 11; i++)
			{
				if (g_arr[pos].deck2[i] != 0)
				{
					buf += std::to_string(g_arr[pos].deck2[i]);
					buf += " ";
				}
			}

			if ((shm_address->string[0] == 'N') && (shm_address->string[1] == 'N'))
			{
				for (int i = 0; i < 11; i++)
				{
					sum1 += g_arr[pos].deck1[i];
					sum2 += g_arr[pos].deck2[i];
				}

				if (sum1 == sum2)
					buf = "Draw!  \n";
				else if ((sum1 > sum2) && (sum1 <= 21))
					buf = "Player1 win!\n";
				else if ((sum2 > sum1) && (sum2 <= 21))
					buf = "Player2 win!\n";
				else if ((sum1 <= 21) && (sum2 > 21))
					buf = "Player1 win!\n";
				else if ((sum2 <= 21) && (sum1 > 21))
					buf = "Player2 win!\n";
				else if ((sum1 > 21) && (sum2 > 21) && (sum1 < sum2))
					buf = "Player1 win!\n";
				else if ((sum1 > 21) && (sum2 > 21) && (sum2 < sum1))
					buf = "Player2 win!\n";
			}

			strcpy(shm_address->string, buf.c_str());

		}
		printf("End reading\n\n\n");

		if ((buf[7] != ',') && (buf[7] != ':'))
		{
			g_arr[pos].id = -1;
			for (int i = 1; i < 11; i++)
			{
				g_arr[pos].deck1[i] = 0;
				g_arr[pos].deck2[i] = 0;
				g_arr[pos].bank[i] = 1;
			}
			printf("For pid %d game %d deleted\n\n\n", id, pos);
		}

		operations[0].sem_num = 0;
		operations[0].sem_op = 1;
		operations[0].sem_flg = IPC_NOWAIT;

		operations[1].sem_num = 1;
		operations[1].sem_op = 1;
		operations[1].sem_flg = IPC_NOWAIT;
		rc = semop(semid, operations, 2);
		if (rc == -1)
		{
			perror("server: semop() failed");
			return -1;
		}
	}
	rc = semctl(semid, 1, IPC_RMID);
	if (rc == -1)
	{
		perror("server: semctl() remove id failed");
		return -1;
	}
	rc = shmdt(shm_address);
	if (rc == -1)
	{
		perror("server: shmdt() failed");
		return -1;
	}
	rc = shmctl(shmid, IPC_RMID, &shmid_struct);
	if (rc == -1)
	{
		perror("server: shmctl() failed");
		return -1;
	}
	return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <string.h>

void chef(void *ptr);
void guest(void *ptr);
int firstNumber,secondNumber, NUM_THREADS;
sem_t sem;
int buffersize = 0;
int buffer[];
int buffereats[80];
int min = 1, max = 4;

int main(){
    char proj[5], option[12];
    int ScanResultsOper;
    int ScanResultsNum = 0;
    int noofcgloops = 0;
    int wanttoeat[40];
    int timetoeat[40];

    //Scanning inputs from UI
    while(strcmp(proj,"bye")){
          printf("12435_G5> $ ");
          ScanResultsOper = scanf( "%s",proj);
          if(!strcmp(proj,"bye")){
                 printf("bye\n");
                 return 0;
           }
           else{

              ScanResultsNum = scanf("%s %d %d",option,&firstNumber, &secondNumber);
              if( ((!strcmp(proj,"tcr")) && (!strcmp(option,"-semaphores")) && (ScanResultsNum == 3)) && (firstNumber != 0) &&
            (secondNumber != 0 ) && (firstNumber < 0) && (secondNumber < 0 ) ){
            buffersize = -(firstNumber);
            buffer[buffersize];

            NUM_THREADS = (-(secondNumber));
            int i=0;

            printf("Chef starts cooking.\n");
            srand(time(NULL));
            for (i =1;i<=NUM_THREADS;i++)
            {
                timetoeat[i]=(rand() % (max + 1 - min)) + min;  //initializing timetoeat for a random number between 1 to 4
                wanttoeat[i] = timetoeat[i];           // assigning number of food guest want to eat to time to eat
                printf("Guest %d  arrives and wants to eat  %d  tandoori chickens.\n",i,wanttoeat[i]);
            }
            for(i=1;i<=NUM_THREADS;i++)
            {
                noofcgloops = noofcgloops + wanttoeat[i];
            }
            pthread_t tchef;
            pthread_t tguest;
            int u,j,k;
            sem_init(&sem,0,1);
			int killed_threads[NUM_THREADS];
			int i1;
			for( i1=0;i1<NUM_THREADS;i1++){
				killed_threads[i1]=0;
			}
			//int killed_threads[]={0,0,0,0};
			int kill_index = 0;

          for(u = 1;u <= noofcgloops; u++)
          {
            k=u;
			//printf("k val %d \n",k);

               if(k>NUM_THREADS)
               {
                 while(k>NUM_THREADS)
                {
                    k=k-NUM_THREADS;
					//printf("k val seond %d \n",k);
                }
				for(i=0;i<NUM_THREADS;i++)
				{
					if(killed_threads[i]==k)
						k=k+1;
					if(k>NUM_THREADS)
						k=k-NUM_THREADS;
				}
                }
          int *i1=k;

          pthread_create(&tchef,NULL,(void *) &chef,(void *)i1);
          pthread_create(&tguest,NULL,(void *) &guest,(void *)i1);

          pthread_join(tchef,NULL);
          pthread_join(tguest,NULL);
          if(buffereats[k] <= wanttoeat[k])
          {
               printf("[%d/%d]\n",buffereats[k],wanttoeat[k]);
               if(buffereats[k] == wanttoeat[k])
               {
                    printf("Guest%d finishes and exits.\n",k);
					//guest.join();
					pthread_join(tguest,NULL);
					//pthread_cancel(&guest);
					//NUM_THREADS=NUM_THREADS-1;
					killed_threads[kill_index]=k;
					//printValues(killed_threads,NUM_THREADS);
					kill_index++;
               }
          }
        }

        for(i=0;i<noofcgloops;i++)
        {
            buffereats[i]=0;
        }
        printf("All guests finish eating and exit.\n");
        buffersize = 0, k = 0, firstNumber = 0, secondNumber = 0, u = 0, noofcgloops = 0;

        sem_destroy(&sem);
        strcpy(proj,"");
        }
        else{
            printf("Please enter valid input.\n");
        }
     }
  }
  return 0;
}

void chef(void *ptr)
{
    int *x=(int *)ptr;
    printf("Chef cooks one tandoori chicken. [1/%d]\n",buffersize);
    sem_wait(&sem);
    void buffer1(x);
    sem_post(&sem);
    pthread_exit(0);
}

void guest(void *ptr)
{
    int y;
    int *x=(int *)ptr;
    y=x;
    sem_wait(&sem);
    buffereats[y]++;
    sem_post(&sem);
    printf("Guest%d eats a tandoori chicken. ",x);
    pthread_exit(0);
}


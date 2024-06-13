/*Michail Symeonidis
AM:2022202200202
dit22202@go.uop.gr

Euthumios Skourtis
AM:2022202200194
dit22194@go.uop.gr
*/

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
int open(int a, int b, int N, int M, char **A, char **B);
int mark(int a, int b, int N, int M, char **A, char **B);
int cheat(int a, int b, int N, int M, char **A, char **B);
char Gemisma_N(char **B, int N, int M, int a, int b);		/*H synarthsh Gemisma_N gemizei ton pinaka B me narkes analoga to epipedo dyskolias*/
char Gemisma_Ar(char **B, int N, int M);					/*H synarthsh Gemisma_Ar gemizei kathe keli tou B analoga me to poses narkes sunoreuei*/
char Gemisma_T(char **B, int N, int M);						/*H synarthsh Gemisma_T gemizei ta kena kelia pou den exoun narkes ki oute sunoreuoun me kapoia, me '.'*/
int main(void)
{
	srand(time(NULL));
	int i, j, r, t = 0, x, y, o = 0, m = 0, c = 0, e = 0, q = 1, f, epipedo, narkes, N, M, opened_cells = 0, Nark_free, kinhseis_ar, LEVEL = 0;
	char **A, **B, E[12], O[] = "open", M2[] = "mark", C[] = "cheat", EX[] = "exit", Num1[4], Num2[4];
	do                                                      /*Stis periptwseis pou o arithmos twn narkwn einai dekadikos ton strogylopoioume pros ta katw. Etsi prepei toulaxiston oi diastaseis tou pinaka na exoun ginomeno >=10*/  
	{
		printf("Give the two dimensions so that their product can be equall or bigger than the numeber 10\n");
		scanf("%d %d", &N, &M);
		if(N * M < 10)
		{
			printf("False dimensions\n");
		}
	}while(N * M < 10); 
	A = (char**) malloc(N*sizeof(char*));
	B = (char**) malloc(N*sizeof(char*));
	for(i = 0; i < N; i++)		
	{
		 A[i] = (char*) malloc(M*sizeof(char));				/*O B pinakas einai gia ton programmatisth, wste na blepei ti exei kathe keli*/ 
		 B[i] = (char*) malloc(N*sizeof(char));				/*O A pinakas einai aytos pou emfanizetai ston paixth kai anoigei me bash tis kinhseis tou paixth, me bash tis times tou pinaka B*/
	}
	if((A != NULL) && (B != NULL))
	{
		printf("Choose difficulty\n");
		do
		{
			printf("Easy difficulty, press 1\n");
			printf("Medium difficulty, press 2\n");
			printf("Hard difficulty, press 3\n");
			printf("Impossible difficulty, press 4\n");
			scanf("%d", &epipedo);
			if((epipedo < 1) || (epipedo > 4))
			{
				printf("Error!\n");
				printf("To choose a difficulty level press a digit between numbers 1 and 4\n");
			}
		}while((epipedo < 1) || (epipedo > 4));
		if(epipedo == 1)
		{
			narkes = (N * M) * 0.1;										
			Nark_free = N*M - narkes;
			for(i = 0; i < N; i++)
			{
				for(j = 0; j < M; j++)
				{
					A[i][j] = '#';
				}
			}
			printf("  ");
			for(j = 0; j < M; j++)
			{
				printf(" %d", j + 1);
			}
			printf("\n");
			for(j = 0; j < M + 1; j++)
			{
				printf(" -");
			}
			printf("\n");
			for(i = 0; i < N; i++)
			{
				for(j = 0; j < M; j++)
				{
					if(j == 0)
					{
						printf("%d|%2c",i + 1, A[i][j]);
					}
					else
					{
						printf("%2c", A[i][j]);
					}
				}
				printf("\n");
            }		                                /*Arxh gyrou*/
			while((opened_cells < Nark_free))	    /*To epipedo synexizetai mexri ta kelia pou anoigei o paixtis ginoun isa me ton arithmo twn keliwn ta opoia den exoun narkes H an anoixei keli me narkh*/
			{
				do
				{
					printf("%d blocks are open.\n Make your move(s): ", t);
					scanf("%s", &E);	
					printf("%s\n", E);		        /*O pinakas E diabazei poia entolh tha dwsei o paixths  (open, mark, cheat) kathws kai tis syntetagmenes, thn elenxei poia apo tis treis einai me*/
					for(i = 0; E[i] != '\0'; i++)	/*th bohtheia twn metablhtwn o,c,m */
					{
						if(E[i] == O[i])
						{
							o++;			        /*H metablhth 'o' antistoixei sthn open*/
						}
						if(E[i] == M2[i])
						{
							m++;			        /*H metablhth 'm' antistoixei sthn mark*/
						}
					 	if(E[i] == C[i])
						{
							c++;			        /*H metablhth 'c' antistoixei sthn cheat*/
						}
						if(E[i] == EX[i])
						{
							e++;
						}				            /*H metablhth 'e' antistoixei sthn 'exit'*/
					}
					if(o == 4 || m == 4)
					{						        /*Afou brethei poia kinhsh egine oi syntetagmenes pou edwse o paixtis apothhkeuontai stous duo pinakes Num1 kai Num2*/
						r = 0;
						i = 5;
						while(E[i] != ',')
						{
							Num1[r] = E[i];
							r++;
							i++;
						}
						f = i + 1;	
						r = 0;
						for(i = f; E[i] != ')'; i++)
						{
							Num2[r] = E[i];
							r++;
						}
					}
					if(c == 5)
					{
						r = 0;
						for(i = 6; E[i] != ','; i++)
						{
							Num1[r] = E[i];
							f = i;
							r++;
						}
						r = 0;
						for(i = f; E[i] != ')'; i++)
						{
							Num2[r] = E[i];
							r++;
						}
					}
					if(e == 4)
					{
						exit(0);
					}
					x = atoi(Num1);	                   /*Oi duo pinakes ginontai integers wste na apothikeutoun stis metablhyes x,y oi opoies tha xrhsimopoihthoun gia na metaferoyn tis syntetagmenes stis synarthseis analoga me*/
					y = atoi(Num2);                    /*poia entolh epaixe o paixths*/
					if((x <= 0) || (x > N) || (y <= 0) || (y > M))
					{
						printf("Error!\nGive coordinates between 1 and the numbers, for the lines %d and columns %d.\n", N, M);
					}
				}while((x <= 0) || (x > N) || (y <= 0) || (y > M));
				if(kinhseis_ar == 0)					/*H metblhth kinhseis_ar bohthaei otan o paixtis kanei thn prvth tou kinhsh mono tote na gemisei o pinakas B kai na mhn xasei kateytheian*/
				{
					for(i = 0; i < narkes; i++)
					{
						Gemisma_N(B, N, M, x - 1, y - 1);	    /*Gemisma pinaka B*/
					}
					Gemisma_Ar(B, N, M);
					Gemisma_T(B, N, M);
					kinhseis_ar++;						/*Edw h metablhth auxanetai wste mexri na teleiwsei ayto to epipedo o paixtis na mhn xanagemisei ton pinaka*/
				}
				if(o == 4)
				{
					t = open(x - 1, y - 1, N, M, A, B);	/*H metablhth t epistrefei kathe fora ton arithmo twn keliwn pou anoixan epomenws den htan narkh kai 0 an htan termatizontas to paixnidi*/
					o = 0;						        /*Oi metablhtes o,m,c,e mhdenizontai kathe fora pou o paixths xanpaizei wste na mhn kratane tis prohgoumenes times kai kollhsei to paixnidi*/
					m = 0;										
					c = 0;
					e = 0;
				}
				else if(m == 4)
				{
					do
					{
						if(q == 0)
						{
							printf("Error!\nGive new coordinates between 1 and the numbers, for the lines %d and columns %d to mark your option.\n", N, M);
							scanf("%d %d", &x, &y);
						}
						q = mark(x - 1, y - 1, N, M, A, B);	/*H metablhth q bohthaei ston elexho an kapoio keli exei hdh ginei 'marked' apo ton paixth na zhtaei nees syntetagmenes*/
					}while(q == 0);					    /*Sthn synarthsh mark ginetai o elexhos autos ki an to eixe hdh markarei o paixths, epistrefei 0 kai zhtaei kainouries*/
					o = 0;
					m = 0;
					c = 0;
					e = 0;
				}
				else if(c == 5)
				{
					cheat(x - 1, y - 1, N, M, A, B);
					o = 0;
					m = 0;
					c = 0;
					e = 0;
				}
				if(t == -1)
				{
					printf("Game over");
					exit(0);
				}
				printf("  ");
				for(j = 0; j < M; j++)
				{
					printf(" %d", j + 1);
				}
				printf("\n");
				for(j = 0; j < M + 1; j++)
				{
					printf(" -");
				}
				printf("\n");
				for(i = 0; i < N; i++)
				{
					for(j = 0; j < M; j++)
					{
						if(j == 0)
						{
							if(A[i][j] >= 1 && A[i][j] <= 8)
							{
								printf("%d|%2d",i + 1, A[i][j]);
							}
							else
							{
								printf("%d|%2c",i + 1, A[i][j]);
							}
						}
						else
						{
							if(A[i][j] >= 1 && A[i][j] <= 8)
							{
								printf("%2d", A[i][j]);
							}
							else
							{
								printf("%2c", A[i][j]);
							}
						}
					} 
					printf("\n");
				}
				opened_cells = opened_cells + t;
				if(opened_cells == Nark_free)
				{
					LEVEL = 1;	/*An anoixei o paixtis ola ta kelia xwris na xasei h metablhth LEVEL ginetai 1 wste na proxvrhsei ton paixti se neo epipedo*/
				}				
			}
		}
		return 0;
	}
	else
	{
		exit(0);
	}
}


char Gemisma_N(char **B, int N, int M, int a, int b)
{
    int x, y;
	do
	{
	    x = rand() % N;
	    y = rand() % M;
	}while(x == a && y == b);	/*Sthn synarthsh me tis narkes prepei na ginetai elexhos prin gemisei kathws o paixtis den prepei na anoixei bomba sthn prwth tou kinhsh*/
	B[x][y] =  '@';			    /*Etsi thn prwth fora pou paizei den exei gemisei akomh o pinakas kai analoga me tis prwtes syntetagmenes ekeino to keli gemizei me arithmo an sunoreuei me narkh H menei keno*/
	return 0;
}


char Gemisma_Ar(char **B, int N, int M)
{
	int c, i, j;
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < M; j++)
		{
			if(B[i][j] != '@')
			{
				c = 0;
				if(i != 0)
				{
					if(B[i-1][j] == '@')		/*Afou exei gemisei o pinakas B me narkes ginetai se kathe keli, pou den exei narkh, elexhos gia to an kai me poses synoreuei sta geitwnika tou kelia*/
					{
						c++;
					}
				}
				if((i != 0) && (j != M - 1))
				{
					if(B[i-1][j+1] == '@')		/*O syntetagmenes gia kathe geitoniko keli fainontai stis synthikes oi opoies an einai alitheis h metablhth c auxanetai mexri kai ton teleutaio elxho tou*/
					{				            /*geitonikou keliou*/
						c++;
					}
				}
				if(j != M - 1)
				{
					if(B[i][j+1] == '@')
					{
						c++;
					}
				}
				if((i != N - 1) && (j != M - 1))
				{
					if(B[i+1][j+1] == '@')
					{
						c++;
					}
				}
				if(i != N - 1)
				{
					if(B[i+1][j] == '@')
					{
						c++;
					}
				}
				if((i != N - 1) && (j != 0))
				{
					if(B[i+1][j-1] == '@')
					{
						c++;
					}
				}
				if(j != 0)
				{
					if(B[i][j-1] == '@')
					{
						c++;
					}
				}
				if((i != 0) && (j != 0))
				{
					if(B[i-1][j-1] == '@')
					{
						c++;
					}
				}
				B[i][j] = c;				    /*Meta apo olous tous elexhous h timh ths c apothikeuetai sto keli sto opoio ginontan oi elexhoi gia to an synoreuei me narkes*/
			}
		}
	}
	return 0;
}


char Gemisma_T(char **B, int N, int M)
{
	int i, j;
	for(i = 0; i < N; i++)
	{								            /*Stis periptvseis pou kapoio keli den synoreue me narkh h metablhth c (ths synarthshs Gemisma_Ar) apothikeue 0 sto keli*/ 
		for(j = 0; j < M; j++)				    /*Etsi se ayth th synarthsh ta kelia me 0 antikathistountai apo ton xarakthra '.' wste na deixoume pws einai kena*/
		{
			if(B[i][j] == 0)
			{
				B[i][j] = '.';
			}
		}
	}
	return 0;
}


int open(int a, int b, int N, int M, char **A, char **B)
{
	int i, j, kout = 0;
	if(B[a][b] == '@')
	{
		kout = -1;
		return kout;
	}
	else if((a >= N) || (a < 0) || (b >= M) || (b < 0)) 
	{
		return kout;
	}
	else if((A[a][b] != '#') && (A[a][b] != '$'))
	{
		return kout;
	}
	else if((B[a][b] >= 1) && (B[a][b] <= 8))
	{
		kout++;
		A[a][b] = B[a][b];
		return kout;
	}
	else
	{
		A[a][b] = B[a][b];
		kout++;
		open(a - 1, b, N, M, A, B);
		open(a - 1, b + 1, N, M, A, B);
		open(a, b + 1, N, M, A, B);
		open(a + 1, b + 1, N, M, A, B);
		open(a + 1, b, N, M, A, B);
		open(a + 1, b - 1, N, M, A, B);
		open(a, b - 1, N, M, A, B);
		open(a - 1, b - 1, N, M, A, B);
	}
}


int mark(int a, int b, int N, int M, char **A, char **B)
{
	if(A[a][b] != '#')
	{
		printf("Already opened cell\n");
		return 0;
	}
	else
	{
		A[a][b] = '$';
	}
}


int cheat(int a, int b, int N, int M, char **A, char **B)
{
	if(B[a][b] == '.')
	{
		printf("Cell %d,%d does not border with mines (empty)\n", a+1, b+1);
	}
	else if(B[a][b] == '@')
	{
		printf("Cell %d,%d has a mine.\n", a+1, b+1);
	}
	else
	{
		printf("Cell %d,%d borders with %d mine(s).\n", a+1, b+1, B[a][b]);
	}
}

/*4. Crie uma estrutura representando os alunos de um determinado curso. A estrutura deve conter a matr´icula do aluno, nome, nota da primeira prova, nota da segunda prova e nota da terceira prova. 
	(a) Permita ao usu´ario entrar com os dados de 5 alunos. 
	(b) Encontre o aluno com maior nota da primeira prova. 
	(c) Encontre o aluno com maior m´edia geral. 
	(d) Encontre o aluno com menor m´edia geral 
	(e) Para cada aluno diga se ele foi aprovado ou reprovado, considerando o valor 6 para aprovação.*/ 

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>

struct aluno
{
	int p1,p2,p3; //notas do aluno da prova 1, prova 2, prova 3.
	char nome [100];
	char matricula[30];
};

void preenche_alunos(struct aluno vet_aluno[])
{
	int i;
	for(i = 0;i < 5;i++)
	{
		system("cls");
		printf("Digite o nome do %iº aluno: ",i+1);
		fflush(stdin);
		gets(vet_aluno[i].nome);
		printf("Digite a matricula do %iº aluno: ",i+1);
		fflush(stdin);
		gets(vet_aluno[i].matricula);
		printf("Digite a nota da 1º prova: ");
		scanf("%i", &vet_aluno[i].p1);
		printf("Digite a nota da 2º prova: ");
		scanf("%i", &vet_aluno[i].p2);
		printf("Digite a nota da 3º prova: ");
		scanf("%i", &vet_aluno[i].p3);
	}
}

void maior_notap1(struct aluno vet_aluno[]) //Encontra a maior nota da primeira prova
{
	int i;
	int maior_nota = vet_aluno[0].p1;
	for(i = 0;i < 5;i++)
		if(vet_aluno[i].p1 > maior_nota)
			maior_nota = vet_aluno[i].p1;
	printf("Alunos com maior(es) nota(s)");
	for(i = 0;i < 5;i++)
		if(vet_aluno[i].p1 == maior_nota)
		printf("\n\nAluno: %s \nMatricula: %s \nNota: %i", vet_aluno[i].nome, vet_aluno[i].matricula, vet_aluno[i].p1);
	getch();
}

void maior_media_notas(struct aluno vet_aluno[]) //Mostra alunos com notas acima da media
{
	int i;
	int media_nota = 0;
	for(i = 0;i < 5;i ++)
		media_nota += vet_aluno[i].p1 + vet_aluno[i].p2 + vet_aluno[i].p3;
	media_nota /= 5;
	printf("Aluno(s) com nota(s) maior(es) que a media: \nMédia: %i \n\n", media_nota);
	for(i = 0;i < 5; i++)
		if(vet_aluno[i].p1 + vet_aluno[i].p2 + vet_aluno[i].p3 >= media_nota)
			printf("Aluno: %s \nMatricula: %s \nNota da prova 1: %i \nNota da prova 2: %i \nNota da prova 3: %i \n\n",vet_aluno[i].nome, vet_aluno[i].matricula, vet_aluno[i].p1, vet_aluno[i].p2, vet_aluno[i].p3);
	getch();
}

void menor_media_notas(struct aluno vet_aluno[]) //Mostra os alunos com as notas menores que a media
{
	int i;
	int media_nota = 0;
	for(i = 0;i < 5;i ++)
		media_nota += vet_aluno[i].p1 + vet_aluno[i].p2 + vet_aluno[i].p3;
	media_nota /= 5;
	printf("Aluno(s) com nota(s) menor(es) que a media:\nMédia:%i \n\n", media_nota);
	for(i = 0;i < 5; i++)
		if(vet_aluno[i].p1 + vet_aluno[i].p2 + vet_aluno[i].p3 < media_nota)
			printf("Aluno: %s \nMatricula: %s \nNota da prova 1: %i \Nota da prova 2: %i \nNota da prova 3: %i \n\n",vet_aluno[i].nome, vet_aluno[i].matricula, vet_aluno[i].p1, vet_aluno[i].p2, vet_aluno[i].p3);
	getch();
}

void apro_repro(struct aluno vet_aluno[]) //Mostra quais alunos estão aprovados e reprovados
{
	int i;
	for(i = 0;i < 5; i++)
		if(vet_aluno[i].p1 + vet_aluno[i].p2 + vet_aluno[i].p3 >= 60)
			printf("Nome: %s \nMatricula: %s \nNota prova 1: %i \nNota prova 2: %i \nNota prova 3: %i\nAluno Aprovado\n\n",vet_aluno[i].nome, vet_aluno[i].matricula, vet_aluno[i].p1, vet_aluno[i].p2, vet_aluno[i].p3);
		else
			printf("Nome: %s \nMatricula: %s \nNota prova 1: %i \nNota prova 2: %i \nNota prova 3: %i\nAluno Reprovado\n\n",vet_aluno[i].nome, vet_aluno[i].matricula, vet_aluno[i].p1, vet_aluno[i].p2, vet_aluno[i].p3);
	getch();	
}

int main()
{
	aluno vet_alunos[5];
	int opcao;
	do
	{
	setlocale(LC_ALL,"portuguese");
	system("cls");
	printf("Escolha uma das opções abaixo: \n\n1 - Cadastrar alunos. \n2 - Maior nota da primeira prova. \n3 - Mostrar alunos com notas maiores que a media. \n4 - Mostrar alunos menores que a média.");
	printf("\n5 - Mostrar alunos que foram aprovados e reprovados. \n6 - Sair do programa. \nDigite: ");
	scanf("%i", &opcao);
	switch(opcao)
	{
		case 1:
			system("cls");
			preenche_alunos(vet_alunos);
			break;
		case 2:
			system("cls");
			maior_notap1(vet_alunos);
			break;
		case 3:
			system("cls");
			maior_media_notas(vet_alunos);
			break;
		case 4:
			system("cls");
			menor_media_notas(vet_alunos);
			break;
		case 5:
			system("cls");
			apro_repro(vet_alunos);
			break;
		case 6:
			return 0;
		default:
			printf("Opção invalida");
			getch();
	}
	}
	while(opcao != 6);
	return 0;	
}

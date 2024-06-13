#include <stdio.h> // Biblioteca de comunicação com o usuário
#include <stdlib.h> // Biblioteca de alocação de espaço em memória
#include <locale.h> // Biblioteca de alocação de texto por região
#include <string.h> // Biblioteca responsavel por cuidar das string

int registro() //funcão para cadastrar os usuários
{
	//inicio criação de variáveis/string
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	//final criação de variáveis/string
	
	printf("\n");
	
	printf("Digite o CPF a ser cadastrado: ");// coletando informções do usuário
	scanf("%s",cpf); // %s refere-se string
	
	strcpy(arquivo,cpf);  //responsavel por copiar o valor das string
	
	FILE *file;  //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo novo
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	printf("\n\n");
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem

	char cpf[40];
	char conteudo [200];

	printf("Digite o CPF a ser consultado: ");
	scanf ("%s", cpf);

	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("\n\n");
		printf(" !!!! CPF não localizado !!!! \n\n");
		printf("        TENTE NOVAMENTE    \n ");
		printf("\n\n");
	}	
	
	while(fgets(conteudo, 200,file)!=NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf ("%s", conteudo) ;
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
		char cpf[40];
		
		printf("\nDigite o CPF a ser deletado: \n\n");
		scanf("%s",cpf);
		
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
	
		
		if(file == NULL);
			{
				printf("\n\nCPF deletado.\n\n");
				system("pause");
			}
	
	   	
}


int main()
{
	int opcao=0; //definindo variáveis
	int laco=1;
	
	for (laco=1;laco=1;)
	{	
		
		system("cls");// responsavel por limpar a tela
	
		setlocale(LC_ALL, "Portuguese");//definindo a limguagem
	
	
		printf("### Cartório da EBAC ###\n\n");//inicio do menu
		printf( "Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //fim do menu

		scanf("%d",&opcao);//armazenando a escolha do usuário
	
		system("cls");
		
		switch(opcao)
		{
		
			case 1:
				registro(); //chamada de funções
	    	 	break;
	    	 	
	    	case 2:
				consulta();
	     		break;
	     		
	     	case 3:
	     		deletar();
	     		break;
	     		
	     	case 4:
	     		printf("Obrigado, volte sempre!\n");
	     		return 0;
	     		break;
			 	
	     	default:
	     		printf("\nEssa opção não esta disponivel\n\n\n\n");//fim da seleção
	   			system("pause");
	   			break;
		}// fim da seleção
	}
}
